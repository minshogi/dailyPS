#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--)
    {
        int M, N, x, y;
        cin >> M >> N >> x >> y;

        int ans = -1;
        for (int i = 0; i <= N; i++)
        {
            if ((x - y + M * i) % N == 0)
            {
                ans = M * i + x;
                break;
            }
        }
        cout << ans << '\n';
    }
}