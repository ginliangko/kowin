/*
125. Valid Palindrome

Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.



For example,
"A man, a plan, a canal: Panama" is a palindrome.
"race a car" is not a palindrome.



Note:
Have you consider that the string might be empty? This is a good question to ask during an interview.

For the purpose of this problem, we define empty string as valid palindrome.
*/

char cToC(char c) {
    if(((c>='a') && (c<='z')) || ((c>='0') && (c<='9')))    return c;
    else if((c>='A') && (c<='Z'))                           return c-'A'+'a';
    else                                                    return ' ';
}

bool isPalindrome(char* s) {
    int start=0;
    int end=strlen(s)-1;

    while(start<end) {
        while(start<end&&cToC(s[start])==' ')  start++;
        while(start<end&&cToC(s[end])==' ')    end--;
        if(cToC(s[start++])!=cToC(s[end--])) {return false;}
    }

    return true;
}

/*
// Solution from network
bool isPalindrome(char* s) {
    int i = 0;
    int j;
    char a, b;
    
    if (!s || !*s) return true;
    
    j = strlen(s) - 1;
    while (i < j) {
        a = s[i];
        b = s[j];
        if (!((a >= '0' && a <= '9') ||
              (a >= 'A' && a <= 'Z') ||
              (a >= 'a' && a <= 'z'))) {
            i ++;
            continue;
        }
        if (!((b >= '0' && b <= '9') ||
              (b >= 'A' && b <= 'Z') ||
              (b >= 'a' && b <= 'z'))) {
            j --;
            continue;
        }
        a = a > 'Z' ? a - 'a' + 'A' : a;
        b = b > 'Z' ? b - 'a' + 'A' : b;
        if (a != b) {
            return false;
        }
        i ++;
        j --;
    }
    return true;
}
*/

/*
Difficulty:Easy
Total Accepted:170.9K
Total Submissions:651.4K


Companies Microsoft Uber Facebook Zenefits
Related Topics Two Pointers String
Similar Questions 
                
                  
                    Palindrome Linked List
*/
