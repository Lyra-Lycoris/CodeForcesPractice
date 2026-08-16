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

    int _;
    cin >> _;
    while (_--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;

        int ans = 1;
        bool ok = true;
        for (int st = 0; st <= 1;st++) {
            //奇数链与偶数链
            int theoryStart = -1;//理论链首
            int k = 0;//相对于链首是第几项
            for (int i = st; i < n;i += 2, k++) {
                if (s[i] == '?') {
                    continue;
                }
                int val = s[i] - '0';
                
                //通过v 反推链首
                if (theoryStart == -1) {
                    theoryStart = val ^ (k & 1);
                }
                else {
                    int guessStart = val ^ (k & 1);
                    if (theoryStart != guessStart) {
                        ok = false;
                        break;
                    }
                }
            }
            if (!ok) {
                break;
            }
            else {
                ans *= (theoryStart == -1 ? 2 : 1);
            }
        }

        if (!ok) {
            cout << 0 << endl;
        }
        else {
            cout << ans << endl;
        }
        


    }

    return 0;
}