#include <bits/stdc++.h>

void solve() {
    // T = 3 1 5, sum = 9

    // A = [3 5] [1]

    // T = [1], sum = 10
    // T = [3 5], sum = 17

    // A = [1], delete
    // A = [3 5]
    int n;
    std::cin >> n;
    std::vector<long long> arr(n);
    long long total_sum = 0;
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
        total_sum += arr[i];
    }
    sort(arr.begin(), arr.end());

    long long score = 0;
    long long curr_sum = total_sum;
    for (int i = 0; i < n; ++i) {
        score += curr_sum;
        if (i < n - 1) {
            score += arr[i];
            curr_sum -= arr[i];
        }
    }
    std::cout << score << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();
    return 0;
}