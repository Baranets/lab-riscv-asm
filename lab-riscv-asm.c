#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

#define N 5
#define M 4

// MARK: - Stack functions 

struct Stack {
    int top;
    unsigned capacity;
    int* array;
};

struct Stack* createStack(unsigned capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int*)malloc(stack->capacity * sizeof(int));
    return stack;
}

// Stack is full when top is equal to the last index
int isFull(struct Stack* stack) {
    return stack->top == stack->capacity - 1;
}
 
// Stack is empty when top is equal to -1
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

// Function to add an item to stack. It increases top by 1
void push(struct Stack* stack, int item) {
    if (isFull(stack))
        return;
    stack->array[++stack->top] = item;
}

void pushArray(struct Stack* stack, int n, int m, int array[N][M]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            push(stack, array[i][j]);
        }
    }
}
 
// Function to remove an item from stack. It decreases top by 1
int pop(struct Stack* stack) {
    if (isEmpty(stack))
        return INT_MIN;
    return stack->array[stack->top--];
}

// MARK: - Processing Function

int process(struct Stack* stack) {
    int result = __INT_MAX__;
    
    while (!isEmpty(stack))
    {
        int value = pop(stack);
        if (value < result)
            result = value;
    }

    return result;
}

int main(int argc, char** argv) {
    int array[N][M] = {
        {  3,  2,  4, 11 },
        {  5,  1,  6, 10 },
        {  7,  9,  8, 12 }, 
        { 20, 19, 18, 17 },
        { 13, 15, 17, 16 }
    };

    struct Stack* stack = createStack(N*M);
    pushArray(stack, N, M, array);

    int result = process(stack);
    printf("%d\n", result);

    return 0;
}