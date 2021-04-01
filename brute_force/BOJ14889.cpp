#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

const int Max = 987654321;
int synergy[20][20] = {0};
int N;

int calc(int Ateam)
{

    vector<int> A, B;
    int asum = 0, bsum = 0;
    for (int i = 0; i < N; i++)
    {
        if (Ateam & (1 << i))
            A.push_back(i);
        else
            B.push_back(i);
    }

    for (int x : A)
    {
        for (int y : A)
            asum += synergy[x][y];
    }
    for (int x : B)
    {
        for (int y : B)
            bsum += synergy[x][y];
    }

    return abs(bsum - asum);
}

int go(int idx, int Ateam)
{
    if (idx == N)
        return calc(Ateam);

    return min(go(idx + 1, Ateam | (1 << idx)), go(idx + 1, Ateam));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> synergy[i][j];
        }
    }

    cout << go(0, 0) << '\n';
}