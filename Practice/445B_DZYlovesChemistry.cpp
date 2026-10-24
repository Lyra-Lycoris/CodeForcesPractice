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

int n, m;
const int N = 55, M = 1500;

int parent[N];

int find(int x)
{
    return ((x == parent[x]) ? x : (parent[x] = find(parent[x])));
}

int main()
{
    optimize();

    cin >> n >> m;

    for (int i = 0; i <= n; i++)
    {
        parent[i] = i;
    }

    while (m--)
    {
        int u, v;
        cin >> u >> v;
        int rootU = find(u), rootV = find(v);
        parent[rootU] = rootV;
    }

    ll cntBlock = 0;
    for (int i = 1; i <= n; i++)
    {
        if (find(i) == i)
        {
            cntBlock++;
        }
    }
    //ans=2^(s1-1)*2^(s2-1)*.....*2^(Sn-1);//si为每一个连通块内的点的个数
    //ans=2^(s1-1+s2-1+.....+Sn-1);
    //ans=2^(n-cntBlock);
    ll ans = 1LL << (n - cntBlock);
    cout << ans << '\n';

    return 0;
}