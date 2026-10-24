#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 300010;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    ll n, x;
    cin >> T;

    while (T--)
    {
        cin >> n >> x;
        vector<int> nums(n);
        for (int i = 0; i < n; i++)
        {
            cin >> nums[i];
        }

        vector<int> primeFactor;
        int temp = x;
        for (int i = 2; i * i <= x; i++)
        {
            if (temp % i == 0)
            {
                // 质因子
                primeFactor.emplace_back(i);
                while (temp % i == 0)
                {
                    temp /= i;
                }
            }
        }
        if (temp > 1)
        {
            primeFactor.emplace_back(temp);
        }

        ll res = 0;
        for (int p : primeFactor)
        {
            // 对于每一种质因子
            ll curRes = 0;
            for (int num : nums)
            {
                if (num % p == 0)
                {
                    curRes += num;
                }
            }
            res = max(res, curRes);
        }
        cout << res << '\n';
    }

    return 0;
}