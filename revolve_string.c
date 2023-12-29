#include <stdio.h>
#include <string.h>
#include <assert.h>

//1.暴力求解法
void meun()
{
	printf("**********************************\n");
	printf("******** 1.右旋   2. 左旋 ********\n");
	printf("********      0.退出      ********\n");
	printf("**********************************\n");
}

void left_revolve(char* p, int sz, int n)
{
	assert(p);
	int i = 0;
	for (i = 0; i < n; i++)
	{
		int j = 0;
		for (j = 0; j < sz - 1; j++)
		{
			char tmp = *(p + j);
			*(p + j) = *(p + j + 1);
			*(p + j + 1) = tmp;
		}
	}
}

void right_revolve(char* p, int sz, int n)
{
	assert(p);
	int i = 0;
	for (i = 0; i < n; i++)
	{
		int j = 0;
		for (j = sz - 1; j >= 1; j--)
		{
			char tmp = *(p + j);
			*(p + j) = *(p + j - 1);
			*(p + j - 1) = tmp;
		}
	}
}

int main()
{
	int n = 0;
	int input = 0;
	char arr[] = "abcdefg";
	int sz = strlen(arr);
	meun();
	printf("请输入:>");
	scanf("%d", &input);
	switch (input)
	{
	case 1:
	{
		printf("请输入想要右旋的字符个数，字符串的长度为%d,请输入:>", sz);
		scanf("%d", &n);
		assert(n <= sz);
		right_revolve(arr, sz, n);
		printf("%s\n", arr);
		break;
	}
	case 2:
	{
		printf("请输入想要左旋的字符个数，字符串的长度为%d,请输入:>", sz);
		scanf("%d", &n);
		assert(n <= sz);
		left_revolve(arr, sz, n);
		printf("%s\n", arr);
		break;
	}
	case 0:
	{
		printf("退出");
			break;
	}
	default:
	{
		printf("输入错误！");
		break;
	}
	}
	return 0;
}

//2.三步求解法
void reverse(char* left, char* right)
{
	assert(left);
	assert(right);
	while (left < right)
	{
		char tmp = *left;
		*left = *right;
		*right = tmp;
		left++;
		right--;
	}
}

void left_revolve(char* p, int n)
{
	int sz = strlen(p);
	assert(n <= sz);
	reverse(p, p + n - 1);
	reverse(p + n, p + sz - 1);
	reverse(p, p + sz - 1);
}

int main()
{
	char arr[] = "abcdefg";
	int n = 0;
	printf("您需要左旋的字符个数，请输入:>");
	scanf("%d", &n);
	left_revolve(arr, n);
	printf("%s\n", arr);
	return 0;
}

//3.比较
void reverse(char* left, char* right)
{
	assert(left);
	assert(right);
	while (left < right)
	{
		char tmp = *left;
		*left = *right;
		*right = tmp;
		left++;
		right--;
	}
}

void left_revolve(char* p, int n)
{
	int sz = strlen(p);
	reverse(p, p + n - 1);
	reverse(p + n, p + sz - 1);
	reverse(p, p + sz - 1);
}

int is_left_revolve(char* p1, char* p2)
{
	int len = strlen(p1);
	int i = 0;
	for (i = 1; i <= len; i++)
	{
		left_revolve(p1, 1);
		int ret = strcmp(p1, p2);
		if (ret == 0)
		{
			return 1;
		}
	}
	return 0;
}

int main()
{
	char arr[] = "abcdefg";
	char arr1[] = "cdefgab";
	int n = 0;
	int ret = is_left_revolve(arr, arr1);
	if (ret == 0)
	{
		printf("arr不是arr1左旋得到的");
	}
	else
	{
		printf("arr是arr1左旋得到的");
	}
	return 0;
}
