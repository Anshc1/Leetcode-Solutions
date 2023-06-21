#define pb push_back
#define v vector
#define vi vector<int>
#define rep(i,a,b) for(int i=a; i<=b; i++)
#ifndef ONLINE_JUDGE
#define dbg(x) cerr<<#x<< " "; _print(x);cerr<<endl;
#else
#define dbg(x)
#endif
using namespace std;


void _print(int x ) {
    cerr << x << " ";
} void _print(float x ) {
    cerr << x << " ";
} void _print(double x ) {
    cerr << x << " ";
} void _print(char x ) {
    cerr << x << " ";
} void _print(string x ) {
    cerr << x << " ";
} void _print(bool x) {
    cerr << x << " ";
}
template<class T, class V> void _print(pair<T, V>x) {
    cerr << "{"; _print(x.first); cerr << ","; _print(x.second); cerr << "}";
}
template<class T> void _print(vector<T> x) {
    cerr << "[ ";
    for (T i : x) {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template<class T> void _print(set<T> x) {
    cerr << "[ ";
    for (T i : x) {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template<class T> void _print(multiset<T>x) {
    cerr << "[ ";
    for (T i : x) {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template<class T , class V> void _print(map<T, V> x) {
    cerr << "[ ";
    for (auto i : x) {
        _print(i);
        cerr << " ";
    }
    cerr << " ]";
}

class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        int n  = nums.size();
        v<pair<int, int>>a(n);
        rep(i , 0 , n - 1) {
            a[i].first = nums[i];
            a[i].second = cost[i];
        }
        v<long long> pref(n + 1 , 0 );
        v<long long> suff(n + 1, 0 );
        sort(a.begin(), a.end());
        rep(i , 0 , n - 1) {
            pref[i + 1] = pref[i] + a[i].second;
        }
        for (int i = n - 1 ; i >= 0 ; i--) {
            suff[i] = suff[i + 1] + a[i].second;
        }
        v<long long> l(n , 0 ) , r(n , 0 );
        rep(i , 1 , n - 1) {
            l[i] = l[i - 1] ;
            long long ct = a[i].first - a[i - 1].first;
            l[i] += ct * pref[i];
        }
        for (int i = n - 2 ; i >= 0 ; i-- ) {
            r[i] = r[i + 1] ;
            long long ct = a[i + 1].first - a[i].first ;
            r[i] += ct * suff[i + 1];
            l[i] += r[i];
        }
        return *min_element(l.begin(), l.end()) ;

    }

};
