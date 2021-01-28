#include "counter.cpp"
#include "utils.cpp"
#include "hash.cpp"


using std::cin;
using std::cerr;
using std::cout;
using std::endl;
using std::function;


function<uint32_t (string)> getHashFuncFromUserInput() 
{
    int user_input;
    cout << "Pick a hash function: " << endl;
    cout << "\t 1 - Jenkins hash function" << endl;
    cout << "\t 2 - FNV-1a (Fowler–Noll–Vo) hash function" << endl;
    cout << "\t 3 - Build-in hash fucntion" << endl;
    cout << "Input: ";

    cin >> user_input;
    
    function<uint32_t (string)> hash_func;

    switch(user_input) 
    {
        case 1: 
            hash_func = jenkins_hash;
            break;
        case 2:
            hash_func = fnv1a_hash;
            break;
        case 3: 
            hash_func = std_hash;
            break;
        default:
            cerr << "Wrong func number. Number must be either 1, 2 or 3. Given num: " << user_input << endl;
    }

    return hash_func;
}


vector<string> getStreamFromUserInput()
{
    int user_input;
    cout << "Choose a data stream format: " << endl;
    cout << "\t 1 - Random integer numbers (converted to string)" << endl;
    cout << "\t 2 - Build-in dataset (only 2K words)" << endl;
    cout << "\t 3 - Scrape from a webpage. Need to type an url" << endl;
    cout << "Input: ";

    cin >> user_input;
    
    vector<string> v;


    switch(user_input) 
    {
        case 1: 
            cout << "Enter the vector size: ";
            size_t size;
            cin >> size;
            v = getRandVectorOfStringNumbers(size);
            break;
        case 2: 
            v = getFileContent("./data/stream.txt");
            break;
         case 3: 
            cout << "Enter url or type any one character for default (Napoleon Wiki page): ";
            static string url;
            cin >> url;
            cout << url.length() << endl;
            if (url.length() < 2) 
            {
                v = getVetctorOfWordsFromURL();
            }
            else 
            {   
                v = getVetctorOfWordsFromURL(url.c_str());
            }
            break;
        default:
            cerr << "Wrong input. Input must be either 1, 2 or 4. Given input: " << user_input << endl;
    }

    return v;
}


int main() {

    auto hash_func = getHashFuncFromUserInput();
    auto v = getStreamFromUserInput();
    auto counter = Counter(hash_func);

    for(auto const& x: v)
        counter.Add(x);

    int cap_real = countRealCapacity(v);
    int cap_est =  counter.Count();

    cout << "Real capacity: " << cap_real << endl;
    cout << "Estimated cardinality: " << cap_est << endl;
    cout << "Error: " << (cap_real-cap_est)/(double)cap_real*100 << "%" << endl;

    return EXIT_SUCCESS;
}
