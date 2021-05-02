#include <iostream>

using namespace std;

int A[100000];
int D[100000]={};

int f(int target)
{
    if(target<0)
        return 0;

    int &ret = D[target];
    if(ret)
        return ret;

    return ret = max(f(target - 1) + A[target], A[target]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    for (int i = 0; i < N;i++)
    {
        cin >> A[i];
    }
    int ans = -1001;
    for (int i = 0; i < N;i++)
    {
        ans = max(ans, f(i));
    }
    cout << ans << '\n';
}