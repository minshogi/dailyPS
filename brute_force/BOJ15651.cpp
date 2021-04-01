#include <iostream>
#include <vector>

using namespace std;

int series[10] = {0};

void go(int index, int N, int M, int bef)
{
    if (index == M)
    {
        for (int i = 0; i < M; i++)
            cout << series[i] << ' ';
        cout << '\n';
        return;
    }
    for (int i = bef; i <= N; i++)
    {
        series[index] = i;
        go(index + 1, N, M, i);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    go(0, N, M, 1);
}