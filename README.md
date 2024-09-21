# Recursive Direction
## Forward Recursion
The recursive calls happen first, and any operations are performed after all recursive calls have returned.
```cpp
void forwardRecursion(int n) {
    if (n == 0) { 
        return;
    }
    forwardRecursion(n - 1);
    cout << n << " ";
}
// 1 2 3 4 5 6 7 8 9 10
```
## Backward Recursion
The operations are performed before the recursive calls. Each recursive call processes its action and then makes the next recursive call.
```cpp
void backwardRecursion(int n) {
    if (n == 0) {
        return;
    }
    cout << n << " ";
    backwardRecursion(n - 1);
}
// 10 9 8 7 6 5 4 3 2 1 
```

# Overflow and Underflow
Overflow occurs when a variable is assigned a value greater than its maximum limit, causing the value to __wrap around__ and produce incorrect results.

- An `int` is typically `32` bits, so it can store values between `-2^31` and `2^31 - 1` (i.e., `-2147483648` to `2147483647`).

If you assign a value larger than `2147483647` to an `int`, overflow will occur. For example:

```cpp
int x = INT_MAX;
cout << "Before overflow: " << x << endl;
x = x + 1;
cout << "After overflow: " << x << endl; 
```

Here, adding `1` to `2147483647` causes the variable to wrap around to the minimum value `-2147483648`.

__Underflow__ does the same but in the opposite direction.

## How to avoid overflow and underflow
1. __Use larger data types:__ consider data types with larger ranges, such as `long long`
2. __Check for overflow/underflow conditions manually:__
```cpp
if(x > INT_MAX){
    // Handle overflow case
}
```
3. __Modular arithmatic:__ you can use modulo `10^9+7` as a limit to avoid overflow.

# Bit Manipulation
## Indexing
### 0-Based Indexing
The bit at position 0 represents the least significant bit (LSB), and the bit at position n−1 represents the most significant bit (MSB).
```cpp
int number = 5;
bool isBitSet = (number & (1 << 0)) != 0;
```
### 1-Based Indexing
The bit at position 1 represents the least significant bit, and the bit at position n represents the most significant bit.
```cpp
int number = 5;
bool isBitSet = (number & (1 << (1 - 1))) != 0;
```
# Even and Odd
- count the number of even number between range [a, b]:
    $$ \frac{b}{2} - \left(\frac{a-1}{2}\right) $$
  count the number of odd number between range [a, b]:
    $$ \text{b−a+1} $$
- $$ \text{even}^{\text{even}}=\text{even} $$
- $$ \text{odd}^{\text{odd}}=\text{odd} $$
- $$ \text{even}+{\text{even}}=\text{even} $$
- $$ \text{odd}+{\text{odd}}=\text{even} $$
- $$ \text{even}+{\text{odd}}=\text{odd} $$

# Time Limit
| **Input Size (n)**  | **Allowed Time Complexity**                     | **Operation Limit (\(\approx 10^8\) per second)**       |
|---------------------|--------------------------------------------------|---------------------------------------------------------|
| $$ \ n\leq10^6 \ $$ | $$ \ O(n) \ $$ $$ \ O(nlog n) \ $$                 | Up to **10 million** iterations (linear and log-linear) |
| $$ \ n\leq10^5 \ $$ | $$ \ O(n) \ $$ $$ \ O(nlog n) \ $$ $$ \ O({n}^{2}) \ $$    | Up to **10 billion** iterations (quadratic)             |
| $$ \ n\leq10^4 \ $$ | $$ \ O(\text{n}^\text{2}) \ $$ $$ \ O(n\sqrt{n}) \ $$             | **Quadratic and sub-quadratic operations**              |
| $$ \ n\leq10^3 \ $$ | $$ \ O(\text{n}^{3}) \ $$                                   | **Cubic operations** allowed                            |
| $$ \ n\leq100  \ $$ | $$ \ O({2}^{n}) \ $$ $$ \ O(n!) \ $$                     | **Exponential operations** allowed                      |
