#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define all(x) x.begin(), x.end()

ll qpow(ll a, ll b)
{
    ll ans = 1;
    while (b)
    {
        if (b & 1)
        {
            ans *= a;
        }
        b >>= 1;
        a *= a;
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll T;
    cin >> T;
    while (T--)
    {
        ll n, c;
        cin >> n >> c;
        vector<ll> Paintings(n + 1);
        for (ll i = 1; i <= n; i++)
        {
            cin >> Paintings[i];
        }

        auto check = [&](const ll &w) -> int
        {
            ll curS = 0;

            for (ll i = 1; i <= n; i++)
            {
                curS += (qpow(Paintings[i] + 2 * w, 2));
                if (curS > c)
                {
                    return 2; // 2表示大了
                }
            }
            if (curS < c)
            {
                return 0; // 0表示小了
            }
            else if (curS == c)
            {
                return 1; // 1表示刚好
            }
            else if (curS > c)
            {
                return 2; // 表示大了
            }
        };

        ll L = 0, R = sqrt(c);
        ll ans = -1;

        while (L <= R)
        {
            ll mid = L + (R - L) / 2;

            ll judge = check(mid);
            if (judge == 0)
            {
                L = mid + 1;
            }
            else if (judge == 2)
            {
                R = mid - 1;
            }
            else if (judge == 1)
            {
                ans = mid;
                break;
            }
        }
        cout << ans << '\n';
    }

    return 0;
}