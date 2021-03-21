#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define fi first
#define se second
#define rep(i,n) for(ll i = 0 ; i < n ; i++)
#define repe(i,n) for(ll i = 0 ; i <= n ; i++)
#define repb(i,a,b) for(ll i = a ; i < b ; i++)
#define repeb(i,a,b) for(ll i = a ; i <= b ; i++)
#define rfor(i,n,a) for(ll i = n ; i >= a ; i--)
#define pb push_back
#define endl "\n"
#define vi vector<ll>
#define vvi vector<vi>
#define pii pair <ll,ll>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define p0(a) cout << a << " "
#define p1(a) cout << a << endl
#define p2(a,b) cout << a << " " << b << endl
#define watch(x) cout << (#x) << " is " << (x) << endl
#define w(x) ll x; cin>>x; while(x--)

    template <typename T1, typename T2>
inline std::ostream& operator << (std::ostream& os, const std::pair<T1, T2>& p)
{
    return os << "(" << p.first << ", " << p.second << ")";
}

    template<typename T>
inline std::ostream &operator << (std::ostream & os,const std::vector<T>& v)
{
    bool first = true;
    os << "[";
    for(unsigned int i = 0; i < v.size(); i++)
    {
        if(!first)
            os << ", ";
        os << v[i];
        first = false;
    }
    return os << "]";
}

/*-------------------------------------------------*/

// read once, read again, think, code

void solve() {

    string s; cin >> s;
    ll n = s.size();
    ll adj0 = 0, adj1 = 0;
    bool firstone = false, sorted = true;

    ll ones = 0, zeroes = 0;
    rep(i,n) {
        (s[i] == '0') ? zeroes++ : ones++;
    }

    ll onesOG = ones;

    rep(i,n-1) {

        (s[i] == '0') ? zeroes-- : ones--;

        if(s[i] == '1') firstone = true;
        if(s[i] == '0' and firstone) sorted = false;
        if(s[i] == '0' and s[i+1] == '0') {
            if(ones < onesOG) adj0 = i+1;
        }
        if(s[i] == '1' and s[i+1] == '1') {
            if(zeroes > 0 and adj1 == 0) adj1 = i+1;
        }
    }

    if(sorted) p1("YES");
    else if(adj0 > 0 and adj1 > 0 and adj0 > adj1) p1("NO");
    else p1("YES");
}


int main()
{
    fastio;

    #ifndef ONLINE_JUDGE
    freopen("/home/devang/input.txt","r",stdin);
    freopen("/home/devang/output.txt","w",stdout);
    #endif

    w(tc)
    solve();
    
    return 0;
}