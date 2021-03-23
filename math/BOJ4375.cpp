#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    while(cin>>n)
    {
        int rest = 1%n, ret = 1;
        while(rest != 0)
        {
            rest = (rest*10+1)%n;
            ret++;
        }
        cout<<ret<<'\n';        
    }
}