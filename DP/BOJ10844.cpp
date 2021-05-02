#include <iostream>

using namespace std;

const long rest = 1000000000;
long D[10][101];
long f(int start, int len)
{

    if (!(0 <= start && start <= 9))
        return 0;
    if (len == 1)
        return 1;

    long &ret = D[start][len];
    if (ret)
        return ret;

    return ret = (f(start + 1, len - 1) + f(start - 1, len - 1)) % rest;
}

int main()
{
    int N;
    cin >> N;
    long ans = 0;
    for (int i = 1; i <= 9; i++)
    {
        ans = (ans + f(i, N)) % rest;
    }
    cout << ans << '\n';
}