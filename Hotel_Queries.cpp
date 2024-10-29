#include <bits/stdc++.h>

using namespace std;

struct segment_tree{
    
    vector<int> seg;
    int size;

    void init(int n){
        size = 1;
        while(size<n) size*=2;
        seg.resize(2*size-1, 0);
    }
    void build(int lx, int rx, int x, vector<int> &a){
        if(lx == rx){
            if(lx < a.size())
                seg[x] = a[lx];
            return;
        }
        int mid = (lx+rx)/2;
        build(lx, mid, 2*x+1, a);
        build(mid+1, rx, 2*x+2, a);

        seg[x] = max(seg[2*x+1], seg[2*x+2]);
    }
    void build(vector<int> &a){
        build(0, size-1, 0, a);
    }

    // void sub(int lx, int rx, int x, int idx, int val){
    //     if(lx == rx){
    //         seg[x] -= val;
    //         return;
    //     }
    //     int mid = (lx+rx)/2;
    //     if(idx<=mid){
    //         sub(lx, mid, 2*x+1, idx, val);
    //     }else{
    //         sub(mid+1, rx, 2*x+2, idx, val);
    //     }
    //     seg[x] = max(seg[2*x+1], seg[2*x+2]);
    // }

    // void sub(int idx, int val){
    //     sub(0, size-1, 0, idx, val);
    // }

    int query(int lx, int rx, int x, int val){
        if(lx == rx){
            seg[x] -= val;
            return lx;
        }
        int mid = (lx+rx)/2;
        int ans;
        if(seg[2*x+1]>=val){
            ans = query(lx, mid, 2*x+1, val);
        }else{
            ans = query(mid+1, rx, 2*x+2, val);
        }
        seg[x] = max(seg[2*x+1], seg[2*x+2]);
        return ans;
    }
    int query(int val){
        if(seg[0]<val) return -1;
        int ans = query(0, size-1, 0, val);
        // sub(ans, val);
        return ans;
    }
};


int main()
{
    int n, m;
    cin>>m>>n;
    vector<int> dog(n), box(m);
    for(auto &i:box) cin>>i; 
    for(auto &i:dog) cin>>i; 

    segment_tree seg;
    seg.init(m);
    seg.build(box);
    // for(auto i:seg.seg) cout<<i<<" ";
    // cout<<endl;
    vector<int> ans;
    for(auto &i:dog){
        cout<<(seg.query(i)+1)<<" ";
    }
    
    //cout<<"\n";
    return 0;
}

