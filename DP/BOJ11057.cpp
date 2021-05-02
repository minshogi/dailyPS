#include <iostream>

using namespace std;

const int mod = 10007;
int D[2][10];

int main()
{
    int N;
    cin >> N;

    for (int i = 0; i < 10; i++)
        D[0][i] = 1;

    for (int i = 1; i < N; i++)
    {
        int now = i % 2, bef = (i - 1) % 2;
        for (int j = 0; j < 10; j++)
        {
            int sum = 0;
            for (int k = 0; k <= j; k++)
            {
                sum += D[bef][k];
            }
            D[now][j] = sum % mod;
        }
    }

    int ans = 0;
    for (int i = 0; i < 10; i++)
    {
        ans += D[(N - 1) % 2][i];
    }
    ans %= mod;
    cout << ans << '\n';
}