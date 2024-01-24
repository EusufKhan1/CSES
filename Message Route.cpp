#include<bits/stdc++.h>
#define mod 1000000007
#define ll long long int
#define nn '\n'
#define pb push_back
#define faster() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

const int N=1e5+7;

vector<int>g[N];

int vis[N];

int pr[N];

void bfs(int source)
{
    queue<int>q;
    q.push(source);
    vis[source]=1;

    while(!q.empty())
    {
        int v=q.front();
        q.pop();
        for(auto u : g[v] )
        {
            if(vis[u])continue;

            q.push(u);
            vis[u]=1;
            pr[u]=v;

        }


    }



}



int main()
{
    faster();

    int n,m;
    cin>>n>>m;

    for(int i=1;i<=m;i++)
    {

        int x,y;
        cin>>x>>y;
        g[x].pb(y);
        g[y].pb(x);
    }
    bfs(1);

    vector<int>path;
    int des=n;
    int src=1;
    if(pr[n]==0)
    {
        cout<< "IMPOSSIBLE"<<endl;
        return 0;
    }
    while(des!=src)
    {

        path.pb(des);
        des=pr[des];
    }
    path.pb(src);
    reverse(path.begin(),path.end());

    cout<<path.size()<<endl;
    for(auto u :path)
    {
        cout<<u<<" ";
    }
    cout<<endl;



    return 0;
}



