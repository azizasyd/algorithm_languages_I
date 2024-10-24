#include <bits/stdc++.h>

void solve(){
    int n, t;
    std::cin >> n >> t; // books, min

    std::vector<int> a(n);
    for(int i = 0; i < n; ++i){
        std::cin >> a[i];
    }

    int left = 0, right = 0, sum = 0, max_num = 0;

    // 4 5
    // 3 1 2 1
    while(right < n){
        sum += a[right];

        while(sum > t){
            sum -= a[left];
            left++;
        }

        max_num = std::max(max_num, right - left + 1);
        right++;
    }
    std::cout << max_num << "\n";
}


int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();
    return 0;
}