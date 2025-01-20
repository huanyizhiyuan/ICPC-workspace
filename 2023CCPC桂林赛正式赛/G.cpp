#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef std::pair<int, int> pii;
#define N 1000100
void solve()
{
    string s;
    cin >> s;
    int cnt = 0;
    vector<int> ans;
    for (auto x : s)
    {
        if (x == '(')
            cnt++, ans.push_back(1);
        else
        {
            if (cnt)
                cnt--;
            else
                ans.push_back(0);
        }
    }
    if (cnt)
        cout << "impossible\n";
    else
        cout << s << "\n";
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
