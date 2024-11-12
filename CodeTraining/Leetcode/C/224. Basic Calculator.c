/*   224. Basic Calculator
Implement a basic calculator to evaluate a simple expression string.
The expression string may contain open ( and closing parentheses ), the plus + or minus sign -, non-negative integers and empty spaces  .
You may assume that the given expression is always valid.
Note: Do not use the eval built-in library function.

Some examples:
"1 + 1" = 2
" 2-1 + 2 " = 3
"(1+(4+5+2)-3)+(6+8)" = 23
*/
int parse(char **sp, int* k) {
    char *s = *sp;

    while(*s == ' ')   s++;

    *k = 0;

    if(*s == 0)    return 0;    //The End

    if(*s == '+' || *s == '-' || *s == '*' || *s == '/' || *s == '(' || *s == ')') {
        *k = *s == '+' ? 1 :
             *s == '-' ? 2 :
             *s == '*' ? 3 :
             *s == '/' ? 4 :
             *s == '(' ? 5 : 6;
        *sp = ++s;
        return 1;   // Operator
    }

    while(*s >= '0' && *s <= '9') {
        *k = ((*k) * 10) + (*s - '0');
        s++;
    }

    *sp = s;
    return 2;   // Number
}

int low_op(int* ops, int oi, int k) {
    const int priority[] = { 0, 2, 2, 3, 3, 1, 1 }; // null, +, -, *, /, (, )
    if(oi==0)   return 0;
    return (priority[ops[oi-1]] >= priority[k]) ? 1 : 0;
}

int calculate(char* s) {
    int len=strlen(s);
    int d[128]={0}, o[128]={0};
    int di=0, oi=0, k=0, a=0, b=0, x=0;

    d[di++]=0;
    o[oi++]=0;
    do {
        x = parse(&s, &k);
        if (x == 2) {           // data, push to stack
            d[di++]=k;
        } else if (k == 5) {    // left parenthese, always push
            o[oi++]=k;
        } else {                // operator
            while(low_op(o, oi, k)) {
                int op = o[--oi];
                if (op== 0 || op == 5) break; // end of input or left parenthese
                b = d[--di];
                a = d[--di];
                switch(op) {
                    case 1:  a = a + b; break;  // '+'
                    case 2:  a = a - b; break;  // '-'
                    case 3:  a = a * b; break;  // '*'
                    case 4:  a = a / b; break;  // '/'
                    default:            break;
                }
                d[di++]=a;
            }

            if(k && k != 6)     o[oi++]=k;  // ignore end or right parenthese
        }
    } while(x);

    return d[di-1];
}
/*
Difficulty:Hard
Total Accepted:51.6K
Total Submissions:190.7K


Companies Google
Related Topics Stack Math
Similar Questions 
                
                  
                    Evaluate Reverse Polish Notation
                  
                    Basic Calculator II
                  
                    Different Ways to Add Parentheses
                  
                    Expression Add Operators
*/
