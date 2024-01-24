#include<bits/stdc++.h>
#define mod 1000000007
#define ll long long int
#define nn '\n'
#define pb push_back
#define faster() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
ll inf=1e18;
const int N=1e5+7;

vector<pair<int,int>>g[N];
vector<ll>dist(N,inf);

 ll pr[N];
void dijkstra(ll source)
{

    dist[source]=0;

    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> pq;

    pq.push({0,source});

    while(!pq.empty())
    {
        auto x=pq.top();
        pq.pop();
        ll u=x.second;
        ll dis=x.first;
        // cout<<u<<" kd "<<dis<<endl;
        if(dist[u]<dis)continue;

        for(auto y : g[u])
        {
            ll v=y.first;
            ll wt=y.second;
           // cout<<v<<" eg "<<wt<<endl;
            if(dist[v]>dis+wt)
            {
                dist[v]=dis+wt;
                //cout<<"C"<<endl;

                pq.push({dist[v],v});
                pr[v]=u;

            }

        }

    }


}




int main()
{
    faster();

    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int x,y,w;
        cin>>x>>y>>w;
        g[x].pb({y,w});


    }
    dijkstra(1);

    for(int i=1;i<=n;i++)
    {
        cout<<dist[i]<<" ";
    }
    cout<<endl;





    return 0;
}




