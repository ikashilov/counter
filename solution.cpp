#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <bitset>


using std::string;
using std::cout;
using std::endl;
using std::vector;
using std::bitset;


const size_t SIZE_KB = 64*8*1024;  


class Counter {
     bitset<SIZE_KB> bit_arr; 
     uint32_t arr_size = SIZE_KB;

    public:
     Counter() { bit_arr.reset(); }

     void Add(string val)
     {
        std::hash<string> h;
        auto offset = h(val) % arr_size;
        bit_arr[offset] = true;
     } 

     double Count()
     {
        double ratio = (arr_size - bit_arr.count()) / (double)arr_size;

        return -(double)arr_size * log(ratio);
     }

};


int main() {
    auto counter = Counter();

    uint n;
    std::cin >> n;

    for (string line; std::getline(std::cin, line);) 
    {
        counter.Add(line);
    }

    cout << (int)counter.Count()-1; 

    return 0;
}
