#include <bits/stdc++.h>

void solve(){
    int n; // 5
    std::cin >> n;
    std::vector<int> a(n);
    std::vector<int> result;
    long long sum = 0;

    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
        sum += a[i];
    }


    for(int i = 0; i < n; ++i) {
        if(((sum - a[i]) % (n - 1) == 0) && ((sum - a[i]) / (n - 1) == a[i])) {
            result.push_back(i+1);
        }
    }

    std::cout << result.size() << "\n";
    for (int res : result) {
        std::cout << res << " ";
    }
    std::cout << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();
    return 0;
}