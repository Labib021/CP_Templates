const ll tsz=4000000;///4*n+qlogn
ll nxt;
ll version[mxn];
ll segT[tsz], bam[tsz], dan[tsz];
ll merge(int l,int r)
{
	return segT[l]+segT[r];
}
void build(int start,int end,int node)
{
	if(start==end)
	{
		segT[node]=0;
		return;
	}
	bam[node]=nxt++;
	dan[node]=nxt++;
	int mid=(start+end)/2;
	build(start,mid,bam[node]);
	build(mid+1,end,dan[node]);
	segT[node]=merge(bam[node],dan[node]);
}
int update(int start,int end,int node,int pos,int val)
{
	if(start>pos || end<pos)return node;
	int nnode=nxt++;
	if(start==end)
	{
		segT[nnode]=segT[node];
		segT[nnode]+=val;
		return nnode;
	}	
	int mid=(start+end)/2;
	bam[nnode]=update(start,mid,bam[node],pos,val);
	dan[nnode]=update(mid+1,end,dan[node],pos,val);
	segT[nnode]=merge(bam[nnode],dan[nnode]);
	return nnode;
}

int query(int start,int end,int lnode,int rnode,int l,int r)
{
	if(l>end || r<start)return 0;
	if(start>=l && end<=r)return segT[rnode]-segT[lnode];
	int mid=(start+end)/2;	
	int lans=query(start,mid,left[lnode],left[rnode],l,r);
	int rans=query( mid+1,end,right[lnode],right[rnode],l,r);
	return lans+rans;
}
//nxt=0
// version[0] = nxt++
// build(version[0], 1, n)