#include <iostream>

using namespace std;

int A[1001];
int N;
int D[1001] = {};

int f(int k)
{
    int &ret = D[k];
    if (ret)
        return ret;

    ret = 1;
    for (int i = k + 1; i < N; i++)
    {
        if (A[i] > A[k])
            ret = max(ret, f(i) + 1);
    }
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }
    D[N - 1] = 1;
    int ans = 1;
    for (int i = 0; i < N; i++)
        ans = max(ans, f(i));
    cout << ans << '\n';
}