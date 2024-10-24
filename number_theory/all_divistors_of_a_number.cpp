#include <bits/stdc++.h>

using namespace std;

void solve(){
    long long n;
    std::cin >> n;

    std::set<long long> divisors;

    // 1 < 120
    // 4 < 120
    // 9 < 120
    // 16 < 120
    // 25 < 120
    // 36 < 120
    // 49 < 120
    // 64 < 120
    // 81 < 120
    // 100 < 120

    // 121 > 120

    for (long long i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            divisors.insert(i); // 2
            divisors.insert(n / i); // 2nd divisor
            // check if it's not same number
//            if(i * i != n){
//                divisors.insert(n / i);
//            }
        }
    }
    for (auto divisor : divisors) {
        std::cout << divisor << " ";
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();
    return 0;
}