#include<iostream>
#include<cstring>
#include<string.h>

using namespace std;

int to_num(char c)
{
    return (int)(c-'0');
}

char to_char(int i)
{
    return (char)i+'0';
}

string add(string num1, string num2)
{
    if(num1=="0")
        return num2;
    if(num2=="0")
        return num1;
    int i=num1.length()-1;
    int j=num2.length()-1;
    string ans="";
    int carry=0;
    while(i>=0 && j>=0)
    {
        int n1=to_num(num1[i]);
        int n2=to_num(num2[j]);
        int n3=n1+n2+carry;
        carry=n3/10;
        n3=n3%10;
        ans=to_char(n3)+ans;
        i--;
        j--;
    }

    string res="";
    if(i>=0)
        res=num1.substr(0,i+1);
    if(j>=0)
        res=num2.substr(0,j+1);
    
    while(carry)
    {
        if(res=="")
        {
            res="1";
            carry=0;
        }
        else if(i>=0)
        {
            int n3 =to_num(res[i]);
            n3= n3+1;
            carry=n3/10;
            res[i]=to_char(n3%10);
            i--;
            if(i<0 && carry)
            {
                res=to_char(carry)+ res;
                carry=0;
            }
        }
        else if(j>=0)
        {
            int n3 =to_num(res[j]);
            n3= n3+1;
            carry=n3/10;
            res[j]=to_char(n3%10);
            j--;
            if(j<0 && carry)
            {
                res=to_char(carry)+ res;
                carry=0;
            }
        }
        
    }
    ans=res+ans;
    return ans;
}



string subtract(string num1,string num2)
{
    if(num1==num2)
        return "0";
    int i=num1.length()-1;
    int j=num2.length()-1;
    int borrow=0;
    string ans="";
    while(i>=0 && j>=0)
    {
        int n1=to_char(num1[i]);
        int n2=to_char(num2[j]);
        int n3=n1-n2-borrow;
        if(n3<0)
        {
            n3+=10;
            borrow=1;
        }
        else
        {
            borrow=0;
        }
        ans=to_char(n3)+ans;
        i--;
        j--;
    }
    string res="";
    if(i>=0)
        res=num1.substr(0,i+1);
    while(borrow)
    {
        int n1=to_num(res[i]);
        n1-=borrow;
        if(n1<0)
        {
            n1+=10;
            borrow=1;
        }
        else
            borrow=0;
        res[i]=to_char(n1);
        i--;

    }

    ans=res+ans;
    int k;
    
    for(k=0;k<ans.length();k++)
    {
        if(ans[k]!='0')
            break;
    }

    if(k>ans.length()-1)
        return "0";
    return ans.substr(k);
}


string multiply(string num1,string num2)
{
    //cout<<"Hello";
    if( num1=="0" || num2=="0")
        return "0";
    int n=num1.length();
    int m=num2.length();
    string ans(n+m,'0');

    for(int i=n-1;i>=0;i--)
    {
        int n1=to_num(num1[i]);
        for(int j=m-1;j>=0;j--)
        {
            int n2=to_num(num2[j]);
            int product= n1*n2 + to_num(ans[i+j+1]);
            ans[i+j+1]= to_char(product%10);
            int carry=to_num(ans[i+j]);
            carry+=(product/10);
            ans[i+j]=to_char(carry);
        }
    }

    for(int k=0;k<ans.length();k++)
    {
        if(ans[k]!='0')
            return ans.substr(k);
    }

    return ans;
}

string factorial(string num)
{
    if(num=="0" || num=="1")
        return "1";
    string ans="1";
    while(!(num=="1"))
    {
        ans=multiply(ans,num);
        num=subtract(num,"1");
    }

    return ans;
}

string expo(string num, long long int power )
{
    if(power==0)
        return "1";
    if(power==1)
        return num;
    string ans="1";
    while(power>0)
    {
        if(power%2)
            ans=multiply(ans,num);
        power=power/2;
        num=multiply(num,num);
    }

    return ans;
}

bool greater_than(string num1,string num2)
{
    if(num1.length()>num2.length())
        return true;
    else if(num1.length()<num2.length())
        return false;
    else
    {
        int n=num1.length();
        for(int i=0;i<n;i++)
        {
            if(num1[i]<num2[i])
                return false;
            else if(num2[i]<num1[i])
                return true;
        }
        return true;
    }
}


string mod(string n1, string n2)
{                       //n1%n2
    if(n2==n1)
        return "0";
    
    if(greater_than(n2,n1))
        return n1;
    
    int len1=n1.length();
    int len2=n2.length();
    while(greater_than(n1,n2))
    {
        int tlen=len2;
        string num1=n1.substr(0,len2);
        if(num1==n2)
            num1="0";
        else if(greater_than(n2,num1) && num1[0]!='0' )
        {
            num1+=n1[len2];
            tlen++;
        }
        while(greater_than(num1,n2))
        {
            num1=subtract(num1,n2);
        }
        if(num1==n2)
            num1="0";
        
        string temp="";
        if(tlen+1<n1.length())
            temp=n1.substr(tlen+1);
        n1=num1+temp;
    }
   
    for(int i=0;i<n1.length();i++)
    {
        if(n1[i]!='0')
            return n1.substr(i);
    }

    return "0";
}


string gcd(string num1,string num2)
{
    if(num1=="0")
        return num2;
    if(num2=="0")
        return num1;
    //if(num1==num2)
    //    return num1;
    string x=num1;
    string y=num2;
    
    while(!(y=="0"))
    {
        x=mod(x,y);
        string temp=y;
        y=x;
        x=temp;
        //cout<<x;
        //cout<<y;
    }

    return x;
}

int priority(char ch)
{
    if(ch == 'x')
        return 1;
    else
        return 0;
}


string calculator(string expr)
{
    //The below code is for postfix notation
    int n=expr.length();
    string token[n];//Contain Postfix notation
    for(int i=0;i<n;i++)
        token[i]="";
    char stk1[n];
    int top=-1;
    int len=0;
    
    for(char ch:expr)
    {
        
        if(isdigit(ch))
            token[len]+=ch;
        else
        {
            len++;
            if(top==-1)
                stk1[++top]=ch;
            else if(priority(stk1[top])<priority(ch))
                stk1[++top]=ch;
            else
            {
                while(priority(stk1[top])>=priority(ch) && top!=-1)
                {
                    token[len]+=stk1[top];
                    len++;
                    top--;
                }
                stk1[++top]=ch;
            }
        }
    }
    if(top!=-1)
    {
        len++;
        while(top!=-1)
        {
            token[len]+=stk1[top];
            len++;
            top--;
        }
    }
    /*
    for(int i=0;i<=len;i++)
    {
        cout<<token[i]<<endl;
    }
    */
    //Here we will solve the question
    string stk2[len+1];
    top=-1;
    for(int i=0;i<=len;i++)
    {
        if(token[i]=="+")
        {
            string res= add(stk2[top-1],stk2[top]);
            top--;
            stk2[top]=res;
            
        }
        else if(token[i]=="-")
        {
            string res= subtract(stk2[top-1],stk2[top]);
            
            top--;
            stk2[top]=res;
            
        }
        else if(token[i]=="x")
        {
            string res= multiply(stk2[top-1],stk2[top]);
            top--;
            stk2[top]=res;
        }
        else
        {
            stk2[++top]=token[i];
        }
    }
    return stk2[0];
}




int main()
{
    
    //cout<<"hello";
    //string ans=calculator("23+245*43-80");
    //string ans=gcd("1","0");
    //cout<<ans;
    string ans="";
    int option;
    cin>>option;
    if(option==1)
    {
        string base;
        long long int power;
        cin>>base;
        cin>>power;
        ans=expo(base,power);
    }
    else if(option==2)
    {
        string num1,num2;
        cin>>num1;
        cin>>num2;
        ans=gcd(num1,num2);
    }
    else if(option==3)
    {
        string num;
        cin>>num;
        ans=factorial(num);
    }
    else
    {
        string expr;
        cin>>expr;
        ans=calculator(expr);
    }
    cout<<ans;
}