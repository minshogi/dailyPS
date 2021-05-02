#include <iostream>

using namespace std;

int D[2][3];
const int mod = 9901;

int main()
{
    int N;
    cin >> N;
    D[0][0] = D[0][1] = D[0][2] = 1;

    for (int i = 1; i < N;i++)
    {
        int now = i%2, bef = (i - 1) % 2;
        D[now][0] = (D[bef][0] + D[bef][1] + D[bef][2])%mod;
        D[now][1] = (D[bef][0] + D[bef][2])%mod;
        D[now][2] = (D[bef][0] + D[bef][1])%mod;
    }

    int a = (N - 1) % 2;
    int ans = (D[a][0] + D[a][1] + D[a][2])%mod;
    cout << ans << '\n';
}