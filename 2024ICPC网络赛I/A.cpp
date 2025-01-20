#include <bits/stdc++.h>
using namespace std;
#define i64 long long
#define int i64
using PII = std::pair<int,int>;
using TIII = std::tuple<int,int,int>;
constexpr int mod = 1e9 + 7;
constexpr int inf = 1e16 + 5;
// constexpr int N = 5e5 + 5;
PII a[100];
int n, m, k;

void solve()
{
    int now=0;
    for(int i=1;i<=32;i++)
    {
        int x;
        cin>>x;
        a[i]={x,i};
    }
    sort(a+1,a+1+32);
    reverse(a+1,a+1+32);
    for(int i=1;i<=32;i++)
    {
        if(a[i].second==1)
        {
            now = i;
            break;
        }
    }

    if(now == 1) cout << 1 << endl;
    else if(now >= 2 and now <= 5) cout << 2 << endl;
    else if(now >= 6 and now <= 18) cout << 4 << endl;
    else if(now >= 19 and now <= 26) cout << 8 << endl;
    else if(now >= 27 and now <= 30) cout << 16 << endl;
    else cout << 32 << endl;
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);
    int T = 1;
    std::cin >> T;
    while(T --)
    {
        solve();
    }

    return 0;
}
