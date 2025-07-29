# 🧠 Task: Implement a Factorial Function Using Recursion

## 🎯 Learning Objectives

- Understand how recursive functions work in Python.
- Learn how base cases and recursive calls interact.
- Develop the ability to trace and debug recursive call stacks.

---

## 📝 Task Instructions

Write a function called `factorial(n)` in `factorial.py` that:

- Accepts a single non-negative integer `n`.
- Returns the factorial of `n`, defined as:

> `n! = n × (n-1) × (n-2) × ... × 1`

- The base case is:  
  `factorial(0)` or `factorial(1)` should return `1`.

---

## Function prototype
```python
def factorial(n):
    """Return the factorial of n using recursion."""
    pass
```

**Your function should:**

- Accept a single non-negative integer n.

- Return the factorial of n, defined as:

- n! = n × (n-1) × (n-2) × ... × 1

Base case:
factorial(0) or factorial(1) should return 1.

## 🧪 Examples

```python
>>> factorial(5)
120

>>> factorial(3)
6

>>> factorial(0)
1
```
## ⚠️ Rules
- You must use recursion.

- You must not use loops (__for__ or __while__).

__Do__ __not__ import external libraries.