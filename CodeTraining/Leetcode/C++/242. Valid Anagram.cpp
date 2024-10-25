/* 242. Valid Anagram
Given two strings s and t, return true if t is an 
anagram of s, and false otherwise.

Example 1:
Input: s = "anagram", t = "nagaram"
Output: true
  
Example 2:
Input: s = "rat", t = "car"
Output: false
*/
// Solution 1
class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<int, int> m;
        int i=0;

        for(auto x:s)   m[x-'a']++;
        for(auto x:t)   m[x-'a']--;

        for(auto k:m) {
            if(k.second != 0)    return false;
        }
        return true;
    }
};

// Solution 
class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s==t;
    }
};
