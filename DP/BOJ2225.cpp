#include <iostream>

using namespace std;

const long mod = 1e9;

long D[201][201] = {};

long go(int N, int K)
{
    if(N==0 || K ==1)
        return 1;
    long &ret = D[N][K];
    if(ret)
        return ret;

    ret = 0;
    for (int i = 0; i <= N; i++)
    {
        ret = (ret + go(N - i, K - 1))%mod;
    }
    return ret;
}

int main()
{
    int N, K;
    cin >> N >> K;
    cout << go(N, K) << '\n';
}