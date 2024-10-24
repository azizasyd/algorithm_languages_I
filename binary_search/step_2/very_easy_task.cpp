#include <bits/stdc++.h>

using namespace std;

bool can_make_copies(long long mid, int n, int x, int y) {
    long long copies = mid / x + mid / y;
    return copies >= n;
}

void solve() {
    int n, x, y;
    cin >> n >> x >> y;

    if (x > y) swap(x, y);

    long long left = 0, right = (long long)n * y;
    while (left < right) {
        long long mid = (left + right) / 2;
        if (can_make_copies(mid, n - 1, x, y)) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }

    cout << left + x << "\n";
}


int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();
    return 0;
}