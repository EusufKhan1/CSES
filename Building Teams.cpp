#include<bits/stdc++.h>
#define mod 1000000007
#define ll long long int
#define nn '\n'
#define pb push_back
#define faster() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
const int N=1e5+7;

vector<int>g[N];

int colour[N];

int f=1;

void dfs(int sr,int cl)
{
    if(colour[sr])
    {
        if(colour[sr]!=cl)
        {
            f=0;
            return;
        }

        return;
    }


    colour[sr]=cl;

    for(auto u : g[sr])
    {

        dfs(u,((cl==1)? 2:1));
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

    for(int i=1;i<=n;i++)
    {
        if(colour[i]==0)
        {
            dfs(i,1);
        }
    }
    if(f)
    {
        for(int i=1;i<=n;i++)
        {
            cout<<colour[i]<<" ";
        }
        cout<<endl;
    }
    else{
        cout<< "IMPOSSIBLE"<<endl;
    }




    return 0;
}



