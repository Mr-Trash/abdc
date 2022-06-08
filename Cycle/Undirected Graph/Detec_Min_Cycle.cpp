/// Detect minimum cycle in all possible cycle in Undirected graph
#include<iostream>
using namespace std;

int n, e;
int visited[100];
int grid[100][100];
int startAt = -1;
int path[100];
int cnt = 0;
int sum=0;

vector<int> ans;
int mn_cycle = 1000000000;

void initcase()
{
    for (int i = 0; i <= n; i++)
    {
        visited[i] = 0;
    }
}

void isCycle(int u, int parent)
{

    visited[u] = 1;
    path[cnt++] = u;

    for (int i = 0; i <= n; i++)
    {
        if (grid[u][i] && !visited[i])
        {
            isCycle(i, u);
        }

        if(grid[u][i] && visited[i] && i!=parent)
        {
            cout << "\nCycle:\n";
            bool flg = false;

            vector<int> tmp;

            for(int j = 0; j < cnt; j++) {
                if(path[j] == i) flg = true;
                if(flg) tmp.push_back(path[j]);
            }

            int sum = 0;
            for(int j = 1; j < tmp.size(); j++) {
                cout << tmp[j] << " -> ";
                sum += grid[tmp[j-1]][tmp[j]];
            }
            cout << tmp[0] << " : " << sum << "\n";

            if(sum < mn_cycle) {
                mn_cycle = sum;
                ans = tmp;
            }
        }
    }

    visited[u] = 0;
    cnt--;
}

bool solve()
{
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            isCycle(i, -1);
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
        int a, b, c;
        cin >> a >> b >> c;
        grid[a][b] = c;
        grid[b][a] = c;
    }

    solve();


    cout << "\n========================================\nMIN Cycle: \n";
    for(auto i : ans) cout << i << " -> ";
    cout << ans[0] << " : " << mn_cycle << "\n========================================\n";
}
