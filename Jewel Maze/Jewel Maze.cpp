/// Question & Input -> https://blog.csdn.net/broadCE/article/details/47959227
#include <iostream>
using namespace std;
int test, n;
int grid[100][100];
int ansMat[100][100];
int ans;
int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
bool isValid(int x, int y)
{
    return ((grid[x][y] == 0 || grid[x][y] == 2) && x >= 0 && x < n && y >= 0 && y < n);
}
void solve(int row, int col, int jewel)
{
    if (row == n - 1 && col == n - 1)
    {
        if (ans < jewel)
        {
            ans = jewel;
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    ansMat[i][j] = grid[i][j];
                }
            }
        }
    }
    for (int i = 0; i < 4; i++)
    {
        int x = row + dir[i][0];
        int y = col + dir[i][1];
        if (isValid(x, y))
        {
            int check = 0;
            if (grid[x][y] == 2)
            {
                check = 1;
            }
            else if (grid[x][y] == 0)
                check = 0;
            grid[x][y] = 3;
            solve(x, y, jewel + check);
            if (check == 1)
                grid[x][y] = 2;
            else
                grid[x][y] = 0;
        }
    }
}
int main()
{
    cin >> test;
    int cnt = 1;
    while (test--)
    {
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                cin >> grid[i][j];
        }
        ans = -1;
        grid[0][0] = 3;
        solve(0, 0, 0);
        cout << "#" << cnt << " " << ans << endl;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << ansMat[i][j] << " ";
            }
            cout << endl;
        }

        cnt++;
    }

    return 0;
}
