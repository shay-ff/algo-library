#include <bits/stdc++.h>
using namespace std;

struct SuffixAutomaton {
    struct State{ int len, link; unordered_map<char,int> next; };
    vector<State> st; int last;
    SuffixAutomaton(int maxlen=0){ st.reserve(2*maxlen); st.push_back({0,-1,{}}); last=0; }
    void extend(char c){
        int cur = (int)st.size(); st.push_back({st[last].len+1, 0, {}});
        int p = last;
        while(p != -1 && !st[p].next.count(c)){ st[p].next[c] = cur; p = st[p].link; }
        if(p == -1) st[cur].link = 0;
        else {
            int q = st[p].next[c];
            if(st[p].len + 1 == st[q].len) st[cur].link = q;
            else {
                st.push_back(st[q]);
                int clone = (int)st.size()-1;
                st[clone].len = st[p].len + 1;
                while(p != -1 && st[p].next[c] == q){ st[p].next[c] = clone; p = st[p].link; }
                st[q].link = st[cur].link = clone;
            }
        }
        last = cur;
    }

    // build automaton from string
    static SuffixAutomaton build_from(const string &s){ SuffixAutomaton sa((int)s.size()); for(char c: s) sa.extend(c); return sa; }
};

int main(){ ios::sync_with_stdio(false); cin.tie(nullptr);
    string s; if(!(cin>>s)) return 0; auto sa = SuffixAutomaton::build_from(s);
    cout << "States: " << sa.st.size() << "\n";
    return 0;
}
