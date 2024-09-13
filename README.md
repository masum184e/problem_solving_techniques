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