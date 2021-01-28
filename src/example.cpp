#include "counter.h"
#include "utils.cpp"
#include "hashfunc.cpp"


template <typename T>
int countRealCapacity(vector<T> v) 
{
    std::set <T,std::greater<T>> s;

    for (auto const& x: v)
        s.insert(x);

    return s.size();
}

int main() {
    auto counter = Counter(jenkins_hash);

    //auto v = getFileContent("stream.txt");
    auto v = getRandVectorOfNumbers(1000000, 0, 1000000);

    for(auto const& x: v)
        counter.Add(std::to_string(x));
        //counter.Add(x);

    int cap_real = countRealCapacity(v);
    int cap_est =  counter.Count();

    cout << "Real capacity: " << cap_real << endl;
    cout << "Estimated cardinality: " << cap_est << endl;
    cout << "Error: " << (cap_real-cap_est)/(double)cap_real*100 << "%" << endl;

    return 0;
}
