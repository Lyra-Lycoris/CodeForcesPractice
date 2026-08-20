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
const int N = 55;
char graph[N][N];

bool vis[N][N];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

bool DFS(int x, int y, int px, int py)
{

    vis[x][y] = true;

    for (int k = 0; k < 4; k++)
    {
        int nx = x + dx[k];
        int ny = y + dy[k];

        if (nx >= 1 && nx <= n && ny >= 1 && ny <= m)
        {
            if (graph[nx][ny] == graph[x][y] && !(nx == px && ny == py))
            {
                if (vis[nx][ny])
                {
                    // 遇到环
                    return true;
                }
                else
                {
                    if (DFS(nx, ny, x, y))
                    {
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

int main()
{
    optimize();

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        string line;
        cin >> line;
        for (int j = 1; j <= m; j++)
        {
            graph[i][j] = line[j - 1];
        }
    }

    memset(vis, 0, sizeof(vis));

    bool ok = false;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (!vis[i][j])
            {
                if (DFS(i, j, -1, -1))
                {
                    ok = true;
                    break;
                }
            }
        }
        if (ok)
        {
            break;
        }
    }

    cout << (ok ? "Yes\n" : "No\n");

    return 0;
}