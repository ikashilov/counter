#include <string>
#include <bitset>
#include <cmath>
#include <functional>

using std::string;
using std::bitset;

const size_t SIZE_KB = 32; 

class Counter 
{
    private:
        bitset<SIZE_KB*8*1024> bit_arr; 
        const uint32_t arr_size = SIZE_KB*8*1024;
        std::function<uint32_t (string)> hash_func;

    public:
        Counter(std::function<uint32_t (string)> h_func) 
        { 
            bit_arr.reset(); 
            hash_func = h_func; 
        }

        void Add(const string& val)
        {
            uint32_t hval = hash_func(val);
            auto offset = hval % arr_size;
            bit_arr[offset] = true;
        } 

        double Count()
        {
            double ratio = (arr_size - bit_arr.count()) / (double)arr_size;

            return -(double)arr_size * log(ratio);
        }
};
