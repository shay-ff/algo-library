#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_pset;
// methods : find_by_order(k) - returns iterator to the k-th element (0-based index)
//           order_of_key(k) - returns number of elements strictly less than k
//           insert(x) - inserts x
//           erase(x) - erases x
//           count(x) - returns number of elements equal to x
//           lower_bound(x) - returns iterator to the first element not less than x
//           upper_bound(x) - returns iterator to the first element greater than x
