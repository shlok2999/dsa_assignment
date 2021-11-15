#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
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
vector<int> sa;
vector<int> lp;

vector<int> suffix_array(string s);
vector<int> kasai(vector<int> &sa,string s);
int lcp(int i,int j);

int main()
{
    string s;
    cin>>s;
    sa=suffix_array(s);
    lp=kasai(sa,s);
    // for(int i=0;i<sa.size();i++)
    // {
    //     cout<<s.substr(sa[i])<<endl;
    // }
}

vector<int> suffix_array(string s)
{
    int size=s.length();
    vector<suffix> ans(size);
    for(int i=0;i<size;i++)
    {
        ans[i].index=i;
        ans[i].rank.first=(int)(s[i]);
        if(i+1<size)
            ans[i].rank.second=(int)(s[i+1]);
        else
            ans[i].rank.second=-1;

    }
    sort(ans.begin(),ans.end());
    vector<int> arr(size);
    for(int k=2;k<2*size;k*=2)
    {
        int nr=0;
        int prev=ans[0].rank.first;
        ans[0].rank.first=nr;
        arr[ans[0].index]=0;
        for(int i=1;i<size;i++)
        {
            if(ans[i].rank.first!=prev || ans[i].rank.second!=ans[i-1].rank.second )
                nr++;
            prev=ans[i].rank.first;
            ans[i].rank.first=nr;
            arr[ans[i].index]=i;
        }

        for(int i=0;i<size;i++)
        {
            int new_substr_index=ans[i].index + k;
            if(new_substr_index>=size)
                ans[i].rank.second=-1;
            else
                ans[i].rank.second=ans[arr[new_substr_index]].rank.first;
        }

        sort(ans.begin(),ans.end());
    }

    vector<int> sa;
    for(suffix ss:ans)
        sa.push_back(ss.index);
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

            while(j=k<n && i+k<n && s[i+k]==s[j+k])
                k++;
            lp[rank[i]]=k;
            if(k)
                k--;
        }
        else
            k=0;
    }
    return lp;
}

int lcp(int i, int j)
{
    int mini=INT_MAX;
    for(int k=i+1;k<=j;k++)
    {
        mini=min(mini,lp[k]);
    }
    return mini;
}