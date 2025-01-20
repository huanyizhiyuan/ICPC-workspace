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

    int odd = (n + 1) / 2;
    int even = n / 2;

    // 最后一组剩余：
    int res = n % k;
    // 总共这么多组：
    int num = n / k;
    // 每组应该分的奇数个数
    int oddnum = (k + 1) / 2;
    // 剩余的奇数：
    int resodd = odd - oddnum * num;
    // 可以共享的位置：
    int share = k - res;
    // 我是多算了一组，不管剩余的是不是0
    // 剩余的 + num * oddnum >= oddnum * (num + 1);
    // 演化成下面这个。
    // 其余组内一定可以平衡，所以我想要做的就是平衡最后一组。
    if(std::min(share, oddnum) + resodd >= oddnum)
        std::cout << "Yes\n";
    else
        std::cout << "No\n";
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

