#ifndef THREAD_POOL_H
#define THREAD_POOL_H

#include <vector>             //数组
#include <queue>              //队列
#include <memory>             //内存操作
#include <thread>             //线程相关      主要包含了线程对象std::thread的构造
#include <mutex>              //互斥量        主要包含各种Mutex的类的构造，主要是std::mutex
#include <condition_variable> //条件变量      包含多线程中常用的条件变量的声明，例如notify_one、wait、wait_for等等
#include <future>             //从异步函数获取结果    可以获取异步任务的结果，可用来实现同步。包括std::sync和std::future
#include <functional>         //包装函数为对象    简单来说可以实现函数到对象的绑定，如bind()函数
#include <stdexcept>          //异常相关

// 右值引用
// int num = 10;
// int && a = num;    // 错误，右值引用不能初始化为左值
// int &&a = 10; // 正确

class ThreadPool
{
public:
    ThreadPool(size_t);
    template <class F, class... Args>                              // 这是一个函数模板，返回类型是auto，后面class...Args表示接受多个参数
    auto enqueue(F &&f, Args &&...args)                            //&&是右值引用,enqueue是函数名,()里面的是形参表
        -> std::future<typename std::result_of<F(Args...)>::type>; // 这里用到C++11中的lambda表达式，表示
    // 函数返回的类型是std::future<typename std::result_of<F(Args...)>::type>
    // std::future 其本身就是一个模板，包含在<future>中，通过std::future可以返回A类型的任务结果，
    // 这里的A就是后面的std::result_of<F(Args...)>::type
    // result_of 获取了someTask的执行结果的类型，F(Args...)就是这段代码的someTask，
    // 所以enqueue返回值类型就是F(Args...)的异步执行结果类型
    ~ThreadPool();

private:
    // need to keep track of threads so we can join them
    std::vector<std::thread> workers; // 线程数组   用来保存线程对象
    // the task queue
    std::queue<std::function<void()>> tasks; // 任务队列，所有的线程池都有任务队列

    // synchronization
    std::mutex queue_mutex;            // 互斥量
    std::condition_variable condition; // 条件变量          这两个是线程同步需要的变量
    bool stop;                         // 停止或开始任务
};

// the constructor just launches some amount of workers
inline ThreadPool::ThreadPool(size_t threads)
    : stop(false)
{
    for (size_t i = 0; i < threads; ++i)
        workers.emplace_back(
            [this]
            {
                for (;;)
                {
                    std::function<void()> task;

                    {
                        std::unique_lock<std::mutex> lock(this->queue_mutex);
                        this->condition.wait(lock,
                                             [this]
                                             { return this->stop || !this->tasks.empty(); });
                        if (this->stop && this->tasks.empty())
                            return;
                        task = std::move(this->tasks.front());
                        this->tasks.pop();
                    }

                    task();
                }
            });
}

// add new work item to the pool
template <class F, class... Args>
auto ThreadPool::enqueue(F &&f, Args &&...args)
    -> std::future<typename std::result_of<F(Args...)>::type>
{
    using return_type = typename std::result_of<F(Args...)>::type;

    auto task = std::make_shared<std::packaged_task<return_type()>>(
        std::bind(std::forward<F>(f), std::forward<Args>(args)...));

    std::future<return_type> res = task->get_future();
    {
        std::unique_lock<std::mutex> lock(queue_mutex);

        // don't allow enqueueing after stopping the pool
        if (stop)
            throw std::runtime_error("enqueue on stopped ThreadPool");

        tasks.emplace([task]()
                      { (*task)(); });
    }
    condition.notify_one();
    return res;
}

// the destructor joins all threads
inline ThreadPool::~ThreadPool()
{
    {
        std::unique_lock<std::mutex> lock(queue_mutex);
        stop = true;
    }
    condition.notify_all();
    for (std::thread &worker : workers)
        worker.join();
}

#endif
