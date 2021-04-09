#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> next_p(vector<int> &P)
{
    vector<int> ret(P);

    auto begin = ret.begin();
    auto end = ret.end();
    auto now = end - 1;
    int bef = -1;
    while (now >= begin)
    {
        if (*now < bef)
        {
            break;
        }
        bef = *now;
        now--;
    }
    if (now < begin)
        return vector<int>(1, -1);

    int min = 987654321;
    vector<int>::iterator minit;
    for (auto iter = now; iter != end; iter++)
    {
        if (*now < *iter && *iter < min)
        {
            min = *iter;
            minit = iter;
        }
    }

    int tmp = *now;
    *now = *minit;
    *minit = tmp;
    sort(now + 1, end);
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

    vector<int> nxtP = next_p(P);
    for (int a : nxtP)
        cout << a << ' ';
    cout << '\n';
}