#include <iostream>

using namespace std;

const int rest = 10007;
int D[1001] = {};

int f(int N)
{
    if (D[N])
        return D[N];

    return D[N] = (f(N - 1) + f(N - 2)) % rest;
}

int main()
{
    int N;
    cin >> N;
    D[1] = 1;
    D[2] = 2;
    cout << f(N) << '\n';
}
