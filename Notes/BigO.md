Big O notation is a mathematical way to describe the efficiency of an algorithm in terms of time or space complexity, focusing on how the algorithm scales as the input size grows. 
It gives you an upper bound on the time or space an algorithm will take, allowing you to compare different algorithms' efficiency.

#  Key Concepts:
    * Input Size (n): This refers to the size of the data the algorithm processes. For example, if you're searching through an array of numbers, the size n is the number of elements in that array.
    *  Worst-Case Scenario: Big O focuses on the worst-case performance of an algorithm to give a guaranteed upper limit, no matter what input it gets.
 ## O(1) – Constant Time

    *  The algorithm takes the same amount of time regardless of the input size.
    *  Example: Accessing an element in an array by index (arr[0]).
        Real World: No matter how big the array is, accessing an element by index is done in a constant time.

        ```
        int x = arr[3]; // O(1)
        ```
 ##  O(log n) – Logarithmic Time

    *  The algorithm's performance improves as the input size grows, but it increases logarithmically. This often happens in divide-and-conquer algorithms.
    *  Example: Binary search in a sorted array, where you repeatedly split the array in half.
        Real World: Doubling the input size only adds a small amount of extra work.
    ```
        // Binary Search Algorithm
        int binarySearch(int arr[], int n, int x) {
        int low = 0, high = n - 1;
        while (low <= high) {
          int mid = (low + high) / 2;
          if (arr[mid] == x)
            return mid;
          else if (arr[mid] < x)
            low = mid + 1;
          else
            high = mid - 1;
          }
        return -1;
        }```

  ##  O(n) – Linear Time

     *  The running time grows linearly with the input size.
     *  Example: A simple loop that iterates over all elements in an array.
          Real World: Doubling the input size doubles the running time.

```
// Linear search algorithm
for (int i = 0; i < n; i++) {
    if (arr[i] == target) {
        return i; // O(n)
    }
}

```
## O(n log n) – Log-Linear Time

    *  This complexity often comes from algorithms that break a problem into smaller subproblems, solve them, and then combine the results. Most efficient sorting algorithms, such as merge sort and quicksort, fall into this category.
    *  Real World: Sorting algorithms like merge sort run in O(n log n) time, and increasing the input size increases the time slightly more than linear growth.  

##  O(n²) – Quadratic Time

    *  The algorithm’s running time grows quadratically with the input size. This often happens when you have nested loops.
    *  Example: A naive sorting algorithm like bubble sort.
        Real World: Doubling the input size makes the running time quadruple.

```
// Bubble sort algorithm
for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
        if (arr[j] > arr[j + 1]) {
            // swap arr[j] and arr[j+1]
        }
    }
}
```
##  O(2ⁿ) – Exponential Time

    *  The running time doubles with every additional input element. This is common in recursive algorithms that solve subproblems in multiple ways.
    *  Example: Recursive algorithms for problems like the Fibonacci sequence or the traveling salesman problem.
        Real World: The algorithm becomes impractical for larger input sizes due to the extreme growth in running time.

```
// Recursive Fibonacci algorithm
int fib(int n) {
    if (n <= 1)
        return n;
    return fib(n - 1) + fib(n - 2);  // O(2^n)
}
```
How to Analyze an Algorithm’s Time Complexity:

    Identify Loops:
        A single loop that runs n times is O(n).
        Nested loops (loops inside loops) result in O(n²) or higher, depending on the depth of the loops.

    Consider Recursive Calls:
        If a function calls itself n times (recursion), the complexity can vary depending on how the input is reduced. For example, binary search reduces the input by half every time, leading to O(log n).

    Constant-Time Operations:
        Operations like arithmetic, comparisons, or accessing an array element by index are typically O(1).

    Drop Constants and Lower-Order Terms:
        Big O notation ignores constant factors and focuses on the dominant term that grows the fastest as input increases. For example, O(2n) is simplified to O(n), and O(n + log n) simplifies to O(n).

Visual Growth of Big O Notation:

| Big O Notation	   |  Input Size = 10    | Input Size = 100     |Input Size = 1000| 
| ---    | ---   | ---     | ---     |
| O(1)	|1	|1	|1|
| O(log n)|	3	|6	|9|
| O(n)	|10	|100	|1000|
| O(n log n)	|33	|600	|9000|
| O(n²)	|100	|10,000	|1,000,000|
| O(2ⁿ)	|1024	|~10²⁹	|~10³⁰⁰|
### Key Takeaways:

    - Big O helps compare algorithms by showing how they scale with input size.
    - Focus on the dominant term in the algorithm's time complexity.
    - Optimize algorithms by reducing time complexity from O(n²) or higher to O(n log n) or O(n).

