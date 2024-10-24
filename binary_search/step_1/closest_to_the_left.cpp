#include <bits/stdc++.h>

void solve(){
    int n, k;
    std::cin >> n >> k;

    std::vector<int> a(n);
    for(int i = 0; i < n; ++i){
        std::cin >> a[i];
    }

    for(int i = 0; i < k; ++i){
        int num;
        std::cin >> num; // 2

        int left = 0, right = n - 1;
        int res = 0;

        while (left <= right) {
            int mid = left + (right - left) / 2; // 2

            if (a[mid] <= num) {
                res = mid + 1; // +1 for 1-index based
                left = mid + 1; // +1 to move
            } else {
                right = mid - 1;
            }
        }
        std::cout << res << "\n";
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();
    return 0;
}
