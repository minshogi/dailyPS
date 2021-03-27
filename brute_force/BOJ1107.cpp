#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
const int MAX = 1e6;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<bool> cannotUse(10, 0);
    int N, M;
    cin >> N >> M;

    for (int i = 0; i < M; i++)
    {
        int x;
        cin >> x;
        cannotUse[x] = 1;
    }

    int ans = abs(N - 100);
    if (!cannotUse[0])
        ans = ans < N + 1 ? ans : N + 1;

    for (int i = 1; i < MAX; i++)
    {
        int move = 0;
        bool flag = 1;
        for (int j = 1; j <= i && flag; j *= 10)
        {
            int now = (i % (j * 10)) / j;
            move++;
            if (cannotUse[now])
                flag = 0;
        }
        if (flag)
        {
            int tmp = move + abs(i - N);
            ans = ans < tmp ? ans : tmp;
        }
    }

    cout << ans << '\n';
}