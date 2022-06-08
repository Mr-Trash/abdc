/*
	A Research team want to establish a research center in a region where they found some rare-elements.
	They want to make it closest to all the rare-elements as close as possible so that they can reduce
	overall cost of research over there. It is given that all the rare-element’s location is connected
	by roads. It is also given that Research Center can only be build on road. Team decided to assign
	this task to a coder. If you feel you have that much potential.

	Here is the Task :- Find the shortest of the longest distance of research center from given locations
	of rare-elements.

	Locations are given in the matrix cell form where 1 represents roads and 0 no road.
	Number of rare-element and their location was also given(number<=5) and order of square matrix
	was less than equal to (20).
Constraints:
• n<=20 (n is the grid size of the square matrix, row and column numbering starts from 1)
• c<=4 (c Is the rare earth element number in the grid)
• You can only move to cells to your left, right, top and bottom.
Input:
The first line will take the input of the number of test cases, say T.
The next line will take the value of “n” then the value for “c”. Next “c” lines will contain the position of the rare earth elements. The next “n” lines will contain the grid. This will follow for all the test cases
Output:
Find the shortest of the longest distance of the research center from given locations of rare-elements. Locations are given in the matrix cell form where 1 represents roads and 0 no road.
*/
#include <iostream>
using namespace std;
int n, c, test;
int lab[10][2];
int grid[50][50];
int rear = -1, front = -1;
int visited[50][50];

struct rareElements
{
    int row, col;
};
rareElements queue[100];

void enqueue(int x, int y)
{
    rear++;
    queue[rear].row = x;
    queue[rear].col = y;
}

void dequeue()
{
    front++;
}

void initcase()
{
    for (int i = 0; i < 50; i++)
    {
        for (int j = 0; j < 50; j++)
            visited[i][j] = 0;
    }
    front = -1, rear = -1;
    for (int i = 0; i < 100; i++)
    {
        queue[i].row = 0;
        queue[i].col = 0;
    }
}

void solve(int row, int col, int value)
{
    int cnt = 0;
    for (int i = 0; i < c; i++)
    {
        if (visited[lab[i][0]][lab[i][1]] > 0)
            cnt++;
    }
    if (cnt >= c)
        return;
    if (row - 1 >= 1 && visited[row - 1][col] == 0 && (grid[row - 1][col] == 1 || grid[row - 1][col] == 3))
    {
        enqueue(row - 1, col);
        visited[row - 1][col] = value + 1;
    }
    if (row + 1 <= n && visited[row + 1][col] == 0 && (grid[row + 1][col] == 1 || grid[row + 1][col] == 3))
    {
        enqueue(row + 1, col);
        visited[row + 1][col] = value + 1;
    }
    if (col - 1 >= 1 && visited[row][col - 1] == 0 && (grid[row][col - 1] == 1 || grid[row][col - 1] == 3))
    {
        enqueue(row, col - 1);
        visited[row][col - 1] = value + 1;
    }
    if (col + 1 <= n && visited[row][col + 1] == 0 && (grid[row][col + 1] == 1 || grid[row][col + 1] == 3))
    {
        enqueue(row, col + 1);
        visited[row][col + 1] = value + 1;
    }
    while (front < rear)
    {
        dequeue();
        solve(queue[front].row, queue[front].col, visited[queue[front].row][queue[front].col]);
    }
}

int main()
{
    cin >> test;
    int cnt = 1;
    while (test--)
    {
        cin >> n >> c;
        for (int i = 0; i < c; i++)
        {
            int x, y;
            cin >> x >> y;
            lab[i][0] = x;
            lab[i][1] = y;
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
                cin >> grid[i][j];
        }
        for (int i = 0; i < c; i++)
        {
            grid[lab[i][0]][lab[i][1]] = 3;
        }
        int ans = 99999;
        initcase();

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                initcase();
                int temp = 0;
                if (grid[i][j] == 1)
                {
                    visited[i][j] = 1;
                    solve(i, j, 1);
                    for (int i = 0; i < c; i++)
                    {
                        if (temp < visited[lab[i][0]][lab[i][1]])
                            temp = visited[lab[i][0]][lab[i][1]];
                    }
                    if (ans > temp)
                        ans = temp;
                }
            }
        }
        cout << "#" << cnt << " " << ans - 1 << endl;
        cnt++;
    }

    return 0;
}
