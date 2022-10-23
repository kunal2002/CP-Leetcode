#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define fork(k,n) for(int i = k; i < n; ++ i)
#define fori(n) for(int i = 0; i < n; ++ i)
#define rfor(n) for(int i = n-1; i >= 0; ++ i)
#define forj(n) for(int j = 0; j < n; ++ j)
ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
#define mp make_pair
#define pb push_back
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
#define read(type) readInt<type>()
const double pi=acos(-1.0);
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<string> VS;
typedef map<int,int> mpii;


const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
//4 1 5
void solve() {
    int m;
    cin>>m;
    map<string,int> ch;
    fori(m){
        string a;
        cin>>a;
        int n;
        cin>>n;
        ch[a] += n;
        fori(n){
            string b;
            cin>>b;
            //cout<<b<<" ";
            ch[b]--;
        }
    }
    int meal = 0,day = 0;
    for(auto i:ch){
        if(i.second > 0){
            meal += i.second;
            day = max(i.second,day);
        }
    }
    cout << meal << " " << day << endl;
    
}
int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    freopen("error.txt","w",stderr);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    //int i = 1;
    while(t--){
        //cout<<"Case #"<<i<<": ";i++;
        solve();
    }
}
