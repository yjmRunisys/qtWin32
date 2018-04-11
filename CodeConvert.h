#ifndef CCODECONVERT_H
#define CCODECONVERT_H
#include "QString"
#include "string"
using namespace std;
#pragma execution_character_set("utf-8")//MSVC中中文不乱码

class CCodeConvert
{
public:
    CCodeConvert();
    ~CCodeConvert();

    static QString Convert2Unicode(string pSrc,QString codeName);//转换为Unicode
    static string ConvertFromUnicode(QString pSrc,QString codeName);//转换自Unicode
    static int getUnicodeMemory(QString qsSrc,char *des);//获取宽字符内存，des提前申请好

    static string ConvertUnicode2Utf8(QString pSrc);//Unicode编码转化为utf-8编码
    static QString ConvertUtf82Unicode(string pSrc);//utf-8编码转化为Unicode编码

    static string ConvertUnicode2Gbk(QString pSrc);//Unicode编码转化为gbk编码
    static QString ConvertGBk2Unicode(string pSrc);//gbk编码转化为Unicode编码

    static string ConvertGbk2Utf8(string pGbk);//gbk转换为utf-8
    static string ConvertUtf82Gbk(string pGbk);//utf-8转换为gbk

    static void cpyMulti2Wide(string pChar,string pwChar);//窄字节拷贝到宽字节
    static void cpyWide2Multi(string pwChar,string pChar);//宽字节拷贝到窄字节
    static void ConvertAnsi2Unicode(string pSrc,string pDes);//ANSI编码转化为Unicode编码
    static void ConvertAnsi2Utf8(string pSrc,string pDes);//ANSI编码转化为utf-8编码
    static void ConvertUtf82Ansi(string pSrc,string pDes);//utf-8编码转化为ANSI编码
    static void ConvertUnicode2Ansi(string pSrc,string pDes);//Unicode编码转化为ANSI编码

    static void testCode();
    static void writeFileBina(string src,string fileName);//
    static void writeFileBina(char* src,int size,string fileName);

};



#endif // CCODECONVERT_H
