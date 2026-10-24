#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> num(n);
        vector<int> cnt(114, 0);
        for (int i = 0; i < n; i++)
        {
            cin >> num[i];
            cnt[num[i]]++;
        }

        if (n == 0)
        {
            cout << "0\n";
            continue;
        }

        int EndLoop = 0;
        for (int i = 0; i < 114; i++)
        {
            if (cnt[i] == 0)
            {
                EndLoop = i;
                break;
            }
        }

        int res = EndLoop;

        for (int a = 0; a < EndLoop; a++)
        {

            if (cnt[a] >= k)
            {
                cnt[a] -= k;
            }
            else
            {
                
                int cntSmaller = 0; // 比这个数小的
                for (int i = a; i >= 0; i--)
                {
                    if (cnt[i] > 0)
                    {
                        int diff = min(cnt[i], k - cntSmaller);
                        cnt[i] -= diff;
                        cntSmaller += diff;
                        if (cntSmaller >= k)
                        {
                            break;
                        }
                    }
                }

                if (cntSmaller >= k)
                {
                    continue;
                }
                else
                {
                    res = a;
                    break;
                }
            }
        }

        cout << res << '\n';
    }

    return 0;
}