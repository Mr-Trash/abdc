#include<iostream>
using namespace std;

int n, e;
int visited[100];
int grid[100][100];
int cycle;
int startAt;
int cnt;

void initcase()
{
	for (int i = 0; i < 100; i++)
		visited[i] = 0;
}

bool isCycle(int u, int parent)
{
	visited[u] = 1;
	for (int i = 0; i <= n; i++)
	{
		//cout << u << " -> " << i << endl;
		if (grid[u][i]==1)
		{
			if (visited[i] == 0)
			{
				if (isCycle(i, u))
					return true;
			}
			else if (visited[i]==1 && i!=parent)
			{
				return true;
			}
		}
	}
	return false;
}

bool solve()
{
	for (int i = 0; i < n; i++)
	{
		if (visited[i] == 0)
		{
			if (isCycle(i, -1))
			{
				return true;
			}

		}
	}
	return false;
}

int main()
{
	cin >> n >> e;
	initcase();
	for (int i = 0; i < e; i++)
	{
		int a, b;
		cin >> a >> b;
		grid[a][b] = 1;
		grid[b][a] = 1;
	}
	if (solve())
		cout << "True" << endl;
	else
		cout << "False" << endl;
}
