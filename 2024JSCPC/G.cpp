#include<bits/stdc++.h>
#define i64 long long
// #define int i64
using PII = std::pair<int,int>;
using TIII = std::tuple<int,int,int>;
constexpr int mod = 1e9+7;
constexpr int inf = 1e9+5;
int n,m,k;

void solve()
{
    bool ok = false;
    int B, t1 , a1, t2, a2;
    double ans1 = 0, ans2 = 0;
    std::cin >> B >> t1 >> a1 >> t2 >> a2;

    std::cout << std::fixed << std::setprecision(10);

    // 我们让a1是先开始的。
    if(t1 > t2)
    {
        std::swap(t1, t2);
        std::swap(a1, a2);
        ok = true;
    }
    
    // a1单独使用的时间。
    int tt = t2 - t1;
    double need = a1 * 1.0 / B;

    if(need <= tt)
        ans1 += need, a1 = 0;
    else
        ans1 += tt, a1 -= tt * B;

    //考虑两个人分别还需要多少时间。
    double BB = B * 1.0 / 2;
    double ttt = std::min(a1 * 1.0 / BB, a2 * 1.0 / BB);
    ans1 += ttt, ans2 += ttt;

    double res1 = a1 * 1.0 - ttt * BB;
    double res2 = a2 * 1.0 - ttt * BB;

    if(res1)
        ans1 += res1 / B;
    if(res2)
        ans2 += res2 / B;

    if(!ok)
        std::cout << ans1 << " " << ans2 << "\n";
    else
        std::cout << ans2 << " " << ans1 << "\n";
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
