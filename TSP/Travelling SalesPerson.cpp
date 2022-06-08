#include <iostream>
using namespace std;

int test, n, ans;
int visited[101];
int grid[101][101];

void initcase()
{
    ans = 999999;
    for (int i = 0; i < n; i++)
        visited[i] = 0;
}

void solve(int current, int cost, int nodeLeft)
{
    if (nodeLeft == 0)
    {
        cost = cost + grid[current][0];
        if (ans > cost)
            ans = cost;
        return;
    }
    for (int i = 1; i < n; i++)
    {
        if (visited[i] == 0)
        {
            visited[i] = 1;
            solve(i, cost + grid[current][i], nodeLeft - 1);
            visited[i] = 0;
        }
    }
}

int main()
{
    cin >> test;
    while (test--)
    {
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                cin >> grid[i][j];
        }

        initcase();
        solve(0, 0, n - 1);
        cout << ans << endl;
    }

    return 0;
}