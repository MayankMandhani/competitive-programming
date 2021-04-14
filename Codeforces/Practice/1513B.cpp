#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
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
const ll MAXM = 2e5 + 1;
vi fac(MAXM);


void solve() {

    
	 ll n, mn = INT_MAX; cin >> n;
	 vi a(n);

	 unordered_map<ll, ll> m;
	 m.reserve(1<<10);
	 m.max_load_factor(0.25);

	 rep(i,n) {
	 	cin >> a[i];
	 	m[a[i]]++;
	 	mn = min(mn, a[i]);
	 }

	 ll mn1 = mn, x = 0;
	 vi pos;
	 while(mn1) {
	 	if(mn1 & 1) pos.pb(x);
	 	mn1 >>= 1;
	 	x++;
	 }

	if(m[mn] < 2) {
		p1(0); return;
	}

	rep(i,n) {
		if(a[i] == mn) continue;
		for(auto p : pos) {
			if(a[i] & 1<<p) continue;
			else {
				p1(0); return;
			}
		}
	}

	ll ans = ((m[mn] * ((m[mn]-1)) % MOD) * fac[n-2]) % MOD;
	p1(ans);
}



int main()
{
	fastio;

    #ifndef ONLINE_JUDGE
        freopen("/home/devang/input.txt","r",stdin);
        freopen("/home/devang/output.txt","w",stdout);
    #endif

    fac[0] = fac[1] = 1;
    repb(i,2,MAXM) {
    	fac[i] = (i * fac[i-1]) % MOD;
    }

    w(tc)
    	solve();
	
	return 0;
}