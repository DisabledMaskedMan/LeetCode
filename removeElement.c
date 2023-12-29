include<stdio.h>

int removeDuplicates(int* nums, int numsSize)
{
	int flagend = 0;
	int flag = 1;
	while (flag < numsSize)
	{
		if (nums[flag] == nums[flagend])
		{
			flag++;
		}
		else
		{
			if ((0 == flag) && (1 == flagend))
			{
				while ((nums[flag] != nums[flagend])&&(flag<numsSize))
				{
					flag++;
					flagend++;
				}
			}
			else
			{
				flagend++;
				nums[flagend] = nums[flag];
			}
		}
	}
	return flagend + 1;
}

int main()
{
	int arr[] = { 1,2,2,3,4,5,5,6,7,8,8,9 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int size = removeDuplicates(arr, n);
	printf("%d\n", size);
	int i = 0;
	for (i = 0; i < n; i++)
		printf("%d ", arr[i]);
	return 0;
}
