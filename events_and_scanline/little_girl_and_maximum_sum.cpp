// 5 3 = 8
// 3 2 = 5
// 5 3 2 = 10

// 5 -> 2
// 3 -> 3
// 2 -> 2

// 5 * 3 = 15
// 3 * 2 = 6
// 2 * 2 = 4


// 5 2 4 1 3

// 5 2 4 1 3
// 2 4
// 2 4

// 5 -> 1
// 4 -> 3
// 3 -> 1
// 2 -> 3
// 1 -> 1

// 5 -> 3
// 4 -> 3
// 3 -> 1
// 2 -> 1
// 1 -> 1

// 15 12 3 2 1 = 33


#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int num, query;
    cin >> num >> query;

    vector<int> values(num);
    for (int i = 0; i < num; ++i) {
        cin >> values[i];
    }

    vector<int> freq(num + 1, 0);

    for (int i = 0; i < query; ++i) {
        int left, right;
        cin >> left >> right;
        left--; right--;
        freq[left]++;
        if (right + 1 < num) freq[right + 1]--;
    }

    for (int i = 1; i < num; ++i) {
        freq[i] += freq[i - 1];
    }

    freq.pop_back();

    sort(values.begin(), values.end());
    sort(freq.begin(), freq.end());

    long long max_sum = 0;
    for (int i = 0; i < num; ++i) {
        max_sum += (long long)values[i] * freq[i];
    }

    cout << max_sum << endl;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();
    return 0;
}