#include <iostream>

using namespace std;

const long long rest = 1000000009;

long long D[100001][4] = {};

long long f(int N, int l)
{
    if (N >= 1 && N <= 3)
        return D[N][l];
    if (D[N][l])
        return D[N][l];
    long long &ret = D[N][l];

    if (l == 0)
    {
        ret = f(N, 1) + f(N, 2) + f(N, 3);
    }
    else if (l == 1)
    {
        ret = f(N - 1, 2) + f(N - 1, 3);
    }
    else if (l == 2)
    {
        ret = f(N - 2, 1) + f(N - 2, 3);
    }
    else
    {
        ret = f(N - 3, 1) + f(N - 3, 2);
    }

    return ret % rest;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    D[1][1] = 1;
    D[2][2] = 1;
    D[3][1] = 1;
    D[3][2] = 1;
    D[3][3] = 1;
    D[1][0] = 1;
    D[2][0] = 1;
    D[3][0] = 3;
    while (T--)
    {
        int N;
        cin >> N;
        cout << f(N, 0) << '\n';
    }
}
