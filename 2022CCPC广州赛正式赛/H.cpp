#include<bits/stdc++.h>
// #define i64 long long
// #define int i64
using PII = std::pair<int,int>;
using TIII = std::tuple<int,int,int>;
constexpr int mod = 1e9+7;
constexpr int inf = 1e9+5;
int n,m,k;

std::map<int,int>mp;
void solve()
{
    mp.clear();
    std::cin >> n >> k;
    for(int i = 1;i <= n;i ++)
    {
        int x;
        std::cin >> x;
        mp[x] = 1;
    }

    int now = 0;
    for(int i = 0;i <= 2000000;i += 2)
    {
        if(now >= k)
            break;
        if(mp[i] == 0)
            mp[i] = 1,now ++;
    }

    now = 0;
    for(int i = 1;i <= 2000000;i += 2)
    {
        if(now >= k)
            break;
        if(mp[i] == 0)
            mp[i] = 1,now ++;
    }

    for(int i = 0;i <= 2000000;i ++)
    {
        if(mp[i] == 0)
        {
            if(i & 1)
                std::cout << "Bob\n";
            else
                std::cout << "Alice\n";
            break;
        }
    }
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

