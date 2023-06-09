#include <functional>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

#if 0 
class Solution {
   public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        for (auto c : letters) {
            if (c > target) {
                return c;
            }
        }
        return letters[0];
    }
};
#else
class Solution {
   public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int left = 0;
        int right = letters.size() - 1;
        if (target > letters[right]) {
            return letters[0];
        }
        while (right >= left) {
            int mid = left + (right - left) / 2;
            if (letters[mid] > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return letters[left];
    }
};
#endif

int main(int argc, char* argv[]) {
    auto s = new Solution();
    {
        auto nums = vector<char>{'c', 'f', 'j'};
        cout << s->nextGreatestLetter(nums, 'a') << endl;
    }
    {
        auto nums = vector<char>{'c', 'f', 'j'};
        cout << s->nextGreatestLetter(nums, 'c') << endl;
    }

    delete s;
    return 0;
}
