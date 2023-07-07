#include <bits/stdc++.h>
using namespace std;

/**
 * Random number generator (32-bit). 
 * For 64-bit, use mt19937_64
 * Usage: 
 * rng() (returns unsigned int, do abs(int(rng())))
 * shuffle(v.begin(), v.end(), rng);
*/
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
