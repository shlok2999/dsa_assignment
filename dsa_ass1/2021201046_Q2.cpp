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
    int capacity;
    int size;
    frame *head;
    frame *tail;
    unordered_map<int,frame*> umap;
    public:
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
            frame *temp=umap[key];
            return temp->value;
        }
    }
    void set(int key,int value)
    {
        if(head==NULL)
        {
            frame *node=new frame;
            node->key=key;
            node->value=value;
            node->prev=NULL;
            node->next=NULL;
            head=node;
            tail=node;
            size++;
        }
        else if(size<capacity)
        {
            frame *node=new frame;
            node->key=key;
            node->value=value;
            node->prev=tail;
            node->next=NULL;
            tail->next=node;
            tail=node;
            size++;
        }
        else if(umap.find(key)!=umap.end())
        {
            
        }
        else
        {
            frame *last=tail;
            tail=last->prev;
            tail->next=NULL;
            last->prev=NULL;
            frame *node=new frame;
            node->key=key;
            node->value=value;
            node->prev=NULL;
            node->next=head;
            head->prev=node;
            head=node;
            delete last;
            //last->next=head;
            //head=last;
        }
    }

};