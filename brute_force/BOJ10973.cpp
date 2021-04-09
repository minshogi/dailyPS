#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> bef_p(vector<int> &P)
{
    vector<int> ret(P);

    auto begin = ret.begin();
    auto end = ret.end();
    auto now = end - 1;
    int bef = 987654321;
    while (now >= begin)
    {
        if (*now > bef)
        {
            break;
        }
        bef = *now;
        now--;
    }
    if (now < begin)
        return vector<int>(1, -1);

    int big = -1;
    vector<int>::iterator bigit;
    for (auto iter = now; iter != end; iter++)
    {
        if (*now > *iter && *iter > big)
        {
            big = *iter;
            bigit = iter;
        }
    }

    int tmp = *now;
    *now = *bigit;
    *bigit = tmp;
    sort(now + 1, end, greater<int>());
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<int> P(N);
    for (int i = 0; i < N; i++)
        cin >> P[i];

    vector<int> befP = bef_p(P);
    for (int a : befP)
        cout << a << ' ';
    cout << '\n';
}