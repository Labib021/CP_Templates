//Labib
#include <bits/stdc++.h>
#define nl "\n"

#define ll long long
#define ff first
#define ss second
#define all(x) x.begin(), x.end()
#define pb push_back
using namespace std;
const ll M=1e9+7;
const int mxn=1e6;
const ll inf=1e18;
ll pw1[mxn+3];
ll pw2[mxn+3];
const ll m1=1e9+1011;
const ll m2=1e9+1011;
ll b1=1e9+21, b2=1e9+181;
ll B1[15]={68749,23627,91621,613,3389,971,797,4339,5333,269,5821,1031,1583,1949,593};
ll B2[15]={359,3719,6397,6211,5701,11743,677,1667,1759,947,733,5023,4547,4139,8831};
ll M1[10]={131280223,132573641,172575217,175515731,125517299,121024213,121231897,121230377,151349167,151351111};
ll M2[10]={111346687,141346033,101346859,131347813,191345867,161348821,171346753,151347593,181347541,161347471};
void pre()
{
	pw1[0]=pw2[0]=1;
	
	for(int i=1;i<mxn;i++)
	{
		pw1[i]=(pw1[i-1]*b1)%m1;
		pw2[i]=(pw2[i-1]*b2)%m2;
		
	}
}

struct Hash
{
	vector<ll> h1,h2;
	void init(string s)
	{
		int n=s.size();
		h1.resize(n+2);
		h2.resize(n+2);
		h1[0]=s[0]*pw1[0]%m1;
		h2[0]=s[0]*pw2[0]%m2;
		for(int i=1;i<n;i++)
		{
			h1[i]=((h1[i-1]*b1)%m1+s[i])%m1;
			h2[i]=((h2[i-1]*b2)%m2+s[i])%m2;
		}
		 
	}
	ll get_hash(int l,int r)
	{
		if(l==0)
		{
			ll a=(h1[r]+m1)%m1;
			ll b=(h2[r]+m2)%m2;
			return a<<32|b;
		}
		ll x=(h1[r]-(h1[l-1]*pw1[r-l+1])%m1+m1)%m1;
		ll y=(h2[r]-(h2[l-1]*pw2[r-l+1])%m2+m2)%m2;
		return x<<32|y;
	}
};
/*
		srand(time(NULL));
		b1=B1[rand()%15];
		b2=B2[rand()%15];
		m1=M1[rand()%10];
		m2=M2[rand()%10];
		
		const int m1=1e9+1011;
const int m2=1e9+1011;
int b1=1e9+21, b2=1e9+181;

/// 0 base indexing

*/
