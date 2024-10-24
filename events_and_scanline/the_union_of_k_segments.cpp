#include <bits/stdc++.h>
using namespace std;

void solve()
{
    using segment_t = pair<int, int>;
    int n, k;
    cin >> n >> k;

    vector<segment_t> segments(n);
    for (auto& [start, end] : segments) {
        cin >> start >> end;
    }

    auto get_ans = [&]()
    {
        using event_t = pair<int, int>;

        const int OPEN = 0, CLOSE = 1;
        vector<event_t> events;

        for (auto& [start, end] : segments) {
            events.emplace_back(start, OPEN);
            events.emplace_back(end, CLOSE);
        }

        sort(events.begin(), events.end());

        vector<segment_t> ans;
        int open_cnt = 0;
        int current_start = -1;

        for (auto& [x, ev_type] : events) {
            if (OPEN == ev_type) {
                ++open_cnt;
                if (open_cnt == k) {
                    current_start = x;
                }
            }
            if (CLOSE == ev_type) {
                if (open_cnt == k) {
                    ans.emplace_back(current_start, x);
                }
                --open_cnt;
            }
        }

        return ans;
    };

    vector<segment_t> result = get_ans();

    cout << result.size() << "\n";
    for (auto& [start, end] : result) {
        cout << start << " " << end << "\n";
    }
}

void fast_io()
{
    std::ios::sync_with_stdio(false); // turn off sync with scanf/printf
    std::cin.tie(NULL);               // turn off sync between cin and cout
}

int main()
{
    fast_io();
    solve();
    return 0;
}