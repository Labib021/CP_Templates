#include <bits/stdc++.h>
using namespace std; 
  
// Header files, namespaces, 
// macros as defined above 
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
  
#define ordered_set tree<long long, null_type,less<long long>, rb_tree_tag,tree_order_statistics_node_update>
/*#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<std::pair<long long, long long>, null_type, less<std::pair<long long, int>>, rb_tree_tag, tree_order_statistics_node_update>*/ 
  
int main()
{
	ordered_set st;
	st.insert(1e18);
	cout<<*(st.find_by_order(0));
}
  
