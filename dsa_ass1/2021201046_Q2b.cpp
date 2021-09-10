#include<iostream>
#include<unordered_map>
using namespace std;

class frame;
class fn;


class frame
{
    public:
    int key;
    int value;
    frame *next;
    frame *prev;
    fn *parent;
    frame(int k, int v)
    {
        key=k;
        value=v;
        next=NULL;
        prev=NULL;
        parent=NULL;
    }
};


class fn
{
    public:
    int freq;
    fn *next;
    fn *prev;
    frame *head;
    frame *tail;
    fn(int f)
    {
        freq=f;
        next=NULL;
        prev=NULL;
        head=NULL;
        tail=NULL;
    }
};


class LFUCache {
    int capacity;
    int size;
    fn *head;
    unordered_map<int,frame*> umap;
public:
    LFUCache(int n) {
        capacity=n;
        size=0;
        head=NULL;
        
    }
    
    void add(fn *parent,frame *node)
    {
        node->parent=parent;
        node->next=NULL;
        if(parent->head==NULL)
        {
            parent->head=node;
            parent->tail=node;
            node->prev=NULL;
            return;
        }
        node->prev=parent->tail;
        parent->tail->next=node;
        parent->tail=node;
    }
    
    void del(fn *node)
    {
        fn *tp=node->prev;
        fn *tn=node->next;
        if(tp)
        {
            tp->next=tn;
        }
        else
        {
            head=tn;
        }
        if(tn)
        {
            tn->prev=tp;
        }
        delete node;
    }
    
    int get(int key) {
        
        if(umap.find(key)==umap.end() || capacity==0)
            return -1;
        else
        {
           // cout<<3;
            frame *temp=umap[key];
            fn *parent=temp->parent;
            frame *tp=temp->prev;
            frame *tn=temp->next;
            //cout<<parent;
            if(parent->next!=NULL && parent->next->freq==parent->freq+1)
            {
                add(parent->next,temp);
            }
            
            else
            {
                if(parent->next==NULL)
                {
                    fn *t=new fn(parent->freq+1);
                    t->prev=parent;
                    parent->next=t;
                    add(t,temp);
                }
                else
                {
                    fn *t=new fn(parent->freq+1);
                    t->prev=parent;
                    t->next=parent->next;
                    parent->next->prev=t;
                    parent->next=t;
                    add(t,temp);
                }
            }
    //cout<<3;
            if(tp==NULL && tn==NULL)
            {
                del(parent);
                return temp->value;
            }
            //cout<<3;
            if(tp)
            {
                tp->next=tn;
            }
            else
            {
                parent->head=tn;
            }
            if(tn)
            {
                tn->prev=tp;
            }
            else
            {
                parent->tail=tp;
            }
            //cout<<" "<<temp->parent->freq<<" ";
            return temp->value;
        }
        
    }
    
    void set(int key, int value) {
        
        if(capacity==0)
            return;
        
        if(head==NULL)
        {
            //cout<<"1";
            head=new fn(1);
            frame *node=new frame(key,value);
            umap[key]=node;
            head->head=node;
            head->tail=node;
            node->parent=head;
            size++;
        }
        else if(umap.find(key)!=umap.end())
        {
            frame *temp=umap[key];
            temp->value=value;
            fn *parent=temp->parent;
            frame *tp=temp->prev;
            frame *tn=temp->next;
            if(parent->next!=NULL && parent->next->freq==parent->freq+1)
            {
                add(parent->next,temp);
            }
            else
            {
                if(parent->next==NULL)
                {
                    fn *t=new fn(parent->freq+1);
                    t->prev=parent;
                    parent->next=t;
                    add(t,temp);
                }
                else
                {
                    fn *t=new fn(parent->freq+1);
                    t->prev=parent;
                    t->next=parent->next;
                    parent->next->prev=t;
                    parent->next=t;
                    add(t,temp);
                }
            }

            if(tp==NULL && tn==NULL)
            {
                del(parent);
                return;
            }
            if(tp)
            {
                tp->next=tn;
            }
            else
            {
                parent->head=tn;
            }
            if(tn)
            {
                tn->prev=tp;
            }
            else
            {
                parent->tail=tp;
            }
            return;
        }
        else if(size<capacity)
        {
            //cout<<2;
            size++;
            frame *node=new frame(key,value);
            umap[key]=node;
            if(head->freq==1)
            {
                add(head,node);
            }
            else
            {
                fn *temp=new fn(1);
                temp->next=head;
                head->prev=temp;
                head=temp;
                add(head,node);
            }
        }

        else
        {
            //cout<<4;
            frame *node=new frame(key,value);
            umap[key]=node;
            //cout<<key<<" "<<umap[key];
            if(head->freq==1)
            {
                
                frame *temp=head->head;
                umap.erase(temp->key);
                temp=temp->next;
                delete head->head;
                if(temp)
                    temp->prev=NULL;
                head->head=temp;
                add(head,node);
            }
            else
            {
                fn *h=new fn(1);
                h->next=head;
                head->prev=h;
                add(h,node);
                frame *h1=head->head;
                frame *temp=h1;
                umap.erase(temp->key);
                h1=h1->next;
                if(h1)
                h1->prev=NULL;
                delete temp;
                head->head=h1;
                head=h;
                if(h1==NULL)
                {
                    del(head->next);
                }
            }
        }
    }
};

        

int main()
{
    return 0;
}