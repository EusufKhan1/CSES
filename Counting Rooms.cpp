#include<bits/stdc++.h>
#define mod 1000000007
#define ll long long int
#define nn '\n'
#define pb push_back
#define faster() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

char g[1003][1003];
int vis[1003][1003];
int n,m;

void dfs(int r,int c)
{

    if(1>r || r>n || 1>c || c>m)
    {
        return ;
    }
    if(g[r][c]=='#' || vis[r][c])
    {
        return;
    }
    vis[r][c]=1;

    dfs(r+1,c);
    dfs(r-1,c);
    dfs(r,c+1);
    dfs(r,c-1);


}



int main()
{
    faster();
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>g[i][j];
        }
    }

    int cnt=0;
    for(int i=1;i<=n;i++)
    {

        for(int j=1;j<=m;j++)
        {
            if(vis[i][j] || g[i][j]=='#')continue;


            dfs(i,j);

            cnt++;


        }
    }
    cout<<cnt<<endl;




    return 0;
}

