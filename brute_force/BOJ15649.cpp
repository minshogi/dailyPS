#include <iostream>
#include <vector>

using namespace std;

int chosen[10] = {0};
int series[10] = {0};

void go(int index, int N, int M)
{
    if (index == M)
    {
        for (int i = 0; i < M; i++)
            cout << series[i] << ' ';
        cout << '\n';
        return;
    }
    for (int i = 1; i <= N; i++)
    {
        if (!chosen[i])
        {
            chosen[i] = 1;
            series[index] = i;
            go(index + 1, N, M);
            chosen[i] = 0;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    go(0, N, M);
}