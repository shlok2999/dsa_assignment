#include<iostream>
#include<vector>
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
        graph *temp=new graph;
        temp->v=destination;
        temp->w=weight;
        temp->next=g[source];
        g[source]=temp; 
    }
    int source;
    cout<<"Enter the city:";
    cin>>source;
    vertex_det heap[vertex];
    initialize(heap,source,vertex);
    int size=vertex-1;
    while(size>0)
    {
        vertex_det mini=heap[0];
        heap[0]=heap[size];
        heap[size]=mini;
        heapify(heap,0,size-1);
        int index=mini.v;
        graph *temp=g[index];
        while(temp!=NULL)
        {
            if(heap_pos[temp->v]<size)
            {
                relax(heap,temp->v,index,temp->w);
            }
        }

        size--;
    }
    //dijktras algo finished 
    //Heap will have ans in descending order
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
