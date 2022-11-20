## Monotonic Stack

We can use a monotonic stack to find the nearest (next/previous) (smaller/greater) element for all elements of an array in $O(N)$ time. 

The key property of the stack is that all elements must be in increasing OR decreasing order. 

We get $O(N)$ time complexity using amortized analysis: every element is inserted and removed only once from the stack.

```c++
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
```

### Max Histogram Area - Solution

https://cses.fi/problemset/task/1142/ Find maximum area of a rectangle possible. 

For each index, let's assume it is the minimum possible height of the rectangle. We can compute the next smaller and previous smaller element for that index to get the width of this rectangle. 

```c++
long long max_histogram_area(vector <int> &v) {
    int n = v.size();
    long long area = 0;
    vector<int> nse(n), nge(n);
    stack<pair<int, int>> s;
    s.push({-1, -1});
    for(int i = 0; i < n; i++) {
        while(s.top().first >= v[i]) s.pop();
        nse[i] = s.top().second;
        s.push({v[i], i});
    }
    while(!s.empty()) s.pop();
    s.push({-1, n});
    for(int i = n - 1; i >= 0; i--) {
        while(s.top().first >= v[i]) s.pop();
        nge[i] = s.top().second;
        s.push({v[i], i});
    }
    for(int i = 0; i < n; i++) {
        area = max(area, 1ll * v[i] * (nge[i] - nse[i] - 1));
    }
    return area;
}
```