LC:151 : Reverse Words in a String
https://leetcode.com/problems/reverse-words-in-a-string/
//Using sstream Method that works as a split method of Java
class Solution {
public:
    string reverseWords(string s) {
        vector<string> res;
        
        stringstream str(s);
        
        string word;
        
        string ans;
        
        while(str>>word){
            res.push_back(word);
        }
        
        for(int i = res.size()-1 ; i>=0 ;i--){
            ans =ans+" "+ res[i];
        }
            
        ans.erase(0,1);
            
        return ans;
    }
};
//Using without any Function
/*
class Solution {
public:
    string reverseWords(string s) {
         stack<string>st;
        int start = 0;
        int end = s.length();
        while(s[start]==' '){
            start++;
        }
        while(s[end]==' '){
            end--;
        }
        for(int i = start ; i<end ; i++){
            string word = " ";
            while(i<end && s[i]!=' '){
                word = word + s[i];
                
                i++;
                if(i==end){
                    st.push(word);
                    break;
                
                }
                
                if(s[i]==' ' && i<end){
                    st.push(word);
                    st.push("");
                }
                
                
                
            }
            while(i<end && s[i+1]==' ' ){
                i++;
            }
            
        }
       
        string ans;
        while(!st.empty()){
            ans = ans + st.top();
            st.pop();
            
        }
        ans.erase(0, 1);
        return ans;
        
    }
};
*/