#include<iostream>
#include<climits>
using namespace std;


bool flag;

class abc{
    private:
    int a;
    public:
    abc()
    {
        a=0;
    }

    abc(int x)
    {
        a=x;
    }

    bool operator < (abc const &x)
    {
        if(a<x.a)
        return true;
        else
            return false;
    }

    bool operator > (abc const &x)
    {
        if(a>x.a)
        return true;
        else
            return false;
    }

    bool operator == (abc const &x)
    {
        if(a==x.a)
        return true;
        else
            return false;
    }

    bool operator >= (abc const &x)
    {
        if(a>=x.a)
        return true;
        else
            return false;
    }

    bool operator <= (abc const &x)
    {
        if(a<=x.a)
        return true;
        else
            return false;
    }
    
   friend ostream& operator <<(ostream& os, const abc& x);
};

 ostream& operator <<(ostream& os, const abc& x)
    {
        os << x.a;
        return os;
    }

template <typename T>
class AVL{
    class node
    {
        public:
        T val;
        int count;
        int lc,rc;
        int height;
        node *left;
        node *right;
        node(T v)
        {
            val=v;
            count=1;
            height=1;
            lc=0;
            rc=0;
            left=NULL;
            right=NULL;
        }
    };

    node *head;
    public:

    AVL()
    {
        head=NULL;
    }
 /////////////////////Kth smallest////////////////////////////////////////
    T k_smallest(node *root, int k)
    {
        if(root == NULL)
        {
            T temp;
            return temp;
        }
        //k=k-root->count;
        if(k<0)
        {
            flag=true;
            return root->val;
        }
        if(k < root->lc)
            return k_smallest(root->left,k);
        else
        {
            k-=root->lc;
            if(k<root->count)
            {
                flag=true;
                return root->val;
            }
            else
                return k_smallest(root->right, k - root->count);
        }

    }

    T k_smallest(int k)
    {
        flag=false;
        return k_smallest(head,k);
    }
//////////////////////////////////////////Useful Functions////////////////////////////////////////////////

    int h(node* root)
    {
        if(root)
            return root->height;
        else
            return 0;
    }

    node * rot_right(node *root)
    {
        node *temp=root;
        root=root->left;
        temp->left=root->right;
        root->right=temp;
        temp->lc=root->rc;
        root->rc= temp->lc + temp->rc + temp->count;
        temp->height= 1+ max(h(temp->left),h(temp->right));
        root->height= 1+ max(h(root->left),h(root->right));
        return root;
    }

    node * rot_left(node *root)
    {
        node *temp=root;
        root= root->right;
        temp->right=root->left;
        root->left=temp;
        temp->rc=root->lc;
        root->lc=temp->lc + temp->rc + temp->count;
        temp->height= 1+ max(h(temp->left),h(temp->right));
        root->height= 1+ max(h(root->left),h(root->right));
        return root; 
    }

    node * RL(node *root)
    {
        root->right=rot_right(root->right);
        root=rot_left(root);
        return root;
    }

    node * LR(node *root)
    {
        root->left=rot_left(root->left);
        root=rot_right(root);
        return root;
    }
    
    T min(T a,T b)
    {
        if(a>b)
            return b;
        else
            return a;
    }

///////////////////////////Insertion//////////////////////////////////////////////////////////////////////

    node * insert(node *root, T x)
    {
        if(root==NULL)
            return new node(x);
        
        if(x==root->val)
        {
            root->count+=1;
            return root;
        }
        else if(x < root->val)
        {
            root->left=insert(root->left,x);
            root->lc= root->lc+1;
        }
        else
        {
            root->right=insert(root->right,x);
            root->rc+=1;
        }

        root->height= 1 + max(h(root->left),h(root->right));

        int balance= h(root->left)-h(root->right);

        if(balance > 1)
        {
            if(h(root->left)>=0)
                root=rot_right(root);
            else
                root=LR(root);
        }

        else if(balance<-1)
        {
            if(h(root->right)<=0)
                root=rot_left(root);
            else
                root=RL(root);
        }

        return root;
    }


    void insert(T x)
    {
        head=insert(head,x);
    }
/////////////////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////Lower Bound And Upper Bound////////////////////////////////////////////////


    node * lower_bound(node *root,T val,node *ans)
    {
        if(root==NULL)
            return ans;
        
        if(val>root->val)
            ans=lower_bound(root->right,val,ans);
        else
        {
            ans=root;
            ans=lower_bound(root->left,val,ans);
        }

        return ans;
    }

    T lower_bound(T val)
    {
        flag=false;
        node *ans=lower_bound(head,val,NULL);

        if(ans)
        {
            flag=true;
            return ans->val;
        }
        else
        {
            T temp;
            return temp;
        }
    }

    node * upper_bound(node *root,T val,node *ans)
    {
        if(root==NULL)
            return ans;
        
        if(val>=root->val)
            ans=upper_bound(root->right,val,ans);
        else
        {
            ans=root;
            ans=upper_bound(root->left,val,ans);
        }

        return ans;
    }

    T upper_bound(T val)
    {
        flag=false;
        node *ans=upper_bound(head,val,NULL);
        if(ans)
        {
            flag=true;
            return ans->val;
        }
        else
        {
            T temp;
            return temp;
        }
    }
//////////////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////Find Operation //////////////////////////////////////////////////
    bool find(node * root,T val)
    {
        if(root==NULL)
            return false;
        
        if(val < root->val)
            return find(root->left,val);
        else if(val > root->val)
            return find(root->right,val);
        else
            return true;
    }
    
    bool find(T val)
    {
        return find(head, val);
    }
////////////////////////////////////////Closest element///////////////////////////////////////////////
    T closest_ele(node * root,T val, T ans)
    {
        if(root==NULL)
            return ans;
        flag=true;
        if(abs(root->val-val)<abs(ans-val))
            ans=root->val;
        //cout<<ans<<endl;
        if(val<root->val)
        {
            T temp=closest_ele(root->left,val,ans);
            if(abs(temp-val)<abs(ans-val))
                ans=temp;
        }
        else if(val>root->val)
        {
            T temp=closest_ele(root->right,val,ans);
            if(abs(temp-val)<abs(ans-val))
                ans=temp;   
        }
        
        return ans;
    }

    T closest_ele(T val)
    {
        flag=false;
        T ans=closest_ele(head,val,100);
        //cout<<head->val<<endl;
        return ans;
    }
//////////////////////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////Deletion////////////////////////////////////////////////////////

    node * find_successor(node * root)
    {
        if(root->left==NULL)
            return root;
        else
            return find_successor(root->left);
    }



    node * deletion(node *root,T val)
    {
        if(root==NULL)
            return root;
        
        if(val < root->val)
        {
            root->left=deletion(root->left,val);
            root->lc-=1;
        }
        else if(val > root->val)
        {
            root->right=deletion(root->right,val);
            root->rc-=1;
        }

        else
        {
            //if(root->count>1)
            //{
            //    root->count-=1;
            //    return root;
            //}

            if(root->left==NULL && root->right==NULL)
            {
                delete root;
                root=NULL;
                return root;
            }
            else if(root->left!=NULL && root->right==NULL)
            {
                node*temp=root->left;
                delete root;
                root=temp;
            }

            else if(root->left==NULL && root->right!=NULL)
            {
                node*temp=root->right;
                delete root;
                root=temp;
            }

            else
            {
                node * ans=find_successor(root->right);
                root->val=ans->val;
                root->count=ans->count;
                root->right=deletion(root->right,ans->val);
                root->rc-=1;
            }
        }

        root->height= 1 + max(h(root->left),h(root->right));

        int balance= h(root->left)-h(root->right);

        if(balance > 1)
        {
            if(h(root->left)>=0)
                root=rot_right(root);
            else
                root=LR(root);
        }

        else if(balance<-1)
        {
            if(h(root->right)<=0)
                root=rot_left(root);
            else
                root=RL(root);
        }

        return root;
    }

    void deletion(T val)
    {
        if(find(val))
        {
            head=deletion(head,val);
        }
    }

///////////////////////////////////// Inorder Traversal /////////////////////////////////////
    void Inorder(node * root)
    {
        if(root==NULL)
            return;
        Inorder(root->left);
        for(int i=0;i<root->count;i++)
            cout<<root->val<<" ";
        Inorder(root->right);
    }

    void Inorder()
    {
        Inorder(head);
    }
///////////////////////////////////////// Counting occurances /////////////////////////////////

    int count_occurrence(node * root,T val)
    {
        if(root==NULL)
            return 0;
        
        if(val < root->val)
            return find(root->left,val);
        else if(val > root->val)
            return find(root->right,val);
        else
            return root->count;
    }

    int count_occurrence(T val)
    {
        return count_occurrence(head, val);
    }
/////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////// In Range Function //////////////////////////////////////////////

    void count_less_than_x(node * root,T x, int &count, bool &check)
    {
        if(root==NULL)
            return;
        if(x > root->val)
        {
            count+=(root->lc + root->count);
            count_less_than_x(root->right,x,count,check);
        }
        else if(x == root->val)
        {
            count+=(root->lc);
            check=true;
            count_less_than_x(root->right,x,count,check);
        }
        else
        {
            count_less_than_x(root->left,x,count,check);
        }
    }


    int inrange( T low, T high)
    {
        int ll=0,lh=0;
        bool lowp=false,highp=false;
        
        
        count_less_than_x(head,low,ll,lowp);
        count_less_than_x(head,high,lh,highp);
        lh+=(count_occurrence(high)-1);
        int ans= lh-ll;
        ans++;
        return ans;
    }

};

int main()
{
    AVL<abc> tree;
    abc a(12),b(12),c(11),d(10);
    tree.insert(a);
    tree.insert(b);
    tree.insert(c);
    tree.insert(d);
    //tree.insert(9);
    //tree.insert(1);
   // tree.deletion(11);
    //tree.deletion(9);
    tree.deletion(a);
    tree.Inorder();
    //cout<<tree.count_occurrence(1);
    //cout<<tree.find(12)<<endl;
    //cout<<tree.find(11)<<endl;
    //cout<<tree.find(11)<<endl;
    //cout<<tree.find(10)<<endl;
    //cout<<tree.find(9)<<endl;
    //cout<<tree.find(1)<<endl; 
    //cout<<tree.k_smallest(5);
    //cout<<tree.closest_ele(1);
    
    //cout<<tree.inrange(13,14);
    //int ans=tree.upper_bound(-1);
    //if(flag)
    //    cout<<ans;
}