// Problem: A - Phone List
// Contest: Virtual Judge - Trie/Prefix Tree
// URL: https://vjudge.net/contest/662858#problem/A
// Memory Limit: 1024 MB
// Time Limit: 5000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//Labib
#include <bits/stdc++.h>
#define nl "\n"
#define ll long long
#define all(x) x.begin(), x.end()
#define pb push_back
using namespace std;
const int M=1e9+7;
const int mxn=3e5;
const ll inf=1e18;
bool f=1;
struct TRIE
{
	vector<vector<int>> trie;
	vector<int> endshere;
	int num;
	void init()
	{
		trie.clear();
		endshere.clear();
		trie.pb(vector<int>(10));
		endshere.pb(0);
		num=0;
	}
	void add(string s)
	{
		int node=0;
		for(auto c:s)
		{
			int ch=c-'0';
			if(!trie[node][ch])
			{
				trie.pb(vector<int>(10));
				endshere.pb(0);
				trie[node][ch]=++num;
			}
			node=trie[node][ch];
		}
		endshere[node]++;
	}
	void travarse(int node,string pref)
	{
		bool fl=0;
		//cout<<node<<nl;
		if(endshere[node])
		{
			fl=1;
			//cout<<pref<<nl;
		}
		for(int i=0;i<10;i++)
		{
			if(trie[node][i])
			{
				if(fl)
				{
					//cout<<i<<nl;
					//cout<<pref+char('0'+i)<<" "<<char('0'+i)<<nl;
					//return 0;
					f=0;
					return;
				}
				//return
				 travarse(trie[node][i],pref+char('0'+i));
			}
		}
	}
};
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int t=1;
    cin>>t;
    int tc=1;
    while (t--)
    {
    	int n;
    	cin>>n;
    	f=1;
    	TRIE a;
    	a.init();
    	for(int i=0;i<n;i++)
    	{
    		string s;
    		cin>>s;
    		a.add(s);
    	}
    	string d="";
    	//bool f=
    	a.travarse(0,d);
    	if(f)cout<<"YES"<<nl;
    	else cout<<"NO"<<nl;


    }


}

