#include <iostream>

using namespace std;

int T[15], P[15], N;

int go(int index, int pay)
{
    if (index == N)
        return pay;

    int ret = 0;
    if (index + T[index] <= N)
        ret = go(index + T[index], pay + P[index]);
    int tmp = go(index + 1, pay);
    ret = ret > tmp ? ret : tmp;

    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> T[i] >> P[i];
    }

    cout << go(0, 0) << '\n';
}