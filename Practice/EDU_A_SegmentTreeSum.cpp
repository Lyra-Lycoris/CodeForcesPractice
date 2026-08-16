#include <bits/stdc++.h>
using namespace std;

using ll = long long;
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

    auto build = [&](auto &&self, int p, int l, int r) -> void
    {
        if (l == r)
        {
            Tree[p] = a[l];
            return;
        }

        int mid = l + (r - l) / 2;

        self(self, p * 2, l, mid);
        self(self, p * 2 + 1, mid + 1, r);

        Tree[p] = Tree[p * 2] + Tree[p * 2 + 1];
    };

    auto update = [&](auto &&self, int p, int pos, ll val, int l, int r) -> void
    {
        if (l == r)
        {
            Tree[p] = val;
            return;
        }

        int mid = l + (r - l) / 2;

        if (pos <= mid)
        {
            self(self, p * 2, pos, val, l, mid);
        }
        else
        {
            self(self, p * 2 + 1, pos, val, mid + 1, r);
        }

        Tree[p] = Tree[p * 2] + Tree[p * 2 + 1];
    };

    auto query = [&](auto &&self, int p, int l, int r,int ql, int qr) -> ll
    {
        if (ql <= l && r <= qr)
        {
            return Tree[p];
        }

        if (qr < l || r < ql)
        {
            return 0;
        }

        int mid = l + (r - l) / 2;

        ll leftSum = self(self, p * 2, l, mid, ql, qr);
        ll rightSum = self(self, p * 2 + 1, mid + 1, r, ql, qr);

        return leftSum + rightSum;
    };

    build(build, 1, 1, n);

    while (m--)
    {
        int type;
        cin >> type;

        if (type == 1)
        {
            int i;
            ll v;
            cin >> i >> v;

            // 0-based 位置变成 1-based
            i++;

            update(update, 1, i, v, 1, n);
        }
        else
        {
            int l, r;
            cin >> l >> r;

            l++;

            cout << query(query, 1, 1, n, l, r) << '\n';
        }
    }

    return 0;
}