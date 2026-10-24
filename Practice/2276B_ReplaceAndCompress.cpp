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
        string s;
        cin>>s;
        int n=s.length();
        bool s101=false;//101 or 010
        bool s111=false;//000 or 111
        for(int i=1;i<=n-2;i++){
            if(s[i]=='0'){
                if(s[i-1]==s[i+1]&& s[i-1]=='0'){//000
                    s111=true;
                }else if(s[i-1]==s[i+1]&& s[i-1]=='1'){//101
                    s101=true;
                }
            }else if(s[i]=='1'){
                if(s[i-1]==s[i+1]&& s[i-1]=='0'){//010
                    s101=true;
                }else if(s[i-1]==s[i+1]&& s[i-1]=='1'){//111
                    s111=true;
                }
            }
        }

        int ans=1+(s101? 1:0) + (s111? 1:0);
        cout<<ans<<'\n';
    }

    return 0;
}