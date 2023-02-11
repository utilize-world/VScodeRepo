#include <vector>
#include <iostream>

class test
{
public:
    test()
    {
        std::vector<int> a(3, 2);
        std::vector<int> b(3, 3);
        std::vector<int> c(3, 1);
        A.push_back(a);
        A.push_back(b);
        A.push_back(c);
        A.push_back(std::vector<int>(3, 0));
        A.pop_back(); // 删去一整行
    }

public:
    std::vector<std::vector<int>> A;
    void printVector2(std::vector<std::vector<int>> test_2D_Vector)
    {
        for (auto i : test_2D_Vector) // 对二维数组进行迭代
        {
            for (auto j : i)
            {
                std::cout << j << " ";
            }
            std::cout << std::endl;
        }
    }

private:
    int &&a = 20;
};

int main()
{
    test *A = new test();
    A->printVector2(A->A);
}