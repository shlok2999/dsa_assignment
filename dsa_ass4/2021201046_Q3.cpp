#include<iostream>
using namespace std;


class node
{
    public:
    node *child[2];
    bool last_bit;
    long long int num;
    node()
    {
        for(int i=0;i<2;i++)
            child[i]=NULL;
        last_bit=false;
        num=0;
    }
    ~node()
    {
        for(int i=0;i<2;i++)
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
    void insert(long long int n)
    {
        node *temp=root;
        int index;
        for(int i=63;i>=0;i--)
        {
            if((n &(1<<i)))
                index=1;
            else
                index=0;
            if(temp->child[index]==NULL)
                temp->child[index]=new node;
            temp=temp->child[index];
        }
        temp->last_bit=true;
        temp->num=n;
    }


    long long int search(long long int n)
    {
        node *temp=root;
        long long int ans=0;
        int index;
        for(int i=63;i>=0;i--)
        {
            //cout<<i<<" ";
            if((n &(1<<i)))
                index=0;
            else
                index=1;
            if(temp->child[index]==NULL)
            {
                temp=temp->child[1-index];               
            }
            else
            {
                
                //cout<<ans<<endl;
                 temp=temp->child[index];
                //ans+=(1<<i);
               // cout<<(1<<i)<<" ";
                ans=ans+((1<<i));
            }
        }
        //cout<<ans<<endl;
        return ans/2;
    }
    ~trie()
    {
        delete root;
    }
};



int main()
{
    trie t;
    int n,q;
    cout<<"enter the number:";
    cin>>n;
    cout<<"Enter no of queries:";
    cin>>q;
    //int *arr=new int[n];
    cout<<"Enter arrays:";
    for(int i=0;i<n;i++)
    {
        int temp;
        cin>>temp;
        //arr[i]=temp;
        t.insert(temp);
    }
    cout<<"Enter queries:";
    for(int i=0;i<q;i++)
    {
        int query;
        cin>>query;
        cout<<t.search(query)<<endl;
    }

    //delete[] arr; 
}