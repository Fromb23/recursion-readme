# Python Searching and Sorting Algorithms

This project teaches you how to implement and understand various searching and sorting algorithms in Python. You'll learn linear search, binary search, bubble sort, merge sort, quick sort, heap sort, hashing algorithms, and dynamic programming techniques.

## Learning Objectives

- How to implement linear and binary search algorithms
- How to understand time and space complexity of algorithms
- How to implement various sorting algorithms (bubble, merge, quick, heap)
- How to work with hashing algorithms and hash tables
- How to solve problems using dynamic programming
- How to analyze algorithm efficiency and optimization
- How to handle edge cases in algorithmic solutions
- How to write clean, efficient, and well-documented code
- How to test algorithms with various input sizes
- How to choose the right algorithm for specific problems

## Requirements

- All files will be interpreted/compiled on Ubuntu 20.04 LTS using python3 (version 3.8.5)
- All files should end with a new line
- The first line of all files should be exactly `#!/usr/bin/python3`
- Your code should use the pycodestyle (version 2.8.*)
- All files must be executable
- All modules should have documentation
- All functions should have documentation
- Handle edge cases and invalid inputs appropriately
- Optimize for time and space complexity where possible

## Tasks

### 0. Linear Search

Write a function `linear_search(arr, target)` that implements linear search algorithm:

- Search for `target` in `arr` using linear search
- Return the index of the target if found, -1 if not found
- Handle empty arrays and None inputs
- Document the time complexity: O(n)
- You are not allowed to import any module

**File:** `0-linear_search.py`

**Test File:** `0-main.py`

**Example:**
```python
arr = [2, 3, 4, 10, 40]
target = 10
result = linear_search(arr, target)
print(f"Element found at index: {result}")
```

---

### 1. Binary Search

Write a function `binary_search(arr, target)` that implements binary search algorithm:

- Search for `target` in a **sorted** `arr` using binary search
- Return the index of the target if found, -1 if not found
- Handle empty arrays and None inputs
- Assume the array is already sorted
- Document the time complexity: O(log n)
- You are not allowed to import any module

**File:** `1-binary_search.py`

**Test File:** `1-main.py`

**Example:**
```python
arr = [2, 3, 4, 10, 40]
target = 10
result = binary_search(arr, target)
print(f"Element found at index: {result}")
```

---

### 2. Binary Search Recursive

Write a function `binary_search_recursive(arr, target, low=0, high=None)` that implements binary search recursively:

- Implement binary search using recursion
- Handle the base cases appropriately
- Return the index of the target if found, -1 if not found
- Use default parameters for initial call
- Document the time complexity: O(log n), space complexity: O(log n)
- You are not allowed to import any module

**File:** `2-binary_search_recursive.py`

**Test File:** `2-main.py`

**Example:**
```python
arr = [2, 3, 4, 10, 40]
target = 10
result = binary_search_recursive(arr, target)
print(f"Element found at index: {result}")
```

---

### 3. Bubble Sort

Write a function `bubble_sort(arr)` that implements bubble sort algorithm:

- Sort the array in ascending order using bubble sort
- Modify the array in-place
- Return the sorted array
- Handle empty arrays and single element arrays
- Document the time complexity: O(n²)
- You are not allowed to import any module

**File:** `3-bubble_sort.py`

**Test File:** `3-main.py`

**Example:**
```python
arr = [64, 34, 25, 12, 22, 11, 90]
sorted_arr = bubble_sort(arr)
print(f"Sorted array: {sorted_arr}")
```

---

### 4. Selection Sort

Write a function `selection_sort(arr)` that implements selection sort algorithm:

- Sort the array in ascending order using selection sort
- Modify the array in-place
- Return the sorted array
- Handle empty arrays and single element arrays
- Document the time complexity: O(n²)
- You are not allowed to import any module

**File:** `4-selection_sort.py`

**Test File:** `4-main.py`

**Example:**
```python
arr = [64, 25, 12, 22, 11]
sorted_arr = selection_sort(arr)
print(f"Sorted array: {sorted_arr}")
```

---

### 5. Merge Sort

Write a function `merge_sort(arr)` that implements merge sort algorithm:

- Sort the array in ascending order using merge sort
- Implement both `merge_sort` and helper `merge` functions
- Handle empty arrays and single element arrays
- Document the time complexity: O(n log n)
- You are not allowed to import any module

**File:** `5-merge_sort.py`

**Test File:** `5-main.py`

**Example:**
```python
arr = [12, 11, 13, 5, 6, 7]
sorted_arr = merge_sort(arr)
print(f"Sorted array: {sorted_arr}")
```

---

### 6. Quick Sort

Write a function `quick_sort(arr, low=0, high=None)` that implements quick sort algorithm:

- Sort the array in ascending order using quick sort
- Implement both `quick_sort` and `partition` functions
- Use the last element as pivot
- Handle empty arrays and single element arrays
- Document the time complexity: Average O(n log n), Worst O(n²)
- You are not allowed to import any module

**File:** `6-quick_sort.py`

**Test File:** `6-main.py`

**Example:**
```python
arr = [10, 7, 8, 9, 1, 5]
quick_sort(arr)
print(f"Sorted array: {arr}")
```

---

### 7. Heap Sort

Write a function `heap_sort(arr)` that implements heap sort algorithm:

- Sort the array in ascending order using heap sort
- Implement helper functions: `heapify` and `build_max_heap`
- Handle empty arrays and single element arrays
- Document the time complexity: O(n log n)
- You are not allowed to import any module

**File:** `7-heap_sort.py`

**Test File:** `7-main.py`

**Example:**
```python
arr = [12, 11, 13, 5, 6, 7]
heap_sort(arr)
print(f"Sorted array: {arr}")
```

---

### 8. Hash Table Implementation

Write a class `HashTable` that implements a basic hash table:

- Methods: `__init__(self, size=10)`, `hash_function(self, key)`, `insert(self, key, value)`, `get(self, key)`, `delete(self, key)`
- Handle collisions using chaining (linked lists)
- Support string keys and any type of values
- Implement dynamic resizing when load factor exceeds 0.75
- Handle key errors appropriately
- You are not allowed to import any module

**File:** `8-hash_table.py`

**Test File:** `8-main.py`

**Example:**
```python
ht = HashTable()
ht.insert("name", "John")
ht.insert("age", 25)
print(ht.get("name"))
```

---

### 9. Hash Table with Linear Probing

Write a class `HashTableLinear` that implements a hash table using linear probing:

- Handle collisions using linear probing
- Methods: `__init__(self, size=10)`, `hash_function(self, key)`, `insert(self, key, value)`, `get(self, key)`, `delete(self, key)`
- Implement proper deletion with tombstone marking
- Support dynamic resizing
- Handle clustering issues
- You are not allowed to import any module

**File:** `9-hash_table_linear.py`

**Test File:** `9-main.py`

**Example:**
```python
htl = HashTableLinear()
htl.insert("key1", "value1")
htl.insert("key2", "value2")
print(htl.get("key1"))
```

---

### 10. Consistent Hashing

Write a class `ConsistentHash` that implements consistent hashing:

- Support adding and removing nodes dynamically
- Methods: `__init__(self, nodes=None)`, `add_node(self, node)`, `remove_node(self, node)`, `get_node(self, key)`
- Use virtual nodes for better distribution
- Handle node failures gracefully
- Implement efficient key lookup
- You must import `hashlib` module only

**File:** `10-consistent_hash.py`

**Test File:** `10-main.py`

**Example:**
```python
ch = ConsistentHash(['server1', 'server2', 'server3'])
node = ch.get_node("my_key")
print(f"Key assigned to: {node}")
```

---

### 11. Dynamic Programming - Fibonacci

Write a function `fibonacci_dp(n)` that calculates the nth Fibonacci number using dynamic programming:

- Use memoization or tabulation approach
- Handle base cases (n=0, n=1)
- Optimize for both time and space complexity
- Compare with naive recursive approach
- Document time complexity: O(n), space complexity: O(n) or O(1)
- You are not allowed to import any module

**File:** `11-fibonacci_dp.py`

**Test File:** `11-main.py`

**Example:**
```python
result = fibonacci_dp(10)
print(f"10th Fibonacci number: {result}")
```

---

### 12. Dynamic Programming - Longest Common Subsequence

Write a function `lcs_dp(text1, text2)` that finds the length of the longest common subsequence:

- Use dynamic programming approach with 2D table
- Handle empty strings
- Return the length of LCS
- Add function `lcs_string(text1, text2)` to return actual LCS string
- Document time complexity: O(m*n), space complexity: O(m*n)
- You are not allowed to import any module

**File:** `12-lcs_dp.py`

**Test File:** `12-main.py`

**Example:**
```python
text1 = "ABCDGH"
text2 = "AEDFHR"
length = lcs_dp(text1, text2)
sequence = lcs_string(text1, text2)
print(f"LCS length: {length}, LCS: {sequence}")
```

---

### 13. Dynamic Programming - Knapsack Problem

Write a function `knapsack_dp(weights, values, capacity)` that solves the 0/1 knapsack problem:

- Use dynamic programming with 2D table
- Handle edge cases (empty items, zero capacity)
- Return maximum value that can be obtained
- Add function `knapsack_items(weights, values, capacity)` to return selected items
- Document time complexity: O(n*W), space complexity: O(n*W)
- You are not allowed to import any module

**File:** `13-knapsack_dp.py`

**Test File:** `13-main.py`

**Example:**
```python
weights = [10, 20, 30]
values = [60, 100, 120]
capacity = 50
max_value = knapsack_dp(weights, values, capacity)
items = knapsack_items(weights, values, capacity)
print(f"Maximum value: {max_value}")
print(f"Selected items: {items}")
```

---

### 14. Algorithm Performance Comparison

Write a class `AlgorithmBenchmark` that compares algorithm performances:

- Methods to benchmark all sorting algorithms with different input sizes
- Generate test data: random, sorted, reverse sorted, nearly sorted
- Measure execution time and memory usage
- Create performance reports and visualizations
- Compare best, average, and worst-case scenarios
- You must import `time`, `random`, and `sys` modules

**File:** `14-benchmark.py`

**Test File:** `14-main.py`

**Example:**
```python
benchmark = AlgorithmBenchmark()
results = benchmark.compare_sorting_algorithms([100, 1000, 5000])
benchmark.print_results(results)
```

---

### 15. Advanced Search - Interpolation Search

Write a function `interpolation_search(arr, target)` that implements interpolation search:

- Works best with uniformly distributed sorted arrays
- Calculate probe position using interpolation formula
- Handle edge cases and non-uniform distributions
- Return index if found, -1 if not found
- Document time complexity: Average O(log log n), Worst O(n)
- You are not allowed to import any module

**File:** `15-interpolation_search.py`

**Test File:** `15-main.py`

**Example:**
```python
arr = [10, 12, 13, 16, 18, 19, 20, 21, 22, 23, 24, 33, 35, 42, 47]
target = 18
result = interpolation_search(arr, target)
print(f"Element found at index: {result}")
```

---

## Testing

Each task includes a corresponding main file for testing. Here's the testing structure:

### Testing Example for Task 5 (Merge Sort)

**File: `5-main.py`**
```python
#!/usr/bin/python3
merge_sort = __import__('5-merge_sort').merge_sort

# Test case 1: Regular array
arr1 = [12, 11, 13, 5, 6, 7]
print("Original array:", arr1)
sorted_arr1 = merge_sort(arr1.copy())
print("Sorted array:", sorted_arr1)

# Test case 2: Already sorted array
arr2 = [1, 2, 3, 4, 5]
print("Already sorted:", arr2)
sorted_arr2 = merge_sort(arr2.copy())
print("Merge sorted:", sorted_arr2)

# Test case 3: Reverse sorted array
arr3 = [5, 4, 3, 2, 1]
print("Reverse sorted:", arr3)
sorted_arr3 = merge_sort(arr3.copy())
print("Merge sorted:", sorted_arr3)

# Test case 4: Single element
arr4 = [42]
print("Single element:", arr4)
sorted_arr4 = merge_sort(arr4.copy())
print("Merge sorted:", sorted_arr4)

# Test case 5: Empty array
arr5 = []
print("Empty array:", arr5)
sorted_arr5 = merge_sort(arr5.copy())
print("Merge sorted:", sorted_arr5)

# Test case 6: Duplicates
arr6 = [3, 1, 4, 1, 5, 9, 2, 6, 5]
print("With duplicates:", arr6)
sorted_arr6 = merge_sort(arr6.copy())
print("Merge sorted:", sorted_arr6)
```

### Testing Example for Task 11 (Fibonacci DP)

**File: `11-main.py`**
```python
#!/usr/bin/python3
fibonacci_dp = __import__('11-fibonacci_dp').fibonacci_dp

# Test cases for Fibonacci
test_cases = [0, 1, 2, 5, 10, 15, 20, 30]

print("Fibonacci numbers using Dynamic Programming:")
for n in test_cases:
    result = fibonacci_dp(n)
    print(f"F({n}) = {result}")

# Performance test
import time

n = 35
start_time = time.time()
result = fibonacci_dp(n)
end_time = time.time()

print(f"\nPerformance test for F({n}):")
print(f"Result: {result}")
print(f"Time taken: {end_time - start_time:.6f} seconds")

# Test edge cases
try:
    print(f"\nEdge case - negative number: F(-1) = {fibonacci_dp(-1)}")
except ValueError as e:
    print(f"Error: {e}")

print(f"Edge case - F(0) = {fibonacci_dp(0)}")
print(f"Edge case - F(1) = {fibonacci_dp(1)}")
```

## Algorithm Complexity Reference

| Algorithm | Time Complexity (Best) | Time Complexity (Average) | Time Complexity (Worst) | Space Complexity |
|-----------|------------------------|---------------------------|-------------------------|------------------|
| Linear Search | O(1) | O(n) | O(n) | O(1) |
| Binary Search | O(1) | O(log n) | O(log n) | O(1) |
| Bubble Sort | O(n) | O(n²) | O(n²) | O(1) |
| Selection Sort | O(n²) | O(n²) | O(n²) | O(1) |
| Merge Sort | O(n log n) | O(n log n) | O(n log n) | O(n) |
| Quick Sort | O(n log n) | O(n log n) | O(n²) | O(log n) |
| Heap Sort | O(n log n) | O(n log n) | O(n log n) | O(1) |

## Repository

- **GitHub repository:** `recursion-readme`
- **Directory:** `0x0C-python-algorithms`
- **Files:** `0-linear_search.py`, `0-main.py`, `1-binary_search.py`, `1-main.py`, `2-binary_search_recursive.py`, `2-main.py`, `3-bubble_sort.py`, `3-main.py`, `4-selection_sort.py`, `4-main.py`, `5-merge_sort.py`, `5-main.py`, `6-quick_sort.py`, `6-main.py`, `7-heap_sort.py`, `7-main.py`, `8-hash_table.py`, `8-main.py`, `9-hash_table_linear.py`, `9-main.py`, `10-consistent_hash.py`, `10-main.py`, `11-fibonacci_dp.py`, `11-main.py`, `12-lcs_dp.py`, `12-main.py`, `13-knapsack_dp.py`, `13-main.py`, `14-benchmark.py`, `14-main.py`, `15-interpolation_search.py`, `15-main.py`

## Prerequisites

You should have completed:
- Basic Python programming concepts
- Python Data Structures (Lists, Dictionaries)
- Python Object-Oriented Programming
- Basic understanding of recursion
- Mathematical concepts (logarithms, complexity analysis)

## Important Notes

- Always consider time and space complexity when implementing algorithms
- Test your algorithms with various input sizes and edge cases
- Handle invalid inputs gracefully (empty arrays, None values, etc.)
- Use meaningful variable names and add comments for complex logic
- Consider the trade-offs between different algorithmic approaches
- Practice analyzing algorithm performance in best, average, and worst cases
- Remember that some algorithms work better with certain types of data distributions

## Tips for Success

1. **Understand Before Coding**: Make sure you understand the algorithm logic before implementation
2. **Start Simple**: Begin with basic test cases, then move to edge cases
3. **Draw It Out**: Visualize how the algorithm works with small examples
4. **Test Thoroughly**: Use the provided main files and create additional test cases
5. **Optimize Gradually**: First make it work, then make it efficient
6. **Compare Results**: Use different algorithms on the same data to verify correctness
7. **Analyze Complexity**: Always document and understand the time/space complexity

## Author

This project is part of the Python Algorithms and Data Structures learning curriculum.