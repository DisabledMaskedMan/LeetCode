#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int StackType;


struct Stack
{
	StackType* a;
	int top;
	int capacity;
};

typedef struct {
	struct Stack EnterStack;
	struct Stack OutStack;
} MyQueue;

void StackInit(struct Stack* ST)
{
	assert(ST);
	ST->a = NULL;
	ST->capacity = 0;
	ST->top = 0;
}

void StackDestory(struct Stack* ST)
{
	assert(ST);
	free(ST->a);
	ST->a = NULL;
	ST->capacity = ST->top = 0;
}

void StackPush(struct Stack* ST, StackType x)
{
	assert(ST);
	if (ST->capacity == ST->top)
	{
		int NewCapacity = ST->capacity == 0 ? 4 : ST->capacity * 2;
		ST->capacity = NewCapacity;
	}
	StackType* tmp = (StackType*)realloc(ST->a, ST->capacity * sizeof(StackType));
	if (tmp == NULL)
	{
		printf("realloc fail!");
		exit(-1);
	}
	ST->a = tmp;
	(ST->a)[ST->top] = x;
	ST->top++;
}

void StackPop(struct Stack* ST)
{
	assert(ST);
	assert(!StackEmpty(ST));
	ST->top--;
}

StackType StackFront(struct Stack* ST)
{
	assert(ST);
	assert(!StackEmpty(ST));
	return (ST->a)[ST->top - 1];
}

bool StackEmpty(struct Stack* ST)
{
	assert(ST);
	return ST->top == 0;
}

int StackSize(struct Stack* ST)
{
	assert(ST);
	return ST->top;
}

MyQueue* myQueueCreate() {
	MyQueue* MQ = (MyQueue*)malloc(sizeof(MyQueue));
	StackInit(&MQ->EnterStack);
	StackInit(&MQ->OutStack);

	return MQ;
}

void myQueuePush(MyQueue* obj, int x) {
	StackPush(&obj->EnterStack, x);
}

int myQueuePop(MyQueue* obj) {
	if (StackEmpty(&obj->OutStack))
	{
		while (!StackEmpty(&obj->EnterStack))
		{
			StackPush(&obj->OutStack, StackFront(&obj->EnterStack));
			StackPop(&obj->EnterStack);
		}
	}
	int x = StackFront(&obj->OutStack);
	StackPop(&obj->OutStack);
	return x;
}

int myQueuePeek(MyQueue* obj) {
	if (StackEmpty(&obj->OutStack))
	{
		while (!StackEmpty(&obj->EnterStack))
		{
			StackPush(&obj->OutStack, StackFront(&obj->EnterStack));
			StackPop(&obj->EnterStack);
		}
	}
	return StackFront(&obj->OutStack);
}

bool myQueueEmpty(MyQueue* obj) {
	return StackEmpty(&obj->EnterStack) && StackEmpty(&obj->OutStack);
}

void myQueueFree(MyQueue* obj) {
	StackDestory(&obj->EnterStack);
	StackDestory(&obj->OutStack);
	free(obj);
}
