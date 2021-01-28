#include <iostream>
#include <string>
#include <curl/curl.h>


size_t writeCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

std::string getURL(const char* url="https://en.wikipedia.org/wiki/Napoleon")
{
    CURL *curl;
    CURLcode res;
    std::string readBuffer;

    curl = curl_easy_init();
    if(! curl)
    {
      std::cerr << "Error initializig curl: " << std::endl;
    }
    else 
    {
      curl_easy_setopt(curl, CURLOPT_URL, url);
      curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeCallback);
      curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
      res = curl_easy_perform(curl);
      curl_easy_cleanup(curl);
    }

    return readBuffer;
}


int main()
{
  std::cout<<getURL();
  return 0;
}