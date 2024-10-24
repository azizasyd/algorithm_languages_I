#include <bits/stdc++.h>

bool is_valid(int v, int n, int k){
    int total = v;
    while(v > 0){
        v /= k;
        total += v;
    }
    return total >= n;
}

void solve(){
    int n, k;
    std::cin >> n >> k;

    int left = k, right = n, res = n;

    while(left <= right){
        int mid = left + (right - left) / 2;

        if(is_valid(mid, n, k)){
            res = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    std::cout << res << "\n";
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    int testCases = 1;
    while (testCases--) {
        solve();
    }
}
