#include<iostream>
using namespace std;

int n;
int x[100];
int Y[100];
int visited[100];
int ans;

void initcase()
{
    ans = 999999;
    for (int i = 0; i < 100; i++)
        visited[i] = 0;
}

int Abs(int a)
{
    if (a < 0)
        return -a;
    else
        return a;
}

int Min(int a, int b)
{
    if (a < b)
        return a;
    else
        return b;
}

int distance(int i, int j)
{
    int x1 = x[i];
    int x2 = x[j];
    int y1 = Y[i];
    int y2 = Y[j];
    return Abs(x1 - x2) + Abs(y1 - y2);
}

void solve(int current, int value, int nodeLeft)
{
    if (nodeLeft == n)
    {
        ans = Min(ans, value + distance(current, n + 1));
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        if (visited[i] == 0)
        {
            visited[i] = 1;
            solve(i, value + distance(current, i), nodeLeft + 1);
            visited[i] = 0;
        }
    }
}

int main()
{
    int cnt = 1;
    for (int j = 1; j <= 10; j++)
    {
        cin >> n;
        initcase();
        cin >> x[n + 1] >> Y[n + 1] >> x[0] >> Y[0];
        for (int i = 1; i <= n; i++)
        {
            int a, b;
            cin >> a >> b;
            x[i] = a;
            Y[i] = b;
        }
        solve(0, 0, 0);
        cout << "# " << cnt++ << " " << ans << endl;
    }
    return 0;
}
