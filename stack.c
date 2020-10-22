#include <stdio.h>
#include <malloc.h>
struct stack{
int data;
struct stack *next;
};
struct stack* top = NULL;
struct stack* push(struct stack*, int);
struct stack* pop(struct stack*);
struct stack* display(struct stack*);
int main()
{
    top = push(top, 4);
    top = push(top, 5);
    top = push(top, 6);
    top = push(top, 7);
    top = push(top, 8);
    top = display(top);
    top = pop(top);
    top = display(top);
    top = push(top, 9);
    top = display(top);
    top = pop(top);
    top = display(top);


}
struct stack* push(struct stack *top, int num)
{
    printf("\nPush %d", num);
    struct stack *new_;
    new_ = (struct stack*)malloc(sizeof(struct stack));
    if(top == NULL)
    {
        new_->data = num;
        new_->next =  NULL;
        top = new_;
    }
    else
    {
        new_->data = num;
        new_->next = top;
        top = new_;
    }
    return top;
}

struct stack* pop(struct stack *top)
{
    int num;
    struct stack *ptr = top;
    if(top == NULL)
    {
        printf("\nStack underflow");
    }
    else
    {
        num = top->data;
        top = top->next;
        ptr->next = NULL;
        free(ptr);
        printf("\nThe pop element is %d",num);
    }
    return top;
};

struct stack* display(struct stack *top)
{
    printf("\nDisplay the elements");
    struct stack *ptr = top;
    if(top == NULL)
    {
        printf("\nStack underflow");
    }
    else
    {
        while(top != NULL)
        {
            printf(" %d",top->data);
            top = top->next;
        }
    }
    return ptr;
};
