#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

//   https://csacademy.com/app/graph_editor/

/*
//....01....graph represented by adjacency matrix
int main()
{
    int n,m;
    cout<<"Enter the number of node : ";
    cin>>n;
    cout<<"Enter the number of edge : ";
    cin>>m;

    int met[n+5][n+5];
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            met[i][j]=0;
        }
    }
    for(int i=0; i<m; i++){
        int u,v;
        cin>>u>>v;
        met[u][v]=1;
        met[v][u]=1;
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<met[i][j]<<" ";
        }
        cout<<endl;
    }
}


//....02....graph represented by adjacency list
const int lim=10005;
vector<int>adj[lim];
int main()
{
    int n,m;
    cout<<"Enter the number of node : ";
    cin>>n;
    cout<<"Enter the number of edge : ";
    cin>>m;

    for(int i=0; i<m; i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int i=1; i<=n; i++)
    {
        cout<<"vector "<<i<<" : ";
        for(int j=0; j<adj[i].size(); j++)
        {
            cout<<adj[i][j]<<" ";
        }
        cout<<endl;
    }
}


//....03....DFS
const int lim=10005;
vector<int>adj[lim];
bool vis[lim];

void dfs(int u){
    vis[u]=1;
    cout<< u << " -> " ;
    for(int i=0;i<adj[u].size();i++){
        int v=adj[u][i];
        if(vis[v]==0){
            dfs(v);
        }
    }
}

int main()
{
    int n,m;
    cout<<"Enter the number of node : ";
    cin>>n;
    cout<<"Enter the number of edge : ";
    cin>>m;

    for(int i=0; i<m; i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1);
}

*/
//....04....BFS
const int lim=1e5+5;
vector<int>adj[lim];
int dis[lim];
int n,m;

void bfs(int src){
    queue<int>q;
    for(int i=1;i<=n;i++){
        dis[i]=-1;
    }
    dis[src]=0;
    q.push(src);

    while(q.empty()==false){
        int u=q.front();
        q.pop();

        for(int i=0;i<adj[u].size();i++){
            int v=adj[u][i];
            if(dis[v]==-1){
                dis[v]=dis[u]+1;
                q.push(v);
            }
        }
    }
}

int main()
{
    cout<<"Enter the number of node : ";
    cin>>n;
    cout<<"Enter the number of edge : ";
    cin>>m;

    for(int i=0; i<m; i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int x,y;
    cout<<"Enter 2 node for sortest distance"<<endl;
    cin>>x>>y;

    bfs(x);

    cout<<dis[y];
}


