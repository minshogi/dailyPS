#include <iostream>
#include <vector>

#define MAXSIZE 1000000

using namespace std;

vector<long long> g(MAXSIZE+1, 1);
vector<long long> ans(MAXSIZE+1);
void init()
{
    for (int i=2; i<=MAXSIZE; i++)
        for (int j=1; i*j<=MAXSIZE; j++)
            g[i*j]+=i;
    
    for (int i=1; i<=MAXSIZE; i++)
        ans[i] = ans[i-1]+g[i];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    init();

    int T;
    cin>>T;

    while(T--)
    {
        int n;
        cin>>n;
        cout<<ans[n]<<'\n';
    }

}
