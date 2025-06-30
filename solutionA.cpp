#include <iostream>
#include <vector>

int main () {
    int t = 0, n = 0, s = 0;
    std::cin >> t;
    while (t--) {
        int sum = 0;
        std::cin >> n >> s;
        std::vector<int> ll(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> ll[i];
        }
        if (s < ll[0]) {
            sum = ll[n - 1] - s;
        }
        else if (s > ll[n - 1]) {
            sum = s - ll[0];
        }
        else if (s >= ll[0] && s <= ll[n - 1]) {
            int left = s - ll[0];
            int right = ll[n - 1] - s;
            if (left < right) {
                sum += left * 2 - 1;
                sum += ll[n - 1] - s + 1;
            }
            else {
                sum += right * 2 - 1;
                sum += left + 1;
            }
        }
        std::cout << sum << "\n";
    }




    return 0;
}