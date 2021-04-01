#include <iostream>

using namespace std;

const int MIN = -987654321;

int nums[10][10] = {0};
bool cant[10][10] = {0};
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};
int N, M, K;

bool check(int row, int col)
{
    if (cant[row][col])
        return false;
    for (int i = 0; i < 4; i++)
    {
        int nr = row + dr[i], nc = col + dc[i];
        if (nr >= 0 && nr < N && nc >= 0 && nc < M)
            if (cant[nr][nc])
                return false;
    }
    return true;
}

int go(int l, int d, int idx)
{
    if (idx == K)
        return d;
    if (l == N * M)
        return MIN;

    int row = l / M, col = l % M, ret = MIN + 1;
    if (check(row, col))
    {
        cant[row][col] = 1;
        ret = go(l + 1, d + nums[row][col], idx + 1);
        cant[row][col] = 0;
    }
    ret = max(ret, go(l + 1, d, idx));

    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M >> K;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> nums[i][j];
        }
    }

    cout << go(0, 0, 0) << '\n';
}
