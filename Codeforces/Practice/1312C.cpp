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

ll modPower(ll num,ll r) {
    if(r==0) return 1;
    if(r==1) return num;
    ll ans=modPower(num,r/2);
    if(r%2==0) {
        return (ans*ans);
    } return (((ans*ans))*num);
}

bool solve() {

	ll n, k, sumVal = 0, num; cin >> n >> k;
	vi a(n);
	rep(i,n) cin >> a[i];

	ll s = 16 * (log(10) / log(k)), zero = 0;
	ll x = modPower(k,s);
	while(s >= 0) {

		ll idx = -1;
		// watch(x);

		rep(i,n) {
			if(a[i] >= x) {
				if(idx == -1) idx = i;
				else return 0; 
			}
		}

		if(idx != -1) a[idx] -= x;
		x /= k;
		s--;
	}

	// watch(a);
	rep(i,n) if(a[i] != 0) return 0;
	return 1;
}


int main()
{
	fastio;

    #ifndef ONLINE_JUDGE
        freopen("/home/devang/input.txt","r",stdin);
        freopen("/home/devang/output.txt","w",stdout);
    #endif

    w(tc)
    	(solve()) ? p1("YES") : p1("NO");
	
	return 0;
}