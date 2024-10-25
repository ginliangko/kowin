/* 290. Word Pattern
Given a pattern and a string s, find if s follows the same pattern.
Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in s. Specifically:
Each letter in pattern maps to exactly one unique word in s.
Each unique word in s maps to exactly one letter in pattern.
No two letters map to the same word, and no two words map to the same letter.
 
Example 1:
Input: pattern = "abba", s = "dog cat cat dog"
Output: true
Explanation:
The bijection can be established as:
'a' maps to "dog".
'b' maps to "cat".

Example 2:
Input: pattern = "abba", s = "dog cat cat fish"
Output: false

Example 3:
Input: pattern = "aaaa", s = "dog cat cat dog"
Output: false
*/

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        s=s+' ';
        unordered_map<string,char>mp1;
        unordered_map<char,string>mp2;
        string temp="";
        int ind=0;
        for(auto i:s){
            if(i==' '){
                if(mp1.count(temp)>0 && mp1[temp]!=pattern[ind]){
                    return false;
                } else {
                    mp1[temp]=pattern[ind];
                }

                if(mp2.count(pattern[ind])>0 && mp2[pattern[ind]]!=temp){
                    return false;
                } else {
                    mp2[pattern[ind]]=temp;
                }
                ind++;
                temp.clear();
            } else {
                temp+=i;
            }
        }
      
        return ind == pattern.size(); 
    }
};
