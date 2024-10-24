#include <bits/stdc++.h>

void solve(){
    int q; // 9
    std::cin >> q;
    double sum = 0;
    int count = 0;

    for(int i = 0; i < q; ++i){
        char c;
        int num;
        std::cin >> c >> num;

        if(c == '+'){
            ++count;
            sum += num; // 1
        } else if (c == '-'){
            count--;
            sum -= num;
        }

        double res = count > 0 ? (sum) / count : 0.0;
        std::cout << std::fixed << std::setprecision(9) << res << "\n";
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();
    return 0;
}