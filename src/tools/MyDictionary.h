/*
 * MyDictionary.h
 *
 *  Created on: 2018年10月11日
 *      Author: quliang
 */

#ifndef TOOLS_MYDICTIONARY_H_
#define TOOLS_MYDICTIONARY_H_

#include "/home/quliang/workspace/cworkspaces/CPlusTools/src/bean/dict_word.h"

class MyDictionary{

public:
	int open_dict(dict_word **word, const char * dict_filename);
	int serach_word(char *cin_word, const dict_word*word1);
	void free_dict(dict_word *dictword);
	void primary();
};



#endif /* TOOLS_MYDICTIONARY_H_ */
