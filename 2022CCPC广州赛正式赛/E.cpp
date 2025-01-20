#include<bits/stdc++.h>
#define i64 long long
#define int i64
using PII = std::pair<int,int>;
using TIII = std::tuple<int,int,int>;
constexpr int mod = 1e9+7;
constexpr int inf = 1e9+5;
const int N = 500005;
int n,m,k;

std::vector<int>c(N);
struct Fenwick_Tree_Array
{
    int lowbit(int x){return x&(-x);}

    //树状数组查找区间和[1,x]，类似前缀和。

    int Prefix_Sum(int x)
    {
        int res=0;
        for(int i=x;i;i-=lowbit(i))
            res+=c[i];
        return res;
    }

    //给x位置，加上y。
    void add(int x,int y)
    {
        //从小到大修改需要修改的位置。
        for(int i=x;i<=n;i+=lowbit(i))
            c[i]+=y;
    }
}FTA;


void solve()
{
    std::cin >> n >> k;
    std::vector<PII>a(n + 1, {0, 0});
    std::vector<int>b(n + 1, 0);
    std::vector<int>num(n + 1, 0);

    for(int i = 1;i <= n;i ++)
    {
        int x, y;
        std::cin >> x;
        y = i;
        a[i] = {x, y};
        b[i] = x;
    }

    std::sort(b.begin(),b.end());
    for(int i = 1;i <= n;i ++)
        num[i] = std::lower_bound(b.begin() + 1,b.end(),a[i].first) - b.begin();

    std::vector<int>ans(n + 1, 0);

    for(int i = 1;i <= n;i ++)
    {
        ans[i] = FTA.Prefix_Sum(num[i]) - FTA.Prefix_Sum(0);
        FTA.add(num[i], 1);
    }

    std::sort(a.begin() + 1, a.end());
    std::vector<int>sum(n + 1, 0);

    for(int i = 1;i <= n;i ++)
        sum[i] = sum[i - 1] + a[i].first;

    for(int i = 1;i <= n;i ++)
    {
        auto [val, pos] = a[i];
        ans[pos] = ans[pos] + (i - 1) * val - sum[i - 1] ;
    }

    for(int i = 1;i <= n;i ++)
    {
        if(ans[i] <= k - 2)
            std::cout << ans[i] << "\n";
        else
            std::cout << -1 << "\n";
    }
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int T=1;
    // std::cin>>T;
    while(T--)
    {
        solve();
    }
    return  0;
}

