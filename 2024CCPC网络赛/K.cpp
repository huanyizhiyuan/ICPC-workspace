#include<bits/stdc++.h>
#define i64 long long
#define int i64
using PII = std::pair<int,int>;
using TIII = std::tuple<int,int>;

int n,m,k;

void solve()
{
    std::cin >> n >> k;
    if(k >= n or (n & 1))
    {
        std::cout << "Alice\n";
        return ;
    }

    bool ok = false;
    for(int i = 1;i <= k;i <<= 1)
    {
        if(n % i == 0 and (n / i & 1))
            ok = true;
    }

    if(ok)
        std::cout << "Alice\n";
    else
        std::cout << "Bob\n";
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int T = 1;
    std::cin >> T;

    while(T --)
    {
        solve();
    }

    return 0;
}
