
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int QueueType;

struct QueueNode
{
	QueueType val;
	struct QueueNode* next;
};

struct Queue
{
	struct QueueNode* head;
	struct QueueNode* tail;
};

typedef struct {
	struct Queue First;
	struct Queue Second;
} MyStack;

void QueueInit(struct Queue* Q)
{
	Q->head = NULL;
	Q->tail = NULL;
}


void QueuePush(struct Queue* Q, QueueType x)
{
	struct QueueNode* NewNode = (struct QueueNode*)malloc(sizeof(struct QueueNode));
	NewNode->val = x;
	NewNode->next = NULL;
	if (Q->head == NULL)
		Q->head = Q->tail = NewNode;
	else
	{
		Q->tail->next = NewNode;
		Q->tail = NewNode;
	}
}

MyStack* myStackCreate() {
	MyStack* MS = (MyStack*)malloc(sizeof(MyStack));
	QueueInit(&MS->First);
	QueueInit(&MS->Second);

	return MS;
}

void myStackPush(MyStack* obj, int x) {
	if (obj->First.head)
	{
		QueuePush(&obj->First, x);
	}
	else
	{
		QueuePush(&obj->Second, x);
	}
}

int myStackPop(MyStack* obj) {
	if(!(obj->First.head || obj->Second.head))
        return 0;
	struct QueueNode* cur1 = NULL;
	struct QueueNode* cur2 = NULL;
    int x = 0;
	if (obj->First.head)
	{
        cur1 = obj->First.head;
        if(obj->First.head->next)
        {
		    obj->Second.head = cur2 = cur1 = obj->First.head;
		    cur1 = cur1->next;
        }
		while (cur1->next)
		{
            cur2->next = cur1;
            cur1 = cur1->next;
            cur2 = cur2->next;
		}
        if(cur2)
        {
            cur2->next = NULL;
            obj->Second.tail = cur2;
        }
        x = cur1->val;
		free(cur1);
		obj->First.head = obj->First.tail = NULL;
		return x;
	}
	else
	{
        cur1 = obj->Second.head;
        if(obj->Second.head->next)
        {
            obj->First.head = cur2 = cur1 = obj->Second.head;
            cur1 = cur1->next;
        }
		while (cur1->next)
		{
            cur2->next = cur1;
            cur1 = cur1->next;
            cur2 = cur2->next;
		}
        if(cur2)
        {
            cur2->next = NULL;
            obj->First.tail = cur2;
        }
        x = cur1->val;
		free(cur1);
		obj->Second.head = obj->Second.tail = NULL;
		return x;
	}
}

int myStackTop(MyStack* obj) {
	if (obj->First.head)
	{
        return obj->First.tail->val;
	}
	if (obj->Second.head)
	{
        return obj->Second.tail->val;
	}
	return NULL;
}

bool myStackEmpty(MyStack* obj) {
	if ((obj->First.head == NULL) && (obj->Second.head == NULL))
		return true;
	return false;;
}

void myStackFree(MyStack* obj) {
	struct QueueNode* cur = NULL;
	if (obj->First.head)
	{
		while (obj->First.head)
		{
			cur = obj->First.head->next;
			free(obj->First.head);
			obj->First.head = cur;
		}
	}
	if (obj->Second.head)
	{
		while (obj->Second.head)
		{
			cur = obj->Second.head->next;
			free(obj->Second.head);
			obj->Second.head = cur;
		}
	}
	free(obj);
}

//two
bool QueueEmpty(struct Queue* Q);

typedef int QueueType;

struct QueueNode
{
	QueueType val;
	struct QueueNode* next;
};

struct Queue
{
	struct QueueNode* head;
	struct QueueNode* tail;
};

typedef struct {
	struct Queue First;
	struct Queue Second;
} MyStack;

void QueueInit(struct Queue* Q)
{
	assert(Q);
	Q->head = NULL;
	Q->tail = NULL;
}

void QueueDestroy(struct Queue* Q)
{
	assert(Q);
	while (Q->head)
	{
		struct QueueNode* Tmp = Q->head->next;
		free(Q->head);
		Q->head = Tmp;
	}
}

void QueuePush(struct Queue* Q, QueueType x)
{
	assert(Q);
	struct QueueNode* NewNode = (struct QueueNode*)malloc(sizeof(struct QueueNode));
	NewNode->val = x;
	NewNode->next = NULL;
	if (Q->head == NULL)
		Q->head = Q->tail = NewNode;
	else
	{
		Q->tail->next = NewNode;
		Q->tail = NewNode;
	}
}

void QueuePop(struct Queue* Q)
{
	assert(Q);
	assert(!(QueueEmpty(Q)));

	struct QueueNode* Tmp = Q->head->next;
	free(Q->head);
	Q->head = NULL;
	Q->head = Tmp;
	if (Q->head == NULL)
		Q->tail = NULL;
}

QueueType QueueFront(struct Queue* Q)
{
	assert(Q);
	assert(!(QueueEmpty(Q)));
	return Q->head->val;
}

QueueType QueueBack(struct Queue* Q)
{
	assert(Q);
	assert(!(QueueEmpty(Q)));
	return Q->tail->val;
}

int QueueSize(struct Queue* Q)
{
	assert(Q);
	int n = 0;
	struct QueueNode* cur = Q->head;
	while (cur)
	{
		n++;
		cur = cur->next;
	}
	return n;
}

bool QueueEmpty(struct Queue* Q)
{
	assert(Q);
	return Q->head == NULL;
}

MyStack* myStackCreate() {
	MyStack* MS = (MyStack*)malloc(sizeof(MyStack));
	QueueInit(&MS->First);
	QueueInit(&MS->Second);
	return MS;
}

void myStackPush(MyStack* obj, int x) {
	if (!QueueEmpty(&obj->First))
		QueuePush(&obj->First, x);
	else
		QueuePush(&obj->Second, x);
}

int myStackPop(MyStack* obj) {
	struct Queue* empty = &obj->First;
	struct Queue* nonempty = &obj->Second;
	if (obj->First.head)
	{
		nonempty = &obj->First;
		empty = &obj->Second;
	}
	while (QueueSize(nonempty) > 1)
	{
		QueuePush(empty, QueueFront(nonempty));
		QueuePop(nonempty);
	}
	int top = nonempty->head->val;
	QueuePop(nonempty);
	return top;
}

int myStackTop(MyStack* obj) {
	if (!QueueEmpty(&obj->First))
		return QueueBack(&obj->First);
	else
		return QueueBack(&obj->Second);
}

bool myStackEmpty(MyStack* obj) {
	if (QueueEmpty(&obj->First) && QueueEmpty(&obj->Second))
		return true;
	else
		return false;
}

void myStackFree(MyStack* obj) {
	QueueDestroy(&obj->First);
	QueueDestroy(&obj->Second);
	free(obj);
}


int main()
{

	MyStack* MS = myStackCreate();
	myStackPush(MS, 1);
	myStackPush(MS, 2);
	int x = myStackTop(MS);
	printf("%d ", x);
	myStackPush(MS, 3);
	myStackPush(MS, 4);
	x = myStackTop(MS);
	printf("%d ", x);
	myStackPop(MS);
	x = myStackTop(MS);
	printf("%d ", x);
	myStackFree(MS);
	return 0;
}
