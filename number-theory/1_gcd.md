### GCD

Finds the greatest common divisor of two values.

Time complexity : $ O(log(min(a, b))) $

* Values must be non-negative. (For negative values, magnitude of gcd will be correct but sign may not be).
* If $ a = b = 0$, $gcd = 0$.
* If one value is 0, gcd is the non-zero value.
* Number of recursive calls performed by the function is related to the Fibonacci number sequence. If $a > b \geq 1$ and $b < F_n$, the Euclidean algorithm performs at most $n - 2$ recursive calls.

```c++
int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}
```

### Extended Euclidean Algorithm for GCD

In addition to finding the gcd, also finds integers $x$ and $y$ satisfying: 

$$ ax + by = gcd(a, b) $$

* For slightly faster versions of both GCD and Euclidean Algo, see [this](1A_gcd_fast.cpp).

```c++
int gcd(int a, int b, int& x, int& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}
```