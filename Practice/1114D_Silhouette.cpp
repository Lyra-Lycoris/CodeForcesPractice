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

struct node
{
    ll val;    // b的值
    ll pos;    // 当前b[i]的位置
    ll Theory; // 理论a[i]值
};

int main()
{
    optimize();

    ll T;
    cin >> T;
    while (T--)
    {
        ll n;
        cin >> n;
        vector<node> b(n);    // 给定b数组
        map<ll, ll> cnt;      // 出现次数
        map<ll, ll> Next;     // 下一个该出现的数
        bool hasZero = false; // 第一判否

        for (ll i = 0; i < n; i++)
        {
            cin >> b[i].val;
            if (b[i].val == 0)
            {
                hasZero = true;
            }
            cnt[b[i].val]++;
            b[i].pos = i;
        }

        if (!hasZero)
        {
            cout << -1 << '\n'; // 没得用了
            continue;
        }
        if (n == 1)
        {
            // 唯一值且是0
            cout << 1 << '\n';
            continue;
        }

        sort(b.begin(), b.end(), [&](const node &a, const node &b)
             {
            if(a.val!=b.val){
                return a.val<b.val;
            }else{
                return a.pos<b.pos;
            } });

        // 初始化Next
        for (int i = 0; i < n - 1; i++)
        {
            if (b[i + 1].val != b[i].val)
            {
                Next[b[i].val] = b[i + 1].val;
            }
            else
            {
                Next[b[i].val] = -1; //-1占位
            }
        }

        if (b[n - 1].val != b[n - 2].val)
        {
            Next[b[n - 1].val] = -1;
        }

        // 开始处理构造Theroy
        ll lastGet = 0; // 第二判否原则，不能搞出比上一个理论值小的数字或者小数

        bool Vaild = true;

        vector<ll> a(n);
        for (ll i = 0; i < n; i++)
        {
            ll v = b[i].val;
            if (Next[v] == -1)
            {
                a[b[i].pos] = lastGet + 1;
                continue;
            }

            if ((Next[v] - v) % cnt[v] != 0 || (Next[v] - v) / cnt[v] <= lastGet)
            //这里应该是Next[v]-v
            { // 不能整除或者除出一个比上一个理论小或者相等的东西来
                Vaild = false;
                break;
            }

            ll curTheory = (Next[v] - v) / cnt[v];
            b[i].Theory = curTheory;
            a[b[i].pos] = curTheory;
            if (i != n - 1 && b[i + 1].val != v)
            {
                lastGet = curTheory;
            }
        }

        if (!Vaild)
        {
            cout << -1 << '\n';
            continue;
        }

        for (ll i = 0; i < n; i++)
        {
            cout << a[i] << ' ';
        }
        cout << '\n';
    }

    return 0;
}