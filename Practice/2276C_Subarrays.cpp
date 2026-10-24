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
        int n,k;
        cin>>n>>k;
        vector<int> a(n+1);
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }

        vector<ll> pref(n+1,0);

        for(int i=1;i<=n;i++){
            pref[i]=pref[i-1]+a[i];
        }

        ll res=0;

        vector<ll> cnt(k+1,0);

        for(int r=k+1;r<=n;r++){
            int p=r-k-1;//p=l-1=r-k-1;
            ll rem1=pref[p]%k;
            cnt[rem1]++;
            ll rem2=pref[r]%k;
            res+=(cnt[rem2]);
        }
        cout<<res<<'\n';

    }

    return 0;
}