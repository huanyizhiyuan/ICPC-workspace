#include<bits/stdc++.h>
#define i64 long long
#define int i64
using PII = std::pair<int,int>;
using TIII = std::tuple<int,int,int>;
constexpr int mod = 1e9+7;
constexpr int inf = 1e9+5;
int n,m,k;
using namespace std;
void solve()
{
    int n;
    cin>>n;
    vector<double>ans;
    for(int i=0;i<n;i++){
        double a,b,c;
        cin>>a>>b>>c;
        ans.push_back((1.0*a+b*c));
    }
    sort(ans.begin(),ans.end());
    double res=0,s=0;
    for(auto x:ans){
        s+=x;
        res+=s;
    }
    cout<<fixed<<setprecision(10)<<res<<endl;
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int T=1;
    std::cin>>T;
    while(T--)
    {
        solve();
    }
    return  0;
}

