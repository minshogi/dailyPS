#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int nums[500][500] = {0};
    int N, M;
    cin >> N >> M;
    for (int r = 0; r < N; r++)
    {
        for (int c = 0; c < M; c++)
        {
            cin >> nums[r][c];
        }
    }

    int ans = 0;
    for (int r = 0; r < N; r++)
    {
        for (int c = 0; c < M; c++)
        {
            if (c + 3 < M)
            {
                int tmp = nums[r][c] + nums[r][c + 1] + nums[r][c + 2] + nums[r][c + 3];
                ans = ans > tmp ? ans : tmp;
            }
            if (r + 3 < N)
            {
                int tmp = nums[r][c] + nums[r + 1][c] + nums[r + 2][c] + nums[r + 3][c];
                ans = ans > tmp ? ans : tmp;
            }
            if (r + 1 < N && c + 1 < M)
            {
                int tmp = nums[r][c] + nums[r + 1][c] + nums[r][c + 1] + nums[r + 1][c + 1];
                ans = ans > tmp ? ans : tmp;
            }
            if (r + 2 < N && c + 1 < M)
            {
                int tmp = nums[r][c] + nums[r + 1][c] + nums[r + 2][c] + nums[r + 2][c + 1];
                ans = ans > tmp ? ans : tmp;
            }
            if (r + 1 < N && c + 2 < M)
            {
                int tmp = nums[r][c] + nums[r + 1][c] + nums[r][c + 1] + nums[r][c + 2];
                ans = ans > tmp ? ans : tmp;
            }
            if (r + 2 < N && c + 1 < M)
            {
                int tmp = nums[r][c] + nums[r][c + 1] + nums[r + 1][c + 1] + nums[r + 2][c + 1];
                ans = ans > tmp ? ans : tmp;
            }
            if (r + 1 < N && c + 2 < M)
            {
                int tmp = nums[r + 1][c] + nums[r + 1][c + 1] + nums[r + 1][c + 2] + nums[r][c + 2];
                ans = ans > tmp ? ans : tmp;
            }
            if (r + 2 < N && c + 1 < M)
            {
                int tmp = nums[r + 2][c] + nums[r][c + 1] + nums[r + 1][c + 1] + nums[r + 2][c + 1];
                ans = ans > tmp ? ans : tmp;
            }
            if (r + 1 < N && c + 2 < M)
            {
                int tmp = nums[r][c] + nums[r + 1][c] + nums[r + 1][c + 1] + nums[r + 1][c + 2];
                ans = ans > tmp ? ans : tmp;
            }
            if (r + 2 < N && c + 1 < M)
            {
                int tmp = nums[r][c] + nums[r + 1][c] + nums[r + 2][c] + nums[r][c + 1];
                ans = ans > tmp ? ans : tmp;
            }
            if (r + 1 < N && c + 2 < M)
            {
                int tmp = nums[r][c] + nums[r][c + 1] + nums[r][c + 2] + nums[r + 1][c + 2];
                ans = ans > tmp ? ans : tmp;
            }
            if (r + 2 < N && c + 1 < M)
            {
                int tmp = nums[r][c] + nums[r + 1][c] + nums[r + 1][c + 1] + nums[r + 2][c + 1];
                ans = ans > tmp ? ans : tmp;
            }
            if (r + 1 < N && c + 2 < M)
            {
                int tmp = nums[r + 1][c] + nums[r + 1][c + 1] + nums[r][c + 1] + nums[r][c + 2];
                ans = ans > tmp ? ans : tmp;
            }
            if (r + 2 < N && c + 1 < M)
            {
                int tmp = nums[r + 1][c] + nums[r + 2][c] + nums[r][c + 1] + nums[r + 1][c + 1];
                ans = ans > tmp ? ans : tmp;
            }
            if (r + 1 < N && c + 2 < M)
            {
                int tmp = nums[r][c] + nums[r][c + 1] + nums[r + 1][c + 1] + nums[r + 1][c + 2];
                ans = ans > tmp ? ans : tmp;
            }
            if (r + 1 < N && c + 2 < M)
            {
                int tmp = nums[r][c] + nums[r][c + 1] + nums[r][c + 2] + nums[r + 1][c + 1];
                ans = ans > tmp ? ans : tmp;
            }
            if (r + 2 < N && c + 1 < M)
            {
                int tmp = nums[r][c] + nums[r + 1][c] + nums[r + 2][c] + nums[r + 1][c + 1];
                ans = ans > tmp ? ans : tmp;
            }
            if (r + 1 < N && c + 2 < M)
            {
                int tmp = nums[r + 1][c] + nums[r][c + 1] + nums[r + 1][c + 1] + nums[r + 1][c + 2];
                ans = ans > tmp ? ans : tmp;
            }
            if (r + 2 < N && c + 1 < M)
            {
                int tmp = nums[r][c + 1] + nums[r + 1][c] + nums[r + 1][c + 1] + nums[r + 2][c + 1];
                ans = ans > tmp ? ans : tmp;
            }
        }
    }
    cout << ans << '\n';
}