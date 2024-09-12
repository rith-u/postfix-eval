#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>
#define MAX 15
int stack [MAX];
int top = -1;

void push(int x){
    if(top == MAX-1){
        printf("Stack Overflow\n");
    }
    else{
        top++;
        stack[top] = x;
    }
}

int pop(){
    if(top == -1){
        printf("Stack Underflow\n");
    }
    else{
        int x = stack[top];
        top--;
        return x;
    }
}
int expo(int b, int e){
    int prod = 1;
    while(e--){
        prod*=b;
    }
    return prod;
}
int evalPostfix(char *exp){
    for(int i =0; exp[i] != '\0'; i++){
        char ch = exp[i];
        if(isdigit(ch)) push(ch - '0');
        else{ 
            int val1 = pop();
            int val2 = pop();
            switch(ch){
                case '+': push(val2 + val1); break;
                case '-': push(val2 - val1); break;
                case '*': push(val2 * val1); break;
                case '/': push(val2 / val1); break;
                case '%': push(val2 % val1); break;
                case '^': push(expo(val2, val1)); break;
                default: printf("Invalid Input"); return -1;
            }
        }
    }
    return pop();
}
int main(){
    char exp[] = "23+12*42/^^";
    printf("%d\n", evalPostfix(exp));
    return 0;
}