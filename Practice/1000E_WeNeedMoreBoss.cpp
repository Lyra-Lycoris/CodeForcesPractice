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

ll n, m;
const int N = 300005;
const int M = 600005;

int Head[N];
int Next[M], To[M];
int tot = 1;

void add(int u, int v)
{
    ++tot;
    To[tot] = v;
    Next[tot] = Head[u];
    Head[u] = tot;
}

ll dfn[N], low[N];
bool isBridge[M]; // 是不是桥边
ll Time = 0;

void tarjan(int u, int inEdge)
{

    dfn[u] = low[u] = ++Time;

    for (int i = Head[u]; i; i = Next[i])
    {
        // 下一条边
        int v = To[i];
        if (!dfn[v])
        {
            // 递归进入
            tarjan(v, i);
            low[u] = min(low[u], low[v]);
            if (low[v] > dfn[u])//这里是大于
            {
                // 是桥边
                isBridge[i] = isBridge[i ^ 1] = true;
            }
        }
        else if (i != (inEdge ^ 1))//运算符优先级
        { // 一定要有i!=inEdge^1的条件
            // 遇到返祖边
            low[u] = min(low[u], dfn[v]);
        }
    }
}

// 完成后缩点
int color[N];
int cc; // 连通分量个数

void paint(int st)
{
    // 从st出发，进行染色缩点
    queue<int> q;
    q.push(st);

    color[st] = cc;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (int i = Head[u]; i; i = Next[i])
        {
            int v = To[i];
            // 桥边和已经访问过的不走
            if (isBridge[i] || color[v])
            {
                continue;
            }
            else
            {
                color[v] = cc;
                q.push(v);
            }
        }
    }
}

vector<int> Tree[N]; // 缩点后的树
int dis[N];

int BFS(int st)
{
    // 求出最远点
    fill(dis + 1, dis + cc + 1, -1);
    queue<int> q;
    q.push(st);
    dis[st] = 0;
    int far = st;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        if (dis[u] > dis[far])
        {
            far = u;
        }
        for (int v : Tree[u])
        {
            if (dis[v] == -1)
            {
                dis[v] = dis[u] + 1;
                q.push(v);
            }
        }
    }
    return far;
}

int main()
{
    optimize();

    ll T = 1;
    // cin >> T;
    while (T--)
    {
        cin >> n >> m;

        for (int i = 1; i <= m; i++)
        {
            int u, v;
            cin >> u >> v;
            add(u, v);
            add(v, u);
        }

        tarjan(1, 0);
        cc = 0;
        for (int u = 1; u <= n; u++)
        {
            if (!color[u])
            {
                ++cc;
                paint(u);
            }
        }

        for (int i = 2; i <= m * 2; i += 2)
        {

            if(!isBridge[i]){//不是桥的时候跳过，因为建立桥树只需要保留桥
                continue;
            }
            // 建树
            int x = color[To[i]];
            int y = color[To[i ^ 1]];

            Tree[x].emplace_back(y);
            Tree[y].emplace_back(x);
        }

        int p = BFS(1);
        int q = BFS(p);
        cout << dis[q] << endl;
    }

    return 0;
}
