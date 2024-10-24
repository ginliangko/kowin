/*
205. Isomorphic Strings
Given two strings s and t, determine if they are isomorphic.
Two strings are isomorphic if the characters in s can be replaced to get t.
All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character but a character may map to itself.

Example 1:
Input: s = "egg", t = "add"
Output: true
Explanation:
The strings s and t can be made identical by:
Mapping 'e' to 'a'.
Mapping 'g' to 'd'.

Example 2:
Input: s = "foo", t = "bar"
Output: false
Explanation:
The strings s and t can not be made identical as 'o' needs to be mapped to both 'a' and 'r'.

Example 3:
Input: s = "paper", t = "title"
Output: true

Note:
You may assume both s and t have the same length.
*/

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int a[128]={0}, b[128]={0};

        for(int i=0; i<s.length(); i++) {
            if(a[s[i]]==0 && b[t[i]]==0) {
                a[s[i]]=t[i];
                b[t[i]]=s[i];
            } else if(a[s[i]]!=t[i] || b[t[i]]!=s[i]) {
                return false;
            }
        }

        return true;
    }
};
