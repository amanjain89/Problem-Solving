//LC3 : Longest Substring without Repeating Character


//BruteForce Approach : Enumerate over all the substring and check if there exists duplicate character
// SC : O(n^3) , TC : O(k) where k is size of set
//TLE
/*class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res = 0;
        
        for(int i = 0 ; i <s.length() ;i++){
            
            for(int j = i ; j<s.length();j++ ){
                
                if(checkDuplicate(s , i , j))
                    res = max(res , j-i+1);
            }
        }
        
        return res;
    }
    
    bool checkDuplicate(string& s , int i , int j){
        // we will use unordered set to check duplicate character.
        
        unordered_set<char> set;
        
        while(i<=j){
            
            char ch = s[i];
            
            //set.count(ch) gives presence of character or not. returns either 0 or 1
            
            if(set.count(ch))
                return false;
            set.insert(ch);
        }
        return true;       
    }
}; */



//Sliding Window Approach: Using Hash Map and Sliding Window Approach using 2 Pointers 
// TC : O(2n) , In worst case each element will be visited twice by left and right pointer
// SC : O(k) , Size of HashMap

/*
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res = 0;
        unordered_map<char ,int> um;
        
        int left = 0 , right = 0;
        
        int len = s.length();
        
        while(right < len){
            
            char ch = s[right];
            um[ch]++;
            
            while(um[ch] > 1){
                char chl = s[left];
                um[chl]--;
                left++;
            }
            
            res = max(res , right - left + 1);
            
            right++;
        }
        
        return res;
    } 
}; */

// Approach Sliding Window but we can avoid 2n visits to n visits only by mapping in map
// we have s[j] duplicate in range of (i,j) with index j' so we can directly move i to j'+1 instead of
// moving slowly by 1 and check like above case

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res = 0;
        vector<int> um(256, -1);
        
        int left = 0 , right = 0;
        
        while(right < s.length()){
            char ch = s[right];
            
            if(um[ch]!=-1)
                left = max(left, um[ch] + 1);
        
            
            
            std::cout<<res;
            
            um[ch] = right;
            
            res = max(res, right-left+1);
            
            right++;
        }
        return res;
    }
}; 