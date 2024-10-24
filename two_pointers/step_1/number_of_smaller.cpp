#include <bits/stdc++.h>

void solve(){
    int n, m;
    std::cin >> n >> m;

    std::vector<int> a(n), b(m);
    std::vector<int> res(m,0);

    for(int i = 0; i < n; ++i){
        std::cin >> a[i];
    }
    for(int i = 0; i < m; ++i){
        std::cin >> b[i];
    }

    std::sort(a.begin(), a.end());
    std::sort(b.begin(), b.end());

    int i = 0;
    for(int j = 0; j < b.size(); ++j){
        while(a[i] < b[j] && i < a.size()){
            i++;
        }
        res[j] = i;
    }

    for(int num : res){
        std::cout << num << " ";
    }
    std::cout << "\n";

}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();
    return 0;
}