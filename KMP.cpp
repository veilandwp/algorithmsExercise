/***************************************
实现KMP算法
2013/4/16
veil
***************************************/
#include <iostream>
#include <string>
#include <algorithm>
#include <string.h>
#include <stdio.h>
using namespace std;

//记录pattern的每一个子串中前缀和后缀相等时前缀的长度到pattern_overlap中
void overlap(string pattern, int *pattern_overlap)
{
	int n = pattern.size();
	pattern_overlap[0] = -1;
	for(int i = 1; i < n; i++)
	{
		int index = pattern_overlap[i - 1];
		if(pattern[index + 1] == pattern[i])
		{
			pattern_overlap[i] = pattern_overlap[i - 1] + 1;
		}
		else
		{
			do
			{
				index = pattern_overlap[index + 1];
			}
			while(pattern[index + 1] != pattern[i] && index != -1);
			if(pattern[index + 1] == pattern[i])
				pattern_overlap[i] = pattern_overlap[index + 1] + 1;
			else
				pattern_overlap[i] = -1;
		}
	}
}

//实现KMP函数的函数主体
int KMP(string s, string pattern)
{
	int n = pattern.size();
	int *pattern_overlap = (int *)malloc(sizeof(int) * (n));
	overlap(pattern, pattern_overlap);
	int i = 0;
	cout << s << endl;
	cout << pattern << endl;
	while(i < s.size())
	{
		cout << "i: " << i << endl;
		int j;
		if(i + n > s.size())
			return -1;
		for(j = i; (j - i) < n && pattern[j - i] == s[j]; j++)
			;
		cout << "j: " << j << endl;
		if(j == i + n)
			return i;
		int right = 0;
		if((j - i) > 0)
			right = pattern_overlap[j - i - 1] + 1;
		right = max((j - i) - right, 1);
		i = i + right;
	}
	return -1;
}

int main()
{
	string s("bnan0");
	string pattern("nan0");
	cout << KMP(s, pattern) << endl;
	return 0;
}
