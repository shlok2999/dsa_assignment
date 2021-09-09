#include<iostream>
using namespace std;
////////////////////////////////////////Array all function other than converter function///////////////////////////////////////////////////////////////////
void add(double mat1[][3],int len1,int row1,int col1,double mat2[][3],int len2, int row2,int col2)
{
    if(row1!=row2 || col1!=col2)
        return;
    double mat[row1*col1][3];
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


int partition(double mat[][3], int start, int end)
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


void sort(double mat[][3],int start, int end)
{
    if(start>=end)
        return;
    int p=partition(mat,start ,end);
    sort(mat,start,p-1);
    sort(mat,p+1,end);
}

void transpose(double mat[][3], int size)
{
    for(int i=0;i<size;i++)
    {
        int temp=mat[i][0];
        mat[i][0]=mat[i][1];
        mat[i][1]=temp;
    }

    sort(mat,0,size-1);
}

void multiply(double mat1[][3],int len1,int row1,int col1,double mat2[][3],int len2, int row2,int col2)
{
    //cout<<"hello";
    if(col1!=row2)
    {
        cout<<"Multiplication not possible";
        return;
    }

    transpose(mat2,len2);
    
    int i=0,j=0;
    double ans[row1*col2][3];
    int len=0;
    while(i<len1)
    {
        int row=mat1[i][0];
        j=0;
        while(j<len2)
        {
            int col=mat2[j][0];
            double sum=0;
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
////////////////////////////////// Array important functions implemented/////////////////////////////////////////////////


/////////////////////////////////// Linked list implementation ///////////////////////////////////////////////////////////
struct matrix
{
    int col;
    double val;
    matrix *next;
};


matrix** transpose(matrix *mat[],int row,int col)
{
    matrix **result= new matrix*[col];
    matrix *tail[col];
    for(int i=0;i<col;i++)
    {
        result[i]=NULL;
        tail[i]=NULL;
    }

    for(int i=0;i<row;i++)
    {
        matrix *temp=mat[i];
        while(temp!=NULL)
        {
            matrix *node=new matrix;
            node->col=i;
            node->val=temp->val;
            node->next=NULL;
            int index=temp->col;
            temp=temp->next;
            if(result[index]==NULL)
            {
                result[index]=node;
            }
            else
            {
                tail[index]->next=node;
            }
            tail[index]=node;
        }
    }

    return result;

} 

void multiply(matrix *mat1[],int row1,int col1,matrix *mat2[],int row2,int col2)
{
    if(col1!=row2)
    {
        cout<<"No multiplication possible";
        return;
    }
    matrix *mat3[row1];
    for(int i=0;i<row1;i++)
    { 
           mat3[i]=NULL;
    }

    matrix **m2=transpose(mat2,row2,col2);
    for(int i=0;i<row1;i++)
    {
        matrix *t1;
        matrix *tail;
        t1=mat1[i];
        if(t1==NULL)
            continue;
        for(int j=0;j<col2;j++)
        {
            matrix *t11=t1;
            matrix *t2=m2[j];
            double sum=0;
            while(t2!=NULL && t11!=NULL)
            {
                if(t11->col==t2->col)
                {
                    sum+=(t11->val*t2->val);
                    t11=t11->next;
                    t2=t2->next;
                }
                else if(t11->col < t2->col)
                {
                    t11=t11->next;
                }
                else
                {
                    t2=t2->next;
                }
            }
            if(sum==0)
                continue;
            matrix *node=new matrix;
            node->col=j;
            node->val=sum;
            node->next=NULL;
            if(mat3[i]==NULL)
            {
                mat3[i]=node;
            }
            else
                tail->next=node;
            tail=node;  
        }    
    }
    
    
    for(int i=0;i<row1;i++)
    {
        matrix *head=mat3[i];
        while(head!=NULL)
        {
            cout<<i<<" "<<head->col<<" "<<head->val<<endl;
            head=head->next;
        }
    }
    
}

void add(matrix *mat1[],int row1,int col1,matrix *mat2[],int row2,int col2)
{
    if(row1!=row2 || col1!=col2)
    {
        cout<<"No addition possible";
        return;
    }
    matrix *result[row1];
    for(int i=0;i<row1;i++)
        result[i]=NULL;
    for(int i=0;i<row1;i++)
    {
        if(mat1[i]==NULL && mat2[i]==NULL)
            continue;
        matrix *t1=mat1[i];
        matrix *t2=mat2[i];
        matrix *tail;
        while(t1!=NULL && t2!=NULL)
        {
            matrix *node=new matrix;
            node->next=NULL;
            if(t1->col < t2->col)
            {
                node->col=t1->col;
                node->val=t1->val;
                t1=t1->next;
            }
            else if(t2->col < t1->col)
            {
                node->col=t2->col;
                node->val=t2->val;
                t2=t2->next;
            }
            else
            {
                node->col=t2->col;
                node->val=t2->val+t1->val;
                t2=t2->next;
                t1=t1->next;
            }

            if(result[i]==NULL)
                result[i]=node;
            else
                tail->next=node;
            tail=node;
        }

        if(t1!=NULL)
        {
            if(result[i]==NULL)
                result[i]=t1;
            else
                tail->next=t1;
        }

        else if(t2!=NULL)
        {
            if(result[i]==NULL)
                result[i]=t2;
            else
                tail->next=t2;
        }
    }
    
    for(int i=0;i<row1;i++)
    {
        matrix *head=result[i];
        while(head!=NULL)
        {
            cout<<i<<" "<<head->col<<" "<<head->val<<endl;
            head=head->next;
        }
    }
}
//////////////////////////////////Linked list Important Functions Implemented ////////////////////////////////////////////////////////////////

/////////////////////////////////////////////Matrix to LL ////////////////////////////////////////////////////////////////////////////

void sparsell()
{
    int row,col;
    cout<<"Enter Rows:";
    cin>>row;
    cout<<"Enter Colunms:";
    cin>>col;
    cout<<"Enter Matrix:\n";
    matrix *mat[row];
    for(int i=0;i<row;i++)
        mat[i]=NULL;
    matrix *tail;
    for(int i=0;i<row;i++)
    {   
        for(int j=0;j<col;j++)
        {
            double temp;
            cin>>temp;
            if(temp==0)
                continue;
            matrix *node=new matrix;
            node->next=NULL;
            node->col=j;
            node->val=temp;
            if(mat[i]==NULL)
                mat[i]=node;
            else
                tail->next=node;
            tail=node;
        }
    }
    
    cout<<"2nd Matrix:\n";
    int row2,col2;
    cout<<"Enter No. of rows:";
    cin>>row2;
    cout<<"Enter the no of colunms:";
    cin>>col2;
    matrix *mat2[row2];
    for(int i=0;i<row2;i++)
        mat2[i]=NULL;
    for(int i=0;i<row2;i++)
    {   
        for(int j=0;j<col2;j++)
        {
            double temp;
            cin>>temp;
            if(temp==0)
                continue;
            matrix *node=new matrix;
            node->next=NULL;
            node->col=j;
            node->val=temp;
            if(mat2[i]==NULL)
                mat2[i]=node;
            else
                tail->next=node;
            tail=node;
        }
    }
    
    cout<<"Ans is:\n";
    
    add(mat,row,col,mat2,row2,col2);
    /*
    matrix **mat1=transpose(mat,row,col);
    cout<<"Transpose of matrix is:\n";
    
    for(int i=0;i<row2;i++)
    {
        matrix *head=mat2[i];
        while(head!=NULL)
        {
            cout<<i<<" "<<head->col<<" "<<head->val<<endl;
            head=head->next;
        }
    }
    */
}




///////////////////////////////////////////Matrix to LL /////////////////////////////////////////////////////////////////////////////////////
int main()
{
    double mat[][3]={0,0,1,1,2,3,1,3,1};
    double mat1[][3]={0,0,1,1,2,3,1,3,1};
    //multiply(mat,3,2,4,mat1,3,4,4);
    sparsell();
    //transpose(mat1,3);
    /*
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            cout<<mat1[i][j]<<" ";
        }
        cout<<endl;
    }
    */
}