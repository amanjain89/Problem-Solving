//1. Problem : TwoSum :
//LC: https://leetcode.com/problems/two-sum/

// BruteForce TC: O(n^2) , SC: O(1)
/*class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        
        for(int i = 0 ; i< nums.size()-1 ; i++){
            
            for(int j = i+1 ; j<nums.size() ; j++){
                
                if(nums[i]+nums[j]  == target)
                    res.push_back(i);
                    res.push_back(j);
                    
                    return res;
            }
        }
        
        return res;
    }
};*/


// Sorting and Two Pointer TC: O(nlogn + n) , SC : O(1)
/*
class Solution {
public:
    vector<int> twoSum(vector<int>& v, int target) {
        vector<int> res;
        
        sort(v.begin() , v.end());
        
        int start = 0 , end = v.size()-1;
        
        while(start < end){
            
            if(v[start] + v[end] < target)
                start++;
            else if(v[start]+v[end]>target)
                end--;
            else
            {
                res.push_back(start);
                res.push_back(end);
                
                return res;
            }
        }
        
        return res;
    }
};*/


// Using Unorder_map  TC: O(n) , SC : O(1)

class Solution {
public:
    vector<int> twoSum(vector<int>& v, int target) {
       // vector<int> res;
        unordered_map<int,int> mp;
        
        for(int i = 0 ; i < v.size() ; i++){
            
            if(mp.find(target - v[i]) == mp.end())
                mp.insert({v[i] , i});
           /* else
            {
                res.push_back(i);
                res.push_back(mp[target-v[i]]);
                
                return res;
            }*/
            else
                return {i , mp[target-v[i]]} ; 
        }
        //return res;
        return {};
    }
};