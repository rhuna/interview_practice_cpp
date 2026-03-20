#include <iostream>
#include <vector>
#include <chrono>

//big O(N LOG N) time complexity, as it uses a nested loop to calculate the product of all elements except the current index
std::vector<int> product_except_self(const std::vector<int>& nums) {
    //start time
    auto start = std::chrono::high_resolution_clock::now();
    std::vector<int> result(nums.size(), 1); // Initialize result vector with 1s
    for (size_t i = 0; i < nums.size(); ++i) {
        for (size_t j = 0; j < nums.size(); ++j) {
            if (i != j) {
                result[i] *= nums[j]; // Multiply all elements except the current index
            }
        }
    }
    //end time
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    std::cout << "Time taken: " << elapsed.count() << " seconds" << std::endl;
    return result;
}



int main() {
    std::vector<int> nums = {1, 2, 3, 4};
    std::vector<int> result = product_except_self(nums);
    
    std::cout << "Input: ";
    for (int num : nums) {
        std::cout << num << " ";
    }
    std::cout << "\nOutput: ";
    for (int prod : result) {
        std::cout << prod << " ";
    }
    std::cout << std::endl;
    
    return 0;
}