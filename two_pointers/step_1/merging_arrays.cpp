#include <bits/stdc++.h>

void solve(){
    int n, m;
    std::cin >> n >> m;

    std::vector<int> a(n), b(m);
    std::vector<int> res(a.size() + b.size());

    for(int i = 0; i < n; ++i){
        std::cin >> a[i];
    }

    for(int i = 0; i < m; ++i){
        std::cin >> b[i];
    }

    int i = 0, j = 0;

    while(i < a.size() || j < b.size()){
        if(j == b.size() || i < a.size() && a[i] < b[j]){
            res[i+j] = a[i];
            i++;
        } else {
            res[i+j] = b[j];
            j++;
        }
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