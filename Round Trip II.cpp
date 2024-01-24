#include<bits/stdc++.h>
#define mod 1000000007
#define ll long long int
#define nn '\n'
#define pb push_back
#define faster() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

const int N=2e5+7;

vector<int>g[N];
int vis[N];
int parent[N];
int st=0,en=0;


void dfs(int sr)
{
    vis[sr]=1;
    for(auto u : g[sr])
    {

         if(vis[u]==0)
        {
               parent[u]=sr;
               dfs(u);
               if(st)return;
        }
       else if(vis[u]==1)
        {
            st=u;
            en=sr;
            return;
        }

      // vis[u]=2;


    }
    vis[sr]=2;

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
       // g[y].pb(x);

    }
    int f=0;
    for(int i=1;i<=n;i++)
    {

        if(vis[i]==0)
        {
            dfs(i);
        }
        if(st!=0)
        {
            f=1;
            break;
        }

    }


    if(f)
    {
        vector<int>vt;
        int pr=en;

       // cout<<st<<" "<<en<<endl;
        vt.pb(st);
        while(pr!=st)
        {
            vt.pb(pr);
            pr=parent[pr];
            //cout<<pr<<endl;

        }





         vt.pb(st);
         reverse(vt.begin(),vt.end());
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
