#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <set>
#include <functional>
#include <algorithm>
#include <curl/curl.h>


using std::string;
using std::cout;
using std::endl;
using std::vector;

const char charset[] ="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

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


vector<int> getRandVectorOfNumbers(size_t size, int rand_from=0, int rand_to=1000)
{
    srand(time(NULL));
    vector<int> result;

    for (int i = 0; i < size; ++i) 
    {
        result.push_back((rand() % rand_to) + rand_from); 
    }

    return result;
}


string random_string(size_t length)
{
    auto randchar = []() -> char
    {
        const size_t max_index = (sizeof(charset) - 1);
        return charset[ rand() % max_index ];
    };
    string str(length,0);
    std::generate_n( str.begin(), length, randchar );
    return str;
}

vector<string> getRandVectorOfStrings(const size_t size, const size_t str_len)
{
    vector<string> result;

    for (int i = 0; i < size; ++i) 
    {
        result.push_back(random_string(str_len)); 
    }

    return result;
}

// ****************************************** Fetch Web Page content using cURL ******************************

// size_t curl_write_callback(void *contents, size_t size, size_t nmemb, void *userp)
// {
//     ((std::string*)userp)->append((char*)contents, size * nmemb);
//     return size * nmemb;
// }

// string getURL(const char* url="https://en.wikipedia.org/wiki/Napoleon")
// {
//     string read_buffer;

//     auto curl = curl_easy_init();
//     if(! curl)
//     {
//       std::cerr << "Error initializig curl: " << std::endl;
//     }
//     else 
//     {
//       curl_easy_setopt(curl, CURLOPT_URL, url);
//       curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, curl_write_callback);
//       curl_easy_setopt(curl, CURLOPT_WRITEDATA, &read_buffer);
//       auto res = curl_easy_perform(curl);
//       curl_easy_cleanup(curl);
//     }

//     return read_buffer;
// }
