#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<string> ans;
vector<string> list;
vector< vector<int>> mat;
int col;
int index;
/*
int Levenshtein(string s1,string target)
{
    s1="?"+s1;
    target="?"+target;
    int mat[target.length()][s1.length()];
    for(int i=0;i<target.length();i++)
    {
        mat[i][0]=i;
    }
    for(int i=0;i<s1.length();i++)
    {
        mat[0][i]=i;
    }

    for(int i=1;i<target.length();i++)
    {
        for(int j=1;j<s1.length();j++)
        {
            if(target[i]==s1[j])
            {
                mat[i][j]=mat[i-1][j-1];
                continue;
            }

            mat[i][j]=min(mat[i-1][j-1],min(mat[i-1][j],mat[i][j-1]));
            mat[i][j]++;
        }
    }
    return mat[target.length()-1][s1.length()-1];
}
*/
class node
{
    public:
    node *child[26];
    bool last_char;
    node()
    {
        for(int i=0;i<26;i++)
            child[i]=NULL;
        last_char=false;
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
    }

    bool spell_checker(string s)
    {

        node *temp=root;
        for(int i=0;i<s.length();i++)
        {
            int index=(int)(s[i]-'a');
            if(temp->child[index]==NULL)
                return false;
            temp=temp->child[index];
        }
        if(temp->last_char)
            return true;
        else
            return false;
    }
   
   void auto_complete(node *r,string s)
   {
       if(r==NULL)
            return;
        if(r->last_char)
            list.push_back(s);
        for(int i=0;i<26;i++)
        {
            if(r->child[i]!=NULL)
            {
                char c = (char)(i +'a');
                s=s+c;
                auto_complete(r->child[i],s);
                s.pop_back();
            }
        }
   }
   void auto_complete(string s)
   {
       list.clear();
       node *temp=root;
       for(int i=0;i<s.length();i++)
       {
           int index=(int)(s[i]-'a');
           if(temp->child[index]==NULL)
                return;
            temp=temp->child[index];
       }
       auto_complete(temp,s);
   }

   void auto_correct(node *r,string s,string target)
   {
       if(r==NULL)
            return;
        if(s.length()>target.length()+3)
            return;
        if(r->last_char)
        {
            
            int check=mat[index-1][col-1];
            if(check<=3)
            ans.push_back(s);
        }
        for(int i=0;i<26;i++)
        {
            if(r->child[i]!=NULL)
            {
                char c = (char)(i +'a');
                s=s+c;
                vector<int> temp(col,0);
                temp[0]=index;
                for(int j=1;j<col;j++)
                {
                    if(c==target[j-1])
                    {
                        temp[j]=mat[index-1][j-1];
                        continue;
                    }
                    temp[j]=min(mat[index-1][j],min(temp[j-1],mat[index-1][j-1]));
                    temp[j]++;
                }
                mat.push_back(temp);
                index++;
                auto_correct(r->child[i],s,target);
                s.pop_back();
                index--;
                mat.pop_back();
            }
        }
   }

   void auto_correct(string target)
   {
       ans.clear();
       vector<int> temp;
       for(int i=0;i<=target.length();i++)
        temp.push_back(i);
        mat.push_back(temp);
        index=1;
        col=target.length()+1;
       auto_correct(root,"",target);

   }

};


int main()
{
    trie t;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        string s;
        cin>>s;
        t.insert(s);
    }
    int choice;
    cin>>choice;
    string word;
    cin>>word;
    if(choice==1)
    {
        
        bool ans=t.spell_checker(word);
        cout<<ans;
    }
    else if(choice==2)
    {
        t.auto_complete(word);
        cout<<list.size()<<endl;
        for(int i=0;i<list.size();i++)
        {
            cout<<list[i]<<endl;
        }
    }
    else if(choice==3)
    {
        t.auto_correct(word);
        cout<<ans.size()<<endl;
        for(int i=0;i<ans.size();i++)
        {
            cout<<ans[i]<<endl;
        }
    }
}