#include <iostream>
#include <string>
#include <vector>

using namespace std;
#define rep(i,n) for(int i = 0; i < (n); ++i)

class Solution {
public:
    int minPartitions(string n) {
		int max = 0;
		for (auto& c : n) {
			int number = c - '0';
			max = std::max(max, number);
		}

		return max;
    }
};

int
main(int argc, char* argv[]) {
	auto s = new Solution();

	{
		cout << s->minPartitions("32") << endl;
		cout << s->minPartitions("82734") << endl;
		cout << s->minPartitions("27346209830709182346") << endl;
	}
		
	delete s;
	return 0;
}
