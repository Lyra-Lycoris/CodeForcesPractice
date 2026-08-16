#include<bits/stdc++.h>
using namespace std;

int main(int argc,char *argv[]){

    srand(atoi(argv[1]));
    int n=rand()%5+1;
    cout<<n<<'\n';

    for(int i=0;i<n;i++){
        cout<<rand()%15+1<<' ';//生成1到15的随机数
    }
    cout<<'\n';

    return 0;
}