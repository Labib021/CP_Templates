
vector<int>g[mxn];
int sub[mxn]={}, iscentroid[mxn]={};
int parcentroid[mxn]={};

int dfs(int node, int par, int dep, int start)
{
	sub[node]=1;
    for(int a : g[node])
    {
    	if(a!=par && !iscentroid[a]) sub[node]+=dfs(a,node,dep+1,start);
    }
    return sub[node];
}

int getCentroid(int node, int par, int n)
{
	for(int a : g[node])
	{
		 if(a!=par && !iscentroid[a] && sub[a]>n/2) return getCentroid(a, node, n);
    
	}
       
    return node;
}
    


void decompose(int node, int par, int parentcentroid)
{
	int n=dfs(node,par,0,node), centroid=getCentroid(node, par, n);
    iscentroid[centroid]=1;
    if(parentcentroid!=-1)
    {
    	 parcentroid[centroid]=parentcentroid;
    }     
    for(int a : g[centroid])
    {
    	 if(a!=par && !iscentroid[a]) decompose(a,centroid,centroid);
    }
}
