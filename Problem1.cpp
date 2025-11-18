//problem: https://www.geeksforgeeks.org/problems/missing-number-in-sorted-array-of-natural-numbers/1
// Time complexity: O(log n) - binary search 
// Space complexity: O(1) - not utilizing extra space for any ops

// Approach: as the questing states as these are integers from 1 to n where there is a change of one missing element
// if it's a sorted array from 1 to n elements, their respective indices should be index - 1...find the mid element and find out if this discrepancy happended 
// on left array of right array..move the low and high values accordingly to narrow down the search and where these both low and high index meet is where discrapency happended
//so return that index ( .i.e our current low or high ) + 1 to produce the missing value
//
class Solution {
  public:
    int missingNumber(vector<int>& arr) {
        // Code here
        
        int low = 0, high = arr.size() -1;
        int res = -1;
        
        if(arr[low] != 1) return 1;
        
        while(low <= high){
            
            int mid = low + (high - low)/2;
            
            if(mid == arr[mid] - 1){// don have to look on the left
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
           res = low + 1;//this is where both pointers meet & the value will be index + 1
           
        }
        
        return res;
    }
};
