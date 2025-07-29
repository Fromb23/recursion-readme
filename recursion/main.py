# main.py
from recursion.tasks.countdown.countdown import countdown
from tasks.factorial import recursive_factorial
from tasks.factorial_compare import compare_factorials
from tasks.nested_traverse import traverse_recursive, traverse_iterative
from tasks.palindrome import is_palindrome
from tasks.quicksort import quicksort

def run_all():
    print("1. Countdown to Zero")
    countdown(5)
    
    print("\n2. Recursive Factorial of 5:", recursive_factorial(5))

    print("\n3. Comparing Factorial Speed")
    compare_factorials()

    print("\n4. Traverse Nested List Recursively")
    traverse_recursive([1, [2, [3, 4], 5]])
    print("\n5. Traverse Nested List Non-Recursively")
    traverse_iterative([1, [2, [3, 4], 5]])

    print("\n6. Palindrome Check")
    print("racecar:", is_palindrome("racecar"))
    print("hello:", is_palindrome("hello"))

    print("\n7. Quicksort")
    data = [4, 2, 7, 1, 3]
    print("Before:", data)
    print("After:", quicksort(data))

if __name__ == "__main__":
    run_all()
