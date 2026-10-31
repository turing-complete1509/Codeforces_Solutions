/*
 * ___________________________________________________________________________________
 * |                                                                                 |
 * |       _____    _____    _____     _____   _______        _____     _____        |
 * |      |  __ \  |_   _|  / ____|   |_   _| |__   __|      |  __ \   |  __ \       |
 * |      | |  | |   | |   | |  __      | |      | |         | |  | |  | |__) |      |
 * |      | |  | |   | |   | | |_ |     | |      | |         | |  | |  |  ___/       |
 * |      | |__| |  _| |_  | |__| |    _| |_     | |         | |__| |  | |           |
 * |      |_____/  |_____|  \_____|   |_____|    |_|         |_____/   |_|           |
 * |                                                                                 |
 * |      "Kill the boy, and let the man be born."                                   |
 * |_________________________________________________________________________________|
 */

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define all(v) v.begin(), v.end()

template <typename T>
void debug(const vector<T>& arr) {
    for(const auto& x: arr) cout << x << " ";
    cout << nl;
}

long long gcd(long long a, long long b) { return b==0?a:gcd(b,a%b); }
long long lcm(long long a, long long b) { return (a/gcd(a,b))*b; }

void dfs1(int u, int p, vector<vector<int>>& tree, vector<vector<int>>& dp) {
    dp[u][0] = 0;
    dp[u][1] = 1;
    for (int v : tree[u]) {
        if (v == p) continue;
        dfs1(v, u, tree, dp);
        dp[u][0] += max(dp[v][0], dp[v][1]);
        dp[u][1] += dp[v][0];
    }
}

void dfs2(int u, int p, vector<vector<int>>& tree, vector<vector<int>>& dp) {
    if(u!=1){
        int old_u_0 = dp[u][0];
        int old_u_1 = dp[u][1];
        dp[u][0] += max(dp[p][0]-max(old_u_0,old_u_1), dp[p][1] - old_u_0);
        dp[u][1] += dp[p][0] - max(old_u_0, old_u_1);
    }
    for (int v : tree[u]) {
        if (v == p) continue;
        dfs2(v, u, tree, dp);
    }
}

void solve() {
    int k;
    cin >> k;

    bool all_ones = true;
    vector<int> in_node(k);
    int hub_tree = -1;
    int hub_node = -1;

    for (int i = 0; i < k; i++) {
        int n;
        cin >> n;

        if (n > 1) {
            all_ones = false;
        }

        vector<vector<int>> tree(n + 1);
        for (int j = 1; j < n; j++) {
            int u, v;
            cin >> u >> v;
            tree[u].push_back(v);
            tree[v].push_back(u);
        }

        vector<vector<int>> dp(n+1, vector<int>(2, 0));

        dfs1(1, 0, tree, dp);
        dfs2(1, 0, tree, dp);

        int max_is = max(dp[1][0], dp[1][1]);
        int cur_in = -1;
        int cur_out = -1;

        for (int j = 1; j <= n; j++) {
            if (dp[j][1] == max_is) cur_in = j;
            if (dp[j][0] == max_is) cur_out = j;
        }

        in_node[i] = cur_in;

        if (cur_out != -1) {
            hub_tree = i;
            hub_node = cur_out;
        }
    }

    if (all_ones) {
        for (int i = 1; i < k; i++) {
            cout << 1 << " " << 1 << " " << i + 1 << " " << 1 << nl;
        }
        return;
    }

    for (int i = 0; i < k; i++) {
        if (i == hub_tree) continue;
        cout << hub_tree + 1 << " " << hub_node << " " << i + 1 << " " << in_node[i] << nl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}