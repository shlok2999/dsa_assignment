#include<iostream>
#include<sstream>

using namespace std;

#define maxi 100005
#define mod 10000007

template <class A,class B>
class unordered_map{
    public:
    class node
    {
        public:
        A key;
        B val;
        node *next;
        node(A k, B v)
        {
            key=k;
            val=v;
            next=NULL;
        }
    };

    node *arr[maxi];

    unordered_map()
    {
        for(int i=0;i<maxi;i++)
            arr[i]=NULL;
    }

    int getkey(A key)
    {
        long long int ans=0;
        ostringstream temp;
        temp<<key;
        string s=temp.str();
        long long int al=47;
        long long int p=1;
        int n=s.length();
        for(int i=n-1;i>=0;i--)
        {
            ans=(ans + (s[i]*p)%mod)%maxi;
            p=(p*al)%mod;
        }
        return ans;
    }



    void insert(A key, B val)
    {
        int index=getkey(key);
        if(arr[index])
        {
            node *temp=arr[index];
            while(temp!=NULL)
            {
                if(temp->key==key)
                {
                    temp->val=val;
                    return;
                }
            }

            temp=new node(key,val);
            temp->next=arr[index];
            arr[index]=temp;
        }

        else
        {
            node *temp =new node(key,val);
            arr[index]=temp;
        }
    }


    bool find(A key)
    {
        int index=getkey(key);
        if(arr[index]==NULL)
            return false;
        
        node *p1=arr[index];;
        while(p1!=NULL)
        {
            if(p1->key==key)
                return true;
            p1=p1->next;
        }
        return false;
    }

    void erase(A key)
    {
        int index=getkey(key);

        if(arr[index]==NULL)
            return ;
        else
        {
            node *p1=arr[index];
            node *p2=p1->next;
            if(p1->key==key)
            {
                arr[index]=p2;
                return;
            }

            while(p2!=NULL && p2->key!=key)
            {
                p1=p2;
                p2=p2->next;
            }

            if(p2)
            {
                p1->next=p2->next;
                delete p2;
                p2=NULL;
            }
        }
    }

    B operator [] (A key)
    {
       int index=getkey(key);
        if(arr[index]==NULL)
            return -1;
        
        node *p1=arr[index];;
        while(p1!=NULL)
        {
            if(p1->key==key)
                return p1->val;
            p1=p1->next;
        }
        return -1; 
    }


};

int main()
{
    unordered_map<int,int> umap;
    umap.insert(2,3);
    cout<<umap[2];
    umap.erase(2);
    cout<<umap.find(2);
    
    return 0;
}
