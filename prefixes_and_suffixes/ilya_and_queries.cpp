#include <bits/stdc++.h>

void solve() {
    std::string str;
    std::cin >> str;

    int m; // 4
    std::cin >> m;

    int n = str.length();

    std::vector<int> count(n, 0); // {0,0,1,1,2,3}

    for (int i = 1; i < n; ++i) {
        count[i] = count[i - 1] + (str[i] == str[i - 1] ? 1 : 0);
    }

    for (int i = 0; i < m; ++i) {
        int li, ri;
        std::cin >> li >> ri;
        std::cout << count[ri-1] - count[li-1] << "\n";
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();
    return 0;
}
