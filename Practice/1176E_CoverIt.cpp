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

int n, m;
const int N = 200005, M = 400005;

int Head[N];
int To[M], Next[M];
int tot;

void add(int u, int v)
{
    tot++;
    To[tot] = v;
    Next[tot] = Head[u];
    Head[u] = tot;
}

int Layer[N]; // 分层数组,同时承担vis标记

int main()
{
    optimize();

    int T;
    cin >> T;
    queue<int> q; // 这样更好
    while (T--)
    {
        tot = 0;
        cin >> n >> m;
        // 清空
        // memset(Head, 0, sizeof(Head));
        // memset(To, 0, sizeof(To));
        // memset(Next, 0, sizeof(Next));
        // memset(Layer, 0, sizeof(Layer));
        /*关于清空范围，To，Next是不用清理的，
        每次add都会直接覆写，Head和Layer都是可以按范围用循环清理*/

        for (int i = 1; i <= n; i++)
        {
            Head[i] = 0, Layer[i] = 0;
        }

        int Lim = n / 2;
        int oddLayersCnt = 0, posLayersCnt = 0; // 位于奇数层和偶数层的点的个数

        while (m--)
        {
            int u, v;
            cin >> u >> v;
            add(u, v);
            add(v, u);
        }

        q.push(1);
        Layer[1] = 1; // 第一层
        oddLayersCnt++;

        while (!q.empty())
        {
            int u = q.front();
            int L = Layer[u];
            q.pop();
            for (int i = Head[u]; i; i = Next[i])
            {
                int v = To[i];
                if (Layer[v])
                {
                    continue;
                }
                Layer[v] = L + 1;
                if ((L + 1) & 1)
                {
                    oddLayersCnt++;
                }
                else
                {
                    posLayersCnt++;
                }
                q.push(v);
            }
        }

        if (oddLayersCnt <= Lim)
        {
            // 选奇数层
            cout << oddLayersCnt << '\n';
            for (int i = 1; i <= n; i++)
            {
                if (Layer[i] & 1)
                {
                    cout << i << ' ';
                }
            }
            cout << '\n';
        }
        else
        {
            cout << posLayersCnt << '\n';
            for (int i = 1; i <= n; i++)
            {
                if (!(Layer[i] & 1))
                {
                    cout << i << ' ';
                }
            }
            cout << '\n';
        }
    }

    return 0;
}