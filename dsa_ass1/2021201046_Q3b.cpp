#include<iostream>
using namespace std;

template <typename T>
class array
{
    public:
void add(T mat1[][3],int len1,int row1,int col1,T mat2[][3],int len2, int row2,int col2)
{
    if(row1!=row2 || col1!=col2)
        return;
    T mat[row1*col1][3];
    int len=0;
    int i=0,j=0;
    while(i<len1 && j<len2)
    {
        if(mat1[i][0]<mat2[j][0])
        {
            mat[len][0]=mat1[i][0];
            mat[len][1]=mat1[i][1];
            mat[len][2]=mat1[i][2];
            i++;
            len++;
        }
        else if(mat2[j][0]<mat1[i][0])
        {
            mat[len][0]=mat2[j][0];
            mat[len][1]=mat2[j][1];
            mat[len][2]=mat2[j][2];
            j++;
            len++;
        }
        else if(mat1[i][1]<mat2[j][1])
        {
            mat[len][0]=mat1[i][0];
            mat[len][1]=mat1[i][1];
            mat[len][2]=mat1[i][2];
            i++;
            len++;
        }
        else if(mat2[j][1]<mat1[i][1])
        {
            mat[len][0]=mat2[j][0];
            mat[len][1]=mat2[j][1];
            mat[len][2]=mat2[j][2];
            j++;
            len++;
        }

        else
        {
            mat[len][0]=mat2[j][0];
            mat[len][1]=mat2[j][1];
            mat[len][2]=mat2[j][2]+mat1[i][2];
            i++;
            j++;
            len++;
        }
    }

    while(i<len1)
    {
        mat[len][0]=mat1[i][0];
        mat[len][1]=mat1[i][1];
        mat[len][2]=mat1[i][2];
        i++;
        len++;
    }
    while(j<len2)
    {
        mat[len][0]=mat2[j][0];
        mat[len][1]=mat2[j][1];
        mat[len][2]=mat2[j][2];
        j++;
        len++;
    }

    for(int i=0;i<len;i++)
    {
        for(int j=0;j<3;j++)
        {
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
}


int partition(T mat[][3], int start, int end)
{
    int pivot=start;
    int p=start;
    for(int i= start;i<=end;i++)
    {
        if(mat[i][0]< mat[pivot][0])
        {
            int td,tc,tr;
            td=mat[i][2];
            tc=mat[i][1];
            tr=mat[i][0];
            p++;
            mat[i][0]=mat[p][0];
            mat[i][1]=mat[p][1];
            mat[i][2]=mat[p][2];
            mat[p][0]=tr;
            mat[p][1]=tc;
            mat[p][2]=td;
        }
        else if(mat[i][0]==mat[pivot][0] && mat[i][1]<mat[pivot][1])
        {
            int tc,tr;
            T td;
            td=mat[i][2];
            tc=mat[i][1];
            tr=mat[i][0];
            p++;
            mat[i][0]=mat[p][0];
            mat[i][1]=mat[p][1];
            mat[i][2]=mat[p][2];
            mat[p][0]=tr;
            mat[p][1]=tc;
            mat[p][2]=td;
        }

    }

    if(p!=start)
    {
        int i=start;
        int td,tc,tr;
        td=mat[i][2];
        tc=mat[i][1];
        tr=mat[i][0];
        mat[i][0]=mat[p][0];
        mat[i][1]=mat[p][1];
        mat[i][2]=mat[p][2];
        mat[p][0]=tr;
        mat[p][1]=tc;
        mat[p][2]=td;   
    }

    return p;
}


void sort(T mat[][3],int start, int end)
{
    if(start>=end)
        return;
    int p=partition(mat,start ,end);
    sort(mat,start,p-1);
    sort(mat,p+1,end);
}

void transpose(T mat[][3], int size)
{
    for(int i=0;i<size;i++)
    {
        int temp=mat[i][0];
        mat[i][0]=mat[i][1];
        mat[i][1]=temp;
    }

    sort(mat,0,size-1);
}

void multiply(T mat1[][3],int len1,int row1,int col1,T mat2[][3],int len2, int row2,int col2)
{
    //cout<<"hello";
    if(col1!=row2)
    {
        cout<<"Multiplication not possible";
        return;
    }

    transpose(mat2,len2);
    
    int i=0,j=0;
    T ans[row1*col2][3];
    int len=0;
    while(i<len1)
    {
        int row=mat1[i][0];
        j=0;
        while(j<len2)
        {
            int col=mat2[j][0];
            T sum=0;
            int ta=i;
            int tb=j;
            while(ta<len1 && mat1[ta][0]==row && tb<len2 && mat2[tb][0]==col)
            {
                if (mat1[ta][1] > mat2[tb][1])
                    tb++;
                else if(mat1[ta][1] < mat2[tb][1])
                    ta++;
                else
                {
                    sum+=mat1[ta][2]*mat2[tb][2];
                    ta+=1;
                    tb+=1;
                }
            }

            if(sum)
            {
                ans[len][0]=row;
                ans[len][1]=col;
                ans[len][2]=sum;
                len++;
            }

            while( j  < len2 && mat2[j][0]==col)
                j++;
        }

        while( i<len1 && mat1[i][0]==row)
            i++;
    }

    for(int m=0;m<len;m++)
    {
        for(int n=0;n<3;n++)
        {
            cout<<ans[m][n]<<" ";
        }
        cout<<endl;
    }
}


void matrix()
{   int row1,col1;
    cout<<"Enter The Rows:";
    cin>>row1;
    cout<<"Enter The Colunms:";
    cin>>col1;
    T temp1[row1][col1];
    int size1=0;
    for(int i=0;i<row1;i++)
    {
        for(int j=0;j<col1;j++)
        {
            T temp;
            cin>>temp;
            temp1[i][j]=temp;
            if(temp)
                size1++;
        }
    }

    T mat[size1][3];
    int k=0;
    for(int i=0;i<row1;i++)
    {
        for(int j=0;j<col1;j++)
        {
            if(temp1[i][j])
            {
                mat[k][0]=i;
                mat[k][1]=j;
                mat[k][2]=temp1[i][j];
                k++;
            }
        }
    }

    int row2,col2;
    cout<<"Enter The Rows:";
    cin>>row2;
    cout<<"Enter The Colunms:";
    cin>>col2;
    T temp2[row2][col2];
    int size2=0;
    for(int i=0;i<row2;i++)
    {
        for(int j=0;j<col2;j++)
        {
            T temp;
            cin>>temp;
            temp2[i][j]=temp;
            if(temp)
                size2++;
        }
    }

    T mat2[size2][3];
    k=0;
    for(int i=0;i<row1;i++)
    {
        for(int j=0;j<col1;j++)
        {
            if(temp2[i][j])
            {
                mat2[k][0]=i;
                mat2[k][1]=j;
                mat2[k][2]=temp2[i][j];
                k++;
            }
        }
    }

    multiply(mat,size1,row1,col1,mat2,size2,row2,col2);
}

};
////////////////////////////////// Array important functions implemented/////////////////////////////////////////////////


/////////////////////////////////// Linked list implementation ///////////////////////////////////////////////////////////

//////////////////////////////////Linked list Important Functions Implemented ////////////////////////////////////////////////////////////////

/////////////////////////////////////////////Matrix to LL ////////////////////////////////////////////////////////////////////////////






///////////////////////////////////////////Matrix to LL /////////////////////////////////////////////////////////////////////////////////////
int main()
{
    array<int> a;
    a.matrix();
}