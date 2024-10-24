#include <bits/stdc++.h>

void solve(){
    int n, k;
    std::cin >> n >> k;

    std::vector<int> a(n);
    for(int i = 0; i < n; ++i){
        std::cin >> a[i];
    }

    for(int i = 0; i < k; ++i){
        int num;
        std::cin >> num;

        int left = 0, right = n - 1;
        bool found = false;


        while(left <= right){
            int mid = left + (right - left) / 2;

            if(num == a[mid]){
                found = true;
                break;
            } else if(num > a[mid]){
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        if(found){
            std::cout << "YES\n";
        } else {
            std::cout << "NO\n";
        }
    }
}


int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();
    return 0;
}
