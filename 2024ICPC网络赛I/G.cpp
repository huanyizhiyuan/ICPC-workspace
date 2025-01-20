#include<bits/stdc++.h>
#define i64 long long
#define int i64
#define N 111000
using PII = std::pair<int,int>;
using TIII = std::tuple<int,int,int>;
constexpr int mod = 1e9+7;
constexpr int inf = 1e9+5;
int n,m,k;

// using namespace std;

void solve()
{
    std::cin >> n;
    std::vector<int>a(n + 1, 0);

    for(int i=1;i<=n;i++)
        std::cin >> a[i];

    std::sort(a.begin() + 1, a.end());

    std::multiset<int> b, c;

    for(int l=1;l<=n;l++)
    {
        for(int r=l;r<=n;r++)
        {
            int mid=(l + r + 1) / 2;
            b.insert(a[mid]);
        }
    }

    std::vector<int>res;
    res.push_back(-1);
    for(auto v:b)
        res.push_back(v);

    for(int i = 1;i < res.size();i ++)
    {
        for(int j = i;j < res.size();j ++)
        {
            int mid=(i + j + 1) / 2;
            c.insert(res[mid]);
        }
    }

    res.clear();
    int cnt = 0;
    res.push_back(-1);
    for(auto v:c)
    {
        res.push_back(v);
    }

    std::cout << res[(n+1) / 2] << "\n";

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

