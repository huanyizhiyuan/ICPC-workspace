#include <bits/stdc++.h>
using namespace std;
#define i64 long long
#define int i64
using PII = std::pair<int,int>;
using TIII = std::tuple<int,int,int>;
constexpr int mod = 1e9 + 7;
constexpr int inf = 1e16 + 5;
constexpr int N = 5e5 + 5;

int n,  k;
map<string,set<string>>m;
void solve()
{
    int n;
    cin>>n;
    m.clear();
     int mx=0;
    string ans;
    for(int i=0;i<n;i++){
        string a,b,c;
        cin>>a>>b>>c;
        if(c=="accepted") {
              m[b].insert(a);
        }
        if(m[b].size()>mx) mx=m[b].size(),ans=b;
        if(m[b].size()==mx) {
             if(b<ans)  ans=b;
        }
    }


    cout<<ans<<endl;
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
