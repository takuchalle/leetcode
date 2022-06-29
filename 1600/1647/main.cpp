#include <functional>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minDeletions(string s) {
		const int num = 26;
		// # of alphabet is 26
		auto a = vector<int>(26, 0);

		for (auto& c : s) {
			a[(int)(c - 'a')]++;	
		}

		sort(a.rbegin(), a.rend());

		int ans = 0;
		for (size_t i = 0; i < a.size() - 1; i++) {
			if(a[i+1] == 0) continue;
			if(a[i] <= a[i+1]) {
				int org = a[i+1];
				a[i+1] = std::max(0, a[i] - 1);
				ans += (org - a[i+1]);
			}
		}

		return ans;
    }
};

int
main(int argc, char* argv[]) {
	auto s = new Solution();

	cout << s->minDeletions("aab") << endl;
	cout << s->minDeletions("aaabbbcc") << endl;
	cout << s->minDeletions("ceabaacb") << endl;
	cout << s->minDeletions("bbcebab") << endl;
	
	delete s;
	return 0;
}
