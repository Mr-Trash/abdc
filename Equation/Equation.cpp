/*
Use Different type of log bases
X = A * N + B*log(N) + C*N*N*N
INTPUT A B C X
OUTPUT N
1 <= A <=100
1 <= B <=100
0 <= C <=100
0 <= X <=10^15
N must be integer
0 <= N <=10^13
*/
#include <iostream>
using namespace std;
long long a, b, c, x;
long long n;
int log(long long n)
{
    double d = (double)n;
    int value = 0;
    while (d >= 2.71828)
    {
        d = d / 2.71828;
        value++;
    }
    return value;
}
void solve()
{
    long long low = 0, mid, high, result;
    n = -1;
    if (c == 0)
        high = 10000000000000;
    else
        high = 100000;
    while (low <= high)
    {
        mid = (low + high) / 2;
        result = a * mid + b * log(mid) + c * mid * mid * mid;
        if (result > x)
            high = mid - 1;
        else if (result < x)
            low = mid + 1;
        else
        {
            n = mid;
            break;
        }
    }
}
int main()
{
    int test;
    cin >> test;
    while (test--)
    {
        cin >> a >> b >> c >> x;
        solve();
        cout << n << endl;
    }
}
