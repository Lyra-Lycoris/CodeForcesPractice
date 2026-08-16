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
        ll len;
        cin >> len;
        string A, B;
        cin >> A >> B;

        int cntOddA = 0, cntPosA = 0, cntOddB = 0, cntPosB = 0; // 奇数下标上1的个数和偶数下标上的

        for (int i = 0; i < len; i++)
        {
            if (i & 1)
            {
                // 奇数
                if (A[i] == '1')
                {
                    cntOddA++;
                }
                if (B[i] == '1')
                {
                    cntOddB++;
                }
            }
            else
            {
                if (A[i] == '1')
                {
                    cntPosA++;
                }
                if (B[i] == '1')
                {
                    cntPosB++;
                }
            }
        }

        if (cntPosA == cntPosB && cntOddA == cntOddB)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }

    return 0;
}