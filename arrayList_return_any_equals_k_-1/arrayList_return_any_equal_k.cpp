#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <chrono>

// Function to return any elements from the array that sum up to k
// this is of O(n^2) time complexity, as it uses nested loops to check all pairs of elements
std::vector<int> arrayList_return_any_equal_k(const std::vector<int>& arr, int k) {
    //time complexity: O(n^2) due to the nested loops
    //start time measurement
    auto start = std::chrono::high_resolution_clock::now();
    // Create a vector to store the result
    std::vector<int> result;
    // Iterate through the array and check for pairs that sum to k
    for (int num : arr) {
        // Check if there is another number in the array that, when added to num, equals k
        for(int other_num : arr) {
            // Skip the same number to avoid using it twice            if (num == other_num) {continue;}
            if (num + other_num == k) {
                // If we find such a pair, we can add either num or other_num to the result
                result.push_back(num);
                break; // Break to avoid adding the same number multiple times
            }
        }   
    }
    //end time measurement
    auto end = std::chrono::high_resolution_clock::now();
    // Calculate the duration and print it
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    // Print the time taken by the function
    std::cout << "Time taken by arrayList_return_any_equal_k: " << duration.count() << " microseconds" << std::endl;
    return result;
}

// Test function to verify the correctness of arrayList_return_any_equal_k
bool test_arrayList_return_any_equal_k() {
    // Test case: arr = [10, 15, 3, 7], k = 17
    std::vector<int> arr = {10, 15, 3, 7};
    // We expect to find either 10 or 7, since 10 + 7 = 17
    int k = 17;
    // The expected result can be either 10 or 7, so we will check if the result contains either of these values
    std::vector<int> expected = {10,7};
    // Call the function and get the result
    std::vector<int> result = arrayList_return_any_equal_k(arr, k);
    // Check if the result contains either 10 or 7
    return result == expected;
}



bool two_sum(const std::vector<int>& arr, int k) {
    //this function is of O(n) time complexity, as it uses a hash set to check for the complement of each element in a single pass
   // Start time measurement
    auto start = std::chrono::high_resolution_clock::now();
   // Create a hash set to store seen numbers
    std::unordered_set<int> seen;
    // Iterate through the array and check for the complement
    for (int num : arr) {
        // Calculate the complement that would sum to k
        int complement = k - num;
        // Check if the complement is already in the seen set
        if (seen.count(complement)) {
            // If it is, we found a pair that sums to k
            return true; 
        }
        // Otherwise, add the current number to the seen set
        seen.insert(num);
    }
    //end time measurement
    auto end = std::chrono::high_resolution_clock::now();
    // Calculate the duration and print it
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    // Print the time taken by the function
    std::cout << "Time taken by two_sum: " << duration.count() << " microseconds" << std::endl;

    return false;
}

//big O(N log N) time complexity, as it sorts the array and then uses a two-pointer technique to find pairs that sum to k
bool two_sum_sorted(std::vector<int> arr, int k) {
        // Start time measurement
    auto start = std::chrono::high_resolution_clock::now();
    // Sort the array first
    std::sort(arr.begin(), arr.end());
    
    // Use two pointers to find pairs that sum to k
    int left = 0;
    int right = arr.size() - 1;
    
    // Iterate until the two pointers meet
    while (left < right) {
        // Calculate the sum of the elements at the two pointers
        int sum = arr[left] + arr[right];
        if (sum == k) {
            return true; // Found a pair that sums to k
        } else if (sum < k) {
            left++; // Move the left pointer to increase the sum
        } else {
            right--; // Move the right pointer to decrease the sum
        }
    }
    //end time measurement
    auto end = std::chrono::high_resolution_clock::now();
    // Calculate the duration and print it
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    // Print the time taken by the function
    std::cout << "Time taken by two_sum_sorted: " << duration.count() << " microseconds" << std::endl;
    return false; // No pair found that sums to k
}


//binary search function to find if a number exists in a sorted array
bool binary_search(const std::vector<int>& arr, int target) {
    // Start time measurement
    auto start = std::chrono::high_resolution_clock::now();
    // Initialize the left and right pointers for binary search
    int left = 0;
    int right = arr.size() - 1;
    // Perform binary search
    while (left <= right) {
        int mid = left + (right - left) / 2; // Calculate the middle index
        if (arr[mid] == target) {
            return true; // Target found
        } else if (arr[mid] < target) {
            left = mid + 1; // Search in the right half
        } else {
            right = mid - 1; // Search in the left half
        }
    }
    //end time measurement
    auto end = std::chrono::high_resolution_clock::now();
    // Calculate the duration and print it
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    // Print the time taken by the function
    std::cout << "Time taken by binary_search: " << duration.count() << " microseconds" << std::endl;
    return false; // Target not found
}


int main() {
    std::vector<int> arr = {10, 15, 3, 7};
    int k = 17;

    //big O(n^2) time complexity, as it uses nested loops to check all pairs of elements
    std::vector<int> result = arrayList_return_any_equal_k(arr, k);
    
    std::cout << "Elements equal to " << k << ": ";
    for (int num : result) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    std::cout << "Test passed: " << (test_arrayList_return_any_equal_k() ? "Yes" : "No") << std::endl;  


    //big O(n) time complexity, as it uses a hash set to check for the complement of each element in a single pass
    bool has_pair = two_sum(arr, k);
    std::cout << "Pair that sums to " << k << ": " << (has_pair ? "Yes" : "No") << std::endl;


    //big O(N log N) time complexity, as it sorts the array and then uses a two-pointer technique to find pairs that sum to k
    bool has_pair_sorted = two_sum_sorted(arr, k);
    std::cout << "Pair that sums to " << k << " (sorted): " << (has_pair_sorted ? "Yes" : "No") << std::endl;



    return 0;
}