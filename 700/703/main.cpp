#include <functional>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

class KthLargest {
   private:
    priority_queue<int, vector<int>, greater<int>> _q;
    int _k;

   public:
    KthLargest(int k, vector<int>& nums) {
        _k = k;

        for (auto v : nums) {
            _q.push(v);
            if (_q.size() > _k) {
                _q.pop();
            }
        }
    }

    int add(int val) {
        _q.push(val);

        if (_q.size() > _k) {
            _q.pop();
        }

        return _q.top();
    }
};

int main(int argc, char* argv[]) {
    int k = 3;
    auto nums = vector<int>{1, 3, 4};
    auto s = new KthLargest(k, nums);

    delete s;
    return 0;
}
