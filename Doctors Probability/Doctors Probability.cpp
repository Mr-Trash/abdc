#include <iostream>
using namespace std;

int test;
double ans;
int index;
double grid[100][100];
double sol[100][100];
int n, e, Time;

void initcase()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            grid[i][j] = 0.0;
    }
}

void solve()
{
    int i, j, k;
    ans = -1.0;
    index = -1;
    sol[0][1] = 1.0;
    for (i = 2; i <= n; i++)
        sol[0][i] = 0;
    for (i = 0; i < Time; i++)
    {
        for (j = 1; j <= n; j++)
            sol[i + 1][j] = 0;
        for (j = 1; j <= n; j++)
        {
            if (sol[i][j] > 0)
            {
                for (k = 1; k <= n; k++)
                {
                    if (grid[j][k])
                    {
                        sol[i + 1][k] = sol[i + 1][k] + (sol[i][j] * grid[j][k]);
                    }
                }
            }
        }
    }

    for (j = 1; j <= n; j++)
    {
        if (sol[i][j] > ans)
        {
            ans = sol[i][j];
            index = j;
        }
    }
}

int main()
{
    int cnt=1;
    cin >> test;
    while (test--)
    {
        cin >> n >> e >> Time;
        Time = Time / 10;
        initcase();
        for (int i = 0; i < e; i++)
        {
            int a, b;
            double x;
            cin >> a >> b >> x;
            grid[a][b] = x;
        }
        solve();

        cout<<"#"<<cnt++<<" ";
        printf("%d %lf \n", index, ans);
    }

    return 0;
}
