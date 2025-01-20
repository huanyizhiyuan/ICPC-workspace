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

    std::vector<int>l(n + 10, 0);
    std::vector<int>r(n + 10, 0);
    std::vector<int>sum(n + 10, 0);
    std::vector<int>a(n + 10, 0);

    for(int i = 1;i <= n;i ++)
    {
        std::cin >> a[i];
        l[i] = r[i] = i;
        sum[i] = 0;
    }

    int nowl = 1, nowr = 1, now = 0;

    while(true)
    {
        // std::cout << std::format("nowl = {}, nowr = {},now = {}\n", nowl, nowr ,now);
        if(nowl == 1 and nowr == n)
        {
            std::cout << now << "\n";
            break;
        }

        //只考虑右边。
        if(nowl - 1 == 0)
        {
            //我要去右边。
            int tar = nowr + 1;
            if(a[nowr] > a[tar])
            {
                nowl = l[tar];
                nowr = r[tar];
                now = sum[tar];
            }
            //我和他一样合并它。
            else if(a[nowr] == a[tar])
            {
                /*
        ·           右边扩展
                    目标的左边扩展
                    大小扩展（加一个就行）
                    目标的大小扩展
                */
                nowr = r[tar];
                l[tar] = nowl;
                sum[tar] = now;
                sum[nowl] = now;
            }
            //我比它小，我要加上自身长度。
            else
            {
                /*
                    右边扩展
                    目标的左边扩展
                    大小扩展（加自身）
                    目标的大小扩展。
                */
                now = now + (nowr - nowl + 1) + sum[tar];
                nowr = r[tar];
                l[tar] = nowl;
                sum[tar] = now;
                sum[nowl] = now;
                a[nowl] = a[tar];
            }
            continue;
        }

        //只考虑左边。
        if(nowr + 1 == n + 1)
        {
            int tar = nowl - 1;
            if(a[nowl] > a[tar])
            {
                nowl = l[tar];
                nowr = r[tar];
                now = sum[tar];
            }
            //我和他一样合并它。
            else if(a[nowl] == a[tar])
            {
                /*
        ·           左边扩展
                    目标的右边扩展
                    大小扩展（加一个就行）
                    目标的大小扩展
                */
                nowl = l[tar];
                r[tar] = nowr;
                sum[tar] = now;
                sum[nowr] = now;
            }
            //我比它小，我要加上自身长度。
            else
            {
                /*
                    左边扩展
                    目标的右边扩展
                    大小扩展（加自身）
                    目标的大小扩展。
                */
                now = now + (nowr - nowl + 1) + sum[tar];
                nowl = l[tar];
                r[tar] = nowr;
                sum[tar] = now;
                sum[nowr] = now;
                a[nowr] = a[tar];
            }
            continue;
        }
        //考虑两边
        int tarl = nowl - 1, tarr = nowr + 1;
        if(a[tarl] == a[nowl])
        {
            /*
    ·           左边扩展
                目标的右边扩展
                大小扩展（加一个就行）
                目标的大小扩展
            */
            nowl = l[tarl];
            r[tarl] = nowr;
            sum[tarl] = now;
            sum[nowr] = now;
        }
        else if(a[tarr] == a[nowr])
        {
            /*
    ·           右边扩展
                目标的左边扩展
                大小扩展（加一个就行）
                目标的大小扩展
            */
            nowr = r[tarr];
            l[tarr] = nowl;
            sum[tarr] = now;
            sum[nowl] = now;
        }
        else if(a[tarl] < a[nowl])
        {
            nowl = l[tarl];
            nowr = r[tarl];
            now = sum[tarl];
        }
        else if(a[tarr] < a[nowr])
        {
            nowl = l[tarr];
            nowr = r[tarr];
            now = sum[tarr];
        }
        //最后一种情况，变成比我大的那个中小的那个。
        else
        {
            if(a[tarl] > a[tarr])
            {
                /*
                    右边扩展
                    目标的左边扩展
                    大小扩展（加自身）
                    目标的大小扩展。
                */
                now = now + (nowr - nowl + 1) + sum[tarr];
                nowr = r[tarr];
                l[tarr] = nowl;
                sum[tarr] = now;
                sum[nowl] = now;
                a[nowl] = a[tarr];
            }
            else
            {
                /*
                    左边扩展
                    目标的右边扩展
                    大小扩展（加自身）
                    目标的大小扩展。
                */
                now = now + (nowr - nowl + 1) + sum[tarl];
                nowl = l[tarl];
                r[tarl] = nowr;
                sum[tarl] = now;
                sum[nowr] = now;
                a[nowr] = a[tarl];
            }
        }
    }
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int T=1;
    std::cin >> T;
    while(T--)
    {
        solve();
    }
    return  0;
}

