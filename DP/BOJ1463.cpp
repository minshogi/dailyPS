#include <iostream>
#include <algorithm>

using namespace std;

int D[1000001] = {};

int mk1(int N)
{
    if (N == 1 || D[N])
        return D[N];
    int &ret = D[N];
    ret = mk1(N - 1) + 1;
    if (N % 3 == 0)
        ret = min(ret, mk1(N / 3) + 1);
    if (N % 2 == 0)
        ret = min(ret, mk1(N / 2) + 1);

    return ret;
}

int main()
{

    int N;
    cin >> N;
    cout << mk1(N) << '\n';
}