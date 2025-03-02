# Topic Discussed

- Array
  - Generate Subbarray
  - Unique Pair
- Big Integers
  - Addition
- Bit Masking
  - Arithmetic
  - Bit Operation
  - Even Odd
  - Power
  - Swap
- Graph
  - Combinatorics
    - Binomial Coeefficient
    - Birthday Paradox
    - Catalan Number
    - Number of digit in factorial
    - Zero at end of factorial
  - Prime
    - Is Prime
    - Prime Factorization
    - Segmented Sieve
    - Sieve of Eratosthenes
  - Chinese Remainder
  - Divisors
  - Euler Totient
  - Exponentiation
  - Euclidean
  - Extended Euclidean
  - Matrix Exponentiation
  - Modulo Arithmetic
  - Fast Multiplication
  - MMI
- Number Theory
  - Shortestpath BFS
- Searching
  - Lower-Upper Bound
- Sorting
  - Inversion Count
  - Is Sorted

# Contents

- [Recursion](#recursion)
- Overflow Underflow
- Bit Indexing
- Even Odd
- Time Limit
- Sum
- Reverse VS Sort
- Binary Search

# Recursion

## Direction

### Forward Recursion

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

### Backward Recursion

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

## How Recursion Uses the Stack

In recursion, each function call is pushed onto the stack. When a function finishes, it's popped off the stack, and execution returns to the previous function call.

**1. Function Call:** Each recursive call adds a new frame to the stack, containing:

    - Local variables
    - Parameters
    - Return address (where to resume after the function ends)

**2. Base Case:** When the base case is hit, the recursion stops — the function returns, and the stack starts unwinding.

**3. Stack Unwinding:** As each function returns, its frame is popped off the stack, and the result is passed back to the previous frame.

### Understaing Call Stack Behavior

For sum of N integer, suppose you input `num = 3`. The recursive function works like this:

1. `sum(3)` is called → Push `sum(3)` onto the stack
2. `sum(2)` is called → Push `sum(2)` onto the stack
3. `sum(1)` is called → Push `sum(1)` onto the stack
4. `sum(0)` is called → Push `sum(0)` onto the stack
   At this point, the stack looks like this:

```sql
| sum(0) |
| sum(1) |
| sum(2) |
| sum(3) |   <-- Top of the stack
```

**🛑 Base Case Reached:**

- `sum(0)` returns 0, and the stack starts unwinding.

**🔓 Stack Unwinding:**

- `sum(1)` pops from the stack and returns `1`.
- `sum(2)` pops from the stack and returns `2 + 1 = 3`.
- `sum(3)` pops from the stack and returns `3 + 3 = 6`.

### Tree Recursion

A function makes more than one recursive call to itself. This creates a recursive tree-like structure where each function call branches into multiple sub-calls.

**Optimize Tree Recursion:**

- Memoization
- Tabulation
- Iteration

### Tracing Tree

**Forward Recursion:**

```js
                      forwardPrint(3)
                            |
                    forwardPrint(2)
                            |
                    forwardPrint(1)
                            |
                    forwardPrint(0)  <- Base case
                            |
                          Print(1)
                            |
                          Print(2)
                            |
                          Print(3)
```

**Backward Recursion:**

```s
                      backwardPrint(3)
                            |
                         Print(3)
                            |
                    backwardPrint(2)
                            |
                         Print(2)
                            |
                    backwardPrint(1)
                            |
                         Print(1)
                            |
                    backwardPrint(0) <- Base case
```

# Overflow and Underflow

Overflow occurs when a variable is assigned a value greater than its maximum limit, causing the value to **wrap around** and produce incorrect results.

- An `int` is typically `32` bits, so it can store values between `-2^31` and `2^31 - 1` (i.e., `-2147483648` to `2147483647`).

If you assign a value larger than `2147483647` to an `int`, overflow will occur. For example:

```cpp
int x = INT_MAX;
cout << "Before overflow: " << x << endl;
x = x + 1;
cout << "After overflow: " << x << endl;
```

Here, adding `1` to `2147483647` causes the variable to wrap around to the minimum value `-2147483648`.

**Underflow** does the same but in the opposite direction.

## How to avoid overflow and underflow

1. **Use larger data types:** consider data types with larger ranges, such as `long long`
2. **Check for overflow/underflow conditions manually:**

```cpp
if(x > INT_MAX){
    // Handle overflow case
}
```

3. **Modular arithmatic:** you can use modulo `10^9+7` as a limit to avoid overflow.

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
  $$
  \left\lfloor \frac{b}{2} \right\rfloor - \left\lfloor \frac{a-1}{2} \right\rfloor
  $$
  count the number of odd number between range [a, b]:
  $$
  (b - a + 1) - \left( \left\lfloor \frac{b}{2} \right\rfloor - \left\lfloor \frac{a-1}{2} \right\rfloor \right)
  $$
- $$ {even}^{even}={even} $$
- $$ {odd}^{odd}={odd} $$
- $$ {even}+{even}={even} $$
- $$ {odd}+{odd}={even} $$
- $$ {even}+{odd}={odd} $$

# Time Limit

| **Input Size (n)** | **Allowed Time Complexity**                         | **Operation Limit (\(\approx 10^8\) per second)**       |
| ------------------ | --------------------------------------------------- | ------------------------------------------------------- |
| $ \ n\leq10^6 \ $  | $ \ O(n) \ $, $ \ O(nlog n) \ $                     | Up to **10 million** iterations (linear and log-linear) |
| $ \ n\leq10^5 \ $  | $ \ O(n) \ $, $ \ O(nlog n) \ $, $ \ O({n}^{2}) \ $ | Up to **10 billion** iterations (quadratic)             |
| $ \ n\leq10^4 \ $  | $ \ O(\text{n}^\text{2}) \ $, $ \ O(n\sqrt{n}) \ $  | **Quadratic and sub-quadratic operations**              |
| $ \ n\leq10^3 \ $  | $ \ O(\text{n}^{3}) \ $                             | **Cubic operations** allowed                            |
| $ \ n\leq100 \ $   | $ \ O({2}^{n}) \ $, $ \ O(n!) \ $                   | **Exponential operations** allowed                      |

# Sum

- sum of integers in the range [a,b]:
  $$ \frac{b-a+1}{2} \times (a + b) $$

# Reverse vs Sort

## reverse

- time complexity is O(n)
- doesn't consider the original order

## sort

- time complexity is O(nlogn)
- changes order based on sorting criteria

# Binary Search

1. Sort the array
2. Define search space
3. Handle corner cases
4. Conditional Check
5. Function building
6. Update search space
7. Extract solution
