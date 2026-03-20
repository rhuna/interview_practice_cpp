

#binary search tree, hash set, two-pointer technique
#big O(n log n) time complexity, as it sorts the array and then uses binary search to find the complement of each element
def two_sum_binary_search(arr, k):
    # This function checks if there are any two numbers in the array that sum up to k using binary search
    arr.sort()  # Sort the array first
    for i in range(len(arr)):
        complement = k - arr[i]  # Calculate the complement
        left, right = i + 1, len(arr) - 1  # Initialize two pointers for binary search
        while left <= right:  # Perform binary search for the complement
            mid = left + (right - left) // 2
            if arr[mid] == complement:  # If the complement is found, return True
                return True
            elif arr[mid] < complement:  # If the mid value is less than the complement, search in the right half
                left = mid + 1
            else:  # If the mid value is greater than the complement, search in the left half
                right = mid - 1
    return False  # If no pair is found, return False



#big O(n) time complexity, as it uses a hash set to check for the complement of each element in a single pass

def two_sum(arr, k):
    # This function checks if there are any two numbers in the array that sum up to k
    seen = set()  # Create a set to store seen numbers
    for num in arr:
        complement = k - num  # Calculate the complement
        if complement in seen:  # Check if the complement is in the seen set
            return True  # If found, return True
        seen.add(num)  # Add the current number to the seen set
    return False  # If no pair is found, return False

#big O(n log n) time complexity, as it sorts the array and then uses a two-pointer technique to find pairs that sum to k
def two_sum_sorted(arr, k):
    # This function checks if there are any two numbers in the sorted array that sum up to k
    arr.sort()  # Sort the array first
    left, right = 0, len(arr) - 1  # Initialize two pointers
    while left < right:  # Iterate until the two pointers meet
        current_sum = arr[left] + arr[right]  # Calculate the sum of the elements at the two pointers
        if current_sum == k:  # If the sum is equal to k, return True
            return True
        elif current_sum < k:  # If the sum is less than k, move the left pointer to increase the sum
            left += 1
        else:  # If the sum is greater than k, move the right pointer to decrease the sum
            right -= 1
    return False  # If no pair is found, return False


#big O(n^2) time complexity due to the nested loops
def arrayList_return_any_equal_k(arr, k):
    # This function returns any number from the array that has a complement in the array that sums to k
    seen = set()  # Create a set to store seen numbers
    for num in arr:
        complement = k - num  # Calculate the complement
        if complement in seen:  # Check if the complement is in the seen set
            return num  # If found, return the current number (or you could return the complement)
        seen.add(num)  # Add the current number to the seen set
    return None  # If no such number is found, return None  

if __name__ == "__main__":
    arr = [10, 15, 3, 7]
    k = 17
    print(two_sum(arr, k))  # Output: True
    print(two_sum_sorted(arr, k))  # Output: True
    print(arrayList_return_any_equal_k(arr, k))  # Output: 2 or 3 (since both have complements that sum to 5)