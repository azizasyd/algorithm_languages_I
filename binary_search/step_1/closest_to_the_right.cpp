#include <bits/stdc++.h>

void solve(){
    int n, k;
    std::cin >> n >> k;

    std::vector<int> a(n);
    for(int i = 0; i < n; ++i){
        std::cin >> a[i];
    }

    for(int i = 0; i < k; ++i) {
        int num;
        std::cin >> num; // 2

        int left = 0, right = n;

        while (left < right) {
            int mid = left + (right - left) / 2; // 2

            if (a[mid] >= num) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        if (left < n) {
            std::cout << left + 1 << "\n"; // 1-based index
        } else {
            std::cout << n + 1 << "\n";
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();
    return 0;
}
