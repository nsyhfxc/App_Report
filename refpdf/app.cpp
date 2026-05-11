//此文件仅用于占位使用，防止空文件夹无法上传GitHub
#include<bits/stdc++.h>
using namespace std;
constexpr int MAXN = 5e5 + 10;
int n, m, s, a, b;
vector<int> e[MAXN];
int dep[MAXN], fa[MAXN][20];

void dfs(const int &u, const int &father) {
    dep[u] = dep[father] + 1;
    fa[u][0] = father;
    for (int i = 1;	 i <= 19; i++) {
        fa[u][i] = fa[fa[u][i - 1]][i - 1];
    }
    for (const int &v: e[u]) {
        if (v != father) {
            dfs(v, u);
        }
    }
}

int lca(int u, int v) {
    if (dep[u] < dep[v]) swap(u, v);
    for (int i = 19; i >= 0; i--) {
        if (dep[fa[u][i]] >= dep[v]) {
            u = fa[u][i];
        }
    }
    if (u == v) return v;
    for (int i = 19; i >= 0; i--) {
        if (fa[u][i] != fa[v][i]) {
            u = fa[u][i];
            v = fa[v][i];
        }
    }
    return fa[u][0];
}

void solve() {
    cin >> n >> m >> s;
    for (int i = 1;i < n;i++) {
        int x, y;
        cin >> x >> y;
        e[x].push_back(y);
        e[y].push_back(x);
    }
    dfs(s,0);
    while (m--) {
        int u, v;
        cin >> u >> v;
        cout << lca(u, v) << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
