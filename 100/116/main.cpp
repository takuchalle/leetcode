#include <deque>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

#include "../../node.h"

using namespace std;

class Solution {
   public:
    Node* connect(Node* root) {
        deque<Node*> q = deque<Node*>();
        if (!root) return nullptr;

        q.push_back(root);
        while (!q.empty()) {
            auto size = q.size();
            for (size_t i = 0; i < size; i++) {
                auto n = q.front();
                q.pop_front();
                if (n->left) q.push_back(n->left);
                if (n->right) q.push_back(n->right);
            }
            size = q.size();
            for (size_t i = 0; i < size; i++) {
                auto n = q.front();
                q.pop_front();
				q.push_back(n);
				if(i == size - 1) {
					n->next = nullptr;
				} else {
					n->next = q.front();
				}
            }
        }

        return root;
    }
};

int main(int argc, char* argv[]) {
    auto s = new Solution();

    delete s;
    return 0;
}
