// Given an integer n, return the number of structurally unique BST's (binary search trees) which has exactly n nodes of unique values from 1 to n.

// Solution: Calculate Catlan No. result= 2nCn/(n+1)
class Solution {
public:
    long binomialCoeff(int n, int r){
      long res = 1;
      if(r > (n-r)) r = n-r;
      
      for (int i=0; i<r; i++){
        res *= (n-i);
        res /= (i+1);
      }
      return res;
    }
    long numTrees(int n) {
      long res = binomialCoeff(2*n, n);
      res = res/(n+1);
      return res;
    }
};