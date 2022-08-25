#include <iostream>
#include <memory>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
   public:
    bool canConstruct(string ransomNote, string magazine) {
        auto hash = unordered_map<char, int>(26);

        for (auto c : magazine) {
            hash[c]++;
        }

        for (auto c : ransomNote) {
            hash[c]--;
        }

        for (size_t i = 0; i < 26; i++) {
            char c = 'a' + i;
            if (hash[c] < 0) {
                return false;
            }
        }

        return true;
    }
};

int main(int argc, char* argv[]) {
    auto s = new Solution();

    cout << s->canConstruct("a", "b") << endl;
    cout << s->canConstruct("aa", "ab") << endl;
    cout << s->canConstruct("aa", "aab") << endl;

    delete s;
    return 0;
}
