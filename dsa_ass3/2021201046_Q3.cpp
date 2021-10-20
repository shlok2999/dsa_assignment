#include<iostream>
using namespace std;

bool dfs(char **mat,int r,int c,int x,int y,string s); 
bool solve(char **mat,int r,int c,string s);
void sort(string list[],int i,int j);
int partition(string list[],int i,int j);

int main()
{
    int r,c;
    cin>>r;
    cin>>c;
    char **mat=new char*[r];
    for(int i=0;i<r;i++)
    {
        mat[i]=new char[c];
    }

    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            char temp;
            cin>>temp;
            mat[i][j]=temp;
        }
    }

    //print(mat,r,c);
    int n;
    cin>>n;
    string list[n];
    for(int i=0;i<n;i++)
    {
        string temp;
        cin>>temp;
        list[i]=temp;
        
    }
    /*
    for(int i=0;i<n;i++)
        cout<<list[i]<<endl;
    */
   sort(list,0,n-1);
   for(int i=0;i<n;i++)
   {
       if(solve(mat,r,c,list[i]))
        cout<<list[i]<<" ";
   }

    for(int i=0;i<r;i++)
        delete [] mat[i];
    delete [] mat;
}


bool dfs(char **mat,int r,int c,int x,int y,string s)
{
    if(s=="")
        return true;
    if(x<0 || x>=r || y<0 || y>=c)
        return false;
    if(mat[x][y]==s[0])
    {
        mat[x][y]='@';
        char ch=s[0];
        s.erase(s.begin());
        bool ans= dfs(mat,r,c,x+1,y,s) || dfs(mat,r,c,x-1,y,s) || dfs(mat,r,c,x,y-1,s) || dfs(mat,r,c,x,y+1,s);
        mat[x][y]=ch;
        return ans;  
    }
    else
        return false;
}

bool solve(char **mat,int r,int c,string s)
{
    if(s=="")
        return true;
    
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            if(mat[i][j]==s[0])
            {
                mat[i][j]='@';
                char ch=s[0];
                s.erase(s.begin());
                bool ans= dfs(mat,r,c,i+1,j,s) || dfs(mat,r,c,i-1,j,s) || dfs(mat,r,c,i,j-1,s) || dfs(mat,r,c,i,j+1,s);
                mat[i][j]=ch;   
                s=ch+s;
                if(ans)
                    return ans;
            }
        }
    }

    return false;
}

/*

void print(char **mat,int r,int c)
{
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
            cout<<mat[i][j]<<" ";
        cout<<endl;
    }
}
*/

