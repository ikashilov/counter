#include "counter.cpp"

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
