#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <map>
int main () {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::map<char, int> count;
        std::vector <char> ll;
        for (int i = 0; i < n; ++i) {
            char p;
            int c;
            std::cin >> p;
            ll.push_back(p);
            if (count.find(p) == count.end()) {
                count.insert({p, 1});
            }
            else {
                auto it = count.find(p);
                it->second += 1;

            }

        }
            if (n == 3) {
                char b = ll[n / 2];
                ll.erase(ll.begin() + n / 2);
                if (std::find(ll.begin(), ll.end(), b) == ll.end()) {
                    std::cout << "NO\n";
                } else {
                    std::cout << "YES\n";
                }
            }
            else {
                char f0 = ll[0];
                char f1 = ll[n - 1];
                std::vector<std::pair<char, int>> vec(count.begin(), count.end());
                std::sort(vec.begin(), vec.end(),
                          [](const auto& left, const auto& right) {
                              return left.second > right.second;
                          }
                );
                if (vec[0].first == f0 && vec[0].first == f1 && vec[1].second < 2) {
                    if (vec[0].second >= 3) {
                        std::cout << "YES\n";
                    }
                    else {
                        std::cout << "NO\n";
                    }
                }
                else {
                    if (vec[0].second >= 2 || vec[1].second >= 2) {
                        std::cout << "YES\n";
                    }
                    else {
                        std::cout << "NO\n";
                    }
                }
            }
    }
    return 0;
}