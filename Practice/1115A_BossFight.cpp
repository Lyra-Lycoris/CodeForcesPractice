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

    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        vector<ll> a(n);
        unordered_map<ll, ll> cnt;

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            cnt[a[i]]++;
        }

        if (n == 1)
        {
            cout << a[0] << '\n';
            continue;
        }

        sort(a.rbegin(), a.rend());
        a.erase(unique(all(a)), a.end());

        sort(all(a), [&](const ll &a, const ll &b)
             { return cnt[a] > cnt[b]; });

        ll lastOp = -1;
        ll res = 0;
        ll i = 0;
        while (i < a.size())
        {
            if (i == a.size() - 1)
            {
                /*最后一组值特判一下*/
                if (cnt[a[i]] == 0)
                {
                    break;
                }
                else if (cnt[a[i]] == 1)
                {
                    res += a[i];
                    break;
                }
                else if (cnt[a[i]] >= 2)
                {
                    res += 2 * a[i];
                    break;
                }
            }
            else
            {
                if (lastOp != a[i] && cnt[a[i]] != 0)
                {
                    // 有操作，直接操作这个数字
                    res += a[i];
                    cnt[a[i]]--;
                    lastOp = a[i];
                }
                else
                {
                    if (lastOp == a[i] && i != a.size() - 1)
                    {
                        // 试着加下一个数
                        res += a[i + 1];
                        cnt[a[i + 1]]--;
                        lastOp = a[i + 1];
                        if (cnt[a[i + 1]] == 0)
                        {
                            a.erase(a.begin() + i + 1);
                        }
                    }
                    else if (cnt[a[i]] == 0)
                    {
                        a.erase(a.begin());
                    }
                }
            }
        }
        cout << res << '\n';
    }

    return 0;
}