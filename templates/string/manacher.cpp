#include <bits/stdc++.h>
using namespace std;

struct Manacher {
    // returns pair of vectors: d1 (odd-radius), d2 (even-radius)
    static pair<vector<int>, vector<int>> build(const string &s){
        int n=(int)s.size(); vector<int> d1(n), d2(n);
        for(int i=0,l=0,r=-1;i<n;i++){
            int k = (i>r?1:min(d1[l+r-i], r-i+1));
            while(0<=i-k && i+k<n && s[i-k]==s[i+k]) k++;
            d1[i]=k--;
            if(i+k>r){ l=i-k; r=i+k; }
        }
        for(int i=0,l=0,r=-1;i<n;i++){
            int k = (i>r?0:min(d2[l+r-i+1], r-i+1));
            while(0<=i-k-1 && i+k<n && s[i-k-1]==s[i+k]) k++;
            d2[i]=k--;
            if(i+k>r){ l=i-k-1; r=i+k; }
        }
        return {d1,d2};
    }
};

int main(){ ios::sync_with_stdio(false); cin.tie(nullptr);
    string s; if(!(cin>>s)) return 0; auto [d1,d2] = Manacher::build(s); cout<<"max odd radius: "<< *max_element(d1.begin(), d1.end())<<"\n"; return 0; }
