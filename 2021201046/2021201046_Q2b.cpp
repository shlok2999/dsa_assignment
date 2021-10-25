#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> visited;
vector<pair<int,string>> ans;

void solve(vector<vector<int>> &g, int v);
void dfs(vector<vector<int>> &g,int u,int weight,string s);


int main()
{
    int vertex,edge;
    cin>>vertex;
    cin>>edge;
    vector<vector<int>> g(vertex, vector<int>(vertex,0));
    for(int i=0;i<edge;i++)
    {
        int source,destination,weight;
        cin>>source;
        cin>>destination;
        cin>>weight;
        g[source][destination]=weight;
        g[destination][source]=weight;
    }
    int k;
    cin>>k;
    visited.resize(vertex,0);
    solve(g,vertex);
    sort(ans.begin(),ans.end());
    for(int i=0;i<k && i<ans.size();i++)
        cout<<ans[i].second<<endl;
}

void solve(vector<vector<int>> &g,int v)
{
    ans.clear();
    for(int i=0;i<v-1;i++)
    {
        visited[i]=2;
        for(int j=0;j<v;j++)
        {
            if(g[i][j])
            {
                dfs(g,j,g[i][j],to_string(i));
            }
        }
        visited[i]=1;
    }
}

void dfs(vector<vector<int>> &g,int u,int weight,string s)
{
    if(visited[u]==0)
    {
        s=s+" "+to_string(u);
        ans.push_back({weight,s});
        visited[u]=2;
        int v=g.size();
        for(int i=0;i<v;i++)
        {
            if(g[u][i])
            {
                dfs(g,i,weight+g[u][i],s);
            }
        }

        visited[u]=0;
    }
    else if(visited[u]==1)
    {
        s=s+" "+to_string(u);
        //ans.push_back({weight,s});
        visited[u]=3;
        int v=g.size();
        for(int i=0;i<v;i++)
        {
            if(g[u][i])
            {
                dfs(g,i,weight+g[u][i],s);
            }
        }

        visited[u]=1;
    }
    else
        return;
}