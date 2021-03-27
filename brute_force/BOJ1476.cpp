#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int E, S, M;
    cin >> E >> S >> M;
    int years[15][28][19] = {0};
    for (int i = 0; i < 15 * 28 * 19; i++)
    {
        years[i % 15][i % 28][i % 19] = i;
    }
    cout << years[E - 1][S - 1][M - 1] + 1 << '\n';
}