---
Author: Sumit Kumar
Email: ravirajkarn21@gmail.com
Date Created: 2025-06-08T11:45:00
tags:
  - Algorithm
  - Bubble-Sort
  - Sorting_Algo
---

# Bubble Sort | Sorting Algorithm
<img src="transparent-warning-sign.png" alt="WARNING" width="30" height="30" > We should not use this method in real life project. This is only for learning.

## Work to do
-  [X] Understanding Bubble Sort Algorithm.
-  [X] Creating a basic C++ code for Bubble Sort Algorithm.
-  [ ] Creating Template for Bubble Sort Algorithm.
- Applying Bubble Sort in other programming language.

In **Bubble sort**, each element is compared with its adjacent element. If the first element is smaller than the second one, then the positions of the elements are interchanged, otherwise it is not changed.

Then next element is compared with its adjacent element and the same process is rpeated for all the elements in the array until we get a sorted array.

![BubbleSort_Avg_case](BubbleSort_Avg_case.gif)

>## Algorithm 
```C++
void bubble_sort(int arr[], int n){
    bool isSorted = true;
    for (int j = 0; j < n - 1; j++){
        isSorted = true;
        for (int i = 1; i < n; i++){
            if (arr[i-1] > arr[i]){
                std::swap(arr[i-1], arr[i]);
                isSorted = false;
            }
        }
        if (isSorted == true)
            break;
    }
}
```

><img src="https://icon-library.com/images/important-note-icon/important-note-icon-17.jpg" alt="NOTE" width="15" height="15" > Bubble Sort is sometimes also referred as Sinking sort as instead of Bubbling up the smallest element to the left side, some developer write an algorithm to moving (sinking) largest element to right side.

>[!Tip] Time Complexity
Now if we consider time taken by each comparison is constant C. Then the total time taken for the above sorting will be C*( N-1 + N-2 + … + 2 + 1 )  which on solving becomes O(N^2) time complexity.

| <span style="display: block; text-align: center;">Average Case</span> | <span style="display: block; text-align: center;">Worst Case (Reverse List)</span> |
| --------------------------------------------------------------------- | ---------------------------------------------------------------------------------- |
| ![BubbleSort_Avg_case](BubbleSort_Avg_case.gif)                       | ![BubbleSort_Avg_case](BubbleSort_worst_case.gif)                                  |

>## Space Complexity
The **space complexity** for the same will be **O(1)** as all operations are almost in space and only a single variable is used in loop for holding value.

Bubble sort gives stable and in place sorting.

>## Advantage
* When data set is small, bubble sort is efficient
* Easy to implement
* Memory efficient
* It gives stable sort

>## Disadvantage
* It is time-inefficient as it is having O(N2) time complexity.
* For large data set it is not very efficient as time grows exponentially.

>## Example

Let's sort the array `[5, 2, 9, 1, 5, 6]` using Bubble Sort:

- **Initial Array**: [5, 2, 9, 1, 5, 6]
- **Pass 1**: [2, 5, 1, 5, 6, 9] (9 bubbled to the correct position)
- **Pass 2**: [2, 1, 5, 5, 6, 9]
- **Pass 3**: [1, 2, 5, 5, 6, 9] (Array is now sorted)
