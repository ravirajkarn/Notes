---
Author: Sumit Kumar
Email: ravirajkarn21@gmail.com
Date Created: 2026-02-02 20:08::03 PM
tags:
  - Algorithm
  - Searching_Algo
  - Binary_Search
  - python
  - Cpp
---
# Binary Search
It divide and concur rule.
We divide an array/list in two part and check for the number. If the number is less then the given number then we check the first half. the first half will again divide into two part and so on. If the number is grater then the given number then we will work on the second half and further divide it and so on. If the number if equal to the number given then we found it!
![[Binary Search.png]]

> [!important] 
> - Binary search only works when your list is in sorted order.

> [!success] Python Implementation
> The binary_search function takes a sorted array and an item. If the  item is in the array, the function returns its position.
> ```python
> def binary_search(list, item):
> 	low = 0
> 	high = len(list) - 1
> 	num = (low + high) // 2
> 	mid = list[num]
> 	
> 	while low <= high and mid != item and item >= list[low] and item <= list[high]:
> 	if item > mid:
> 		low = num + 1
> 	else:
> 		high = num
> 		num = (low + high) // 2
> 		mid = list[num]
> 	if (mid == item):
> 		return num + 1
> 
> def main():
> 	number = [11, 12, 13, 14, 16, 17, 18, 19, 110, 111]
> 	item = 19
> 	print(f"the number is: {binary_search(number, item)}")
>   
> if __name__ == "__main__":
> 	main()
> ```

> [!success] CPP Implementation
> ```Cpp
> #include <iostream>
> #include <vector>
> int my_binary_search(const std::vector<int>& list, int item) {
> 	if (list.empty()) return -1;
> 	int low = 0;
> 	int high = list.size() - 1;
> 	int num = (low + high)/ 2;
> 
> 	int mid = list.at(num);
> 	while (low <= high && mid != item && item >= list.at(low) &&
> item <= list.at(high)) {
> 		if (item > mid)
> 			low = num + 1;
> 		else
> 			high = num;
> 		num = (low + high) / 2;
> 		mid = list.at(num);
> 		if (mid == item) return num + 1;
> 	}
> 	return -1;
> }
>   
> int main() {
> 	std::vector<int> number = {11, 12, 13, 14, 16, 17, 18, 19, 110, 111};
> 	int item = 19;
> 	std::cout << "the numbe is: " << my_binary_search(number, item) << std::endl;
> 	return 0;
> }
> ```

>[!Tip] Time Complexity
>- **Best Case: O(1)**
>- **Average Case: O($log(n)$) **
>- Worst case: O($log(n)$)
