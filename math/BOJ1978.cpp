#include <iostream>

using namespace std;

bool is_prime(int x);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T, ans=0;
    cin>>T;
    
    while(T--)
    {
        int x;
        cin>>x;
        if(is_prime(x)) ans++;  
    }
    cout<<ans<<'\n';
}

bool is_prime(int x)
{
    if(x==1) return false;

    for(int i=2; i*i<=x; i++)
        if(x%i==0) return false;

    return true;
}