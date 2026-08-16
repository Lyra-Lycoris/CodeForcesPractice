#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define all(x) x.begin(), x.end()

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--)
    {

        ll n, h;
        cin >> n >> h;

        vector<ll> Time(n + 1);
        for (ll i = 1; i <= n; i++)
        {
            cin >> Time[i];
        }

        ll l = 1, r = h;

        auto check = [&](const ll &k) -> bool
        {
            ll damage = 0;
            for (int i = 1; i <= n; i++)
            {
                if (i != n)
                {
                    damage += (min(Time[i + 1] - Time[i], k));
                }
                else
                {
                    damage += k;
                }
            }
            if (damage >= h)
            {
                return true;
            }
            else
            {
                return false;
            }
        };

        while (l < r)
        {
            ll mid = l + (r - l) / 2;
            if (check(mid))
            {
                r = mid;
            }
            else
            {
                l = mid + 1;
            }
        }
        cout << l << '\n';
    }

    return 0;
}