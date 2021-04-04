// 1512. Number of Good Pairs

// Given an array of integers nums.

// A pair (i,j) is called good if nums[i] == nums[j] and i < j.

// Return the number of good pairs.

class Solution {
public:
    int npr(int n){
      //n!/(2*(n-2)!) = n(n-1)/2
      //r = 2;
      return n*(n-1)/2;
    }

    int numIdenticalPairs(vector<int>& nums) {
      
      if(nums.size() == 0) return 0;
      
      int res = 0;
      unordered_map<int, int> hashMap;
      
      for(int x: nums){
        hashMap[x]++;
      }
      
      for(auto pair: hashMap){
        if(pair.second > 1){
          res += npr(pair.second);
        }
      }
      
      return res;
    }
};