#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    int K = 30;
    K = min(K, n);

    vector<vector<int>> ratings(n, vector<int>(5));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 5; ++j) {
            cin >> ratings[i][j];
        }
    }

    vector<vector<pair<int, int>>> top_candidates(5);

    for (int pos = 0; pos < 5; ++pos) {
        vector<pair<int, int>> candidates;
        for (int i = 0; i < n; ++i) {
            candidates.push_back({ratings[i][pos], i});
        }
        sort(candidates.rbegin(), candidates.rend()); // Sort in descending order
        for (int i = 0; i < min(K, (int)candidates.size()); ++i) {
            top_candidates[pos].push_back(candidates[i]);
        }
    }

    vector<int> max_ratings(5, 0);
    for (int i = 0; i < 5; ++i) {
        if (!top_candidates[i].empty()) {
            max_ratings[i] = top_candidates[i][0].first;
        }
    }

    vector<bool> selected(n, false);
    int max_total_rating = 0;

    function<void(int, int)> gen = [&](int role, int current_total_rating) {
        if (role == 5) {
            if (current_total_rating > max_total_rating) {
                max_total_rating = current_total_rating;
            }
            return;
        }

        int remaining_roles = 5 - role;
        int max_possible_remaining_rating = 0;
        for (int r = role; r < 5; ++r) {
            max_possible_remaining_rating += max_ratings[r];
        }
        if (current_total_rating + max_possible_remaining_rating <= max_total_rating) {
            return;
        }

        for (auto &p : top_candidates[role]) {
            int candidate_id = p.second;
            int candidate_rating = p.first;
            if (!selected[candidate_id]) {
                selected[candidate_id] = true;

                gen(role + 1, current_total_rating + candidate_rating);

                selected[candidate_id] = false;
            }
        }
    };

    gen(0, 0);

    cout << max_total_rating << "\n";

}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
