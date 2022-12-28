#include <iostream>
#include <vector>


std::vector <int> sort(std::vector <int> &list) // pass by reference --> "&"
{
    size_t len {list.size()};
    for (int i{0}; i<len; i++)
    {
        for (int j{0}; j<len-1; j++)
        {
            if (list[j] > list[j+1])
                {
                    //std::swap(list[j], list[j+1]);
                    int tmp;
                    tmp = list[j];
                    list[j] = list[j+1];
                    list[j+1] = tmp;
                }
        }
    }
    return list;
}


int main()
{
    std::vector <int> y {1,7,4,9,6,7,8};
    size_t len {y.size()};

    std::vector <int> result = sort(y);
    for (int i {0}; i<len; i++)
        std::cout << result[i] << std::endl;
}