#include<bits/stdc++.h>
#define i64 long long
#define int i64
using PII = std::pair<int,int>;
using TIII = std::tuple<int,int,int>;
constexpr int mod = 998244353;
constexpr int inf = 1e9+5;
int n,m,k;

struct linear_basis
{
    int cnt;
    bool zero;
    std::vector<int>p;
    std::vector<int>d;

    // 构造函数，初始化 p 为 64 个元素的向量，所有元素初始值为 0
    linear_basis() : p(100, 0), d(100, 0){
        cnt = 0;
        zero = false;
    }

    //插入线性基，时间复杂度O(logx)
    void insert(int x)
    {
        for(int i = 35;i >= 0;i --)
            if(x & (1ll << i))
            {
                if(!p[i])
                {
                    p[i] = x;
                    return ;
                }
                else
                    x ^= p[i];
            }
        zero = true;
    }

};

void solve()
{
    std::cin >> n;

    linear_basis LB;

    std::vector<int>a(n + 1, 0);
    std::vector<int>b(n + 1, 0);
    int A = 0, B = 0;

    for(int i = 1;i <= n;i ++)
    {
        std::cin >> a[i];
        A ^= a[i];
    }

    for(int i = 1;i <= n;i ++)
    {
        std::cin >> b[i];
        B ^= b[i];
    }

    for(int i = 1;i <= n;i ++)
        LB.insert(a[i] ^ b[i]);

    // for(int i = 0;i <= 10;i ++)
    //     std::cout << LB.p[i] << " \n"[i == 10];


    for(int i = 35;i >= 0;i --)
    {
        // int now = std::max(A, B);
        // int res = std::max(A ^ LB.p[i], B ^ LB.p[i]);
        // if (now > res)
        // {
        //     A ^= LB.p[i];
        //     B ^= LB.p[i];
        // }
        int base = (1ll << i), num = LB.p[i];
        if((A & base) and (B & base))
        {
            A ^= num;
            B ^= num;
        }
        else if(A & base or B & base)
        {
            if(std::max(A, B) > std::max(A ^ num,B ^ num))
            {
                A ^= num;
                B ^= num;
            }
        }
    }

    std::cout << std::max(A, B) << "\n";
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
