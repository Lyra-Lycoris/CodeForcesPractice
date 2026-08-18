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

int main()
{
    optimize();

    ll T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;

        ll LeftMaxCompress = 1;
        ll RightMaxCompress = 1;

        for (int i = 3; i < n; i++)
        {
            if (s[i] != s[i - 1])
            {
                RightMaxCompress++;
            }
        }

        ll ans = INT_MAX;

        for (int i = 1; i <= n - 2; i++)
        {

            if (i != 1)
            {
                if (s[i - 1] != s[i - 2])
                {
                    LeftMaxCompress++;
                }
                if (s[i] != s[i + 1])
                    RightMaxCompress--;
            }

            if (s[i - 1] == s[i + 1])
            {
                ans = min(ans, LeftMaxCompress + RightMaxCompress - 1);
            }
            else
            {
                ans = min(ans, RightMaxCompress + LeftMaxCompress);
            }
        }

        cout << ans << '\n';
    }

    return 0;
}