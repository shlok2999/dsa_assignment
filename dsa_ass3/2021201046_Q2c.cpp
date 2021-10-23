#include<iostream>
#include<queue>
#include<climits>
using namespace std;

bool is_valid(vector<vector<int>> &mat,int i,int j);

int main()
{
    int r,c;
    cin>>r;
    cin>>c;
    vector<pair<int,int>> rider;
    pair<int,int> a;
    vector<vector<int>> mat(r,vector<int>(c,-1));

    

    for(int i=0;i<r;i++)
    {
        string s;
        cin>>s;
        for(int j=0;j<c;j++)
        {
            char ch=s[j];
            if(ch=='#')
            {
                mat[i][j]=INT_MAX;
            }
            else if(ch=='R')
            {
                rider.push_back({i,j});
            }
            else if(ch=='A')
            {
                a={i,j};
            }
        }
    }
    mat[1][0]=0;

    queue<pair<int,int>> q;
    q.push({1,0});
    while(!q.empty())
    {
        pair<int,int> point=q.front();
        q.pop();
        int i=point.first;
        int j=point.second;
        if(is_valid(mat,i-1,j))
        {
            mat[i-1][j]=mat[i][j]+1;
            q.push({i-1,j});
        }
        if(is_valid(mat,i+1,j))
        {
            mat[i+1][j]=mat[i][j]+1;
            q.push({i+1,j});
        }
        if(is_valid(mat,i,j-1))
        {
            mat[i][j-1]=mat[i][j]+1;
            q.push({i,j-1});
        }
        if(is_valid(mat,i,j+1))
        {
            mat[i][j+1]=mat[i][j]+1;
            q.push({i,j+1});
        }
    }

    bool check=true;
    int ans=mat[a.first][a.second];
    for(int i=0;i<rider.size();i++)
    {
        int x=rider[i].first;
        int y=rider[i].second;
        if(mat[x][y]<ans  &&  mat[x][y]>=0)
        {
            check=false;
            break;
        }
    }
    if(check && ans!=-1)
    {
        cout<<"YES\n";
        cout<<ans<<endl;
    }
    else
    {
        cout<<"NO";
    }
    // for(int i=0;i<r;i++)
    // {
    //     for(int j=0;j<c;j++)
    //         cout<<mat[i][j]<<" ";
    //     cout<<endl;
    // }
}

bool is_valid(vector<vector<int>> &mat,int i,int j)
{
    int row=mat.size();
    int col=mat[0].size();

    if(i<0 || i>=row || j<0 || j>=col)
        return false;
    if(mat[i][j]>=0)
        return false;
    else 
        return true;
}