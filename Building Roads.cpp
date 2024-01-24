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

void dfs(int source)
{
    vis[source]=1;

    for(auto u : g[source])
    {
        if(vis[u])continue;

        dfs(u);

    }


}




int main()
{
    faster();
    int n,m;
    cin>>n>>m;

    for(int i=0;i<m;i++)
    {
        int x,y;
        cin>>x>>y;

        g[x].pb(y);
        g[y].pb(x);
    }

    vector<int>vt;

    for(int i=1;i<=n;i++)
    {
        if(vis[i])continue;
       dfs(i);
       vt.pb(i);
    }

    cout<<vt.size()-1<<endl;

    for(int i=0;i<vt.size()-1;i++)
    {
        cout<<vt[i]<< " "<<vt[i+1]<<endl;
    }




    return 0;
}




