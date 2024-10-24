#include <bits/stdc++.h>

using namespace std;

const long long INF = 1e18;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<vector<long long>> graph(n, vector<long long>(n, INF));

    for (int i = 0; i < m; ++i) {
        int a, b;
        long long w;
        cin >> a >> b >> w;
        --a; --b;
        graph[a][b] = w;
        graph[b][a] = w;
    }

    vector<vector<long long>> dp(1 << n, vector<long long>(n, INF));

    for (int i = 0; i < n; ++i) {
        dp[1 << i][i] = 0;
    }

    for (int mask = 0; mask < (1 << n); ++mask) {
        for (int u = 0; u < n; ++u) {
            if (!(mask & (1 << u))) continue;

            for (int v = 0; v < n; ++v) {
                if (mask & (1 << v)) continue;
                if (graph[u][v] == INF) continue;

                int next_mask = mask | (1 << v);
                dp[next_mask][v] = min(dp[next_mask][v], dp[mask][u] + graph[u][v]);
            }
        }
    }

    long long answer = INF;
    for (int i = 0; i < n; ++i) {
        answer = min(answer, dp[(1 << n) - 1][i]);
    }

    if (answer >= INF) {
        cout << -1 << "\n";
    } else {
        cout << answer << "\n";
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
