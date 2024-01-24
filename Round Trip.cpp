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
int parent[N];
int st=0,en=0;


void dfs(int sr,int par)
{
    vis[sr]=1;
    parent[sr]=par;

    for(auto u : g[sr])
    {
        if(u==par)continue;
       // cout<<"S"<<endl;

        if(vis[u])
        {
            st=u;
            en=sr;
            return;
        }
        dfs(u,sr);




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
    int f=0;
    for(int i=1;i<=n;i++)
    {

        if(vis[i])continue;

        dfs(i,0);
        if(st!=0 && en!=0)
        {
            f=1;
            break;
        }

    }


    if(f)
    {
        vector<int>vt;
        int pr=st;

        while(pr!=en)
        {
            vt.pb(pr);
            pr=parent[pr];

        }



        vt.pb(en);
        vt.pb(st);
        cout<<vt.size()<<nn;

        for(auto u: vt)
        {
            cout<<u<<" ";
        }
        cout<<nn;





    }
    else cout<<"IMPOSSIBLE"<<endl;




    return 0;
}


