	if (!((list1) || (list2)))
		return list1;
	if (list1)
		return list2;
	if (list2)
		return list1;
	struct ListNode* NewNode = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* tmp = NewNode;
	while (list1 && list2)
	{
		if ((list1->val) >= (list2->val))
		{
			NewNode->next = list2;
			NewNode = list2;
			list2 = list2->next;
		}
		if ((list1->val) < (list2->val))
		{
			NewNode->next = list1;
			NewNode = list1;
			list1 = list1->next;
		}
		if (list1)
			NewNode->next = list2;
		if (list2)
			NewNode->next = list1;
	}
	return NewNode->next;
