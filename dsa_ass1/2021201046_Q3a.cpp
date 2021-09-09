#include<iostream>
using namespace std;
template <typename T>
class ll
{
    public:
struct matrix
{
    int col;
    T val;
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
            T sum=0;
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
            T temp;
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
            T temp;
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
        matrix *head=mat2[i];Monika
        while(head!=NULL)
        {
            cout<<i<<" "<<head->col<<" "<<head->val<<endl;
            head=head->next;
        }
    }
    */
}
};

int main()
{
    ll<int> a;
    a.sparsell();
}