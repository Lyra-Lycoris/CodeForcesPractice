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
        int a,b;
        cin>>a>>b;

        if(a<=b){
            cout<<"-1\n";
        }else{
            cout<<min(b,a-b)<<'\n';
        }


    }

    return 0;
}