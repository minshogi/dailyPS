#include <iostream>
#include <vector>

using namespace std;

vector<bool> check;
vector<int> primes;

void seive_Eratosthenes(int N);

int main()
{
    int M, N;
    cin>>M>>N;

    primes.clear();
    check.resize(N+1);
    
    seive_Eratosthenes(N);
    for(int ans : primes)
        if(ans >= M) cout<<ans<<'\n';

}

void seive_Eratosthenes(int N)
{
    check[1]=true;
    for(int i = 2; i <= N; i++)
    {
        if(!check[i])
        {
            primes.push_back(i);
            for(int j=2; i*j<=N && i*i<=N; j++)
                check[i*j]=true;
        }
    }
}