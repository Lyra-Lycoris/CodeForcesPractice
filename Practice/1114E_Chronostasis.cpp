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
        ll n;
        cin >> n;
        vector<ll> b(n);

        ll start = LLONG_MAX;
        ll posSum = 0, negSum = 0;

        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
            if (b[i] > 0)
            {
                start = min(start, b[i]);
                posSum += b[i];
            }
            else if (b[i] < 0)
            {
                negSum += b[i];
            }
        }

        if (posSum + negSum <= 0 || start == LLONG_MAX)
        {
            cout << "-1\n";
            continue;
        }

        bool flag = false; // 起点放入标记
        multiset<ll> Mins; // 用来查“当前最小且减下去后合法的值”
        for (int i = 0; i < n; i++)
        {
            // 初始化两个优先队列
            if (b[i] >= 0)
            {
                if (b[i] == start && !flag)
                {
                    flag = true; // 只跳过一个起点值
                    continue;
                }
                Mins.insert(b[i]);
            }
            else
            {
                Mins.insert(b[i]);
            }
        }

        vector<ll> res;
        res.emplace_back(start);
        ll Last = start; // 上一个值

        while (!Mins.empty())
        {
            // 找到第一个比-Last大的值
            auto it = Mins.upper_bound(-1 * Last);
            ll targ = *it;
            Last += targ;
            res.emplace_back(Last);
            Mins.erase(it);
        }

        for (int i = 0; i < res.size(); i++)
        {
            cout << res[i] << ' ';
        }

        cout << '\n';
    }

    return 0;
}