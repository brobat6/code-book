### Linear Diophantine Equation

Find solutions to an equation of the form
$$ ax + by = c $$

First, using Extended Euclidean Algorithm (assuming a, b are non-negative), we can find two integers that satisfy:
$$ ax_g + by_g = g$$
where $g = gcd(a, b)$. 

Now, if c is a multiple of g, then the Diophantine equation has a solution, otherwise, no solution.

The solution of the equation would be:
$$ x_0 = x_g * \frac{c}{g}, y_0 = y_g * \frac{c}{g} $$

Note that we'll have to change the sign of x, y according to the sign of a, b. 

### Getting all solutions

All solutions of the equation are of the form: 
$$ x = x_0 + k * \frac{b}{g}, y = y_0 - k * \frac{a}{g}$$

```c++
bool find_any_solution(int a, int b, int c, int &x0, int &y0, int &g) {
    g = gcd(abs(a), abs(b), x0, y0);
    if (c % g) {
        return false;
    }

    x0 *= c / g;
    y0 *= c / g;
    if (a < 0) x0 = -x0;
    if (b < 0) y0 = -y0;
    return true;
}
```

### Finding modular multiplicative inverse

Find inverse of a, modulo m. This is equivalent to solving the equation:
$$ ax \equiv 1 (mod~m) $$

This can be converted to a diophantine equation, $ ax - my = 1$. Using Euclidean algorithm, we can find any solution $x_0$ for this. Then, the relevant answer would be $x = x_0 \% m$.

```c++
int x, y;
int g = extended_euclidean(a, m, x, y);
if (g != 1) {
    cout << "No solution!";
}
else {
    x = (x % m + m) % m;
    cout << x << endl;
}
```