// test.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <string>
#include <map>
#include <vector>
using namespace std;
// 从文件中循环读取一系列数目不定的大量重复的英文单词放入容器中，要求统计每个单词出现的次数，并能够按照单词出现的顺序输出统计。
// 已提供的函数（不需要实现，可直接用）：
// string getNextWord（）；//从文件中循环读取单词，如果返回“”，则表示读取结束。（15分钟）

string getNextWord(){ return "aaaa";};
int _tmain(int argc, _TCHAR* argv[])
{
	int count = 0;
	std::map<string, int> mapWordCount;
	std::vector<string> vtWord;


	// 获取数据
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

