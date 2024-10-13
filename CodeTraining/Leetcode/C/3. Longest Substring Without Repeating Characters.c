/*
3. Longest Substring Without Repeating Characters

Given a string, find the length of the longest substring without repeating characters.

Examples:

Given "abcabcbb", the answer is "abc", which the length is 3.

Given "bbbbb", the answer is "b", with the length of 1.

Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/

int lengthOfLongestSubstring(char* s) {
    int i, j, l, k = 0;
    char c;
    int pos[128] = { 0 };
    char *p;
    int n = 0;
    
    for (i = 0; s[i]; i ++) {
        n ++;
        c = s[i];
        l = i - pos[c] + 1;
        pos[c] = i + 1;
        n = n < l ? n : l;
        k = k > n ? k : n;
    }
    
    return k;
}

/* Solution by Jerry
int lengthOfLongestSubstring(char* s) {
    int len=strlen(s), start=0, end=0, max=1, d=0;

    if(len<=1)  return len;

    while(start<len-1 && end<len-1) {
        if(s[end]==s[end+1]) {
            end++;
            start=end;
        } else {
            for(int i=start; i<end; i++) {
                if(s[i]==s[end+1]) {
                    d=1;
                    break;
                }
            }

            if(d==0) {
                end++;
            } else {
                start++;
                d=0;
            }
        }
        max=max>(end-start+1)?max:(end-start+1);
    }
    return max;
}
*/

/*
Difficulty:Medium
Total Accepted:330.3K
Total Submissions:1.4M


Companies Amazon Adobe Bloomberg Yelp
Related Topics Hash Table Two Pointers String
Similar Questions 
                
                  
                    Longest Substring with At Most Two Distinct Characters
*/
