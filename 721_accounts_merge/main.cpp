#include <algorithm>
#include <iostream>
#include <memory>
#include <optional>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)

class UnionFind {
   public:
    UnionFind() {}

    string root(string& mail) {
        if (_par[mail].empty())
            return mail;
        else
            return _par[mail] = root(_par[mail]);
    }

    void add(string& mail) {
		if(_par.count(mail)) return;

        _par[mail] = string();
        _size[mail] = 1;
    }

    void unite(string& a, string& b) {
        auto root_a = root(a);
        auto root_b = root(b);

        // same root
        if (equal(root_a.begin(), root_a.end(), root_b.begin(), root_b.end())) return;

        _par[root_b] = root_a;
        _size[root_a] += _size[root_b];
    }

    int size(string& mail) { return _size[root(mail)]; }

    bool issame(string& a, string& b) {
        auto root_a = root(a);
        auto root_b = root(b);

        return equal(root_a.begin(), root_a.end(), root_b.begin(),
                     root_b.end());
    }

    void print() {
        for (auto& var : _par) {
            cout << var.first << " : " << var.second << endl;
        }
    }

    unordered_map<string, string> _par;
    unordered_map<string, int> _size;
};

class Solution {
   public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        UnionFind uf;

        for (auto& account : accounts) {
            uf.add(account[1]);
            for (size_t i = 2; i < account.size(); i++) {
                uf.add(account[i]);

                uf.unite(account[1], account[i]);
            }
        }
        /* uf.print(); */

        auto ans = vector<vector<string>>();
        for (auto& account : accounts) {
            bool found = false;
            for (auto& var : ans) {
                if (uf.issame(account[1], var[1])) {
                    for (size_t i = 1; i < account.size(); i++) {
                        var.push_back(account[i]);
                    }
                    found = true;
                    break;
                }
            }
            if (!found) {
                ans.push_back(account);
            }
        }

        for (auto& var : ans) {
            sort(var.begin() + 1, var.end());
            var.erase(unique(var.begin() + 1, var.end()), var.end());
        }

        return ans;
    }
};

int main(int argc, char* argv[]) {
    auto s = unique_ptr<Solution>();

    {
        vector<vector<string>> accounts = {
            {"John", "johnsmith@mail.com", "john_newyork@mail.com"},
            {"John", "johnsmith@mail.com", "john00@mail.com"},
            {"Mary", "mary@mail.com"},
            {"John", "johnnybravo@mail.com"},
        };
        auto ans = s->accountsMerge(accounts);
        for (auto& account : ans) {
            for (auto& var : account) {
                cout << var << endl;
            }
        }
    }

    return 0;
}
