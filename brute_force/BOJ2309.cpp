#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> find_ans(vector<int> ds, int goal);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<int> dwarfs;
    int total = 0;
    for(int i=0; i < 9; i++)
    {
        int x;
        cin>>x;
        dwarfs.push_back(x);
        total += x;
    }

    int goal = total - 100;
    vector<int> ans = find_ans(dwarfs, goal);
    for(int& e : ans){
        cout<< e << '\n';
    }

}

vector<int> find_ans(vector<int> ds, int goal)
{
    vector<int> ret = ds;
    int size = ds.size();
    bool flag = 0;
    for(int fir=0; fir < size && !flag; fir++)
    {
        for(int sec=fir+1; sec < size && !flag; sec++)
        {
            if(ret[fir]+ret[sec] == goal)
            {
                flag = 1;
                ret.erase(ret.begin()+fir);
                ret.erase(ret.begin()+sec-1);
            }
        }
    }
    sort(ret.begin(), ret.end());
    return ret;
}