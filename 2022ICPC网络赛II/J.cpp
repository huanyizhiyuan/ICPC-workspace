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
    int mxl = 0, mxr = 0, mx = 0;
    for(int i = 1;i <= n;i ++)
        std::cin >> a[i];
    
    if(n == 1)
    {
        std::cout << "Alice\n";
        return ;
    }

    for(int i = 1;i < n;i ++)
    {
        if(a[i] >= a[i + 1])
        {
            mxl = i;
            break;
        }
    }

    for(int i = n;i > 1;i --)
    {
        if(a[i] >= a[i - 1])
        {
            mxr = i;
            break ;
        }
    }

    // std::cout << std::format("mxl = {}, mxr = {}\n", mxl, mxr);
    
    std::vector<int>win(n + 1, 0);
    for(int i = mxl;i >= 1;i --)
    {
        if(i == mxl)
        {
            win[i] = 1;
            continue ;
        }
        win[i] = win[i + 1] + 1;
    }

    for(int i = mxr;i <= n;i ++)
    {
        if(i == mxr)
        {
            win[i] = 1;
            continue ;
        }
        win[i] = win[i - 1] + 1;
    }

    if((win[1] & 1) and (win[n] & 1))
    {
        std::cout << "Alice\n";
        return ;
    }
    else if((win[1] % 2 == 0) and (win[n] % 2 == 0))
    {
        std::cout << "Bob\n";
        return ;
    }

    if(a[1] == a[n])
        std::cout << "Alice\n";
    else if(a[1] < a[n])
    {
        if((win[n]) & 1)
            std::cout << "Alice\n";
        else
        {
            if(a[1] < a[n] and win[n] % 2 == 0)
                std::cout << "Alice\n";
            else
                std::cout << "Bob\n";
        }
    }
    else
    {
        if((win[1]) & 1)
            std::cout << "Alice\n";
        else
        {
            if(a[n] < a[1] and win[1] % 2 == 0)
                std::cout << "Alice\n";
            else
                std::cout << "Bob\n";
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

