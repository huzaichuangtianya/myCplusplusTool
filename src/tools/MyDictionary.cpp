/*
 * MyDictionary.cpp
 *
 *  Created on: 2018年10月11日
 *      Author: quliang
 */

#include "MyDictionary.h"
#include <iostream>
#include <fstream>
#include <ctime>
#include <string.h>
#include <string>
#include <malloc.h>
#include <stdlib.h>

#define MAX  33227
using namespace std;

int MyDictionary::open_dict(dict_word **word, const char * dict_filename) {
	ifstream infile(dict_filename, ios::in | ios::binary);

	FILE *fp = fopen(dict_filename, "r");

	if (fp == NULL) {
		cerr << "open file error" << endl;
		return 0;
	}

	*word = (dict_word*) malloc(sizeof(dict_word) * MAX);
	memset(*word, 0, sizeof(dict_word) * MAX);

	dict_word *pd = *word;

	char buf[1024] = { 0 };

	int len = 0;
	int i = 0; //单词计数器

	while (fgets(buf, sizeof(buf), fp)) {

		len = strlen(buf);

		if (len > 0) {
			pd[i].word = (char*) malloc(len + 1);

			memset(pd[i].word, 0, len + 1);

			strncpy(pd[i].word, buf, len + 1);
		}
		len = 0;
		i++;

	}

	infile.close();
	fclose(fp);
	return i;

}
;

int MyDictionary::serach_word(char *cin_word, const dict_word*word1) {
	string str1 = cin_word;

	string str2;
	int i = 0, n = strlen(cin_word);
	while (i < MAX && word1->word != NULL) {

		str2 = word1->word;

		if (!str1.compare(0, n, str2, 0, n)) {

			strcpy(cin_word, word1->word);

			return 1;
		}
		i++;
		word1++;
	}

	strcpy(cin_word, "没找到你要的单词");
	return 0;
}
;

void MyDictionary::free_dict(dict_word *dictword) {
	int i = 0;
	for (i = 0; i < MAX; i++) {

		free(dictword[i].word);
		dictword[i].word = NULL;

	}

	free(dictword);
	dictword = NULL;

}

void MyDictionary::primary() {

	MyDictionary myd;

	long start_time = clock();

	dict_word *word = NULL;

	int word_count = open_dict(&word, "/home/quliang/temp/dictionary.txt");

	if (word_count <= 0) {
		cerr << "文件中单词数不正确" << endl;

	}

	long end_time = clock();

	cout << "打开文件并将文件中的内容读取到堆内存中所消耗的时长是：" << end_time - start_time << "ms"
			<< endl;

	char cin_word[1024] = { 0 };

	start_time = clock(); //记录查找函数执行的时间
	while (1) {
		memset(cin_word, 0, sizeof(cin_word));

		cout << "请输入你要查找的词语-->";

		cout << "输入command=exit退出程序" << endl;

		cin >> cin_word;

		string st = cin_word;

		if (!st.compare(0, 12, "command=exit", 0, 12)) {

			break;
		}

		start_time = clock();

		if (serach_word(cin_word, word)) {
			end_time = clock();

			cout << cin_word; //将找到的单词输出
			cout << "查找该单词所消耗的时长是：" << end_time - start_time << "ms" << endl;
		} else {
			end_time = clock();

			cout << "查找单词所消耗的时长是：" << end_time - start_time << "ms" << endl;

			cout << cin_word << endl; //没有找到单词，输出没有找到你所要查找的单词
		}

	}

	start_time = clock();

		//释放堆内存空间

		free_dict(word);

		end_time = clock();
		cout << "释放堆内存空间消耗的时长是：" << end_time - start_time << "ms" << endl;

}

