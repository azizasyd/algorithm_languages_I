#include <bits/stdc++.h>

void solve(){
    int n; // 5
    std::cin >> n;

//    while (n--) {
    for(int i = 0; i < n; ++i){
        long long a, b;
        std::cin >> a >> b;

        // sum = n * mean (of first and last nums)
        long long sum = (b - a + 1) * (a + b) / 2;
        std::cout << sum << "\n";
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();
    return 0;
}