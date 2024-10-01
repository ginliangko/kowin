/*
14. Longest Common Prefix

Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

Example 1:

Input: ["flower","flow","flight"]
Output: "fl"


Example 2:

Input: ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.


Note:

All given inputs are in lowercase letters a-z.
*/

cchar* longestCommonPrefix(char** strs, int strsSize) {
    int j=0;
    char c=0;

    while(c=strs[0][j]) {
        for(int i=0; i<strsSize; i++) {
            if(c!=strs[i][j]) {
                strs[0][j]=0;
                return strs[0];
            }
        }
        j++;
    }
    strs[0][j]=0;
    return strs[0];
}

/*
Difficulty:Easy


*/
