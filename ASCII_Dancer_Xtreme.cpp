// Obliviate, Mischief Managed!
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
typedef tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;
#define int long long
#define ar array
#define ll long long
#define FOR(n) for (int i = 0; i < n; ++i)
#define FOR1(n) for (int ii = 0; ii < n; ++ii)
#define pb(n) push_back
#define rep(i,a,b) for(int i = a;i<b;++i)
#define all(x) x.begin(), x.end()
 
const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

#ifndef ONLINE_JUDGE
#define debug(x) cout<<#x<<" is "<<x<<endl;
#define debugv(v) cout<<#v<< " is :-"<<endl;for(auto it: (v))cout<<it<<" ";cout<<endl;
#define debug2d(v) cout<<#v<< " is :-"<<endl;cn=0;for(auto it: (v)) {cout<<cn<<" => ";cn++; for(auto j:it) cout<<j<<" ";cout<<endl;}
#define pline(x) cout<<x<<" line is reached"<<endl;
#define debugvp(v) cout<<#v<<" is :-"<<endl;for(auto i: v){cout<<"("<<i.ff<<","<<i.ss<<")"<<" ";}cout<<endl;
#define prline cout<<endl;
#define debugpair(p) cout<<#p<<" is ("<<p.ff<<","<<p.ss<<")"<<endl;
#define print(s) cout<<s<<endl;
#else
#define debug(x)
#define debugv(v)
#define debug2d(v)
#define pline(x)
#define debugvp(v)
#define prline
#define debugpair(p)
#define print(s) 
#endif

int gcd(int a, int b)
{
    if(b == 0) return a;
    return gcd(b,a%b);
}
int fastpow(int a, int b)
{
    int res = 1;
    while(b > 0)
    {
        if((b&1))
            res *= a;
        a *= a;
        b = b >> 1;
    }
    return res;
}
int grdways(int n, int m)
{
    if(n == 1 || m == 1)
        return 1;
    return grdways(n-1,m) + grdways(n, m-1);
}
//Operator Overloads
template<typename T> // cin >> vector<T>
istream& operator>>(istream &istream, vector<T> &v)
{
  for (auto &it : v)
    cin >> it;
  return istream;
} 

template<typename T1, typename T2> // cin >> pair<T1, T2>
istream& operator>>(istream &istream, pair<T1, T2> &p) { return (istream >> p.first >> p.second); }

template<typename T> // cout << vector<T>
ostream& operator<<(ostream &ostream, const vector<T> &c) { for (auto &it : c) cout << it << " "; return ostream; }

template<typename T1, typename T2> // cout << pair<T1, T2>
ostream& operator<<(ostream &ostream, const pair<T1, T2> &p) { return (ostream << p.first << " " << p.second); }

// For Kickstart : cout << "Case #" << tt <<": " << ans << "\n";

void init()
{
  #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
  #endif
}
void turnit(vector<string>& vec)
{
    FOR(3)
    {
        rep(j,0,3)
        {
            if(vec[i][j] == ')')
            {
                vec[i][j] = '(';
                continue;
            }
            if(vec[i][j] == '(')
            {
                vec[i][j] = ')';
                continue;
            }
            if(vec[i][j] == '<')
            {
                vec[i][j] = '>';
                continue;
            }
            if(vec[i][j] == '>'){
                vec[i][j] = '<';
                continue;
            }
            if(vec[i][j] == '/'){
                vec[i][j] = '\\';
                continue;
            }
            if(vec[i][j] == '\\'){
                vec[i][j] = '/';
                continue;
            }
        }
    }
}
void p(vector<string> s)
{
    FOR(3)
    {
        cout << s[i] << "\n";
    }
}
void solve()
{
    int n; cin >> n;
    map<string,vector<string>> mp;
    vector<string> s;
    s.push_back(" o ");
    s.push_back("/|\\");
    s.push_back("/ \\");
    // FOR(s.size())
    // {
    //     cout << s[i] << "\n";
    // }
    int turn = 0;
    string str;
    FOR(n)
    { 
        getline(cin, str);
        // cout << str << "\n";
        if(str[0] == 's' && str[1] == 'a' && str[2] == 'y')
            {
                FOR(4)
                {
                    str.erase(str.begin());
                }
                cout << str << "\n";
                continue;
            }
        if(turn == 0)
        {
            if(str.find("right") != string::npos && str.find("in") != string::npos)
            {
                s[2][0] = '<';
                p(s);
                continue;
            }
            if(str.find("right") != string::npos && str.find("out") != string::npos)
            {
                s[2][0] = '/';
                p(s);
                continue;
            }
            if(str.find("left") != string::npos && str.find("in") != string::npos)
            {
                s[2][2] = '>';
                p(s);
                continue;
            }
            if(str.find("left") != string::npos && str.find("out") != string::npos)
            {
                s[2][2] = '\\';
                p(s);
                continue;
            }
            if(str.find("left") != string::npos && str.find("hip") != string::npos)
            {
                s[1][2] = '>';
                s[0][2] = ' ';
                p(s);
                continue;
            }
            if(str.find("right") != string::npos && str.find("hip") != string::npos)
            {
                s[1][0] = '<';
                s[0][0] = ' ';
                p(s);
                continue;
            }
            if(str.find("left") != string::npos && str.find("head") != string::npos)
            {
                s[0][2] = ')';
                s[1][2] = ' ';
                p(s);
                continue;
            }
            if(str.find("right") != string::npos && str.find("head") != string::npos)
            {
                s[0][0] = '(';
                s[1][0] = ' ';
                p(s);
                continue;
            }
            if(str.find("left") != string::npos && str.find("start") != string::npos)
            {
                s[1][2] = '\\';
                s[0][2] = ' ';
                p(s);
                continue;
            }
            if(str.find("right") != string::npos && str.find("start") != string::npos)
            {
                s[1][0] = '/';
                s[0][0] = ' ';
                p(s);
                continue;
            }
            if(str == "turn")
            {
                //  turn = 1;
                reverse(all(s[0]));
                reverse(all(s[1]));
                reverse(all(s[2]));
                turnit(s);
                p(s);
            }
        }
    }
    getline(cin , str);
    if(str[0] == 's' && str[1] == 'a' && str[2] == 'y')
            {
                FOR(4)
                {
                    str.erase(str.begin());
                }
                cout << str << "\n";
                // continue;
            }
        if(turn == 0)
        {
            if(str.find("right") != string::npos && str.find("in") != string::npos)
            {
                s[2][0] = '<';
                p(s);
                // continue;
            }
            if(str.find("right") != string::npos && str.find("out") != string::npos)
            {
                s[2][0] = '/';
                p(s);
                // continue;
            }
            if(str.find("left") != string::npos && str.find("in") != string::npos)
            {
                s[2][2] = '>';
                p(s);
                // continue;
            }
            if(str.find("left") != string::npos && str.find("out") != string::npos)
            {
                s[2][2] = '\\';
                p(s);
                // continue;
            }
            if(str.find("left") != string::npos && str.find("hip") != string::npos)
            {
                s[1][2] = '>';
                s[0][2] = ' ';
                p(s);
                // continue;
            }
            if(str.find("right") != string::npos && str.find("hip") != string::npos)
            {
                s[1][0] = '<';
                s[0][0] = ' ';
                p(s);
                // continue;
            }
            if(str.find("left") != string::npos && str.find("head") != string::npos)
            {
                s[0][2] = ')';
                s[1][2] = ' ';
                p(s);
                // continue;
            }
            if(str.find("right") != string::npos && str.find("head") != string::npos)
            {
                s[0][0] = '(';
                s[1][0] = ' ';
                p(s);
                // continue;
            }
            if(str.find("left") != string::npos && str.find("start") != string::npos)
            {
                s[1][2] = '\\';
                s[0][2] = ' ';
                p(s);
                // continue;
            }
            if(str.find("right") != string::npos && str.find("start") != string::npos)
            {
                s[1][0] = '/';
                s[0][0] = ' ';
                p(s);
                // continue;
            }
            if(str == "turn")
            {
                //  turn = 1;
                reverse(all(s[0]));
                reverse(all(s[1]));
                reverse(all(s[2]));
                turnit(s);
                p(s);
            }
        }
}
int32_t main() 
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   init();
   clock_t tt = clock();
   int t=1;
    cin>>t;
//   int i = 1;
   while(t--)
   {
      solve();
   }
   cerr << "RunTime: " << ((double)(clock() - tt) / CLOCKS_PER_SEC);
   return 0;
}
