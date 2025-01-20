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
    std::cin >> n;
    std::vector<int>visx(n + 1, 0);
    std::vector<int>visy(n + 1, 0);
    std::vector<std::vector<int>> a(n + 1, std::vector<int>(n + 1, 0));

    // int ans = 0;

    for(int i = 1;i <= n;i ++)
        for(int j = 1;j <= n;j ++)
        {
            std::cin >> a[i][j];
        }

    int res = 0;
    for(int i = 1;i <= n;i ++)
    {
        bool flag=false;
        vector<int>v;
        for(int j=1;j<=n;j++) v.push_back(a[i][j]);
        sort(v.begin(),v.end());
        int cnt=0;
        for(auto x:v){
            if(x<0) res+=x,cnt++;
        }
        if(cnt==0) res+=v[0];
    }
    int ans=0;
    for(int i = 1;i <= n;i ++)
    {
        bool flag=false;
        vector<int>v;
        for(int j=1;j<=n;j++) v.push_back(a[j][i]);
        sort(v.begin(),v.end());
        int cnt=0;
        for(auto x:v){
            if(x<0) ans+=x,cnt++;
        }
        if(cnt==0) ans+=v[0];
    }


    std::cout << min(res,ans) << "\n";
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int T = 1;
    std::cin>>T;
    while(T--)
    {
        solve();
    }
    return  0;
}

