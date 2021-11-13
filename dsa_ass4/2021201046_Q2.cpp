#include<iostream>
#include<stdio.h>
#include<climits>
#include<vector>
#include <unistd.h>

using namespace std;

/////////////////////////////////////////// Classes and global variables //////////////////////////////////////////////////
vector<string> lof;

class heap
{
    public:
    class node
    {
        public:
        long long int file_num;
        int num;
        node()
        {
            file_num=-1;
            num=INT_MAX;
        }
        node(long long int val, long long int file_no)
        {
            num=val;
            file_num=file_no;
        }
    };    
    int size;
    node *heap_arr;
    heap(int n)
    {
        size=n;
        heap_arr=new node[n];
    }
    void insert(long long int i,long long int val,long long int file_num)
    {
        node n(val,file_num);
        heap_arr[i]=n;
    }

    void heapify(long long int i)
    {
        long long int l=2*i+1;
        long long int r=2*i+2;
        long long int index=i;
        if(l < size && heap_arr[l].num < heap_arr[index].num)    
            index=l;
        if(r < size && heap_arr[r].num < heap_arr[index].num)
            index=r;

        if(index!=i)
        {
            node temp=heap_arr[i];
            heap_arr[i]=heap_arr[index];
            heap_arr[index]=temp;
            heapify(index);
        }

    }


    void build_heap()
    {
        for(long long int i=size/2;i>=0;i--)
            heapify(i);
    }

    void rebuild_heap(node val)
    {
        heap_arr[0]=val;
        heapify(0);
    }

    ~heap()
    {
        delete [] heap_arr;
    }

};
/////////////////////////////////////////////////////// Function Defination ///////////////////////////////////////////////////////

void sort(char* input,char *out,int file_size);
void merge_sort_file(char* input,int file_size);
void merge_sort(int *arr,int start, int end);
void merge(int *arr,int start, long long int mid,long long int end);
void merge_file(char *output,int file_size);
void delete_file();

//////////////////////////////////////////////////// Main Funation //////////////////////////////////////////////////////////////

int main()
{
    int file_size=1000;
    int num_of_chunks;

}

/////////////////////////////////////////// Merge algorithm for file /////////////////////////////////////////////////////////////

void merge(int *arr,int start, long long int mid,long long int end)
{
    
    int size=end-start+1;
    int *temp=new int[size];
    int k=0,i=start,j=mid;

    while(k<size && i<mid && j<=end)
    {
        if(arr[i]<arr[j])
        {
            temp[k]=arr[i];
            i++;
            k++;
        }
        else
        {
            temp[k]=arr[j];
            k++;
            j++;
        }
    }

    while(i<mid)
    {
        temp[k]=arr[i];
        i++;
        k++;
    }

    while(j<=end)
    {
        temp[k]=arr[j];
        k++;
        j++;
    }

    for(k=0;k<size;k++)
    {
        arr[start+k]=temp[k];
    }
}

//////////////////////////////////////////////////  Merge algo implemented //////////////////////////////////////////////////////

void merge_sort(int *arr,long long int start,long long int end)
{
    if(start>=end)
        return;
    long long int mid=(start+end)/2;
    merge_sort(arr,start,mid-1);
    merge_sort(arr,mid,end);
    merge(arr,start,mid,end);
}



//////////////////////////////////////////// Function to perform External sort /////////////////////////////////////////////////

void sort(char* input,char *output,int file_size,int n)
{
    void merge_sort_file(char *input,int file_size,int n);
    void merge_file(char *output,int file_size);
}

////////////////////////////// Creating Small Temporary file and  each file has sorted data ///////////////////////

void merge_sort_file(char * input,long long int file_size)
{

    // Reading the input file
    FILE *in=fopen(input, "r");
    if(in == NULL)
    {
        cout<<"Unable to open file";
        exit(0);
    }
    int num_of_file=0;
    bool more_file=true;
    while(1)
    {
        //Initializing arr 
        int *arr=new int[file_size];
        int actual_size=0;       
        for(long long int i=0;i<file_size;i++)
        {
            if (fscanf(in, "%d,", &arr[i]) != 1) {
                more_file = false;
                break;
            }
            actual_size++;
        }
        if(actual_size==0) // Checking if the file is empty
        {
            delete [] arr;
            break;
        }

        // Creating name for temp file
        num_of_file++;
        string file_name="temp"+to_string(num_of_file);
        lof.push_back(file_name);

        // Sorting the array
        merge_sort(arr,0,actual_size-1);
        
        //Witing data in temp file        
        FILE *out=fopen(file_name.c_str(),"w");
        if(out==NULL)
        {
            cout<<"Can't open the temp file"<<num_of_file<<endl;
            delete [] arr;
            exit(0);
        }

        for(int i=0;i<actual_size;i++)
        {
            fprintf(out,"%d,", arr[i]);
        }
        fclose(out);
        delete [] arr;
        if(more_file==false)
            break;
    }

    fclose(in);
}

void delete_file()
{
    for(string s:lof)
    {
        unlink(s.c_str());
    }
}


///////////////////////////// K-way Merge Sort /////////////////////////////////////////////////

void merge_file(char *output,int file_size)
{
    int num_of_file=lof.size();
    FILE *out =fopen(output,"w");
    if(out==NULL)
    {
        delete_file();
        exit(0);
    }
    FILE *in[num_of_file];
    for(int i=0;i<num_of_file;i++)
    {
        in[i]=fopen(lof[i].c_str(),"r");
        if(in[i]==NULL)
        {
            for(int j=0;j<i;j++)
                fclose(in[j]);
            cout<<"Unable to open temporary File"<<i;
            exit(0);
        }
    }
}