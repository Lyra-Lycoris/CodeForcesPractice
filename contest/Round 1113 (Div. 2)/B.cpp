#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define all(x) x.begin(), x.end()

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll T;
    cin >> T;
    while (T--)
    {
        ll n, m;
        cin >> n >> m;
        vector<ll> a(n), b(m);

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i < m; i++)
        {
            cin >> b[i];
        }

        sort(all(a));
        sort(all(b));

        bool Could = true;

        if (a[0] > b[0] || a.back() < b.back())
        {
            Could = false;
        }

        if (!Could)
        {
            cout << "NO" << '\n';
            continue;
        }

        if (n < 2 * m)
        {
            Could = false;
        }

        if (Could)
        {
            for (int i = 0; i < m; i++)
            {
                ll Smaller = a[i];
                ll Bigger = a[n - m + i];//选的是前m个和后m个

                if (!(Smaller < b[i] && b[i] < Bigger))
                {
                    Could = false;
                    break;
                }
            }
        }

        cout << (Could ? "YES\n" : "NO\n");
    }

    return 0;
}