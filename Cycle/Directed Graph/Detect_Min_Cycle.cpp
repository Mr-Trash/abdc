/// All possible cycle detect and find print the minimum cycle with path.
#include<iostream>
using namespace std;

int n, e;
int grid[105][105], visited[105];
int cycle, cnt, tnt, flag;
int store[105], ans[105];
int res = 9999;
int path[105];

void initcase()
{
	cycle = 0, cnt = 0, tnt = 0, flag = 0;

	for (int i = 0; i < 105; i++)
	{
		for (int j = 0; j < 105; j++)
		{
			grid[i][j] = 0;
		}
	}
}

void dfs(int u)
{
	visited[u] = 1;
	store[cnt++] = u;
	for (int i = 0; i <= n; i++)
	{
		if (grid[u][i])
		{
			if (visited[i] == 1)
			{
				cycle = 1;
				flag = 0;
				int sum = 0;
				for (int j = 0; j < cnt; j++)
				{
					if (store[j] == i)
						flag = 1;
					if (flag)
					{
						//cout << store[j] << "->";
						sum += store[j];
					}
				}
				//cout << endl;
				//cout << sum<<" "<<res << endl;
				flag = 0;
				if (sum < res)
				{
					tnt = 0;
					//cout << "Ok" << endl;
					for (int j = 0; j < cnt; j++)
					{
						if (store[j] == i)
							flag = 1;
						if (flag)
						{
							//	cout << store[j] << "ok ";
							ans[tnt++] = store[j];
						}

					}
					//cout << endl;
					res = sum;
				}

			}
			else if (visited[i] == 0)
				dfs(i);
		}
	}
	visited[u] = 0;
	cnt--;
}

void solve()
{
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j < n; j++)
			visited[j] = 0;
		dfs(i);
	}
}

int main()
{
	int test;
	cin >> test;
	while (test--)
	{
		initcase();
		cin >> n >> e;
		for (int i = 0; i < e; i++)
		{
			int a, b;
			cin >> a >> b;
			grid[a][b] = 1;
		}
		solve();
		if (cycle)
		{
			cout << "Cycle" << endl;
			//cout << tnt << endl;
			for (int i = 0; i < tnt; i++)
			{
				cout << ans[i] << " ";
			}
			//cout<<endl;
		}
		else
			cout << "No Cycle" << endl;
	}
	return 0;
}

/*
10 11
0 1
1 2
2 3
3 4
4 6
6 2
6 7
4 5
5 8
8 9
9 5
*/
