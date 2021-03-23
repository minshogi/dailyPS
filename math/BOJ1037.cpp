#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, small = 1000001, big=-1;
    cin>>n;
    int tmp;
    while(n--)
    {
        cin>>tmp;
        small = small>tmp?tmp:small;
        big = big>tmp?big:tmp;
    }
    cout<<small*big<<'\n';

} 