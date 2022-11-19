#include <bits/stdc++.h>
using namespace std;

// Code to find nearest previous smaller element for all values in an array in O(N) time.
// UNTESTED

vector <int> previous_smaller(vector <int> &v) {
    int n = v.size();
    vector <int> nse(n);
    stack<pair<int, int>> s; // {v[i], i}
    s.push({0, -1}); // {min element, index} (can make min = -INF)
    for(int i = 0; i < n; i++) {
        while(s.top().first >= v[i]) s.pop();
        nse[i] = s.top().second;
        s.push({v[i], i});
    }
    return nse;
}

// Code to find nearest next smaller element for all values in an array in O(N) time.
// UNTESTED

vector <int> next_smaller(vector <int> &v) {
    int n = v.size();
    vector <int> nse(n);
    stack<pair<int, int>> s; // {v[i], i}
    s.push({0, n}); // {min element, index}
    for(int i = n - 1; i >= 0; i--) {
        while(s.top().first >= v[i]) s.pop();
        nse[i] = s.top().second;
        s.push({v[i], i});
    }
    return nse;
}