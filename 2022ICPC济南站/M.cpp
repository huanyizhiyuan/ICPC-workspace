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
    std::vector<int> a(n + 1, 0);
    for (int i = 1; i <= n; i ++)
        std::cin >> a[i];

    int now = a[1], ans = 0;
    for (int i = 2; i <= n; i ++)
    {
        std::string s = std::to_string(now);
        std::string t = std::to_string(a[i]);
        now += a[i];
        std::string ss = std::to_string(now);

        std::reverse(s.begin(), s.end());
        std::reverse(t.begin(), t.end());
        std::reverse(ss.begin(), ss.end());

        bool ok = false;

        for (int j = 0; j < ss.size(); j ++)
        {
            int num = 0;
            if(s.size() > j) num = std::max(num, (int)(s[j] - '0'));
            if(t.size() > j) num = std::max(num, (int)(t[j] - '0'));
            if(!ok and num > ss[j] - '0')
                ans ++, ok = true;
            else if(!ok and num < ss[j] - '0')
                ok = false;
            else if(ok and num >= ss[j] - '0')
                ans ++, ok = true;
            else
                ok = false;
        }
    }
    std::cout << ans << "\n";
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

