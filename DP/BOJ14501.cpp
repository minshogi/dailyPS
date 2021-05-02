#include <iostream>
using namespace std;

const int INF = 987654321;
int N;
int T[15], P[15], D[15];

int go(int k)
{
    if(k>N)
        return -INF;
    if(k==N)
        return 0;

    int &ret = D[k];
    if(ret != -1)
        return ret;
    ret = max(go(k + 1), go(k + T[k]) + P[k]);
    return ret;
}

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> T[i] >> P[i];
        D[i] = -1;
    }

    cout << go(0) << '\n';
}