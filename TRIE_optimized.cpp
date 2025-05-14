// Problem: W - Beautiful Subarrays
// Contest: Virtual Judge - Trie/Prefix Tree
// URL: https://vjudge.net/contest/662858#problem/W
// Memory Limit: 512 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//Labib
#include <bits/stdc++.h>
#define nl "\n"
#define ll long long
#define all(x) x.begin(), x.end()
#define pb push_back
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
using namespace std;


ll c=0;
int n,k;
struct TRIE
{
    struct Node {
        int child[2];  // For storing two children (0 and 1)
        ll count;      // For counting the number of prefixes that reach this node

        Node() {
            child[0] = child[1] = 0;  // Initially no children
            count = 0;                // Initially no prefixes
        }
    };

    vector<Node> trie;
    int num;

    void init() {
        trie.clear();
        trie.emplace_back(Node());  // Add the root node
        num = 0;
    }

    void add(int s) {
        int node = 0;
        for (int i = 30; i >= 0; i--) {
            int ch = (s >> i) & 1;
            if (!trie[node].child[ch]) {
                trie[node].child[ch] = ++num;
                trie.emplace_back(Node());
            }
            node = trie[node].child[ch];
            trie[node].count++;
        }
    }

    void traverse(int node, int d, int sm) {
        for (int i = 30; i >= 0; i--) {
            int ch = (sm >> i) & 1;
            int j = (d >> i) & 1;
            if (ch == 1) {
                if (j == 1) {
                    if (trie[node].child[0]) {
                        if (i == 0) c += trie[trie[node].child[0]].count;
                        node = trie[node].child[0];
                    } else break;
                } else {
                    if (trie[node].child[1]) {
                        if (i == 0) c += trie[trie[node].child[1]].count;
                        node = trie[node].child[1];
                    } else break;
                }
            } else {
                if (j == 1) {
                    if (trie[node].child[0]) c += trie[trie[node].child[0]].count;
                    if (trie[node].child[1]) {
                        if (i == 0) c += trie[trie[node].child[1]].count;
                        node = trie[node].child[1];
                    } else break;
                } else {
                    if (trie[node].child[1]) c += trie[trie[node].child[1]].count;
                    if (trie[node].child[0]) {
                        if (i == 0) c += trie[trie[node].child[0]].count;
                        node = trie[node].child[0];
                    } else break;
                }
            }
        }
    }
};

signed main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
   
    cin>>n>>k;
    TRIE a;
    a.init();
   
    a.add(0);
   
   int xr=0;
    ll ans=0;
    for(int i=0;i<n;i++)
    {
    	int x;
    	cin>>x;
    	xr=(xr^x);
    	
    	c=0;
    	a.traverse(0,xr,k);
    	ans+=c;
    	a.add(xr);
    }
    cout<<ans<<nl;
    


}

