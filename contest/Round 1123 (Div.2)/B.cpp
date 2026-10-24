#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    int n;
    cin >> T;

    while (T--)
    {

        cin >> n;
        vector<int> arr(n);
        unordered_map<int, int> cnt;

        set<int> curMax; // 保留当前最大

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            cnt[arr[i]]++;
            curMax.insert(arr[i]);
        }

        while (!curMax.empty())
        {
            int Max = *prev(curMax.end());
            int curMaxCnt = cnt[Max];
            for (int i = 0; i < cnt[Max]; i++)
            {
                cout << Max << ' ';
            }
            curMax.erase(Max);
            cnt[Max] = 0;

            for (auto &[num, Cnt] : cnt)
            {
                for (int i = 0; i < min(Cnt, curMaxCnt); i++)
                {
                    cout << num << ' ';
                }
                cnt[num] -= min(Cnt, curMaxCnt);
                if (cnt[num] == 0)
                {
                    curMax.erase(num);
                }
            }
        }
        cout << '\n';
    }

    return 0;
}