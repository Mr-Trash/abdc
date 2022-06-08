#include<iostream>
using namespace std;

int grid[1005][1005];
int visited[1005][1005];
int nodeDist[1005][1005];
long long n, m, startX, startY, length, rear, front, ans;

int Up[8] = { 0,1,1,0,1,0,0,1 };
int Down[8] = { 0,1,1,0,0,1,1,0 };
int Left[8] = { 0,1,0,1,0,0,1,1 };
int Right[8] = { 0,1,0,1,1,1,0,0 };

struct endoscope
{
    int x, y;
};
endoscope queue[1000005];

void enqueue(int x, int y)
{
    queue[rear].x = x;
    queue[rear].y = y;
    rear++;
}

endoscope dequeue()
{
    endoscope element = queue[front];
    front++;
    return element;
}

void initcase()
{
    rear = 0, front = 0, ans = 0;
    for (int i = 0; i < 1005; i++)
    {
        for (int j = 0; j < 1005; j++)
        {
            visited[i][j] = 0;
            nodeDist[i][j] = 0;
        }
    }
}

int main()
{
    int test;
    cin >> test;
    while (test--)
    {
        cin >> n >> m >> startX >> startY >> length;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> grid[i][j];
            }
        }
        initcase();
        if (grid[startX][startY] != 0)
        {
            visited[startX][startY] = 1;
            nodeDist[startX][startY] = 1;
            enqueue(startX, startY);

        }
        while (front < rear)
        {
            endoscope element = dequeue();
            int x = element.x;
            int y = element.y;
            ans++;
            long long dist = nodeDist[x][y] + 1;
            if (dist > length)
                continue;
            if (x - 1 >= 0 && Up[grid[x][y]] == 1 && Down[grid[x - 1][y]] == 1 && visited[x - 1][y] == 0)
            {
                visited[x - 1][y] = 1;
                nodeDist[x - 1][y] = dist;
                enqueue(x - 1, y);
            }
            if (x + 1 < n && Down[grid[x][y]] == 1 && Up[grid[x + 1][y]] == 1 && visited[x + 1][y] == 0)
            {
                visited[x + 1][y] = 1;
                nodeDist[x + 1][y] = dist;
                enqueue(x + 1, y);
            }
            if (y - 1 >= 0 && Left[grid[x][y]] == 1 && Right[grid[x][y - 1]] == 1 && visited[x][y - 1] == 0)
            {
                visited[x][y - 1] = 1;
                nodeDist[x][y - 1] = dist;
                enqueue(x, y - 1);
            }
            if (y + 1 < m && Right[grid[x][y]] == 1 && Left[grid[x][y + 1]] == 1 && visited[x][y + 1] == 0)
            {
                visited[x][y + 1] = 1;
                nodeDist[x][y + 1] = dist;
                enqueue(x, y + 1);
            }
        }
        cout << ans << endl;
    }
    return 0;
}
