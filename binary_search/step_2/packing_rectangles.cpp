#include <bits/stdc++.h>

using namespace std;

bool may_fit(long long s, long long w, long long h, long long n) {
    return (s / w) * (s / h) >= n;
}

void solve() {
    long long w, h, n;
    cin >> w >> h >> n;

    long long left = 0, right = 1;
    while (!may_fit(right, w, h, n)) {
        right *= 2;
    }

    long long answer = right;

    while (left <= right) {
        long long mid = (left + right) / 2;
        if (may_fit(mid, w, h, n)) {
            answer = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    cout << answer << "\n";
}


int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();
    return 0;
}
