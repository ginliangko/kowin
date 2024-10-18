/*
20. Valid Parentheses

Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
*/

// Runtime 0ms Beats 100.00%, Memory 7.78MB Beats 77.77%
bool isValid(char* s) {
    int len = strlen(s);
    char *stack=malloc(len);
    int p=0;

    for(int i=0; i<len; i++) {
        char c=s[i];
        switch(c) {
        case '(':
        case '[':
        case '{':   stack[p++]=c;    break;
        case ')':   if(p<=0 || stack[--p]!='(')    return false;    break;
        case ']':   if(p<=0 || stack[--p]!='[')    return false;    break;
        case '}':   if(p<=0 || stack[--p]!='{')    return false;    break;
        }
    }
    if(p>0) return false;
    return true;
}

/* Original solution
bool isValid(char* s) {
    int l;
    char *stack, c;
    int sp = 0;
    
    if (!s || !*s) return true;
    
    l = strlen(s);
    stack = malloc(l * sizeof(char));
    //assert(stack);
    while (c = *s ++) {
        switch (c) {
            case '(':
            case '{':
            case '[':
                stack[sp ++] = c;
                break;
            case ')':
                if (sp == 0 || stack[-- sp] != '(') { free(stack); return false; }
                break;
            case '}':
                if (sp == 0 || stack[-- sp] != '{') { free(stack); return false; }
                break;
            case ']':
                if (sp == 0 || stack[-- sp] != '[') { free(stack); return false; }
                break;
            default:
                break;
        }
    }
    
    free(stack);
    return sp == 0 ? true : false;
}
*/

/*
Difficulty:Easy
Total Accepted:224.5K
Total Submissions:672.8K


Companies Google Airbnb Facebook Twitter Zenefits Amazon Microsoft Bloomberg
Related Topics Stack String
Similar Questions 
                
                  
                    Generate Parentheses
                  
                    Longest Valid Parentheses
                  
                    Remove Invalid Parentheses
*/
