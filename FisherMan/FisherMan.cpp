#include<iostream>
using namespace std;
#define INT_MAX 1000000000

int n;
int visited[20], fisherman[20], gates[20], permutation[20];
long long ans;

void initcase()
{
    for (int i = 0; i < 20; i++)
    {
        visited[i] = 0;
    }
    ans = INT_MAX;
}

int Abs(int a)
{
    if (a < 0)
        return -a;
    else
        return a;
}

void calculation()
{
    long long mini = 0;
    int j = 0;
    for (int i = 0; i < fisherman[0]; i++)
    {
        mini = mini + Abs(permutation[i] - gates[0]) + 1;
        j++;
    }
    for (int i = 0; i < fisherman[1]; i++)
    {
        mini = mini + Abs(permutation[j] - gates[1]) + 1;
        j++;
    }
    for (int i = 0; i < fisherman[2]; i++)
    {
        mini = mini + Abs(permutation[j] - gates[2]) + 1;
        j++;
    }
    if (mini < ans)
        ans = mini;
}

void solve(int i)
{
    if (i == n)
    {
        calculation();
        return;
    }
    for (int j = 1; j <= n; j++)
    {
        if (visited[j] == 0)
        {
            visited[j] = 1;
            permutation[i] = j;
            solve(i + 1);
            visited[j] = 0;
        }
    }

}

int main()
{
    cin >> n;
    initcase();
    for (int i = 0; i < 3; i++)
        cin >> gates[i];
    for (int i = 0; i < 3; i++)
        cin >> fisherman[i];
    solve(0);
    cout << ans << endl;
}
