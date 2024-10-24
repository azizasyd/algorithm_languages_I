#include <bits/stdc++.h>

using namespace std;

void solve() {
    std::string a;
    int b;

    std::cin >> a;
    std::cin >> b;

    long long remainder = 0;

    for (char digit : a) {
        remainder = (remainder * 10 + (digit - '0')) % b;
    }
    std::cout << remainder << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();
    return 0;
}