#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <set>
#include <functional>
#include <algorithm>
#include <regex>
#include "curl.cpp"


using std::string;
using std::cout;
using std::endl;
using std::vector;


template <typename T>
int countRealCapacity(vector<T> v) 
{
    std::set <T,std::greater<T>> s;

    for (auto const& x: v)
        s.insert(x);

    return s.size();
}

vector<string> getFileContent(const string& fileName)
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


vector<string> getRandVectorOfStringNumbers(size_t size)
{
    srand(time(NULL));
    vector<string> result;

    for (int i = 0; i < size; ++i) 
    {
        result.push_back(std::to_string((rand() % size))); 
    }

    return result;
}


vector<string> splitStr(const string str, const string regex_str)
{
    std::regex regexz(regex_str);
    vector<string> list(std::sregex_token_iterator(str.begin(), str.end(), regexz, -1),
                        std::sregex_token_iterator());
    return list;
}


vector<string> getVetctorOfWordsFromURL(const char* url="https://en.wikipedia.org/wiki/Napoleon")
{
    vector<string> result;
    auto s = getURL(url);
 

    return splitStr(s, " ");
}

