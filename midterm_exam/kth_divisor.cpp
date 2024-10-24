#include <bits/stdc++.h>

void solve(){
    long long n, k;
    std::cin >> n >> k;

    std::vector<long long> a;
    for(long long i = 1; i * i <= n; ++i){
        if(n % i == 0) {
            a.push_back(i);
//          a.push_back(n / i);
            if(i * i != n){
                a.push_back(n / i);
            }
        }
    }
    std::sort(a.begin(), a.end());

    if (a.size() < k) {
        std::cout << -1 << "\n";
    } else {
        std::cout << a[k - 1] << "\n";
    }
}


int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();
    return 0;
}