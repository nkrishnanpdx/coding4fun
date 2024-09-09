# Arrays
Common Operations:   **Searching, sorting, finding subarrays**

Problems:
-  Two Sum: Given an array, find two numbers that add up to a target.
-  Maximum Subarray: Find the contiguous subarray with the maximum sum.
Example: Two Sum
```
    int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
        for (int i = 0; i < numsSize; i++) {
            for (int j = i + 1; j < numsSize; j++) {
                if (nums[i] + nums[j] == target) {
                    int* result = malloc(2 * sizeof(int));
                    result[0] = i;
                    result[1] = j;
                    *returnSize = 2;
                    return result;
                }
            }
        }
        *returnSize = 0;
        return NULL;
    }
```
# Linked Lists

Common Operations: **Insertion, deletion, reversal, finding cycles**.
Problems:
-  Reverse a Linked List: Reverse a singly linked list.
-  Detect Cycle: Check if a linked list has a cycle (Floyd’s Tortoise and Hare Algorithm).
Example: Reverse Linked List

```

    struct ListNode* reverseList(struct ListNode* head) {
        struct ListNode* prev = NULL;
        struct ListNode* curr = head;
        while (curr != NULL) {
            struct ListNode* nextTemp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextTemp;
        }
        return prev;
    }
```
# Stacks

Common Operations: **Push, pop, peek**.
Problems:
- Valid Parentheses: Check if a string of parentheses is valid.
- Min Stack: Implement a stack that supports retrieving the minimum element in constant time.
Example: Valid Parentheses

  ```

    bool isValid(char * s) {
        char stack[10000];
        int top = -1;
        for (int i = 0; s[i] != '\0'; i++) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                stack[++top] = s[i];
            } else {
                if (top == -1) return false;
                char last = stack[top--];
                if ((s[i] == ')' && last != '(') ||
                    (s[i] == '}' && last != '{') ||
                    (s[i] == ']' && last != '[')) {
                    return false;
                }
            }
        }
        return top == -1;
    }
```
# Queues

    Common Operations: Enqueue, dequeue, peek.
    Problems:
        Implement Queue using Stacks: Use two stacks to implement a queue.
        Sliding Window Maximum: Find the maximum in each sliding window of size k in an array.
    Example: Implement Queue Using Stacks

   ```

    typedef struct {
        int stack1[10000];
        int top1;
        int stack2[10000];
        int top2;
    } MyQueue;

    MyQueue* myQueueCreate() {
        MyQueue* obj = (MyQueue*)malloc(sizeof(MyQueue));
        obj->top1 = obj->top2 = -1;
        return obj;
    }

    void myQueuePush(MyQueue* obj, int x) {
        obj->stack1[++(obj->top1)] = x;
    }

    int myQueuePop(MyQueue* obj) {
        if (obj->top2 == -1) {
            while (obj->top1 != -1) {
                obj->stack2[++(obj->top2)] = obj->stack1[(obj->top1)--];
            }
        }
        return obj->stack2[(obj->top2)--];
    }
```
#  Hashing

    Common Operations: Insert, search, delete using hash functions.
    Problems:
        Two Sum (with Hash Map): Find two numbers in an array that add up to a target.
        Subarray Sum Equals K: Find the number of subarrays that sum to a given number.
    Example: Two Sum (Hash Map)

```

    int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
        int hashMap[20001] = {0}; // Use an array to simulate hash map
        for (int i = 0; i < numsSize; i++) {
            int complement = target - nums[i];
            if (hashMap[complement + 10000] > 0) {
                int* result = malloc(2 * sizeof(int));
                result[0] = hashMap[complement + 10000] - 1;
                result[1] = i;
                *returnSize = 2;
                return result;
            }
            hashMap[nums[i] + 10000] = i + 1;
        }
        *returnSize = 0;
        return NULL;
    }
```
# Trees

    Common Operations: Traversal (in-order, pre-order, post-order), insertion, deletion.
    Problems:
        Binary Tree Inorder Traversal: Perform an in-order traversal of a binary tree.
        Lowest Common Ancestor: Find the lowest common ancestor of two nodes in a binary tree.
    Example: Inorder Traversal

  ```

    void inorderTraversal(struct TreeNode* root, int* res, int* returnSize) {
        if (root != NULL) {
            inorderTraversal(root->left, res, returnSize);
            res[(*returnSize)++] = root->val;
            inorderTraversal(root->right, res, returnSize);
        }
    }
```
# Graphs

    Common Operations: BFS, DFS, shortest path (Dijkstra’s, Bellman-Ford).
    Problems:
        Clone Graph: Clone a graph (using BFS or DFS).
        Word Ladder: Transform one word into another using the shortest path.
    Example: DFS for Graph Traversal

  ```

    void dfs(int node, bool* visited, struct Graph* graph) {
        visited[node] = true;
        // Process node
        for (int i = 0; i < graph->adjList[node].size; i++) {
            int neighbor = graph->adjList[node].neighbors[i];
            if (!visited[neighbor]) {
                dfs(neighbor, visited, graph);
            }
        }
    }
```
# Dynamic Programming

    Common Problems:
        Longest Increasing Subsequence: Find the longest increasing subsequence in an array.
        Knapsack Problem: Maximize the value that can be carried in a knapsack.
        Fibonacci Sequence: Compute Fibonacci numbers using dynamic programming to avoid redundant calculations.
    Example: Longest Increasing Subsequence

 ```

    int lengthOfLIS(int* nums, int numsSize) {
        if (numsSize == 0) return 0;
        int dp[numsSize], maxLen = 1;
        for (int i = 0; i < numsSize; i++) dp[i] = 1;
        for (int i = 1; i < numsSize; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    dp[i] = fmax(dp[i], dp[j] + 1);
                }
            }
            maxLen = fmax(maxLen, dp[i]);
        }
        return maxLen;
    }
```
# Sorting and Searching Algorithms

    Problems:
        Binary Search: Efficiently search in a sorted array.
        Merge Sort: Implement merge sort to sort an array in O(n log n) time.
    Example: Binary Search

 ```

    int binarySearch(int* nums, int numsSize, int target) {
        int left = 0, right = numsSize - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) return mid;
            if (nums[mid] < target) left = mid + 1;
            else right = mid - 1;
        }
        return -1;
    }
```
# Greedy Algorithms

    Common Problems:
        Activity Selection: Select the maximum number of activities that don’t overlap.
        Minimum Spanning Tree: Use Prim’s or Kruskal’s algorithm to find the minimum spanning tree of a graph.

Key Tips:

    Practice LeetCode and HackerRank: These platforms provide a large number of coding problems similar to those asked in MAANG interviews.
    Time and Space Complexity: For every solution, ensure you understand its time and space complexity.
    Mock Interviews: Practice mock interviews with friends or on platforms like Pramp or Interviewing.io.
    Behavioral Questions: Don't forget to prepare for behavioral interviews. Companies like Google emphasize cultural fit and problem-solving approaches.
