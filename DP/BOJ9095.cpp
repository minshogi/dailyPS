#include <iostream>

using namespace std;

int D[12] = {0};

int f(int N)
{
    if (N < 0)
        return 0;
    if (D[N])
        return D[N];
    return D[N] = f(N - 1) + f(N - 2) + f(N - 3);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    D[0] = 1;

    int T;
    cin >> T;
    while (T--)
    {
        int N;
        cin >> N;
        cout << f(N) << '\n';
    }
}