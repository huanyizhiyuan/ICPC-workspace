#include<bits/stdc++.h>
#define i64 long long
#define int i64
using PII = std::pair<int,int>;
using TIII = std::tuple<int,int,int>;
constexpr int mod = 1e9+7;
constexpr int inf = 1e9+5;
int n,m,k;

void solve()
{
    std::cin >> n;
    std::vector<int>a(n + 1, 0);
    int mx = 0, num = 0;
    for(int i = 1;i <= n;i ++)
    {
        std::cin >> a[i];
        if(a[i] > mx)
        {
            num = 1;
            mx = a[i];
        }
        else if(a[i] == mx)
            num ++;
    }

    if(num & 1)
        std::cout << "Alice\n";
    else
        std::cout << "Bob\n";
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
