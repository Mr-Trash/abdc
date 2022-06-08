/* Try Uva Biocoloring Problem.
Given a graph print either of the set of the vertices that are colored with the same color. And if the graph
is not bipartite print “-1”. Test cases also included the cases when a graph is not connected.
*/

#include <iostream>
using namespace std;
int n, e;
int grid[202][202];
int queue[202];
int front = 0, rear = 0;
int visited[202];
int color[202];
int bipartite;

void initcase()
{
    front = 0, rear = 0, bipartite = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            grid[i][j] = 0;
    }
    for (int i = 0; i < n; i++)
        visited[i] = 0;
}

void enqueue(int val)
{
    queue[rear] = val;
    rear++;
}

int dequeue()
{
    int element = queue[front];
    front++;
    return element;
}

void bfs(int start)
{
    enqueue(start);
    visited[start] = 1;
    color[start] = 0;
    while (front < rear)
    {
        int value = dequeue();
        // cout << value << " ";
        for (int i = 0; i < n; i++)
        {
            if (grid[value][i] == 1)
            {
                if (visited[i] == 0)
                {
                    enqueue(i);
                    visited[i] = 1;
                    color[i] = 1 - color[value];
                }
                else
                {
                    if (color[i] == color[value])
                    {
                        bipartite = 1;
                        break;
                    }
                }
            }
        }
    }
}

void solve()
{
    for (int i = 0; i < n; i++)
    {
        if (visited[i] == 0)
        {
            bfs(i);
            if (bipartite == 1)
                break;
        }
    }
}

int main()
{
    while (1)
    {
        cin >> n;
        if (n == 0)
            break;
        cin >> e;
        initcase();
        for (int i = 0; i < e; i++)
        {
            int x, y;
            cin >> x >> y;
            grid[x][y] = 1;
            grid[y][x] = 1;
        }
        solve();

        if (bipartite == 1)
        {
            // cout << "NOT BICOLORABLE.\n";
            cout << -1 << endl;
        }
        else
        {
            {
                for (int i = 0; i < n; i++)
                {
                    if (color[i] == 0)
                    {
                        cout << i << " ";
                    }
                }
                cout << endl;
            }
        }
    }

    return 0;
}
