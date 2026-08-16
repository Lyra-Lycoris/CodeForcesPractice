#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define all(x) x.begin(), x.end()

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, m;
    cin >> n >> m;
    vector<vector<char>> graph(n + 1, vector<char>(m + 1));
    for (int i = 1; i <= n; i++)
    {
        string line;
        cin >> line;
        for (int j = 1; j <= m; j++)
        {
            graph[i][j] = line[j - 1];
        }
    }

    vector<vector<int>> vis(n + 1, vector<int>(m + 1, 0));

    auto DFS = [&](auto &&self, int x, int y, int lastX, int lastY) -> bool
    {
        vis[x][y]=1;//进入dfs立即标记

        for (int k = 0; k < 4; k++)
        {
            int nx = x + dx[k];
            int ny = y + dy[k];

            
            if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && graph[nx][ny] == graph[x][y])
            { // 先判合法性
                if ((nx == lastX && ny == lastY))
                {
                    continue; // 跳过父节点
                }
                if (vis[nx][ny]==0)
                {
                    // 递归下去
                    vis[nx][ny]=true;
                    if(self(self,nx,ny,x,y)){//注意这个
                        return true;
                    }
                }
                else if (vis[nx][ny]==1)
                {
                    // 找到环返回true
                    return true;
                }
            }else{
                continue;
            }
        }
        // 四个方向递归完都没反应
        return false;
    };

    bool Found = false;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (!vis[i][j])
            {
                vis[i][j]=1;
                bool Cycle = DFS(DFS, i, j, -1, -1); // 棍母做父节点
                if (Cycle)
                {
                    Found = true;
                    break;
                }
               // vis[i][j]=1;
            }
        }
        if (Found)
        {
            break;
        }
    }

    cout<<(Found?"Yes\n":"No\n");

    return 0;
}