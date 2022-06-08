/*
https://www.careercup.com/question?id=14989765
http://ideone.com/oXdBaF
Given a 2 D matrix where 1 represent the places where the frog can jump and 0 represent the empty spaces,
the frog can move freely in horizontal direction (on 1’s only) without incurring any cost (jump).
A vertical jump from a given point of the matrix to other point on the matrix can be taken (on 1’s only)
with cost as the number of jumps taken.
Given a source and destination, the frog has to reach the destination minimizing the cost (jump).
*/

#include <iostream>
using namespace std;
int test, n, m;
int grid[100][100];
int dp[100][100];
int visited[100][100];
int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
void initcase()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            visited[i][j] = 0;
            dp[i][j] = 100000;
        }
    }
}
bool isValid(int x, int y)
{
    return (grid[x][y] == 1 && visited[x][y] == 0 && x >= 0 && x < n && y >= 0 && y < m);
}
void solve(int sx, int sy, int dx, int dy, int ans)
{
    visited[sx][sy] = 1;
    if (dp[sx][sy] > ans)
        dp[sx][sy] = ans;
    if (sx == dx && sy == dy)
        return;
    for (int i = 0; i < 4; i++)
    {
        int x = sx + dir[i][0];
        int y = sy + dir[i][1];
        int temp = 0;
        if (isValid(x, y))
        {
            if (x == sx)
                temp = 0;
            if (y == sy)
                temp = 1;
            solve(x, y, dx, dy, ans + temp);
        }
    }
    return;
}
/* Input
5
0 1 1 0 1
1 0 0 1 0
1 0 0 0 1
0 1 0 1 1
1 0 1 1 1
4 4 2 4*/

int main()
{
    cin >> test;
    while (test--)
    {
        cin >> n >> m;
        initcase();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> grid[i][j];
            }
        }
        int sx, sy, dx, dy;
        cin >> sx >> sy >> dx >> dy;
        solve(sx, sy, dx, dy, 0);
        cout << dp[dx][dy] << endl;
    }

    return 0;
}
