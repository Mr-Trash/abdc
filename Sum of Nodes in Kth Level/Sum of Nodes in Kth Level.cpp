#include<iostream>
using namespace std;

int n=0, k;
char tree[1001];
int level = -1;
int sum = 0;

void solve()
{
    for (int i = 0; i < n; i++)
    {
        if (tree[i] == '(')
            level++;
        else if (tree[i] == ')')
            level--;
        else
        {
            if (level == k)
            {
                int x = tree[i] - 48;
                i++;
                while (tree[i] >= 48 && tree[i] <= 57)
                {
                    int d = tree[i] - 48;
                    x = x * 10 + d;
                    i++;
                }
                sum += x;
                i--;
            }
        }
    }
}



int main()
{
    cin >> k;
    cin >> tree;
    n = sizeof(tree);
    solve();
    cout<<sum<<endl;

    return 0;
}
