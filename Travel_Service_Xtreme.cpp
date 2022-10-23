#include <bits/stdc++.h>
#define SpeeD ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define ll long long
#define mdp memset (dp,-1,sizeof dp) ;
#define endl '\n'
using namespace std;
int const N = 1e4 + 5;
ll a[N], dp[10001][3000];
ll s, c, r;
pair<ll, ll> ap[N];

ll solve(int i, ll cap) {

    if(cap < 0) {
        return 1e6;
    }
    if (i >= s-1) {
        return 0;
    }
    ll &ans= dp[i][cap];
    if (~ans) return ans;
    ans = solve(i+1, cap-ap[i+1].first);
    ans = min(ans, solve(i+1, c - ap[i+1].first)+ (c-cap) * ap[i].second + 500);
    return ans;
}

int main() {
    int t; cin >> t;
    while (t--) {
    memset(dp , -1, sizeof(dp));
    cin >> s >> c >> r;
        for (int i =0; i < s; i++) {
            cin >> ap[i].first >> ap[i].second;
        }
        cout << solve(0, c-ap[0].first) + r*c << endl;

    }
    return 0;
}
