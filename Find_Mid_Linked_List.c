struct ListNode 
{
	int val;
	struct ListNode* next;
};

struct ListNode* middleNode(struct ListNode* head) 
{
	struct ListNode* point = (struct ListNode*)malloc(sizeof(struct ListNode));
	int num = 0;
	point = head;
	while ((point->next) != NULL)
	{
		point = point->next;
		num++;
	}
	if (1 == (num & 1))
		num = num / 2 + 1;
	else
		num = num / 2;
	point = head;
	while (num--)
		point = point->next;
	return point;
}


//two way
struct ListNode 
{
	int val;
	struct ListNode* next;
};

struct ListNode* middleNode(struct ListNode* head)
{
	struct ListNode* flow = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* fast = (struct ListNode*)malloc(sizeof(struct ListNode));
	fast = head;
	flow = head;
	while ((fast != NULL) && ((fast->next) != NULL))
	{
		flow = flow->next;
		fast = fast->next->next;
	}
	return flow;
}
