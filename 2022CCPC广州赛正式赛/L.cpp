#include<bits/stdc++.h>
#define i64 long long
#define int i64
using PII = std::pair<int,int>;
using TIII = std::tuple<int,int,int>;
constexpr int mod = 998244353;
constexpr int inf = 1e9+5;
using namespace std;
int n,m,k;

int ksm(int a, int b)
{
    int res = 1;
    while (b) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

std::vector<int>fac(200000+10,0);
std::vector<int>inv(200000+10,0);
void init()
{
    fac[0]=inv[0]=1;
    for(int i=1;i<=100005;i++)
    {
        fac[i]=fac[i-1]*i%mod;
        inv[i]=inv[i-1]*ksm(i, mod - 2)%mod;
    }
}


void solve()
{
    std::cin >> n >> m;

    auto C = [&](int x,int y)
    {
        return fac[x] * inv[x-y] % mod * inv[y] % mod;
    };

    std::cout<< fac[n] * C(n - 1, m - 1) % mod << "\n";
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int T=1;
    init();
    std::cin>>T;
    while(T--)
    {
        solve();
    }
    return  0;
}

