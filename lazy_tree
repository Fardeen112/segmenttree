vector<ll>lazyarr(8e5+1, 0); // we have initialized a lazy array to store the lazy values that are yet to be updated in the nodes
void lazy_rangeupdate(vector<ll> &segtree, int l, int h, int s, int e, vector<ll>&arr, int tidx, ll val)
{
    if(lazyarr[tidx] != 0){
        segtree[tidx] += lazyarr[tidx];
        if(s != e){
            lazyarr[2*tidx]+=lazyarr[tidx];
            lazyarr[2*tidx+1]+=lazyarr[tidx];
        }
        lazyarr[tidx] = 0;
    }
    if(s > h || l > e)return;
    if(s >= l && e<=h){
        segtree[tidx] +=val;
        if(s != e){
            lazyarr[2*tidx] += val;
            lazyarr[2*tidx+1] += val;

        }
        return;
    }
    int mid = (s+e)/2;
    lazy_rangeupdate(segtree, l, h, s, mid, arr, 2*tidx, val);
    lazy_rangeupdate(segtree, l, h, mid+1, e, arr, 2*tidx+1, val);
    segtree[tidx] = segtree[2*tidx]+segtree[2*tidx+1];

}
// This is a lazy sum query function and it uses the same lazy array
ll lazy_sumq(vector<ll> &segtree, int l, int h, int s, int e, vector<ll>&arr, int tidx)
{
    if(lazyarr[tidx] != 0){
        segtree[tidx] += lazyarr[tidx];
        if(s != e){
            lazyarr[2*tidx]+=lazyarr[tidx];
            lazyarr[2*tidx+1]+=lazyarr[tidx];
        }
        lazyarr[tidx] = 0ll;
    }
    if(s > h || e < l)return 0ll;
    if(s >= l && e <= h){
        // cout<<segtree[tidx]<<endl;
        return segtree[tidx];
    }
    int mid = (s+e)/2ll;
    ll sum = lazy_sumq(segtree, l, h, s, mid, arr, 2*tidx)+lazy_sumq(segtree, l, h, mid+1, e, arr, 2*tidx+1);
    // cout<<sum<<endl;
    return sum;
}
void buildsegrecur(vector<int>&a, vector<ll>&segtree, int tl, int tr, int tidx) // this is iterative
{
	if (tl == tr) {
        segtree[tidx] = a[tl];
    } else {
        int tm = (tl + tr) / 2;
        buildsegrecur(a, segtree, tl, tm, tidx*2);
        buildsegrecur(a, segtree, tm+1, tr, tidx*2+1);
        segtree[tidx] = segtree[tidx*2] + segtree[tidx*2+1];
}
}
