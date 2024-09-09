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
