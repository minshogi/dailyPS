#include <iostream>

using namespace std;

int D[1001][3] = {};
int P[1001][3] = {};
int f(int k, int c)
{
    if(k==1)
        return P[k][c];

    int &ret = D[k][c];
    if(ret)
        return ret;
    return ret = P[k][c] + min(f(k - 1, (c + 1) % 3), f(k - 1, (c + 2) % 3));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    for (int i = 1; i <= N;i++)
    {
        for (int c = 0; c < 3; c++){
            cin >> P[i][c];
        }
    }

    int ans = min(f(N, 0), min(f(N, 1), f(N, 2)));
    cout << ans << '\n';
}