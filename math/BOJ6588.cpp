#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int MAX = 1000000;

vector<int> primes;
vector<bool> check;

void seive(int N);
void init();
string make_target(int target);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    init();
    while(true)
    {
        int N;
        cin>>N;
        if(N==0) return 0;
        cout << make_target(N) << '\n';
    }    
}

void seive(int N)
{
    check[1]=true;
    for(int i=2; i<=N; i++)
    {
        if(!check[i])
        {
            primes.push_back(i);
            for(int j=2; j*i<=N && i*i<=N; j++)
                check[i*j] = true;
        }
    }
}

void init()
{
    primes.clear();
    check.resize(MAX+1);
    seive(MAX);
}

string make_target(int N)
{
    for (int prime : primes)
    {
        if (prime > N) break;
        else if (prime > 2 && !check[N-prime])
            return to_string(N) + " = " + to_string(prime) + " + " + to_string(N-prime);
    }
    return "Goldbach's conjecture is wrong.";
}