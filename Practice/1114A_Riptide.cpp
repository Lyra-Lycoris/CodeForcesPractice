#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define all(x) x.begin(), x.end()

inline void optimize(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}
//A题纯模拟，但也可以用公式实现
int main()
{
    optimize();

    ll T;
    cin>>T;
    while(T--){
        ll a,b,c;
        cin>>a>>b>>c;
        ll cnt=0;
        while (true)    
        {
            if(a==b || b==c || a==c){
                cout<<cnt<<'\n';
                break;
            }
            cnt++;
            ll Max=max({a,b,c}),Min=min({a,b,c});
            if(Max==a){
                if(Min==b){
                    a--,b++;
                }
                else{
                    a--,c++;
                }
            }else if(Max==b){
                b--;
                if(Min==a){
                    a++;
                }else{
                    c++;
                }
            }else{
                c--;
                if(Min==a){
                    a++;
                }else{
                    b++;
                }
            }
        }
        
    }

    return 0;
}