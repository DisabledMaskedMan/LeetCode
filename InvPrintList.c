#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

struct ListNode {
	int m_nKey;
	struct ListNode* m_pNext;
};

struct ListNode* creatList(int n)
{
	assert(n > 0);
	struct ListNode* pHead = NULL;
	struct ListNode* pTail1 = NULL;
	struct ListNode* pTail2 = NULL;
	pHead = (struct ListNode*)malloc(sizeof(struct ListNode));
	if (pHead == NULL)
	{
		printf("malloc Fail\n");
		return NULL;
	}
	pTail1 = pHead;
	pTail1->m_nKey = 1;
	for (int i = 2; i <= n; i++)
	{
		pTail2 = (struct ListNode*)malloc(sizeof(struct ListNode));
		if (pTail2 == NULL)
		{
			printf("continue malloc Fail\n");
			return pHead;
		}
		pTail2->m_nKey = i;
		pTail1->m_pNext = pTail2;
		pTail1 = pTail2;
	}

	pTail1->m_pNext = NULL;
	return pHead;
}

void printList(struct ListNode* phead)
{
	while (phead != NULL)
	{
		printf("%d ", phead->m_nKey);
		phead = phead->m_pNext;
	}
	printf("\n");
}

void destroyList(struct ListNode* phead)
{
	assert(phead != NULL);

	while (phead != NULL)
	{
		struct ListNode* tmp = phead;
		phead = phead->m_pNext;
		free(tmp);
	}
}

void invPrintList(struct ListNode* phead)
{
	assert(phead != NULL);

	if (phead->m_pNext != NULL)
		invPrintList(phead->m_pNext);
	printf("%d ", phead->m_nKey);

	return;
}

int main()
{
	struct ListNode* head = creatList(20);
	printList(head);
	invPrintList(head);
	destroyList(head);

	return 0;
}
