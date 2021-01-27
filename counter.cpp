
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


const size_t SIZE_KB = 64; 


class Counter {
     bitset<SIZE_KB*8*1024> bit_arr; // size in kilobytes
     uint32_t arr_size = SIZE_KB*8*1024;

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
        size_t arr_size = SIZE_KB*8*1024;

        double ratio = (arr_size - bit_arr.count()) / (double)arr_size;

        return -(double)arr_size * log(ratio);
     }

};
