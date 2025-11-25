#include <bits/stdc++.h>
using namespace std;

struct Query{ int l,r,idx; };

int main(){ ios::sync_with_stdio(false); cin.tie(nullptr);
    int n,q; if(!(cin>>n>>q)) return 0; vector<int> a(n); for(int i=0;i<n;i++) cin>>a[i];
    int B = max(1,(int)(sqrt(n)));
    vector<Query> qs(q);
    for(int i=0;i<q;i++){ cin>>qs[i].l>>qs[i].r; qs[i].l--; qs[i].r--; qs[i].idx=i; }
    sort(qs.begin(), qs.end(), [&](const Query &A, const Query &Bq){ if(A.l/B != Bq.l/B) return A.l < Bq.l; return (A.l/B)&1 ? A.r > Bq.r : A.r < Bq.r; });
    vector<long long> ans(q); vector<int> cnt(1000005); long long cur=0; int L=0,R=-1;
    auto add = [&](int idx){ int v=a[idx]; cur += v; cnt[v]++; };
    auto remove = [&](int idx){ int v=a[idx]; cur -= v; cnt[v]--; };
    for(auto &qu: qs){ while(L>qu.l) add(--L); while(R<qu.r) add(++R); while(L<qu.l) remove(L++); while(R>qu.r) remove(R--); ans[qu.idx]=cur; }
    for(auto x: ans) cout<<x<<"\n";
    return 0;
}
