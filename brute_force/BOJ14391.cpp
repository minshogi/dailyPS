#include <iostream>
#include <string>

using namespace std;

int R, C;

int sum(int idx, int **A)
{
    int ret = 0;
    for (int r = 0; r < R; r++)
    {
        int tmp = 0;
        for (int c = 0; c < C; c++)
        {
            if (idx & (1 << (r * C + c))) //idx 1인 경우 가로로 더하기
            {
                tmp = tmp * 10 + A[r][c];
            }
            else
            {
                ret += tmp;
                tmp = 0;
            }
        }
        ret += tmp;
    }
    for (int c = 0; c < C; c++)
    {
        int tmp = 0;
        for (int r = 0; r < R; r++)
        {
            if ((idx & (1 << (r * C + c))) == 0) //idx 0인 경우 세로로 더하기
            {
                tmp = tmp * 10 + A[r][c];
            }
            else
            {
                ret += tmp;
                tmp = 0;
            }
        }
        ret += tmp;
    }
    return ret;
}

int paper(int **A)
{
    int ret = -1;
    for (int idx = 0; idx < (1 << (R * C)); idx++)
    {
        int tmp = sum(idx, A);
        ret = ret > tmp ? ret : tmp;
    }
    return ret;
}

int main()
{
    cin >> R >> C;
    int **A;
    A = new int *[R];
    for (int r = 0; r < R; r++)
    {
        string x;
        cin >> x;
        A[r] = new int[C];
        for (int c = 0; c < C; c++)
        {
            A[r][c] = x[c] - '0';
        }
    }

    cout << paper(A) << '\n';
}