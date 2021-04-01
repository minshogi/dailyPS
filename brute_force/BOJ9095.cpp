#include <iostream>

using namespace std;

int d[12] = {0};

int f(int g)
{
    if (g < 0)
        return 0;
    if (d[g])
        return d[g];
    int &ret = d[g];
    ret = f(g - 1) + f(g - 2) + f(g - 3);
    return ret;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    d[0] = 1;
    int T;
    cin >> T;
    while (T--)
    {
        int N;
        cin >> N;
        int ans = f(N);
        cout << ans << '\n';
    }
}