#include<bits/stdc++.h>
using i64 = long long;
constexpr int P = 998244353;

void solve() {
    int n, k;
    std::cin >> n >> k;
    std::set<std::pair<int, int>> set;
    for (int i = 0; i < n; i ++) {
        int l, r;
        std::cin >> l >> r;
        set.insert({l, -1});
        set.insert({r, 1});
    }

    i64 ans = 1;
    for (const auto &[x, y]: set) {
        if (y == -1) {
            ans = ans * k % P;
            k --;
        } else {
            k ++;
        }
    }
    std::cout << ans << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;

    while(t --) {
        solve();
    }

    return  0;
}

