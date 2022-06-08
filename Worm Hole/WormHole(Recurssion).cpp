#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

int n, cnt = 1, test;
int x1, Y1, x2, y2;
int wh[50][50];
int visited[50];
int ans;

void initcase()
{
    for (int i = 0; i < 50; i++)
        visited[i] = 0;
    for (int i = 0; i < 50; i++)
        for (int j = 0; j < 50; j++)
            wh[i][j] = 0;
     ans = 999999;
}

int Min(int a, int b)
{
    if (a < b)
        return a;
    else
        return b;
}

int Abs(int a)
{
    if (a < 0)
        return -a;
    else
        return a;
}

int distance(int sx, int sy, int dx, int dy)
{
    return Abs(sx - dx) + Abs(sy - dy);
}

void solve(int sx, int sy, int dx, int dy, int dis)
{
    ans = Min(ans, distance(sx, sy, dx, dy) + dis);

    for (int i = 0; i < n; i++)
    {
        if (visited[i] == 0)
        {
            visited[i] = 1;
            int temp = distance(sx, sy, wh[i][0], wh[i][1]) + dis + wh[i][4];
            solve(wh[i][2], wh[i][3], dx, dy,temp);
            temp = distance(sx, sy, wh[i][2], wh[i][3]) + dis + wh[i][4];
            solve(wh[i][0], wh[i][1], dx, dy, temp);
            visited[i] = 0;
        }
    }
}

int main()
{
    //freopen("Input.txt", "r", stdin);
    cin >> test;
    while ( test--)
    {
        cin >> x1 >> Y1 >> x2 >> y2;
        cin>>n;
        initcase();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                cin >> wh[i][j];
            }
        }
        solve(x1, Y1, x2, y2, 0);
        cout<<"#"<<cnt++<<" "<< ans << endl;
    }
    return 0;
}
