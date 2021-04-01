#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int N, ans = 0, maxi = 0;
    cin >> N;

    for (int i = 0; pow(10, i) <= N / 10; i++)
    {
        ans += (i + 1) * 9 * pow(10, i);
        maxi++;
    }
    ans += (maxi + 1) * (N - pow(10, maxi) + 1);
    cout << ans << '\n';
}