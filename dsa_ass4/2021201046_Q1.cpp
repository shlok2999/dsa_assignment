#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
#include<map>
using namespace std;

class suffix
{
    public:
    int index;
    pair<int,int> rank;
    bool operator < (const suffix a)
    {
        return this->rank<a.rank;
    }
};



vector<int> suffix_array(string s);
vector<int> kasai(vector<int> &sa,string s);
string longest_pall(string s);
int longest_subst(string s);
int lcp(int i,int j,string s);
string cyclic_rotation(string s);

int main()
{
    string s;
    cin>>s;
    
    //lp=kasai(sa,s);
    string a=cyclic_rotation(s);
    cout<<a<<endl;
    int b=longest_subst(s);
    cout<<b<<endl;
    string c=longest_pall(s);
    cout<<c<<endl;
    // for(int i=0;i<sa.size();i++)
    // {
    //     cout<<s.substr(sa[i])<<endl;
    // }
}

vector<int> suffix_array(string s)
{
    // int size=s.length();
    // vector<suffix> ans(size);
    // for(int i=0;i<size;i++)
    // {
    //     ans[i].index=i;
    //     ans[i].rank.first=(int)(s[i]);
    //     if(i+1<size)
    //         ans[i].rank.second=(int)(s[i+1]);
    //     else
    //         ans[i].rank.second=-1;

    // }
    // sort(ans.begin(),ans.end());
    // vector<int> arr(size);
    // for(int k=2;k<2*size;k*=2)
    // {
    //     int nr=0;
    //     int prev=ans[0].rank.first;
    //     ans[0].rank.first=nr;
    //     arr[ans[0].index]=0;
    //     for(int i=1;i<size;i++)
    //     {
    //         if(ans[i].rank.first!=prev || ans[i].rank.second!=ans[i-1].rank.second )
    //             nr++;
    //         prev=ans[i].rank.first;
    //         ans[i].rank.first=nr;
    //         arr[ans[i].index]=i;
    //     }

    //     for(int i=0;i<size;i++)
    //     {
    //         int new_substr_index=ans[i].index + k;
    //         if(new_substr_index>=size)
    //             ans[i].rank.second=-1;
    //         else
    //             ans[i].rank.second=ans[arr[new_substr_index]].rank.first;
    //     }

    //     sort(ans.begin(),ans.end());
    // }

    // vector<int> sa;
    // for(suffix ss:ans)
    //     sa.push_back(ss.index);
    map<string,int> suffixes;
    vector<int>sa;
    string suffix="";
    for(int i=s.length()-1;i>=0;i--)
    {
        suffix=s[i]+suffix;
        suffixes[suffix]=i;
    }
    sa.clear();
    for(auto suffix:suffixes)
        sa.push_back(suffix.second);
    return sa;
}


vector<int> kasai(vector<int> &sa,string s)
{
    int n=sa.size();
    vector<int> rank(n,0);
    vector<int> lp(n,0);
    for(int i=0;i<n;i++)
        rank[sa[i]]=i;
    int k=0;
    for(int i=0;i<n;i++)
    {
        if(rank[i]!=0)
        {
            int j=sa[rank[i]-1];

            while(j+k<n && i+k<n)
            {
                if(s[j+k]==s[i+k])
                    k++;
                else
                    break;
            }    
            lp[rank[i]]=k;
            if(k==0)
                continue;
            k=k-1;
        }
        else
            k=0;
    }
    return lp;
}

int lcp(int i, int j, string s)
{
    if(s[i]!=s[j])
        return -1;
    else
    {
        int ans=0;
        int size=s.length();
        while(i<size  && j<size && s[i]==s[j])
        {
            ans++;
            i++;
            j++;
        }
        return ans;
    }
}

string longest_pall(string s)
{
    string revs=s;
    int size=s.size();
    reverse(revs.begin(),revs.end());
    string temp=s+"|"+revs;
    vector<int> suff=suffix_array(temp);
    vector<int> lp=kasai(suff,temp);
    int len=1;
    int index=suff[0];
    for(int i=1;i<suff.size();i++)
    {
        if((suff[i]<size && suff[i-1]>size) || (suff[i-1]<size && suff[i]>size))
        {
            if(lp[i]>len)
            {
                len=lp[i];
                index=suff[i];
            }
        }
    }

    return temp.substr(index,len);
}


int longest_subst(string s)
{   
    int k;
    cin>>k;
    vector<int> sa=suffix_array(s);
    int ans=-1;
    for(int i=0;i+k-1<sa.size();i++)
    {
        int start=sa[i];
        int end=sa[i+k-1];
        int temp=lcp(start,end,s);
        ans=max(ans,temp);
    }

    return ans;
}


string cyclic_rotation(string s)
{
    
    int size=s.size();
    string temp=s+s;
    vector<int> suff=suffix_array(temp);
    //vector<int> lp=kasai(suff,temp);
    
    int index=suff[0];
    for(int i=0;i<suff.size();i++)
    {
        if(suff[i]<size)
        {
            index=i;
            break;
        }

    }

    return temp.substr(index,size);   
}