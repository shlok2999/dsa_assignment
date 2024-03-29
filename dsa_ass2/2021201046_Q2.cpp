#include<iostream>
#include<sstream>
#include<vector>
using namespace std;

#define maxi 94961
#define mod 10000007

bool flag;

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
       //flag=false
       int index=getkey(key);
        if(arr[index]==NULL)
        {
            B temp;
            node *temp2=new node(key,temp);
            temp2->next=arr[index];
            arr[index]=temp2;
            return temp;
        }
        
        node *p1=arr[index];;
        while(p1!=NULL)
        {
            if(p1->key==key)
            {
                //flag=true;
                return p1->val;
            }
            p1=p1->next;
        }

        static B temp;
        node *temp2=new node(key,temp);
        temp2->next=arr[index];
        arr[index]=temp2;
        return temp; 
    }


};


vector<int> function()
{
    unordered_map<int,int> umap;
    vector<int> ans;
    int n,i;
    cout<<"Enter size";
    cin>>n;
    int arr[n];
    cout<<"Enter Array";
    for(i=0;i<n;i++)
    {
        int temp;
        cin>>temp;
        arr[i]=temp;
    }
    int k;
    cout<<"Enter k:";
    cin>>k;
    int count=0;
    for(i=0;i<k;i++)
    {
        if(umap.find(arr[i]))
        {
            int temp=umap[arr[i]];
            temp++;
            umap.insert(arr[i],temp);
        }
        else
        {
            count++;
            umap.insert(arr[i],1);
        }
    }
    //cout<<count<<" ";
    ans.push_back(count);
  
    for(i=k;i<n;i++)
    {
        int start=arr[i-k];
        int val=umap[start];
        if(val>1)
            umap.insert(start,val-1);
        else
        {
            umap.erase(start);
            count--;
        }
        if(umap.find(arr[i]))
        {
            int temp=umap[arr[i]];
            temp++;
            umap.insert(arr[i],temp);
        }
        else
        {
            count++;
            umap.insert(arr[i],1);
        }

        //cout<<count<<" ";
        ans.push_back(count);
    }

    return ans;
}



int main()
{
    //unordered_map<int,int> umap;
    //umap.insert(2,3);
    //cout<<umap[2];
    //umap.erase(2);
    //cout<<umap.find(2);
    unordered_map<int,int> umap;
    vector<int> ans;
    ans=function();
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<"";
    }        
    return 0;
}
