//the headers map, string and iostream are used to be able to make use of map function, cin, cout and strings
#include <iostream>
#include <map>
#include <string>
using namespace std;


void sort(std::map<char, int> dic)
typedef std::pair<char, int> pair; //defines a data type


int main()
{
    //a map called capitalcities is created which stores keys of type strings and corresponding values of type strings
    map<string, int>capitalpop;
    //the elements are added to the created map
    capitalpop["NewDelhi"] = 6456;
    capitalpop["Bangalore"] = 97896;
    capitalpop["Mumbai"] = 234123;
    capitalpop["Chennai"] = 824356;
    //iterating through the created map to print out the key and value pairs from the map

    std::cout<< (capitalpop.find("NewDelhi") == capitalpop.end()) <<std::endl;

    for (auto element :capitalpop)
        {
        //element.first represents the key in the map
        cout<<element.first<<" has a population of ";
        //element.second represents the value in the map
        cout<<element.second << " people" <<endl;
        }
    return 0;
}

void sort(std::map<char, int> dic){

    std::vector<pair> vec;
 
    std::copy(dic.begin(), dic.end(), std::back_inserter<std::vector<pair>>(vec));  // copia os pares do map para o vator
 
    // sort the vector by increasing the order of its pair's second value
    // if the second value is equal, order by the pair's first value
    std::sort(vec.begin(), vec.end(), [](const pair &l, const pair &r){if (l.second != r.second) {return l.second < r.second;}return l.first < r.first;});
 
    // print the vector
    for (auto const &pair: vec) {
        std::cout << '{' << pair.first << "," << pair.second << '}' << std::endl;
    }


    std::cout << vec[3].first << std::endl;
    std::cout << vec[4].first << std::endl;
    std::cout << vec[5].first << std::endl;
    // for (auto const i: vec){
    // std::cout << i << ' ';
    // }
}