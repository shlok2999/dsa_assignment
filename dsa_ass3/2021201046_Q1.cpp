#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<string> ans;
vector<string> list;
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
            int check=Levenshtein(s,target);
            if(check<=3)
            ans.push_back(s);
        }
        for(int i=0;i<26;i++)
        {
            if(r->child[i]!=NULL)
            {
                char c = (char)(i +'a');
                s=s+c;
                auto_correct(r->child[i],s,target);
                s.pop_back();
            }
        }
   }

   void auto_correct(string target)
   {
       ans.clear();
       if(spell_checker(target))
       {
           ans.push_back(target);
           return;
       }
       auto_correct(root,"",target);

   }

};


int main()
{
    trie t;
    string arr[]={"the", "them", "thems", "they", "thee", "thou", "thesis", "that", "then", "thus", "to", "top", "stop"};
    for(int i=0;i<13;i++)
    {
        t.insert(arr[i]);
    }
    /*
    for(int i=0;i<13;i++)
    {
        bool ans=t.spell_checker(arr[i]);
        if(ans)
            cout<<"True\n";
        else
            cout<<"False\n";
    }
    t.auto_complete("to");
    
    for(int i=0;i<list.size();i++)
    {
        cout<<list[i]<<endl;
    }*/
    //cout<<list.size();
    t.auto_correct("p");
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<endl;
    }
}