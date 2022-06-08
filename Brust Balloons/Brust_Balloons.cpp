#include<iostream>
using namespace std;

int n;
int ballons[50];


int solve(int l, int r, int n)
{
    int ans = 0;
    for (int i = l+1; i < r; i++)
    {
        int cs = solve(l,i,n) + solve(i, r, n);

        if (l == 0 && r == n)
            cs = cs + ballons[i];
        else
            cs = cs + ballons[l] * ballons[r];

        if (cs > ans)
            ans = cs;
    }
    return ans;
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> ballons[i];
    }
    ballons[0] = 1;
    ballons[n + 1] = 1;
    cout << solve(0, n + 1, n + 1) << endl;
    return 0;
}
