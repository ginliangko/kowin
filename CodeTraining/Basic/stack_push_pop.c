#define STACK_MAX   4096
int stack[STACK_MAX]={0};
int p=0;

void init_stack(void) {
    p=0;
}

int push(int a) {
    if(p>=STACK_MAX)    return -1;
    stack[p++]=a;
    return 0;
}

int pop(void) {
    if(p<=0)     return -1;
    p--;
    return stack[p];
}

int get_len(void) {
    return p;
}

int main(void) {
    init_stack();
  
    push(10);
    get_len();
    int v = pop();
    get_len();

    return 0;
}
