#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define all(x) x.begin(), x.end()

inline void optimize()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

ll n, m;
const ll N = 200005, M = 400010;

ll Head[N];
ll To[M], Next[M];
ll tot;
ll deg[N]; // 每个点的度数
void add(ll a, ll b)
{
    tot++;
    To[tot] = b;
    Next[tot] = Head[a];
    Head[a] = tot;
    // deg[a]++, deg[b]++;因为add被调用两次，所以这里只加一个点的度数
    deg[a]++;
}

int vis[N];
ll ans; // 环的个数

bool JudgeCyc(ll Node)
{
    // 先对整个连通块染色
    vis[Node] = 1;
    queue<ll> q;
    q.push(Node);

    bool ok = true;
    if (deg[Node] != 2)
    {
        ok = false;
    }
    while (!q.empty())
    {
        ll u = q.front();
        if (deg[u] != 2)
        {
            ok = false;
        }
        q.pop();

        for (ll i = Head[u]; i; i = Next[i])
        {
            ll v = To[i];
            if (vis[v])
            {
                continue;
            }

            vis[v] = 1;
            q.push(v);
        }
    }
    return ok;
}

int main()
{
    optimize();

    tot = 0, ans = 0;
    cin >> n >> m;
    while (m--)
    {
        ll u, v;
        cin >> u >> v;
        add(u, v);
        add(v, u);
    }

    memset(vis, 0, sizeof(vis));

    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            if (JudgeCyc(i))
            {

                ans++;
            }
        }
    }

    cout << ans << '\n';

    return 0;
}
