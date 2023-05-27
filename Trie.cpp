#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define all(v) v.begin(), v.end()
#define int long long
#define ll long long
#define pb push_back
#define endl "\n"
#define bn begin()
#define en end()
#define ppb pop_back
#define ff first
#define ss second
#define pii pair<int, int>
#define loop(i, a, b) for (int i = a; i < b; i++)
#define bs binary_search
const int inf = 1e18, mod = 1e9 + 7;
#define add_mod(a, b) (a % mod + b % mod) % mod
#define mul_mod(a, b) (a % mod * b % mod) % mod
#define sub_mod(a, b) (mod + a % mod - b % mod) % mod
#define compar \
    bool compare(int a, int b) { return a > b; }
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
    #define file  freopen("Error.txt", "w", stderr);freopen("input.txt", "r", stdin ); freopen("output.txt", "w", stdout);
#else
    #define file
#endif
#define per(x) fixed << setprecision(x) << // syntax:-cout<<per(jitni decimal place chahiyaen)variable name;
// bool compare(pair<int,int> a,pair<int,int> b){if(a.first==b.first)return a.second<b.second;return a.first<b.first;}
// if an element have a divisor i less than sqrt(n) the it will definately have n/i as a divisor
//  (a/b) %m = a%m *binpow(b,m-2) provided b and m are co-prime.
//  negative number ka mod tackle karne ke liyaen uss number me mod jod kar mod kar lo
int binpow(int a, int b)
{
    int res = 1LL;
    while (b > 0)
    {
        if (b & 1)
            res = (res%mod * a%mod)%mod;
        a = (a%mod * a%mod)%mod;
        b >>= 1;
    }
    return res;
}
int gcd(int a, int b) {
    if (!a || !b)
        return a | b;
    unsigned shift = __builtin_ctz(a | b);
    a >>= __builtin_ctz(a);
    do {
        b >>= __builtin_ctz(b);
        if (a > b)
            swap(a, b);
        b -= a;
    } while (b);
    return a << shift;
}
int modinv(int a, int m)
{
    int m0 = m;
    int y = 0LL, x = 1LL;
    if (m == 1LL)
        return 0LL;
    while (a > 1LL)
    {
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

void printDivisors(int n, vector<int> &v)
{
    // vector<int> v;
    // Note that this loop runs till square root
    for (int i = 1; i*i <= n; i++)
    {
        if (n % i == 0)
        {
            // If divisors are equal, print only one
            if (n / i == i)
                v.pb(i);

            else
            { // Otherwise print both
                // if (i != 1)
                    v.pb(i);
                v.pb(n / i);
            }
        }
    }
}
// vector<int> x={1,0,0,-1};
// vector<int> y={0,1,-1,0};
// vector<char> path={'D','R','L','U'};
// vector<int> x={0,0,1,-1,1,1,-1,-1};
// vector<int> y={1,-1,0,0,1,-1,1,-1};

// everyday 1 codeforces and 1 leetcode in the morning
// everyday 1 codeforces and 1 leetcode in the evening
// always take the input correctly.

// if p divides x+k and y+k the p also devides (y-x) for (y>x)
// (a|x)-(b&x) == (a|x) ^ (b&x)
// if a%b==0 then a must contain contain all the prime factors of b in same or greater freq. along with other prime numbers
// for interactive problem make sure ki (#define endl as "\n") ko comment out karke endl likho

struct Node
{
    Node*link [26];
    // vector<Node> link(26);
    bool flag=false;
    int count_word=0;
    int count_pref=0;
    bool containKey(char ch)
    {
        return link[(ch-'a')]!=NULL;
    }
    void put(Node* node,char ch)
    {
        link[(ch-'a')]=node;
    }
    Node* next(char ch)
    {
        return link[(ch-'a')];
    }
    void setend()
    {
        flag=true;
    }
    bool is_flag()
    {
        return flag;
    }
};
class Trie
{
private: 
    Node* root;
public:
    Trie()
    {
        root=new Node();
    }
    // O(word.length())
    void insert(string &word)
    {
        Node *curr=root;
        for(int i=0;i<word.length();i++)
        {
            if(!curr->containKey(word[i]))
            {
                curr->put(new Node(),word[i]);
            }
            curr=curr->next(word[i]);
            curr->count_pref++;
        }
        curr->setend();
        curr->count_word++;
    }
    bool search(string &word)
    {
        Node *curr=root;
        for(int i=0;i<word.length();i++)
        {
            if(!curr->containKey(word[i]))
                return false;
            curr=curr->next(word[i]);
        }
        return curr->flag;
    }
    bool startswith(string &pref)
    {

        Node *curr=root;
        for(int i=0;i<pref.length();i++)
        {
            if(!curr->containKey(pref[i]))
                return false;
            curr=curr->next(pref[i]);
        }
        return true;  
    }
    int count_word_occ(string &word)
    {
        Node *curr=root;
        for(int i=0;i<word.length();i++)
        {
            if(curr->containKey(word[i]))
            {
                curr=curr->next(word[i]);
            }
            else
            return 0;
        }
        return curr->count_word;
    }
    int count_pref_occ(string &pref)
    {
        Node *curr=root;
        for(int i=0;i<pref.length();i++)
        {
            if(curr->containKey(pref[i]))
            {
                curr=curr->next(pref[i]);
            }
            else
            return 0;
        }
        return curr->count_pref;   
    }
    void erase(string &word)
    {
        Node *curr=root;
        if(!search(word))
        return;
        for(int i=0;i<word.length();i++)
        {
            curr=curr->next(word[i]);
            curr->count_pref--;
        }
        curr->count_word--;
    }
};
void fun()
{
    int n;
    cin>>n;
    Trie t;
    for(int i=0;i<n;i++)
    {
        string s;
        cin>>s;
        t.insert(s);
    }
    for(int i=0;i<n;i++)
    {
        string s;
        cin>>s;
        cout<<t.count_word_occ(s)<<endl;
        cout<<t.count_pref_occ(s)<<endl;
    }
    // loop(i,0,n)
    // {
    //     string s;
    //     cin>>s;
    //     cout<<t.startswith(s)<<endl;
    // }

}

signed main()
{
    fast 
    file
    int t;

    // cin >> t;
    t=1;
    while (t--)
    {
        fun();
    }
    return 0;
}        
