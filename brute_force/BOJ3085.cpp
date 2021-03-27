#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>


using namespace std;

char candy[50][50];
bool visit[50][50];
int N;

pair<int, int> operator +(const pair<int,int> &l, const pair<int, int> &r)
{
    return make_pair(l.first+r.first, l.second+r.second);
}

pair<int, int> direction(int dir)
{
    pair<int, int> ret(0,0);
    if(dir == 0)    ret.first++;
    else if(dir == 1)   ret.second++;
    else if(dir == 2)   ret.first--;
    else if(dir == 3)   ret.second--;
    return ret;
}

pair<int, int> move_to(pair<int, int>& now, int dir)
{
    pair<int, int> ret = now;
    ret = ret + direction(dir);
    int r = ret.first, c = ret.second;
    if(r<0 || c<0 || r>=N || c>=N) return make_pair(-1,-1);
    return ret;
}

int search(int r, int c, int version)
{
    pair<int, int> x(r,c);
    queue<pair<int, int> > q;
    int ret = 0;
    q.push(x);
    visit[r][c]=1;
    while(!q.empty())
    {
        pair<int, int> now = q.front();
        q.pop();
        int nr = now.first, nc = now.second;
        ret++;
        for(int dir=0+version; dir<4; dir+=2)
        {
            pair<int, int> next = move_to(now, dir);
            int nxr = next.first, nxc = next.second;
            if(nxr!=-1 && candy[nr][nc] == candy[nxr][nxc] && !visit[nxr][nxc])
            {
                q.push(next);
                visit[nxr][nxc]=1;
            }
        }
    }
    return ret;
}


int bf()
{
    int ret = 0;
    for(int r=0; r<N; r++)
    {
        for(int c=0; c<N; c++)
        {
            pair<int, int> now(r,c), nxt;
            for(int dir=0; dir<2; dir++)
            {
                nxt = move_to(now, dir);
                int nxr = nxt.first, nxc = nxt.second;
                if(nxr!=-1 && candy[r][c] != candy[nxr][nxc])
                {
                    char tmp = candy[r][c];
                    candy[r][c] = candy[nxr][nxc];
                    candy[nxr][nxc] = tmp;
                    for(int v = 0; v<2; v++)
                    {
                        memset(visit, 0, sizeof(visit));
                        int n_bfs = search(r,c,v), nx_bfs = search(nxr, nxc,v);
                        int bigb = n_bfs>nx_bfs?n_bfs:nx_bfs;
                        ret = ret>bigb?ret:bigb;
                    }
                    candy[nxr][nxc] = candy[r][c];
                    candy[r][c] = tmp;
                    
                }
            }
        }
    }
    return ret;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>N;
    for(int r=0; r<N; r++)
    {
        for(int c=0; c<N; c++)
        {
            cin>>candy[r][c];
        }
    }
    int ans=0;
    for(int r=0; r<N; r++)
    {
        for(int c = 0; c<N; c++)
        {
            if(!visit[r][c])
            {
                for(int v=0; v<2; v++)
                {
                    memset(visit, 0, sizeof(visit));
                    int tmp = search(r,c,v);
                    ans = ans>tmp?ans:tmp;
                }
            }
        }
    }
    int tmp = bf();
    ans = ans>tmp?ans:tmp;

    cout<<ans<<'\n';
}
