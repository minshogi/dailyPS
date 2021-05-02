#include <iostream>

using namespace std;

int D[100001] = {};

int go(int N)
{
    if(N==0)
        return 0;

    int &ret = D[N];
    if(ret)
        return ret;

    ret = N;
    for (int i = 1; i * i <= N; i++)
    {
        ret = min(ret, go(N - i * i) + 1);
    }

    return ret;
}

int main()
{
    int N;
    cin >> N;
    cout << go(N) << '\n';
}