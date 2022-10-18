LC-15: Three Sum Problem
https://leetcode.com/problems/3sum/
//Brute Force Approach O(n^3) 
//TLE
/*
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
       //create set of vecto<int> type
        set<vector<int>> set ;
        
        // Check if i!=j , i !=k ,  j!=k and sum to 0.
        for(int i = 0 ; i< nums.size()-2 ; i++){
            for(int j = 0 ; j<nums.size()-1 ;j++){
                for(int k=0 ; k<nums.size() ;k++){
                    
                    if((i != j && i!=k && j!=k) && nums[i] + nums[j] + nums[k] == 0){
                      //Creating vector with 3 values
                       vector<int> v = {nums[i] , nums[j] , nums[k]};
                       
                       //Sorting Vector
                       sort(v.begin() , v.end());
                       
                       //inserting into set of vector<int> type
                       set.insert(v);
                    }
                }
            }
        }
            //Copy set to vector of same type
            vector<vector<int>> res(set.begin() , set.end());
            
            return res;
            
        }
};
*/

// Two Pointer solution using Sorting TC : O(nlogn + n)

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> set ;
        //Sort Vector
        sort(nums.begin() , nums.end());
        
        for(int i =0 ; i< nums.size()-2 ;i++){
            
            int start = i+1;
            int end = nums.size()-1;
            
            while(start < end){
                int sum = nums[i] + nums[start] + nums[end];
                if(sum  == 0){
                    set.insert({nums[i] , nums[start++] , nums[end--]});
                }else if(sum < 0)
                    start++;
                else
                    end--;
            }
        }
            
            vector<vector<int>> res(set.begin() , set.end());
            
            return res;
            
        }
};