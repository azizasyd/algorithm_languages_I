#include <bits/stdc++.h>

void solve(){
    long long n;
    std::cin >> n;

    std::vector<long long> a(n);
    for(long long i = 0; i < n; ++i){
        std::cin >> a[i];
    }
    std::sort(a.rbegin(), a.rend());

    long long sum = 0;
    for (long long i = 0; i < n; ++i) {
        if (a[i] >= i + 1) {
            sum += a[i] - (i + 1);
        }
    }
    std::cout << sum << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();
    return 0;
}
