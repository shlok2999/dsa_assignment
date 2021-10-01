#include<iostream>
#include<climits>

using namespace std;
template <typename T>
class deque{
    T *arr;
    long long int start,end;
    int s,capacity;
    public:
    deque()
    {
        capacity=(1<<12);
        arr= new T[capacity];
        s=0;
        start=-1;
        end=-1;
    }

    deque(int n, T x)
    {
        capacity=(1<<12);
        arr= new T[capacity];
        s=n;
        for(int i=0;i<n;i++)
            arr[i]=x;
        
        start=0;
        end=n-1;
    }


    void clear()
    {
        delete[] arr;
        arr=NULL;
        start=-1;
        end=-1;
        s=0;
    }
    ~deque()
    {
        if(arr)
            clear();
    }

    void amort()
    {
        //capacity=capacity<<1;
        T *temp=new T[capacity*2];
        int i=0;
        while(start<=end)
        {
            temp[i]=arr[start];
            start=(start+1)%capacity;
            i++;
        }
        delete[] arr;
        arr=temp;
        temp=NULL;
        start=0;
        end=s-1;
        capacity=capacity<<1;
    }

    void push_back(T x)
    {
        if(s==capacity)
            amort();
        if(s==0)
        {
            start=0;
            end=0;
            arr[end]=x;
        }
        else
        {
            end=(end+1)%capacity;
            arr[end]=x;
        }
        s++;
    }

    void push_front(T x)
    {
        if(s==capacity)
            amort();
        if(s==0)
        {
            start=0;
            end=0;
            arr[start]=x;
        }
        else
        {
           if(start==0)
                start=capacity-1;
            else
                start--;
            arr[start]=x;
        }
        s++;
    }

    void pop_back()
    {
        if(s==0)
            return;
        if(s==1)
        {
            start=-1;
            end=-1;
        }
        else if(end==0)
            end=capacity-1;
        else
            end--;
        s--;
    }

    void pop_front()
    {
        if(s==0)
            return;
        if(s==1)
        {
            start=-1;
            end=-1;
        }
        else
            start=(start+1)%capacity;
        s--;
    }


    T front()
    {
        if(s==0)
        {
            return 0;
        }
            return arr[start];
    }

    T back()
    {
        if(s==0)
        {
            return 0;
        }
            return arr[end];
    }

    int size()
    {
        return s;
    }

    T operator [] (int n)
    {
        long long int index=(start+n)%capacity;
        return arr[index];
    }

    void resize(int n,T x)
    {
        if(n>capacity)
            amort();
        if(n>=s)
        {
            int len=n-s;
            for(int i=0;i<len;i++)
                this->push_back(x);
        }
        else
        {
            int len=s-n;
            for(int i=0;i<len;i++)
                this->pop_back();
        }
    }

};


int main()
{
    deque<string> d;
    int i=0;
    d.push_front("4");
    d.push_back("5");
    d.push_front("1");
    cout<<d.size()<<endl;
    
    d.resize(2,"x");
    cout<<d[0]<<" "<<d.back();
    cout<<endl<<d.size()<<endl;
}