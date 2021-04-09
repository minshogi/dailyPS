#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

vector<string> ans;
string opers;
int K;

bool check(int idx, char bef, char aft)
{
    if (opers[idx] == '>')
        return bef > aft;
    else
        return bef < aft;
}

void go(int idx, string &left, string &right)
{
    if (idx == K)
        ans.push_back(left);

    int size = right.size();
    char now = left.back();

    for (char nxt : right)
    {
        if (check(idx, now, nxt))
        {
            string tmpl = left, tmpr = right;
            tmpr.erase(find(tmpr.begin(), tmpr.end(), nxt));
            tmpl += nxt;
            go(idx + 1, tmpl, tmpr);
        }
    }
}

int main()
{
    cin >> K;
    opers = "";
    for (int i = 0; i < K; i++)
    {
        char x;
        cin >> x;
        opers += x;
    }
    for (int i = 0; i < 10; i++)
    {
        string left = "", right = "0123456789";
        right.erase(i, 1);
        left += '0' + i;

        go(0, left, right);
    }
    sort(ans.begin(), ans.end());
    cout << ans.back() << '\n'
         << ans.front() << '\n';
}