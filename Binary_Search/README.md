Binary Search is an efficient searching algorithm used to find an element in a sorted array by repeatedly dividing the search space in half.

🚀 Concept

Binary Search works on the principle of divide and conquer:

Compare the target element with the middle element
If equal → element found
If smaller → search in the left half
If greater → search in the right half

This process continues until the element is found or the search space becomes empty.

📌 Key Requirements
The data structure must be sorted
Random access (like arrays) is preferred
Works best when frequent searching is required
⏱️ Time Complexity
Case	Complexity
Best Case	O(1)
Average	O(log n)
Worst Case	O(log n)
💾 Space Complexity
Iterative Approach → O(1)
Recursive Approach → O(log n)
🧠 Core Idea

At each step, Binary Search eliminates half of the remaining elements, making it much faster than linear search.

Reduction pattern:
n → n/2 → n/4 → n/8 → ... → 1

⚙️ Variants of Binary Search

Binary Search is not just limited to finding an element. It is widely used in different variations:

Finding first or last occurrence
Lower bound / Upper bound
Searching in rotated sorted arrays
Finding peak elements
Searching in infinite arrays
Binary Search on Answer (optimization problems)
🎯 When to Use Binary Search

Use Binary Search when:

The problem involves a sorted array
You need to optimize brute force solutions
The search space can be divided into two halves
The problem shows a monotonic behavior (increasing/decreasing)
