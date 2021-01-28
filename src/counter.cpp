#include <counter.h>
#include <math.h>

Counter::Counter(std::function<uint32_t (string)> h_func) 
{ 
    bit_arr.reset(); 
    hash_func = h_func; 
}

void Counter::Add(const string& val)
{
    uint32_t hval = hash_func(val);
    auto offset = hval % arr_size;
    bit_arr[offset] = true;
} 

double Counter::Count()
{
    double ratio = (arr_size - bit_arr.count()) / (double)arr_size;

    return -(double)arr_size * log(ratio);
}

