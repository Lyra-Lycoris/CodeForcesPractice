#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define all(x) x.begin(), x.end()

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> graph(n + 1);

    vector<int> cat(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> cat[i]; // 赋值
    }

    for (int i = 1; i <= n - 1; i++)
    {
        ll u, v;
        cin >> u >> v;
        graph[u].emplace_back(v);
        graph[v].emplace_back(u);
    }

    ll ans = 0;

    auto DFS = [&](auto &&self, int u, int lastNode, int catCnt) -> void
    {
        if (cat[u])
        {
            catCnt++;
        }
        else
        {
            catCnt = 0;
        }
        if (catCnt > m)
        {
            return; // 剪枝
        }

        bool Leaf = true;
        for (int v : graph[u])
        {
            if (v == lastNode)
            {
                continue;
            }
            Leaf = false; // 有子节点就不是叶子
            self(self, v, u, catCnt);
        }

        if (Leaf)
        {
            // 走到叶节点就算答案
            ans++;
        }
    };

    DFS(DFS, 1, 0, 0);

    cout << ans << endl;

    return 0;
}