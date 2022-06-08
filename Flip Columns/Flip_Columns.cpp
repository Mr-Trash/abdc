#include<iostream>
using namespace std;

int n, l, k, ans, test,cnt=1;
int bit[110][110];
int zero[110];
int value[110];
int freq[110];




void solvecase()
{
    int i, j;
    ans = 0;
    for (i = 0; i < n; i++)
    {
        value[i] = zero[i] = 0;
        for (j = 0; j < l; j++)
        {
            value[i] = (value[i] << 1) + bit[i][j];
            if (bit[i][j] == 0)
                zero[i]++;
        }
        for (j = i - 1; j >= 0; j--)
        {
            if (value[i] == value[j])
            {
                freq[i] = freq[j] + 1;
                break;
            }
        }

        if (j < 0)
            freq[i] = 1;
        if (zero[i] <= k && (zero[i] - k) % 2 == 0 && freq[i] > ans)
        {
            ans = freq[i];
        }
    }

    cout<<"#"<<cnt++<<" "<<ans << endl;
}

int main()
{
    cin>>test;
    while(test--)
    {
        cin >> n >> l >> k;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < l; j++)
            {
                cin >> bit[i][j];
            }
        }
        solvecase();
    }
}
