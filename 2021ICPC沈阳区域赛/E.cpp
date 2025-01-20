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
    std::string s, ss = "edgnb";
    std::cin >> s;

    int ans = 0, now = 0;

    for(auto v : s)
    {
        if(v == ss[now])
            now ++;
        else if(v != ss[now] and v != 'e')
            now = 0;
        else if(v == 'e')
            now = 1;

        if(now == 5)
            now = 0,ans ++;
    }

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

