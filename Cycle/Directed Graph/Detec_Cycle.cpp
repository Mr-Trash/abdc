///Online Judge Problem: -> https://www.codingninjas.com/codestudio/problems/detect-cycle-in-a-directed-graph_920545
#include<iostream>
using namespace std;

int n, e, test;
int grid[105][105], visited[105];
int cycle, cnt, tnt, flag;
int store[105], ans[105];
int res=9999;
int path[105];

void initcase()
{
    cycle = 0, cnt = 0, tnt = 0, flag = 0;

    for (int i = 0; i < 105; i++)
    {
        for (int j = 0; j < 105; j++)
        {
            grid[i][j] = 0;
        }
    }
}

void dfs(int u)
{
    visited[u] = 1;
    store[cnt++] = u;
    for (int i = 0; i <= n; i++)
    {
        if (grid[u][i])
        {
            if (visited[i] == 1)
            {
                cycle = 1;
                return;
            }
            else if (visited[i] == 0)
                dfs(i);
        }
    }
    visited[u] = 0;
    cnt--;
}

void solve()
{
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j < n; j++)
            visited[j] = 0;
        dfs(i);
    }
}

int main()
{
    cin>>test;
    while(test--)
    {
        initcase();
        cin >> n >> e;
        for (int i = 0; i < e; i++)
        {
            int a, b;
            cin >> a >> b;
            grid[a][b] = 1;
        }
        solve();
        if (cycle)
        {
            cout << "True" << endl;
        }
        else
            cout<<"False"<<endl;

    }
    return 0;
}
