#include <string>

using std::string;

const uint32_t FNV_PRIME = 16777619u;

uint32_t jenkins_hash(const string& str)
{
    uint32_t hash = 0;

    for (auto const& c: str) 
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


uint32_t fnv1a_hash(const string& str)
{
    uint32_t hash = 2166136261u;

    for (auto const& s: str)
    {
        hash ^= int(s);
        hash *= FNV_PRIME;
    }
    return hash;
}


uint32_t std_hash(const string& str)
{
    std::hash<string> h;
    return h(str);
}
