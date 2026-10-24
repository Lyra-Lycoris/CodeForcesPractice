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
        int a;
        char c;
        cin>>a>>c;
        string s;
        
        cin>>s;

        ll res=0;

        int n=s.length();
        for(int i=0;i<n/2;i++){
            
            int Mir=n-i-1;

            //cout<<i<<' '<<Mir<<endl;

            if(s[i]==s[Mir]){
                continue;
            }else{
                if(s[i]==c || s[Mir]==c){
                    res++;
                }else{
                    res+=2;
                }
            }

        }
        cout<<res<<'\n';
    }

    return 0;
}