#include <bits/stdc++.h>

bool customCompare(const std::string &x, const std::string &y){
    return x + y < y + x;
}

void solve(){
    int n;
    std::cin >> n; // 4
    std::vector<std::string> strs(n);

    for(int i = 0; i < n; ++i){
        std::cin >> strs[i]; // abba
    }
    std::sort(strs.begin(), strs.end(), customCompare);

    for (const std::string &s : strs) {
        std::cout << s;
    }
    std::cout << "\n";

}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();
    return 0;
}
