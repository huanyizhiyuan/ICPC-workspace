#include<bits/stdc++.h>
#define i64 long long
#define int i64
using PII = std::pair<int,int>;
using TIII = std::tuple<int,int,int>;
constexpr int mod = 1e9+7;
constexpr int inf = 1e9+5;
int n,m,k;

using namespace std;
vector<int>ans;
void dfs(vector <int>&v,int d){
    for(auto x:v) cout<<x<<" ";
    cout<<endl;
    v.push_back(1);
    dfs(v,d+1);

    int cnt=0;
    for(auto x:v) cnt+=(x==1);
    int t=cnt;
    while(t--){
       v.push_back(0);
    }
    for(auto x:v){
        if(cnt==1) cnt--;
    }
    if(cnt==0){
        int res=0;
        for(int i=0;i<v.size();i++) {
            if(v[i]==1) res+=1ll<<i;
        }
        cout<<res<<endl;
        if(res<=1e9)
        ans.push_back(res);
    }
    else return ;
    v.pop_back();
    return ;
}
void solve(){
     int l,r;
     // cin>>l>>r;

}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int T=1;
    // std::cin>>T;
    vector<int>v;
    for(int i=1;i<=15;i++) {
        if(i==1) v.push_back(1ll<<i);
        else v.push_back(1ll<<(i+2)+1ll<<(i+1));
    }
    for(auto x:v) cout<<x<<endl;

    // dfs(v,1);
    for(auto x:ans ) cout<<x<<" ";
    while(T--)
    {
        // solve();
    }
    return  0;
}

