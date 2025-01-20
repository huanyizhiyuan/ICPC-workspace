#include<bits/stdc++.h>
#define i64 long long
#define i128 __int128
#define int i64
using PII = std::pair<i128,i128>;
i128 n,m,k;

namespace FastIO
{
    i128 read()
    {
        i128 x=0;
        int f=1;char c=getchar();
        while(!isdigit(c)){if(c=='-') f=~f+1;c=getchar();}
        while(isdigit(c)){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
        return x*f;
    }
    void write(i128 x)
    {
        if(x<0){putchar('-');x=-x;}
        if(x>9) write(x/10);
        putchar(x%10+'0');
    }
    void Write(i128 x,char c='\n')
    {
        write(x);
        putchar(c);
    }
}

using namespace FastIO;

void solve()
{
    i128 a = read(), b = read();
    n = read();
    i128 x = a, y = b;
    //陷阱。
    x %= n,y %= n;

    std::map<PII,int>mp;

    i128 ans = 100 * 100 * 2;

    while(mp.find({x, y}) == mp.end())
    {
        mp[{x, y}] = 1;
        i128 tmp = x * x + y * y;
        if(tmp == 0)
            break;
        ans = std::min(ans, tmp);

        i128 step = std::min((n - x + a - 1) / a, (n - y + b - 1) / b);
        x += a * step;
        y += b * step;
        x %= n;
        y %= n;
    }

    write(ans);
    std::cout << "\n";
}

signed main()
{
    // std::ios::sync_with_stdio(false);
    // std::cin.tie(nullptr);
    // std::cout.tie(nullptr);
    int T=1;
    std::cin >> T;
    while(T--)
    {
        solve();
    }
    return  0;
}

