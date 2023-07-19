#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;

int n, m;
vector<int> g[100013];

int tim;
bool vis[100013];
int tin[100013], low[100013];

void dfs(int u, int p = -1) {
    vis[u] = true;
    tin[u] = low[u] = ++tim;

    for (int v: g[u]) {
        if (v == p)
            continue;

        if (vis[v]) {
            low[u] = min(low[u], tin[v]);  // low[v] includes other back-edges

        } else {
            dfs(v, u);
            low[u] = min(low[u], low[v]);  // low[v] includes atmost one back-edge
            if (low[v] > tin[u])
                cout << u + 1 << " " << v + 1 << endl;
        }
    }
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(NULL);

    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v; u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    tim = 0;
    fill(tin, tin + n, -1);
    fill(low, low + n, -1);

    dfs(0);
}