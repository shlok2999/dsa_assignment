#include<iostream>
using namespace std;




class node
{
    public:
    node *child[26];
    string word;
    bool last_char;
    node()
    {
        for(int i=0;i<26;i++)
            child[i]=NULL;
        last_char=false;
    }
    ~node()
    {
        for(int i=0;i<26;i++)
            delete child[i];
    }
};

class trie
{
    public:
    node *root;
    trie()
    {
        root=new node;
    }
    void insert(string s)
    {
        node *temp=root;
        for(int i=0;i<s.length();i++)
        {
            int index=(int)(s[i]-'a');
            if(temp->child[index]==NULL)
                temp->child[index]=new node;
            temp=temp->child[index];
        }
        temp->last_char=true;
        temp->word=s;
    }
    ~trie()
    {
        delete root;
    }
};

trie t;
string *list;
int count;

void dfs(char **mat,int r,int c,int x,int y,node* head,string s); 
void solve(char **mat,int r,int c);
void sort(string list[],int i,int j);
int partition(string list[],int i,int j);

int main()
{
    int r,c;
    cin>>r;
    cin>>c;
    char **mat=new char*[r];
    //Accepting the 2-d matrix of alphabets and creating matrix
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
    //Taking string input 
    int n;
    cin>>n;
    //string list[n];
    
    for(int i=0;i<n;i++)
    {
        string temp;
        cin>>temp;
        t.insert(temp);
    }
    //cout<<"Enter";
    count=-1;
    list=new string[n];
    solve(mat, r, c);
    
    //cout<<count;
    
    sort(list,0,count);
   for(int i=0;i<=count;i++)
    cout<<list[i]<<" ";

    delete [] list;

    for(int i=0;i<r;i++)
        delete [] mat[i];
    delete [] mat;
}

void solve(char **mat,int r,int c)
{

    node *head=t.root;
    //cout<<r<<c;

    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            
            char ch=mat[i][j];
            //cout<<ch;
            int index=(int)(ch-'a');
            if(head->child[index]!=NULL)
            {
                //cout<<ch;
                mat[i][j]='@';
                node *temp=head->child[index];
                string temp2(1,ch);
                //cout<<ch;
                //cout<<temp2;
                dfs(mat,r,c,i+1,j,temp,temp2);
                dfs(mat,r,c,i-1,j,temp,temp2); 
                dfs(mat,r,c,i,j-1,temp,temp2); 
                dfs(mat,r,c,i,j+1,temp,temp2);
                mat[i][j]=ch;
            }
        }
    }
}


void dfs(char **mat,int r,int c,int x,int y,node* head,string s)
{
    
    if(head->last_char)
    {
        count++;
        list[count]=s;
        head->last_char=false;
        //cout<<s;
    }
    if(x<0 || x>=r || y<0 || y>=c)
        return;
    
    char ch=mat[x][y];
    if(ch=='@')
        return;
    int index=(int)(ch-'a');
    if(head->child[index]!=NULL)
    {
        mat[x][y]='@';
        node *temp=head->child[index];
        string temp2=s+ch;
        dfs(mat,r,c,x+1,y,temp,temp2);
        dfs(mat,r,c,x-1,y,temp,temp2); 
        dfs(mat,r,c,x,y-1,temp,temp2); 
        dfs(mat,r,c,x,y+1,temp,temp2);
        mat[x][y]=ch;
    }
    else
        return;
}


void sort(string list[],int i,int j)
{
    if(i>=j)
        return;
    int pivot=partition(list,i,j);
    sort(list,i,pivot-1);
    sort(list,pivot+1,j);
}


int partition(string list[],int start,int end)
{
    int p=start;
    string pivot=list[start];
    for(int i=start+1;i<=end;i++)
    {
        if(list[i]<=pivot)
        {
            p++;
            string temp=list[i];
            list[i]=list[p];
            list[p]=temp;
        }
    }

    string temp=list[start];
    list[start]=list[p];
    list[p]=temp;
    return p;
}