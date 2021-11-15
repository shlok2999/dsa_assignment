#include<iostream>
#include<vector>
#include<algorithm>
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



vector<suffix> suffix_array(string s);


vector<suffix> suffix_array(string s)
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


    return ans;
}

int main()
{
    string s;
    cin>>s;
    vector<suffix> ans=suffix_array(s);

    for(int i=0;i<ans.size();i++)
    {
        cout<<s.substr(ans[i].index)<<endl;
    }
}