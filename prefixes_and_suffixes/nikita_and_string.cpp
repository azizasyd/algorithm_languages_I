#include <iostream>
#include <string>
#include <vector>
using namespace std;

void solve() {
    string s;
    cin >> s;
    int n = s.size();

    vector<int> prefixA(n + 1, 0); // To store how many 'a's from the start to each position.
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'a') {
            prefixA[i + 1] = prefixA[i] + 1;
        } else {
            prefixA[i + 1] = prefixA[i]; // Carry forward the count if it's not 'a'
        }
    }

    vector<int> suffixA(n + 1, 0); // To store how many 'a's from each position to the end.
    for (int i = n - 1; i >= 0; --i) {
        if (s[i] == 'a') {
            suffixA[i] = suffixA[i + 1] + 1;
        } else {
            suffixA[i] = suffixA[i + 1]; // Carry forward the count if it's not 'a'
        }
    }

    int maxLength = 0;
    for (int i = 0; i <= n; ++i) {
        for (int j = i; j <= n; ++j) {
            int countA1 = prefixA[i];

            int countB = 0;
            for (int k = i; k < j; ++k) {
                if (s[k] == 'b') countB++;
            }

            int countA2 = suffixA[j];

            maxLength = max(maxLength, countA1 + countB + countA2);
        }
    }

    cout << maxLength << "\n";
}

int main() {
    solve();
    return 0;
}
