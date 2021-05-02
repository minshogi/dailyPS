#include <iostream>

using namespace std;

const long mod = 1e9 + 9;

long D[1000001]={};

void f(int k)
{
    D[0] = 1;
    D[1] = 1;
    D[2] = 2;
    for (int i = 3; i <= k; i++)
    {
        D[i] = (D[i-1] + D[i - 2] + D[i-3]) % mod;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    f(1000000);

    int T;
    cin >> T;
    while (T--)
    {
        int N;
        cin >> N;
        cout << D[N] << '\n';
    }
}