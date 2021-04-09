#include <iostream>

using namespace std;

int sum(int *A, int idx, int N)
{
    int ret = 0;
    for (int i = 0; i < N; i++)
    {
        if (idx & (1 << i))
            ret += A[i];
    }
    return ret;
}

int ans(int *A, int N, int S)
{
    int ret = 0;
    for (int idx = 1; idx < (1 << N); idx++)
    {
        if (sum(A, idx, N) == S)
            ret++;
    }
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, S;
    cin >> N >> S;
    int nums[N];
    for (int i = 0; i < N; i++)
    {
        cin >> nums[i];
    }
    cout << ans(nums, N, S) << '\n';
}