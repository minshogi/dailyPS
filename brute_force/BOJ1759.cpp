#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int L, C;
string alpha = "";
string mo = "";
string ja = "";
const string moin = "aeiou";

bool is_ok(string x)
{
    int mos = 0, jas = 0;
    for (char i : mo)
    {
        if (x.find(i) != x.npos)
            mos++;
    }
    for (char i : ja)
    {
        if (x.find(i) != x.npos)
            jas++;
    }
    return (mos >= 1 && jas >= 2);
}

void go(int index, string password)
{
    if (password.size() == L)
    {
        if (is_ok(password))
        {
            cout << password << '\n';
        }
        return;
    }
    if (index == C)
        return;

    go(index + 1, password + alpha[index]);
    go(index + 1, password);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> L >> C;
    for (int i = 0; i < C; i++)
    {
        char x;
        cin >> x;
        if (moin.find(x) != moin.npos)
            mo += x;
        else
            ja += x;
        alpha += x;
    }
    sort(alpha.begin(), alpha.end());
    go(0, "");
}