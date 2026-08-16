#include<bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    
    }

    int Max=a[0];
    for(int i=2;i<n;i++){
        Max=max(Max,a[i]);
    }
    cout<<Max<<endl;


    return 0;
}