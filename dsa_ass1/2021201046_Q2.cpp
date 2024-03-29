#include<iostream>
#include<unordered_map>
using namespace std;

struct frame
{
    frame *prev;
    frame *next;
    int key;
    int value;
};
class LRU 
{
public:
    int capacity;
    int size;
    frame *head;
    frame *tail;
    unordered_map<int,frame*> umap;
    LRU(int n) 
    {
        capacity=n;
        size=0;
        head=NULL;
        
    }
    
    int get(int key) 
    {
        if(umap.find(key)==umap.end())
            return -1;
        else
        {
            //frame *temp=umap[key];
            frame *temp=umap[key];
            //temp->value=value;
            frame *tp=temp->prev;
            frame *tn=temp->next;
            if(tp)
            {
                tp->next=tn;
            }
            else
                return temp->value;
            if(tn)
            {
                tn->prev=tp;
            }
            else
            {
                tail=tp;
            }
            temp->prev=NULL;
            temp->next=head;
            head->prev=temp;
            head=temp;
            return temp->value;
        }
        
    }
    
    void set(int key, int value) 
    {
        if(capacity==0)
            return;
        if(head==NULL)
        {
            frame *node=new frame;
            umap[key]=node;
            node->key=key;
            node->value=value;
            node->prev=NULL;
            node->next=NULL;
            head=node;
            tail=node;
            size++;
        }
        else if(umap.find(key)!=umap.end())
        {
            frame *temp=umap[key];
            temp->value=value;
            frame *tp=temp->prev;
            frame *tn=temp->next;
            if(tp)
            {
                tp->next=tn;
            }
            else
                return;
            if(tn)
            {
                tn->prev=tp;
            }
            else
            {
                tail=tp;
            }
            temp->prev=NULL;
            temp->next=head;
            head->prev=temp;
            head=temp;
        }
        else if(size<capacity)
        {
            frame *node=new frame;
            node->key=key;
            umap[key]=node;
            node->value=value;
            node->prev=NULL;
            node->next=head;
            head->prev=node;
            head=node;
            size++;
        }
        
        else
        {
            frame *last=tail;
            umap.erase(last->key);
            tail=tail->prev;
            frame *node=new frame;
            node->key=key;
            node->value=value;
            umap[key]=node;
            node->prev=NULL;
            if(tail==NULL)
            {
                node->next=NULL;
                head=node;
                tail=node;
                delete last;
                return;
            }
            tail->next=NULL;
            last->prev=NULL;
            node->next=head;
            head->prev=node;
            head=node;
            delete last;
            //last->next=head;
            //head=last;
        }
    }
};

int main()
{
    return 0;
}