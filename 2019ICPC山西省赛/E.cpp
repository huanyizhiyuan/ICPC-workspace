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
    std::cin >> n >> k;
    std::string s;
    std::cin >> s;
    int len = s.size();
    s = " " + s;

    auto check = [&](int mid) -> bool
    {
        std::string t = s;

        int cnt = 0;

        for(int i = 1;i <= len;)
        {
            if(t[i] == '1')
            {
                i = i + mid;
                cnt ++;
                continue;
            }
            i ++;
        }

        return cnt <= k;
    };


    int l = 1, r = n, mid, ans = l;

    while(l <= r)
    {

        mid = l + r >> 1;
        if(check(mid))
            ans = mid, r = mid - 1;
        else
            l = mid + 1;
    }

    std::cout << ans << "\n";
}

signed main()
{
    // std::ios::sync_with_stdio(false);
    // std::cin.tie(nullptr);
    // std::cout.tie(nullptr);
    int T=1;
    std::cin>>T;
    while(T--)
    {
        solve();
    }
    return  0;
}

