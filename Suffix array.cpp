/****************************
 * 后缀数组查找字符串中最长公共子串
 * veil
 * 2013/4/16
 ****************************/
#include <iostream>
#include <fstream>
#include <algorithm>
#include <cstring>
using namespace std;
#define MAXN 1202000
char txt[MAXN];
char *a[MAXN];

int comlen(char *p, char *q);
bool pstrcmp(char *p, char *q);

int main()
{
	ifstream ifs("/home/administrator/workspace/KMP/KMP.cpp", ios::binary);
	if(!ifs)
		return 0;
	ifs.seekg(0, ifs.end);
	int length = ifs.tellg();
	if(length < 0)
		return 0;
	ifs.seekg(0, ifs.beg);
	ifs.read(txt, length);
	txt[length] = 0;
	for(int i = 0; i < length; i++)
	{
		a[i] = &txt[i];
	}
	sort(a, a + length - 1, pstrcmp);
	int maxlength = 0;
	int maxi;
	for(int i = 0; i < length - 1; i++)
	{
		int len = comlen(a[i], a[i + 1]);
		if(maxlength < len)
		{
			maxlength = len;
			maxi = i;
		}
	}
	cout << maxlength << endl;
	cout << maxi << endl;
	return 0;
}

int comlen(char *p, char *q)
{
	int i = 0;
	while(*p && *q && (*p++ == *q++))
		i++;
	return i;
}

bool pstrcmp(char *p, char *q)
{
	if(strcmp(p, q) > 0)
		return true;
	else
		return false;
}
