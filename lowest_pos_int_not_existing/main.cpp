#include <iostream>
#include <vector>
#include <algorithm>



//my own thoughts
int smallest_missing_integer(std::vector<int> vectorInts){
    int i= 0;
    std::sort(vectorInts.begin(), vectorInts.end());
    for(int mi : vectorInts){
        
        if(mi == i){
            std::cout<< i << " is found\n";
            i++;
        }else if(mi < i){
            continue;
        }
        else{
            std::cout << "The missing int is " << i << "\n";
            break;
        }
    }
    
    return i;
}

// top tier faang level function for first missing positive

int missingNumber(std::vector<int>& nums){
    int n = nums.size();
    int i = 0;
    while(i<n){
        int correct=nums[i];

        if (correct >= 0 && correct < n && nums[i] != nums[correct])
        {
            std::swap(nums[i], nums[correct]);
        }
        else
        {
            i++;
        }
    }

    
    
    for(int i =0; i< n; i++){
        if(nums[i] != i){
            return i;
        }
    }

    return n;
}

//this accounts for negatives
int firstMissingPositive(std::vector<int> &nums)
{
    int n = nums.size();

    int i = 0;
    while (i < n)
    {
        int val = nums[i];

        if (val >= 1 && val <= n && nums[val - 1] != val)
        {
            std::swap(nums[i], nums[val - 1]);
        }
        else
        {
            i++;
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (nums[i] != i + 1)
        {
            return i + 1;
        }
    }

    return n + 1;
}

int main(){



    std::vector<int> ints = {0,5,8,6,1,7,2,4, -1, -3};
    
    
    smallest_missing_integer(ints);
    std::cout << "missing number is: " << missingNumber(ints)<< std::endl;
    std::cout << "first missing positive number is: " << firstMissingPositive(ints) << " \n";

    return 0;
}