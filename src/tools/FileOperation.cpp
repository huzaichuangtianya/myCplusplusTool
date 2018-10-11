/*
 * FileOperation.cpp
 *
 *  Created on: 2018年10月9日
 *      Author: quliang
 */

#include "FileOperation.h"
#include <iostream>
#include <fstream>
#include <ctime>
#include <string.h>
#include <string>
#include <malloc.h>
#include <stdlib.h>

#define MAX  33227
using namespace std;

bool FileOperation::copy(char* src,char* dst){

    ifstream in(src,ios::binary);
    ofstream out(dst,ios::binary);
    if (!in.is_open()) {
        cout << "error open file " << src << endl;
        exit(EXIT_FAILURE);
    }
    if (!out.is_open()) {
        cout << "error open file " << dst << endl;
        exit(EXIT_FAILURE);
    }
    if (src == dst) {
        cout << "the src file can't be same with dst file" << endl;
        exit(EXIT_FAILURE);
    }
    char buf[2048];
    long long totalBytes = 0;
    while(in)
    {
        //read从in流中读取2048字节，放入buf数组中，同时文件指针向后移动2048字节
        //若不足2048字节遇到文件结尾，则以实际提取字节读取。
        in.read(buf, 2048);
        //gcount()用来提取读取的字节数，write将buf中的内容写入out流。
        out.write(buf, in.gcount());
        totalBytes += in.gcount();
    }
    in.close();
    out.close();
	return true;
};

