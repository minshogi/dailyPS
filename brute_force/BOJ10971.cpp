#include <iostream>
#include <algorithm>

#define Min(a, b) (a > b ? b : a)

using namespace std;

int W[10][10] = {};
int N;
int cost(int *A)
{
    int ret = 0;
    int bef = A[N - 1], aft = A[0];
    ret += W[bef][aft];
    for (int i = 1; i < N; i++)
    {
        bef = A[i - 1];
        aft = A[i];
        ret += W[bef][aft];
    }
    return ret;
}

bool cango(int *A)
{
    int bef = A[N - 1], aft = A[0];
    if (W[bef][aft] == 0)
        return false;
    for (int i = 1; i < N; i++)
    {
        bef = A[i - 1];
        aft = A[i];
        if (W[bef][aft] == 0)
            return false;
    }
    return true;
}
int main()
{
    cin >> N;
    int A[N];
    for (int i = 0; i < N; i++)
    {
        A[i] = i;
        for (int j = 0; j < N; j++)
        {
            cin >> W[i][j];
        }
    }

    int min = 987654321;
    do
    {
        if (cango(A))
        {
            int tmp = cost(A);
            min = Min(tmp, min);
        }

    } while (next_permutation(A + 1, A + N));

    cout << min << '\n';
}