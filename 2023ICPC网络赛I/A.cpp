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
    std::cin >> n >> m;
    std::vector<std::string>a,b;
    std::set<std::string>se1,se2;
    for(int i = 1;i <= n;i ++)
    {
        std::string s;
        std::cin >> s;
        if(!se1.count(s))
        {
            a.push_back(s);
            se1.insert(s);
        }
    }
    for(int i = 1;i <= m;i ++)
    {
        std::string s;
        std::cin >> s;
        if(!se2.count(s))
        {
            se2.insert(s);
            b.push_back(s);
        }
    }

    // for(auto v:a)
    //     std::cout << v << "\n";

    // std::cout << "\n";

    // for(auto v:b)
    //     std::cout << v << "\n";

    // std::cout << "\n";

    int l = 0, r = 0, len1 = a.size(), len2 = b.size();
    se1.clear();
    while(true)
    {
        while(l < len1 and se1.count(a[l]))
            l ++;
        while(r < len2 and se1.count(b[r]))
            r ++;

        if(l == len1 and r == len2)
            break;

        if(l == len1)
        {
            se1.insert(b[r]);
            std::cout << b[r] << "\n";
            r ++;
            continue ;
        }
        if(r == len2)
        {
            se1.insert(a[l]);
            std::cout << a[l] << "\n";
            l ++;
            continue ;
        }

        if(l <= r)
        {
            std::cout << a[l] << "\n";
            se1.insert(a[l]);
            l ++;
            continue ;
        }
        else
        {
            std::cout << b[r] << "\n";
            se1.insert(b[r]);
            r ++;
            continue ;
        }
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

