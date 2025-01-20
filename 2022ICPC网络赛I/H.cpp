#include<bits/stdc++.h>
#define i64 long long
#define int i64
using PII = std::pair<int,int>;
using TIII = std::tuple<int,int,int>;
constexpr int mod = 20220911;
constexpr int inf = 1e9+5;
int n,m,k;

void solve()
{
    std::string s;
    std::vector<std::string>a;

    while(true)
    {
        std::cin >> s;
        if(s == "fin")
            break;
        a.push_back(s);
    }

    int ans = 0, len = a.size();
    // std::cout << "len = " << len << "\n";

    auto fun = [&](auto self, int idx) -> PII
    {
        int now = 0;
        for(int i = idx;i < len;i ++)
        {
            // std::cerr<< now<<" "<<i<<"\n";
            if(a[i] == "library")
                now = (now + 1 + mod) % mod;
            if(a[i] == "arithmetic")
                continue;
            if(a[i] == "repeat")
            {
                auto [u,v] = self(self, i + 1);
                now = (now + u) % mod, i = v;
                continue ;
            }
            if(a[i] == "times")
                return {now, i};
            if(a[i] == "for")
                now *= std::stoll(a[i + 1]), i ++;
        }
        return {now, len - 1};
    };

    ans += fun(fun, 0).first;

    std::cout << ans << "\n";
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

