	#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define int long long
#define pb push_back
#define endl "\n"
#define bn begin()
#define en end()
#define ppb pop_back
#define ff first
#define ss second
#define pii pair<int,int>
#define loop(i,a,b) for(int i=a;i<b;i++)
#define bs binary_search
const int inf= 1e18,mod=1e9+7;
typedef tree<int/*data type*/, null_type, less/*comparator the way we want to campare*/<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order(return the pointer) use * to get the value, order_of_key
#define compar bool compare(int a,int b){return a>b;}
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define per(x) fixed<<setprecision(x)<<  // syntax:-cout<<per(jitni decimal place chahiyaen)variable name;
//bool compare(pair<int,int> a,pair<int,int> b){if(a.first==b.first)return a.second<b.second;return a.first<b.first;}
//if an element have a divisor i less than sqrt(n) the it will definately have n/i as a divisor
// (a/b) %m = a%m *binpow(b,m-2) provided b and m are co-prime.
// negative number ka mod tackle karne ke liyaen uss number me mod jod kar mod kar lo
int binpow(int a, int b) {
    int res = 1LL;
    while (b > 0) {
        if (b & 1)
            res = (res%mod * a%mod)%mod;
        a = (a%mod * a%mod)%mod;
        b >>= 1;
    }
    return res;
}
int modinv(int a, int m)
{
    int m0 = m;
    int y = 0LL, x = 1LL;
    if (m == 1LL)
        return 0LL;
    while (a > 1LL) {
        int q = a / m;
        int t = m;
        m = a % m, a = t;
        t = y;
        y = x - q * y;
        x = t;
    }
    if (x < 0LL)
        x += m0;
 
    return x;
}

void printDivisors(int n,vector<int> &v)
{
    // vector<int> v;
    // Note that this loop runs till square root
    for (int i=1; i<=sqrt(n); i++)
    {
        if (n%i == 0)
        {
            // If divisors are equal, print only one
            if (n/i == i)
                v.pb(i);
  
            else // Otherwise print both
                v.pb(i); v.pb(n/i);
        }
    }
}
// vector<int> x={1,0,0,-1};
// vector<int> y={0,1,-1,0};
// vector<char> path={'D','R','L','U'};
// vector<int> x={0,0,1,-1,1,1,-1,-1};
// vector<int> y={1,-1,0,0,1,-1,1,-1};

class SegTree{
public:
	vector<int> seg;
	 SegTree(int n)
	{
		seg.resize(4*n +1);
	}
	void build(int low,int high,vector<int> &v,int idx)
	{
		if(low==high)
		{
			seg[idx]=v[low];
			return;
		}
		int mid=(low+high)/2;
		build(low,mid,v,2*idx+1);
		build(mid+1,high,v,2*idx+2);
		seg[idx]=min(seg[2*idx+1],seg[2*idx+2]);
	}
	// find min in range from l to r
	int low_in_range(int idx,int low,int high,int l,int r)
	{
		// no overlap when no intersection b/w l,r and low, high
		if(high<l || low>r)
		{
			return INT_MAX;
		}
		// complete overlap when l,r contain low,high
		else if(low>=l && high<=r)
		{
			return seg[idx];
		}
		// partial overlap
		int mid=(low+high)/2;
		int left=low_in_range(2*idx+1,low,mid,l,r);
		int right=low_in_range(2*idx+2,mid+1,high,l,r);
		return min(left,right);
	}
	void update(int idx,int low,int high,int pos,int val)
	{
		if(low==high)
		{
			// cout<<low<<" "<<high<<" "<<idx<<endl;
			seg[idx]=val;
			// cout<<seg[low]<<endl;
			return;
		}
		int mid=(low+high)/2;
		if(pos<=mid)
		{
			update(2*idx+1,low,mid,pos,val);
		}
		else
		{
			update(2*idx+2,mid+1,high,pos,val);
		}
		seg[idx]=min(seg[2*idx+1],seg[2*idx+2]);
	}
};

void fun()
{
	int n;
	cin>>n;
	vector<int> v(n);
	loop(i,0,n)
	{
		cin>>v[i];
	}
	int q;
	cin>>q;
	SegTree s(n);
	s.build(0,n-1,v,0);
	int x=s.low_in_range(0,0,n-1,2,5);
	// cout<<x<<endl;
	// cout<<s.seg[2]<<endl;
	while(q--)
	{
		int t;
		cin>>t;
		if(t==1)//low in range fxn
		{
			int l,r;
			cin>>l>>r;
			// here i am taking full range but we can also do it in any range of low, high
			cout<<s.low_in_range(0,0,n-1,l,r)<<endl;
		}
		else if(t==2)//update fxn
		{
			int pos,val;
			cin>>pos>>val;
						// here i am taking full range but we can also do it in any range of low, high
			s.update(0,0,n-1,pos,val);
			// for(auto it: s.seg)
			// {
			// 	cout<<it<<" ";
			// }
			// cout<<endl;
		}
	}
}


signed main()
{
fast
int t;
// cin>>t;
t=1;
while(t--)
{
fun();
}
return 0;
}