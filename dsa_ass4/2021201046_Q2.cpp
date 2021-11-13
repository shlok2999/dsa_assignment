#include<iostream>
#include<stdio.h>
#include<climits>
#include<vector>
#include <unistd.h>
#include<algorithm>
#include<string.h>
using namespace std;

/////////////////////////////////////////// Classes and global variables //////////////////////////////////////////////////
vector<string> lof;

class node
{
    public:
    long long int file_num;
    long long int num;
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

class heap
{
    public:    
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

void solve(char* input,char *out,long long int file_size);
void merge_sort_file(char* input,long long int file_size);
void merge_sort(int *arr,long long int start,long long int end);
void merge(int *arr,int start, long long int mid,long long int end);
void merge_file(char *output,long long int file_size);
void delete_file();

//////////////////////////////////////////////////// Main Funation //////////////////////////////////////////////////////////////

int main(int argc, char *argv[])
{
    int file_size=50000;
    solve(argv[1],argv[2],file_size);

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

void solve(char* input,char *output,long long int file_size)
{
    merge_sort_file(input,file_size);
    merge_file(output,file_size);
    delete_file();
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
        long long int *arr=new long long int[file_size];
        long long int actual_size=0;       
        for(long long int i=0;i<file_size;i++)
        {
            if (fscanf(in, "%lld,", &arr[i]) != 1) {
                more_file = false;
                break;
            }
            cout<<arr[i]<<endl;
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
        sort(arr,arr+actual_size);
        
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
            fprintf(out,"%lld,", arr[i]);
        }
        fclose(out);
        memset(arr,0,sizeof(arr));
        delete [] arr;
        if(more_file==false)
            break;
    }

    fclose(in);
}
//////////////////////////////// Function to dlete temporaryy file ////////////////////////////
void delete_file()
{
    for(string s:lof)
    {
        unlink(s.c_str());
    }
}


///////////////////////////// K-way Merge Sort /////////////////////////////////////////////////

void merge_file(char *output,long long int file_size)
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
            fclose(out);
            cout<<"Unable to open temporary File"<<i;
            exit(0);
        }
    }


    int nofc=0; //No of file coppied till now
    heap h(num_of_file);
    for(int i=0;i<num_of_file;i++)
    {
        long long int num;
        if (fscanf(in[i], "%lld,", &num) != 1)
        {
            break;
        }
        cout<<num<<endl;
        h.insert(i,num,i);
    }

    h.build_heap();

    while(nofc!=num_of_file)
    {
        node min=h.heap_arr[0];
        fprintf(out,"%lld,", min.num);
        
        int file_num=min.file_num;

        long long int num;
        node new_val;
        if(fscanf(in[file_num],"%lld,",&num)!=1)
            nofc++;
        else
        {
            new_val.num=num;
            new_val.file_num=file_num;
        }
        
        h.rebuild_heap(new_val);
    }
    // close input and output files
    for (int i = 0; i < num_of_file; i++)
        fclose(in[i]);
 
    fclose(out);
}