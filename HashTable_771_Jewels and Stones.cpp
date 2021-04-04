// 771. Jewels and Stones

// You're given strings jewels representing the types of stones that are jewels, and stones representing the stones you have. Each character in stones is a type of stone you have. You want to know how many of the stones you have are also jewels.

// Letters are case sensitive, so "a" is considered a different type of stone from "A".

class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
      int res = 0;
      unordered_set<char> hashSet;
      for(char c: jewels) hashSet.insert(c);
      for(char c: stones){
        if(hashSet.find(c) != hashSet.end()) res++;
      }
      
      return res;
    }
};