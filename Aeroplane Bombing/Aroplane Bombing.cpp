#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

int test, row;
int playGround[50][50];
int answer;

int Max(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}

void getMaxCoins(int current_row, int current_col, bool bombUsed, int coins, int isRowSafe)
{
    if (current_row < 0 || current_col < 0 || current_col >= 5)
    {
        answer = Max(answer, coins);
        return;
    }
    if (playGround[current_row][current_col] == 1 || playGround[current_row][current_col] == 0)
    {
        int new_coins = coins;
        if (playGround[current_row][current_col] == 1)
        {
            new_coins++;
        }
        if (bombUsed)
            isRowSafe--;
        getMaxCoins(current_row - 1, current_col, bombUsed, new_coins, isRowSafe);
        getMaxCoins(current_row - 1, current_col - 1, bombUsed, new_coins, isRowSafe);
        getMaxCoins(current_row - 1, current_col + 1, bombUsed, new_coins, isRowSafe);
    }
    else
    {
        if (bombUsed && isRowSafe <= 0)
        {
            answer = Max(answer, coins);
            return;
        }
        else if (bombUsed && isRowSafe > 0)
        {
            isRowSafe--;
            getMaxCoins(current_row - 1, current_col, bombUsed, coins, isRowSafe);
            getMaxCoins(current_row - 1, current_col - 1, bombUsed, coins, isRowSafe);
            getMaxCoins(current_row - 1, current_col + 1, bombUsed, coins, isRowSafe);
        }
        else
        {
            bombUsed = true;
            isRowSafe = 4;
            getMaxCoins(current_row - 1, current_col, bombUsed, coins, isRowSafe);
            getMaxCoins(current_row - 1, current_col - 1, bombUsed, coins, isRowSafe);
            getMaxCoins(current_row - 1, current_col + 1, bombUsed, coins, isRowSafe);
        }
    }
}

int main()
{
    //freopen("input.txt", "r", stdin);
    int cnt = 1;
    cin >> test;
    while (test--)
    {
        cin >> row;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                cin >> playGround[i][j];
            }
        }
        answer = 0;
        int isRowSafe = 0;

        getMaxCoins(row - 1, 1, false, 0, 0);
        getMaxCoins(row - 1, 2, false, 0, 0);
        getMaxCoins(row - 1, 3, false, 0, 0);
        cout << "#" << cnt++ << " " << answer << endl;
    }
    return 0;
}
