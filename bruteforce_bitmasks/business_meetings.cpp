#include <bits/stdc++.h>

using namespace std;

void solve() {
    long long n, k;
    cin >> n >> k;

    vector<long long> a(n), b(n), c(n);
    for(long long i=0; i<n; ++i) {
        cin >> a[i] >> b[i] >> c[i];
    }

    const long long MOOD_MIN = -2000;
    const long long MOOD_MAX = 2000;



    vector<unordered_set<long long>> dp(1<<n);
    vector<unordered_map<long long, pair<long long,long long>>> parent(1<<n);

    dp[0].insert(k);

    for(long long mask=0; mask<(1<<n); ++mask) {
        if(dp[mask].empty()) continue;
        for(auto mood : dp[mask]) {
            for(long long i=0; i<n; ++i) {
                if(!(mask & (1<<i))) {
                    if(mood >= a[i] && mood <= b[i]) {
                        long long new_mood = mood + c[i];
                        if(new_mood < MOOD_MIN || new_mood > MOOD_MAX) continue;
                        long long new_mask = mask | (1<<i);
                        if(dp[new_mask].find(new_mood) == dp[new_mask].end()) {
                            dp[new_mask].insert(new_mood);
                            parent[new_mask][new_mood] = make_pair(mood, i);
                        }
                    }
                }
            }
        }
    }

    long long max_meetings = -1;
    long long final_mask = -1;
    long long final_mood = 0;
    for(long long mask=0; mask<(1<<n); ++mask) {
        if(dp[mask].empty()) continue;
        long long meetings_attended = __builtin_popcount(mask);
        if(meetings_attended > max_meetings) {
            max_meetings = meetings_attended;
            final_mask = mask;
            final_mood = *dp[mask].begin();
        }
    }

    vector<long long> sequence;
    long long mask = final_mask;
    long long mood = final_mood;
    while(mask != 0) {
        auto p = parent[mask][mood];
        long long prev_mood = p.first;
        long long meeting = p.second;
        sequence.push_back(meeting + 1);
        mask ^= (1 << meeting);
        mood = prev_mood;
    }

    reverse(sequence.begin(), sequence.end());

    cout << max_meetings << "\n";
    for(size_t i = 0; i < sequence.size(); ++i) {
        cout << sequence[i];
        if(i != sequence.size() - 1)
            cout << " ";
    }
    cout << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}

