#include <iostream>
#include <vector>

using namespace std;

char S[10][10] = {};
int N;
bool isend = 0;
char op(int x)
{
    if (x == 0)
        return '0';
    else if (x > 0)
        return '+';
    else
        return '-';
}

bool check(int idx, vector<int> &sum, int next)
{
    for (int i = 0; i <= idx; i++)
    {
        if (op(sum[i] + next) != S[i][idx])
            return false;
    }
    return true;
}

void Btrack(int idx, vector<int> &ans, vector<int> &sum)
{
    if (isend)
        return;

    if (idx == N)
    {
        for (int x : ans)
            cout << x << ' ';
        cout << '\n';
        isend = true;
    }

    int bottom, up;
    char op = S[idx][idx];
    if (op == '0')
    {
        bottom = up = 0;
    }
    else if (op == '-')
    {
        bottom = -10;
        up = -1;
    }
    else
    {
        bottom = 1;
        up = 10;
    }

    for (int nxt = bottom; nxt <= up; nxt++)
    {
        if (check(idx, sum, nxt))
        {
            for (int i = 0; i <= idx; i++)
                sum[i] += nxt;
            ans.push_back(nxt);
            Btrack(idx + 1, ans, sum);
            ans.pop_back();
            for (int i = 0; i <= idx; i++)
                sum[i] -= nxt;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        for (int j = i; j < N; j++)
        {
            cin >> S[i][j];
        }
    }
    vector<int> ans, sum(10, 0);
    Btrack(0, ans, sum);
}