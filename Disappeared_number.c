#include <stdio.h>

int main()
{
	int nums[] = { 9,6,4,2,3,5,7,0,1 };
	int n = sizeof(nums) / sizeof(nums[0]);
	int num = n;
	int i = 0;
	int j = 0;
	for (i = 0; i <= n; i++)
	{
		for (j = 0; j < num; j++)
		{
			if (i == nums[j])
			{
				nums[j] = nums[num - 1];
				num--;
				goto again;
			}

		}
		if (j == num)
		{
			printf("找到了，缺失的数字是%d\n", i);
			return 0;
		}
	again:j = 0;
	}
	return 0；
}
