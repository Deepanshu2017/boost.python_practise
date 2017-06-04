#include <iostream>
#include <iterator>
#include <vector>
#include <random>
#include <algorithm>
using namespace std;

int main(void) {
    static const char alphabet[] =
        "abcdefghijklmnopqrstuvwxyz"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "0123456789";

    static const size_t N_STRS = 10000000;
    static const size_t S_LEN = 32;
    cout << N_STRS << "\n";
    random_device rd;
    default_random_engine rng(rd());
    uniform_int_distribution<> dist(0,sizeof(alphabet)/sizeof(*alphabet)-2);

    vector<string> strs;
    strs.reserve(N_STRS);
    generate_n(back_inserter(strs), strs.capacity(),
        [&] { string str; 
              str.reserve(S_LEN); 
              generate_n(back_inserter(str), S_LEN,
                   [&]() { return alphabet[dist(rng)];}); 
              return str; });
    copy(strs.begin(), strs.end(), ostream_iterator<string>(cout, "\n"));
    return 0;
}
