struct ListNode 
{
	int val;
	struct ListNode* next;
};

bool hasCycle(struct ListNode* head) {

	struct ListNode* flow = head;
	struct ListNode* fast = head;
	while (fast && fast->next)
	{
		flow = flow->next;
		fast = fast->next->next;
		if (fast == flow)
			return true;
	}
	return false;
}

struct ListNode* detectCycle(struct ListNode* head) {
	struct ListNode* Nhead = head;
	struct ListNode* flow = head;
	struct ListNode* fast = head;
	while (fast && fast->next)
	{
		flow = flow->next;
		fast = fast->next->next;
		if (fast == flow)
		{
			while (flow != Nhead)
			{
				flow = flow->next;
				Nhead = Nhead->next;
			}
			return Nhead;
		}
	}
	return NULL;
}
