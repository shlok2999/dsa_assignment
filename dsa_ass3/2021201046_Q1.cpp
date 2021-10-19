#include<iostream>
#include<vector>

using namespace std;
vector<string> ans;
vector<string> list;
int Levenshtein(string s1,string s2);
class node
{
    public:
    struct node *child[26];
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
    /*
    bool delete_node(node *root,string s)
    {
        if(root==NULL)
            return false;
        if(s.length()==0)
            return false;
        int index=(int)(s[0]-'a');
        if(root->child[index]==NULL)
            return false;
        else
        {
            if(root->last_char)
            {
                root->last_char=false;
                for(int i=0;i<26;i++)
                    if(root->child[i]!=NULL)
                        return false;
                delete root;
                return false;
            }
            else
            {
                bool val=delete_node(root->child[index],s.substr(1));
                if(val)
                {
                    root->child[index]==NULL;
                    root->last_char=false;
                    for(int i=0;i<26;i++)
                        if(root->child[i]!=NULL)
                            return false;
                    delete root;
                    return false;
                }
                else
                return false;
            }
        }
    }

    void delete_node(string s)
    {
        delete_node(root,s);
    }
    */
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