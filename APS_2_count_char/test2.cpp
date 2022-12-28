// https://www.techiedelight.com/sort-map-values-cpp/

#include <iostream>
#include <map>
#include <algorithm>
 
typedef std::pair<char, int> pair;
 
int main()
{
    // input map
    std::map<char, int> bla = {
        {'f', 2}, {'t', 1}, {'a', 4}, {'c', 3}
    };
 
    // create an empty vector of pairs
    std::vector<pair> vec;
 
    // copy key-value pairs from the map to the vector
    std::copy(bla.begin(), bla.end(), std::back_inserter<std::vector<pair>>(vec));
 
    // sort the vector by increasing the order of its pair's second value
    // if the second value is equal, order by the pair's first value
    std::sort(vec.begin(), vec.end(), [](const pair &l, const pair &r){if (l.second != r.second) {return l.second < r.second;}return l.first < r.first;});
 
    // print the vector
    for (auto const &pair: vec) {
        std::cout << '{' << pair.first << "," << pair.second << '}' << std::endl;
    }
 
    return 0;
}