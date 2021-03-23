#include <iostream>

using namespace std;

int GCD(int a, int b);
int LCM(int a, int b);


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b;
    cin>>a>>b;

    cout<<GCD(a,b)<<'\n'<<LCM(a,b)<<'\n';
}

int GCD(int a, int b)
{
    if(b==0) return a;
    return GCD(b, a%b);
}

int LCM(int a, int b)
{
    return a*b/GCD(a,b);
}