
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>
#include <set>
#include <bitset>
#include <functional>

using std::string;
using std::cout;
using std::endl;
using std::vector;
using std::bitset;


const size_t SIZE_KB = 32; 


vector<string> getFileContent(string fileName)
{
    vector<string> result;

    std::ifstream in(fileName.c_str());

    if(!in)
    {
        std::cerr << "Error opening the file: " << fileName << endl;
    }

    string str;
    while (std::getline(in, str)) 
    {
        result.push_back(str);
    }

    in.close();
    return result;
}


vector<int> genRandVec(size_t size, int start=0, int end=100)
{
    srand(time(NULL));
    vector<int> result;

    for (int i = 0; i < size; ++i) 
    {
        result.push_back((rand() % end) + start); 
    }

    return result;
}


uint32_t jenkins_hash(string s)
{
    uint32_t hash = 0;

    for (auto const& c: s) 
    {
            hash += int(c);
            hash += hash << 10;
            hash ^= hash >> 6;
    }

    hash += hash << 3;
    hash ^= hash >> 11;
    hash += hash << 15;

    return hash;
}


uint32_t fnv1a_hash(string str)
{
    const uint32_t FNV_PRIME = 16777619u;
    uint32_t hash = 2166136261u;

    for (auto const& s: str)
    {
        hash ^= int(s);
        hash *= FNV_PRIME;
    }
    return hash;
}



class Counter {
     bitset<SIZE_KB*8*1024> bit_arr; // size in kilobytes
     uint32_t arr_size = SIZE_KB*8*1024;
     std::function<uint32_t (string)> hash_func;

    public:
     Counter(std::function<uint32_t (string)> h_func) 
     { 
        bit_arr.reset(); 
        hash_func = h_func; 
     }

     void Add(string val)
     {
        uint32_t hval = hash_func(val);
        auto offset = hval % arr_size;
        bit_arr[offset] = true;
     } 

     double Count()
     {
        size_t arr_size = SIZE_KB*8*1024;

        double ratio = (arr_size - bit_arr.count()) / (double)arr_size;

        return -(double)arr_size * log(ratio);

     }

};

template <typename T>
int countReal(vector<T> v) 
{
    std::set <T,std::greater<T>> s;

    for (auto const& x: v)
        s.insert(x);

    return s.size();
}


// ************************************** MAIN *************************************
int main() {
    auto counter = Counter(jenkins_hash);

    //auto v = getFileContent("stream.txt");
    auto v = genRandVec(10000, 0, 10000);

    for(auto const& x: v)
        counter.Add(std::to_string(x));
        //counter.Add(x);

    int cap_real = countReal(v);
    int cap_est =  counter.Count();

    cout << "Real capacity: " << cap_real << endl;
    cout << "Estimated cardinality: " << cap_est << endl;
    cout << "Error: " << (cap_real-cap_est)/(double)cap_real*100 << "%" << endl;

    return 0;
}
