#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define all(x) x.begin(), x.end()

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll T;
    cin >> T;
    while (T--)
    {
        ll n, k;
        cin >> n >> k;

        vector<ll> a(n + 1);
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }

        sort(a.begin()+1,a.end());

        ll curLen=1;//当前合法区间的长度
        ll maxLen=1;
        for(int i=2;i<=n;i++){
            
            if(a[i]-a[i-1]<=k){
                curLen++;
            }
            else{
                curLen= 1;
            }

            maxLen=max(maxLen,curLen);

        }
        ll ans=n-maxLen;
        cout<<ans<<'\n';

    }

    return 0;
}