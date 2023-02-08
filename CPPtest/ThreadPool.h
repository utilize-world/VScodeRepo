#ifndef THREAD_POOL_H
#define THREAD_POOL_H

#include <vector>             //����
#include <queue>              //����
#include <memory>             //�ڴ����
#include <thread>             //�߳����      ��Ҫ�������̶߳���std::thread�Ĺ���
#include <mutex>              //������        ��Ҫ��������Mutex����Ĺ��죬��Ҫ��std::mutex
#include <condition_variable> //��������      �������߳��г��õ���������������������notify_one��wait��wait_for�ȵ�
#include <future>             //���첽������ȡ���    ���Ի�ȡ�첽����Ľ����������ʵ��ͬ��������std::sync��std::future
#include <functional>         //��װ����Ϊ����    ����˵����ʵ�ֺ���������İ󶨣���bind()����
#include <stdexcept>          //�쳣���

// ��ֵ����
// int num = 10;
// int && a = num;    // ������ֵ���ò��ܳ�ʼ��Ϊ��ֵ
// int &&a = 10; // ��ȷ

class ThreadPool
{
public:
    ThreadPool(size_t);
    template <class F, class... Args>                              // ����һ������ģ�壬����������auto������class...Args��ʾ���ܶ������
    auto enqueue(F &&f, Args &&...args)                            //&&����ֵ����,enqueue�Ǻ�����,()��������βα�
        -> std::future<typename std::result_of<F(Args...)>::type>; // �����õ�C++11�е�lambda���ʽ����ʾ
    // �������ص�������std::future<typename std::result_of<F(Args...)>::type>
    // std::future �䱾�����һ��ģ�壬������<future>�У�ͨ��std::future���Է���A���͵���������
    // �����A���Ǻ����std::result_of<F(Args...)>::type
    // result_of ��ȡ��someTask��ִ�н�������ͣ�F(Args...)������δ����someTask��
    // ����enqueue����ֵ���;���F(Args...)���첽ִ�н������
    ~ThreadPool();

private:
    // need to keep track of threads so we can join them
    std::vector<std::thread> workers; // �߳�����   ���������̶߳���
    // the task queue
    std::queue<std::function<void()>> tasks; // ������У����е��̳߳ض����������

    // synchronization
    std::mutex queue_mutex;            // ������
    std::condition_variable condition; // ��������          ���������߳�ͬ����Ҫ�ı���
    bool stop;                         // ֹͣ��ʼ����
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
