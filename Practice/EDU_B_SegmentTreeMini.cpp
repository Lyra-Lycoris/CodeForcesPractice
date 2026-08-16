#include <bits/stdc++.h>
using namespace std;

using ll  = long long;
using ull = unsigned long long;
#define all(x) x.begin(), x.end()

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<ll> a(n + 1);

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    vector<ll> Tree(4 * n + 5);

    auto build = [&](auto &&self, ll p, ll l, ll r) -> void
    {
        if (l == r)
        {
            Tree[p] = a[l];
            return;
        }
        ll mid = l + (r - l) / 2;
        self(self, p * 2, l, mid);
        self(self, p * 2 + 1, mid + 1, r);

        Tree[p] = min(Tree[p * 2], Tree[p * 2 + 1]);
    };

    auto update = [&](auto &&self, ll p, ll pos, ll val, ll l, ll r) -> void
    {
        if (l == r)
        {
            Tree[p] = val;  // 更新最小值
            return;
        }

        ll mid = l + (r - l) / 2;
        if (pos <= mid)
        {
            self(self, p * 2, pos, val, l, mid);
        }
        else
        {
            self(self, p * 2 + 1, pos, val, mid + 1, r);
        }

        Tree[p] = min(Tree[p * 2], Tree[p * 2 + 1]);
    };

    auto query = [&](auto &&self, ll p, ll l, ll r, ll ql, ll qr) -> ll
    {
        if (ql <= l && r <= qr)
        {
            return Tree[p];
        }
        if (r < ql || l > qr)
        {
            return LLONG_MAX;
        }
        ll mid = l + (r - l) / 2;

        ll LeftMin  = self(self, p * 2, l, mid, ql, qr);
        ll RightMin = self(self, p * 2 + 1, mid + 1, r, ql, qr);

        return min(LeftMin, RightMin);
    };

    build(build, 1, 1, n);

    while (m--)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            ll i, v;
            cin >> i >> v;
            update(update, 1, i + 1, v, 1, n);
        }
        else
        {
            ll a, b;
            cin >> a >> b;
            a++;
            cout << query(query, 1, 1, n, a, b) << '\n';
        }
    }

    cout << flush;
    return 0;
}