struct ListNode 
{
	int val;
	struct ListNode* next;
};

struct ListNode* reverseList(struct ListNode* head) 
{
	struct ListNode* p1 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* p2 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* p3 = (struct ListNode*)malloc(sizeof(struct ListNode));
	if ((head == NULL) || ((head->next) == NULL))
		return head;
	p1 = head->next;
	head->next = NULL;
	p2 = p1->next;
	p1->next = head;
	while (p2)
	{
		p3 = p2->next;
		p2->next = p1;
		p1 = p2;
		p2 = p3;
	}
	return p1;
}
