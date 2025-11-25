#include <bits/stdc++.h>
using namespace std;

struct KMP {
    // prefix function (pi) for string s
    static vector<int> prefix_function(const string &s){ int n=(int)s.size(); vector<int> pi(n); for(int i=1;i<n;i++){ int j=pi[i-1]; while(j>0 && s[i]!=s[j]) j=pi[j-1]; if(s[i]==s[j]) j++; pi[i]=j; } return pi; }

    // find occurrences of pattern in text -> returns starting indices (0-based)
    static vector<int> find_all(const string &pat, const string &txt){ string s = pat + "#" + txt; auto pi = prefix_function(s); vector<int> occ; for(int i=0;i<(int)txt.size(); i++) if(pi[pat.size()+1+i]==(int)pat.size()) occ.push_back(i - (int)pat.size() + 1); return occ; }
};

int main(){ ios::sync_with_stdio(false); cin.tie(nullptr);
    string pat, txt; if(!(cin>>pat>>txt)) return 0;
    auto occ = KMP::find_all(pat, txt);
    for(auto i: occ) cout<<i<<"\n";
    return 0;
}
