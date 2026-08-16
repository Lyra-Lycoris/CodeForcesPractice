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
        int n,k;
        cin>>n>>k;
        if(n<=k+1){
            //第一判否，检查k是否过大，因为有k对相等，至少有k+1个字符相等，这在n==k+1时无法实现
            cout<<"-1\n";
            continue;
        }
        
        int m= n-k;
        int cnt00=(m+1)/2;//0段的个数
        int cnt11=m/2;//1段的个数
        int cnt0=(n+1)/2;//0的个数
        int cnt1=n/2;

        int rest0=cnt0-cnt00;//保底后的0个数,即维持每个段长度至少为1后的0的个数
        int rest1=cnt1-cnt11;

        vector<int> len(m,1);//每个段长
        len[0]+=rest0;
        len[1]+=rest1;

        string s;
        s.reserve(n);
        char cur = '0';
        for(int i=0;i<m;i++){
            s.append(len[i],cur);
            cur=(cur=='0'?'1':'0');
        }

        cout<<s<<'\n';

    }

    return 0;
}