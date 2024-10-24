#include <bits/stdc++.h>

void solve(){
    int n, m;
    std::cin >> n >> m;

    std::vector<int> a(n);
    for(int i = 0; i < n; ++i){
        std::cin >> a[i];
    }

    std::unordered_set<int> seen;
    std::vector<int> distinct_count(n);

    for(int i = n - 1; i >= 0; --i){
        seen.insert(a[i]);
        distinct_count[i] = seen.size();
    }

    for(int i = 0; i < m; ++i){
        int num;
        std::cin >> num;
        std::cout << distinct_count[num-1] << "\n";
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();
    return 0;
}
