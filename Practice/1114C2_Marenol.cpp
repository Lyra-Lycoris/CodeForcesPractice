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
        string A, B;
        cin >> A >> B;

        if (A == B)
        {
            cout << "0\n";
            continue;
        }
        A = " " + A;
        B = " " + B;
        vector<int> oddApos, oddBpos, posApos, posBpos;

        for (int i = 1; i <= n; i++)
        {
            if (i & 1)
            {
                // 奇数
                if (A[i] == '1')
                {
                    oddApos.emplace_back(i);
                }
                if (B[i] == '1')
                {
                    oddBpos.emplace_back(i);
                }
            }
            else
            {
                if (A[i] == '1')
                {
                    posApos.emplace_back(i);
                }
                if (B[i] == '1')
                {
                    posBpos.emplace_back(i);
                }
            }
        }

        if (oddApos.size() == oddBpos.size() && posApos.size() == posBpos.size())
        {
            // 计算最小变化次数

            ll ans = 0;
            ll m1 = oddApos.size(), m2 = posApos.size();

            for (int i = 0; i < m1; i++)
            {
                ans += (abs(oddApos[i] - oddBpos[i])) / 2;
            }
            for (int i = 0; i < m2; i++)
            {
                ans += (abs(posApos[i] - posBpos[i])) / 2;
            }
            cout << ans << '\n';
        }
        else
        {
            cout << "-1\n";
        }
    }

    return 0;
}