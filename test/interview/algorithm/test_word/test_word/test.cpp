// test.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <string>
#include <map>
#include <vector>
using namespace std;
// ���ļ���ѭ����ȡһϵ����Ŀ�����Ĵ����ظ���Ӣ�ĵ��ʷ��������У�Ҫ��ͳ��ÿ�����ʳ��ֵĴ��������ܹ����յ��ʳ��ֵ�˳�����ͳ�ơ�
// ���ṩ�ĺ���������Ҫʵ�֣���ֱ���ã���
// string getNextWord������//���ļ���ѭ����ȡ���ʣ�������ء��������ʾ��ȡ��������15���ӣ�

string getNextWord(){ return "aaaa";};
int _tmain(int argc, _TCHAR* argv[])
{
	int count = 0;
	std::map<string, int> mapWordCount;
	std::vector<string> vtWord;


	// ��ȡ����
	while(true) 
	{
		string strWord = getNextWord();
		if (0 == strWord.length())
		{
			break;
		}

		if (mapWordCount.count(strWord))
		{	
			mapWordCount[strWord] += 1;
		}
		else
		{
			mapWordCount[strWord] = 1;		
			vtWord.push_back(strWord);
		}
		count++;
	}

	for (vector<string>::iterator it = vtWord.begin(); it!= vtWord.end(); it++)
	{
		int count = mapWordCount[*it];
		printf("word:%s, count:%d\r\n", it->c_str(), count);
	}




	return 0;
}

