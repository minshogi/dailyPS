#include <iostream>

using namespace std;

int D[1001] = {};
int P[1001] = {};
int f(int N)
{
    int &ret = D[N];
    if (ret)
        return ret;

    ret = P[N];
    for (int i = 0; i < N; i++)
    {
        ret = min(ret, f(N - i) + P[i]);
    }
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> P[i];
    D[1] = P[1];
    cout << f(N) << '\n';
}