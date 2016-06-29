#ifndef __GETNUMBEROFK_H__
#define __GETNUMBEROFK_H__

//得到第一次出现时的下标
int GetFirstNum(int* a,int length ,int num)
{
	for (int i = 0; i < length; i++)
	{
		if (a[i] == num)
			return i;
	}

	return -1;
}

//得到最后一次出现是的下标
int GetLastNum(int* a, int length, int num)
{
	int prev = 0;
	int cur = 0;
	while (cur<length)
	{
		if (a[cur] != num)
		{
			cur++;
		}
		else 
		{
			prev = cur;
			cur++;
			if (a[prev] != a[cur])
			{
				return prev;
			}
		}
		
	}

	return -1;
}


int GetNumberOfK(int* a,int length,int num)
{
	if (a == NULL || length < 0)
		return 0;

	int first = GetFirstNum(a, length, num);
	int end = GetLastNum(a, length, num);
	int sum = 0;
	if (end != -1 && first != -1)
		sum = end - first + 1;
	return sum;
}

void TestGet()
{
	int a[10] = { 1, 3, 3, 3, 3, 3, 3, 3, 3, 5 };
	cout << GetNumberOfK(a, 10, 3) << endl;
}

#endif //__GETNUMBEROFK_H__



