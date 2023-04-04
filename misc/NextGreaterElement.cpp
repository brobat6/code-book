#include <bits/stdc++.h>
using namespace std;

/**
 * We can use a monotonic stack to find the nearest (next/previous) (smaller/greater) element for all 
 * elements of an array in $O(N)$ time. 
 * The key property of the stack is that all elements must be in (increasing/decreasing) order. 
 * We get $O(N)$ time complexity using amortized analysis: every element is inserted and 
 * removed only once from the stack.
*/
vector <int> previous_smaller(vector <int> &v) {
    int n = v.size();
    vector <int> nse(n);
    stack<pair<int, int>> s; // {v[i], i}
    s.push({0, -1}); // {min element, index} (Change to max element for "greater", Change index to n for "next")
    for(int i = 0; i < n; i++) { // Reverse loop for "next"
        while(s.top().first >= v[i]) s.pop(); // Change equality to <= for "greater"
        nse[i] = s.top().second;
        s.push({v[i], i});
    }
    return nse;
}