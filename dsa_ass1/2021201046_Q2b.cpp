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

class LFU
{
    int capacity;
    int size;
    fn *head;
    unordered_map<int,frame*> umap;
    public:
    LFU(int n)
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
            fn *parent=temp->parent;
            frame *tp=temp->prev;
            frame *tn=temp->next;
            if(parent->next!=NULL && parent->next->freq==parent->freq+1)
            {
                //add(parent->next,temp);
            }
            else
            {
                if(parent->next==NULL)
                {
                    fn *t=new fn(parent->freq+1);
                    t->prev=parent;
                    parent->next=t;
                    //add(t,temp);
                }
                else
                {
                    fn *t=new fn(parent->freq+1);
                    t->prev=parent;
                    t->next=parent->next;
                    parent->next=t;
                    //add(t,temp);
                }
            }

            if(tp==NULL && tn==NULL)
            {
                //del(parent);
                return temp->value;
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
            return temp->value;
        }
    }



    void set(int key, int value)
    {
        if(head==NULL)
        {
            head=new fn(1);
            frame *node=new frame(key,value);
            head->head=node;
            head->tail=node;
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
                //add(parent->next,temp);
            }
            else
            {
                if(parent->next==NULL)
                {
                    fn *t=new fn(parent->freq+1);
                    t->prev=parent;
                    parent->next=t;
                    //add(t,temp);
                }
                else
                {
                    fn *t=new fn(parent->freq+1);
                    t->prev=parent;
                    t->next=parent->next;
                    parent->next=t;
                    //add(t,temp);
                }
            }

            if(tp==NULL && tn==NULL)
            {
                //del(parent);
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
            frame *node=new frame(key,value);
            if(head->freq==1)
            {
                //add(head,node);
            }
            else
            {
                fn *temp=new fn(1);
                temp->next=head;
                head->prev=temp;
                head=temp;
                //add(head,node);
            }
        }

        else
        {
            frame *node=new frame(key,value);
            if(head->freq==1)
            {
                //add(head,node);
                frame *temp=head->head;
                temp=temp->next;
                delete head->head;
                head->head=temp;
            }
            else
            {
                fn *h=new fn(1);
                h->next=head;
                head->prev=h;
                //add(h,node);
                frame *h1=head->head;
                frame *temp=h1;
                h1=h1->next;
                delete temp;
                head->head=h1;
                head=h;
                if(h1==NULL)
                {
                    delete(head->next);
                }
            }
        }
    }
};

int main()
{
    return 0;
}