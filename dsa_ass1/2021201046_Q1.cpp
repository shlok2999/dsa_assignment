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

int main()
{
    
    //cout<<"hello";
    string ans=multiply("11","22");
    cout<<ans;
}