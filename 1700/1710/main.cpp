#include <algorithm>
#include <iostream>
#include <string>
#include <type_traits>
#include <vector>

using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)

class Solution {
   private:
    struct Less {  // 大小比較用の関数オブジェクトを定義することもできる
        bool operator()(const vector<int>& a, const vector<int>& b) const noexcept {
			return a[1] > b[1];
        }
    };

   public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), Less{});

		int units = 0;
		for (auto& boxType : boxTypes) {
			if(truckSize == 0) break;
			auto boxes = std::min(truckSize, boxType[0]);

			units += (boxes * boxType[1]);

			truckSize -= boxes;
		}

        return units;
    }
};

int main(int argc, char* argv[]) {
    auto s = new Solution();

    {
        auto boxTypes = vector<vector<int>>{{1, 3}, {2, 2}, {3, 1}};

        cout << s->maximumUnits(boxTypes, 4) << endl;
    }
    {
        auto boxTypes = vector<vector<int>>{{5, 10}, {2, 5}, {4, 7}, {3, 9}};

        cout << s->maximumUnits(boxTypes, 10) << endl;
    }

    delete s;
    return 0;
}
