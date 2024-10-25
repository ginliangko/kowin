/*
242. Valid Anagram
Given two strings s and t, write a function to determine if t is an anagram of s. 

For example,
s = "anagram", t = "nagaram", return true.
s = "rat", t = "car", return false.

Note:
You may assume the string contains only lowercase alphabets.

Follow up:
What if the inputs contain unicode characters? How would you adapt your solution to such case?
*/

// Solution 1
bool isAnagram(char* s, char* t) {
    int m[26]={0};
    int i=0;

    if(strlen(s) != strlen(t))  return false;
    while(s[i] && t[i]) {
        m[s[i]-'a']++;
        m[t[i]-'a']--;
        i++;
    }

    for(int j=0; j<26; j++) {
        if(m[j])  return false;
    }

    return true;
}

// Solution 2
bool isAnagram(char* s, char* t) {
    int n1[26] = { 0 }, n2[26] = { 0 };
    int i, j;
    
    while (*s && *t) {
        i = *s - 'a';
        j = *t - 'a';
        n1[i] ++;
        n2[j] ++;
        s ++;
        t ++;
    }
    
    if (*s || *t) return false;
    
    for (i = 0; i < 26; i ++) {
        if (n1[i] != n2[i]) return false;
    }
    
    return true;
}


/*
Difficulty:Easy
Total Accepted:165.9K
Total Submissions:357.7K


Companies Amazon Uber Yelp
Related Topics Hash Table Sort
Similar Questions 
                
                  
                    Group Anagrams
                  
                    Palindrome Permutation
                  
                    Find All Anagrams in a String
*/
