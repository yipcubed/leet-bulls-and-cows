#include <algorithm>
#include <cstring>
#include <climits>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>


#include "../utils/VectorUtils.hpp"
#include "../utils/PrintUtils.hpp"
// #include "../utils/HeapUtils.hpp"
// #include "../utils/BinarySearch.hpp"
// #include "../utils/TreeUtils.hpp"

// https://leetcode.com/problems/bulls-and-cows/

using namespace std;

#pragma GCC diagnostic ignored "-Wunknown-pragmas"

// Live coding problems, watch at
// https://www.twitch.tv/yipcubed
// https://www.youtube.com/channel/UCTV_UOPu7EWXvYWsBFxMsSA/videos
//

// makes code faster, but larger. Just for LeetCode fun!
#pragma GCC optimise ("Ofast")

// makes stdin not synced so it is faster. Just for LeetCode fun!
static auto __ __attribute__((unused)) = []() {              // NOLINT
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    string getHint(string& secret, string& guess) {
        int bull_count = 0;
        int cow_count = 0;
        // using a vector of 10 is faster
        unordered_map<char, int> m;
        for (auto c: secret) {
            ++m[c];
        }
        for (int i = 0; i < secret.length(); ++i) {
            if (secret[i] == guess[i]) {
                ++bull_count;
                --m[secret[i]];
            }
        }
        for (int i = 0; i < secret.length(); ++i) {
            if (secret[i] != guess[i]) {
                if (m[guess[i]] > 0) {
                    ++cow_count;
                    --m[guess[i]];
                }
            }
        }

        return to_string(bull_count) + "A" + to_string(cow_count) + "B";
    }
};

void test1() {
    string secret = "1807", guess = "7810";


//    cout << "1A3B ? " << Solution().getHint(secret, guess) << endl;

    secret = "1123", guess = "0111";
    cout << "1A1B ? " << Solution().getHint(secret, guess) << endl;

}

void test2() {

}

void test3() {

}