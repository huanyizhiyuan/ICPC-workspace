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

    std::string s;
    std::map<std::string, int>mp;

    for(int i = 1;i <= n;i ++)
    {

        std::cin >> s;
        mp[s] ++;
    }

    if(n == 1)
    {
        std::cout << s << "\n";
        return ;
    }


    for(auto [u, v] : mp)
    {
        if(v > n / 2)
        {
            std::cout << u << "\n";
            return ;
        }
    }

    std::cout << "uh-oh\n";
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

