#include <iostream>

using namespace std;

int A[1000], N, D[1000] = {}, P[1000] = {};

int f(int k)
{
    int &ret = D[k];
    if (ret)
        return ret;

    ret = 1;
    for (int i = 0; i < k; i++)
    {
        if (A[i] < A[k])
        {
            if (ret < f(i) + 1)
            {
                ret = f(i) + 1;
                P[k] = i;
            }
        }
    }

    return ret;
}

void printSeries(int last)
{
    if(last == -1)
        return;
    printSeries(P[last]);
    cout << A[last] << ' ';

}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
        P[i] = -1;
    }

    int last, ans = 0;
    

    for (int i = 0; i < N; i++)
    {
        if (ans < f(i))
        {
            ans = D[i];
            last = i;
        }
    }

    cout << ans << '\n';
    printSeries(last);
}