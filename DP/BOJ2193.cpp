#include <iostream>

using namespace std;

long D[2][91] = {};

long f(int start, int len)
{
    if (len == 1)
        return 1;

    long &ret = D[start][len];
    if (ret)
        return ret;

    ret = f(0, len - 1);
    if (start == 0)
        ret += f(1, len - 1);
    return ret;
}

int main()
{
    int N;
    cin >> N;
    cout << f(1, N) << '\n';
}