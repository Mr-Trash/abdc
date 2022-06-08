#include<iostream>
using namespace std;

int n, m;
int grid[100][100];
int visited[100][100];
int level;
int flag;

void initcase()
{
    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            visited[i][j] = 0;
        }
    }
    flag = 0;
}

void dfs(int x, int y)
{
    if (x < 0 || y < 0 || x >= n || y >= m)
        return;
    if (visited[x][y] == 1)
        return;
    if (grid[x][y] == 3)
    {
        flag = 1;
        return;
    }
    visited[x][y] = 1;
    if (y + 1 < m && (grid[x][y + 1] == 1 || grid[x][y+1]==3) && visited[x][y + 1] == 0)
    {
        dfs(x, y + 1);
    }
    if (y - 1 >= 0 && (grid[x][y - 1] == 1 || grid[x][y - 1] == 3) && visited[x][y - 1] == 0)
    {
        dfs(x, y - 1);
    }
    int h = 1;
    for (h = 1; h <= level; h++)
    {
        if (x - h >= 0 && h <= level && (grid[x - h][y] == 1 || grid[x - h][y] == 3) && visited[x - h][y] == 0)
        {
            dfs(x - h, y);
        }
    }
    for (h = 1; h <= level; h++)
    {
        if (x + h < n && h <= level && (grid[x + h][y] == 1 || grid[x + h][y] == 3) && visited[x + h][y] == 0)
        {
            dfs(x + h, y);
        }
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
        }
    }

    for (level = 0; level < n; level++)
    {
        initcase();
        dfs(n - 1, 0);
        if(flag)
        {
            cout << level << endl;
            break;
        }
    }
    return 0;
}
