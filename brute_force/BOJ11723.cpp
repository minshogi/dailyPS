#include <iostream>

using namespace std;
const int All = (1 << 21) - 1;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int M, S = 0;
    cin >> M;
    while (M--)
    {
        string input;
        cin >> input;
        int x;
        if (input == "add")
        {
            cin >> x;
            S |= (1 << x);
        }
        else if (input == "remove")
        {
            cin >> x;
            S &= ~(1 << x);
        }
        else if (input == "check")
        {
            cin >> x;
            int out = 0;
            if (S & (1 << x))
                out = 1;
            cout << out << '\n';
        }
        else if (input == "toggle")
        {
            cin >> x;
            S ^= (1 << x);
        }
        else if (input == "all")
        {
            S = All;
        }
        else if (input == "empty")
        {
            S = 0;
        }
    }
}