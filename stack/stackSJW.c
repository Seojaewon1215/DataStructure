#include <stdio.h>
#include <malloc.h>

struct Item
{
    int val;
    struct Item* next;
};

struct Stack
{
    struct Item* top;
    int size;
};

struct Item* new_item(int val)
{
    //top이 null이면 스택이 비어있는것
    // make new item
    struct  Item* item =(struct Item*)malloc(sizeof(struct Item));
    // initializing
    item ->val=val;
    item ->next=NULL;
    //return item
    return item;

}

struct Stack* new_stack() //비어있는 스택 새로 만들기
{
    // make new stack
    struct  Stack* stack =(struct Stack*)malloc(sizeof(struct Stack));
    // initializing
    stack ->size=0;
    stack ->top=NULL;
    // return stack 
    return stack;

}

int size(struct Stack* s)
{
    // return stack size
    return s->size;
}

int empty(struct Stack* s)
{
    // if stack is empty return 1 else return 0
    if(s->size==0)
    {
        return 1;
    }
    else
    {
        return 0;
    }

}

int top(struct Stack* s)//가장 윗부분 값 반환환
{
    // return top of stack 
    return s->top->val;
    
}

void push(struct Stack* s, int val)//비어있으면 top에다가 새로운 값 할당, top할당 이전 값은 next로 
{
    // push to stack 
    if(s->size==0)
    {
        s->top->val=val;
    }
    else
    {
        struct Item* item = s->top;
        s->top=new_item(val);
        s->top->next=item;
       
        //원래 top값 저장, top을 새로운 값으로 바꾸고, 저장한 옛날top next
    }
    
}

int pop(struct Stack* s)
{
    // pop and return the value of stack
     if(s->size==0)
    {
        return -1;
    }
    else
    {
        int val=s->top->val;
        struct Item* it = s->top;
        s->top=s->top->next;
        free(it);
        return val;
        
       
        //삭제하기전 top값 주소 저장, top을 top의 next, 옛날 top값 free 
    }
    
}

int main()
{
    struct Stack* s = new_stack();
    int i,n = 5;
    printf("Size, Pushed item\n");
    for(i=0; i<n; i++)
    {
        push(s,i*10);
        printf("%4d, %11d\n",size(s), top(s));
    }
    printf("Size,  Poped item\n");
    while(!empty(s))
    {
        printf("%4d, %11d\n", size(s), pop(s));
    }

    return 0;
}