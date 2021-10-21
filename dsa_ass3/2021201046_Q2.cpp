#include<iostream>
#include<vector>
#include<climits>
using namespace std;

vector<int> heap_pos;

class graph
{
    public:
    int v;
    int w;
    graph *next;
    graph()
    {
        v=-1;
        w=-1;
        next=NULL;
    }
    ~graph()
    {
        delete next;
    }
};

struct vertex_det
{
    int v;
    int parent;
    int distance;
};


void initialize(vertex_det heap[],int s, int no_of_nodes);
void heapify(vertex_det heap[],int s, int no_of_nodes);
void decrease_key(vertex_det heap[],int index);
void relax(vertex_det heap[],int child,int parent,int edge_weight);
void graph_initialize(graph *g[],int no_of_nodes);

int main()
{
    int vertex,edge;
    cout<<"Enter no of cities:";
    cin>>vertex;
    cout<<"Enter Number of roads:";
    cin>>edge;
    graph *g[vertex];
    graph_initialize(g,vertex);
    // Graph creation
    for(int i=0;i<edge;i++)
    {
        int source,destination,weight;
        cout<<"Enter the source:";
        cin>>source;
        cout<<"Enter the destination:";
        cin>>destination;
        cout<<"Enter the time taken:";
        cin>>weight;
        graph *temp1=new graph;
        temp1->v=destination;
        temp1->w=weight;
        temp1->next=g[source];
        g[source]=temp1;
        graph *temp2=new graph;
        temp2->v=source;
        temp2->w=weight;
        temp2->next=g[destination];
        g[destination]=temp2; 
    }
    int s;
    cout<<"Enter the city:";
    cin>>s;
    vertex_det heap[vertex];
    initialize(heap,s,vertex);
    int size=vertex-1;
    while(size>0)
    {
        vertex_det mini=heap[0];
        heap[0]=heap[size];
        heap[size]=mini;
        heap_pos[mini.v]=size;
        heap_pos[heap[0].v]=0;
        heapify(heap,0,size-1);
        int index=mini.v;
        //cout<<index;
        graph *temp=g[index];
        while(temp!=NULL)
        {
            if(heap_pos[temp->v]<size)
            {

                relax(heap,temp->v,index,temp->w);
            }

            temp=temp->next;
        }

        size--;
    }
    //dijktras algo finished 
    //Heap will have ans in descending order
    for(int i=0;i<vertex;i++)
        cout<<heap[i].distance<<" "<<heap[i].v<<endl;
}

void initialize(vertex_det heap[],int s, int no_of_nodes)
{
    //cout<<"hello";
    for(int i=0;i<no_of_nodes;i++)
    {
        heap[i].v=i;
        heap_pos.push_back(i);
        heap[i].distance=INT_MAX;
        heap[i].parent=-1;
    }
    heap_pos[s]=0;
    heap_pos[0]=s;
    heap[s].distance=0;
    vertex_det temp=heap[s];
    heap[s]=heap[0];
    heap[0]=temp;
    //cout<<"bye";
}

void graph_initialize(graph *g[],int no_of_nodes)
{
    for(int i=0;i<no_of_nodes;i++)
        g[i]=NULL;
}

void heapify(vertex_det heap[],int s, int no_of_nodes)
{
    vertex_det temp;
    int index=s;
    int left=2*s+1;
    int right=2*s+2;
    if(left<=no_of_nodes)
    {
        if((heap[left].distance<heap[s].distance) || (heap[left].distance==heap[s].distance && heap[left].v <heap[s].v))
        {
            heap_pos[heap[s].v]=left;
            heap_pos[heap[left].v]=s;
            temp=heap[s];
            heap[s]=heap[left];
            heap[left]=temp;
            index=left;
        }
    }
    if(right<=no_of_nodes)
    {
        if((heap[right].distance<heap[s].distance) || (heap[right].distance==heap[s].distance && heap[right].v <heap[s].v))
        {
            heap_pos[heap[s].v]=right;
            heap_pos[heap[right].v]=s;
            temp=heap[s];
            heap[s]=heap[right];
            heap[right]=temp;
            index=right;
        }
    }
    if(index==s)
        return ;
    heapify(heap,index,no_of_nodes);    
}


void relax(vertex_det heap[],int child,int parent,int edge_weight)
{
    if(heap[heap_pos[child]].distance>(heap[heap_pos[parent]].distance+edge_weight))
    {
        heap[heap_pos[child]].parent=parent;
        heap[heap_pos[child]].distance=(heap[heap_pos[parent]].distance+edge_weight);
        decrease_key(heap,heap_pos[child]);
    }
}


void decrease_key(vertex_det heap[],int index)
{
    if(index==0)
        return;
    int parent=(index-1)/2;
    if(heap[parent].distance > heap[index].distance || (heap[parent].distance==heap[index].distance && heap[parent].v>heap[index].v))
    {

        heap_pos[heap[parent].v]=index;
        heap_pos[heap[index].v]=parent;
        vertex_det temp=heap[parent];
        heap[parent]=heap[index];
        heap[index]=temp;
        decrease_key(heap,parent);
    }
}