/* 224. Basic Calculator
Given a string s representing a valid expression, implement a basic calculator to evaluate it, and return the result of the evaluation.
Note: You are not allowed to use any built-in function which evaluates strings as mathematical expressions, such as eval().

Example 1:
Input: s = "1 + 1"
Output: 2

Example 2:
Input: s = " 2-1 + 2 "
Output: 3

Example 3:
Input: s = "(1+(4+5+2)-3)+(6+8)"
Output: 23
*/

class Solution {
public:
    int calculate(string s) {
        stack<pair<int,int>> st;
        int sum=0, sign=1;

        for(int i=0; i<size(s); i++) {
            if(s[i]==' ')   continue;

            if(isdigit(s[i])) {
                long num=0;
                while(i<size(s) && isdigit(s[i])) {
                    num=num*10 + s[i]-'0';
                    i++;
                }
                i--;

                sum += num*sign;
                sign=1;
            } else if(s[i]=='-') {
                sign=-1;
            } else if(s[i]=='(') {
                st.push({sum, sign});
                sum=0;
                sign=1;
            } else if(s[i]==')') {
                sum = st.top().first + (st.top().second *sum);
                st.pop();
            }
        }
        return sum;
    }
};
