#include "CodeConvert.h"
#include <QTextCodec>
#include <QDebug>

CCodeConvert::CCodeConvert(void)
{
}


CCodeConvert::~CCodeConvert(void)
{

}

QString CCodeConvert::Convert2Unicode(string pSrc,QString codeName)
{
    QString qsUnicode = "";
    QTextCodec* pCodec = QTextCodec::codecForName(codeName.toLatin1());//
    if(!pCodec)
        return qsUnicode;

    qsUnicode = pCodec->toUnicode(pSrc.c_str(),pSrc.size());

    return qsUnicode;
}

string CCodeConvert::ConvertFromUnicode(QString pUnicode,QString codeName)
{
    string pDes = "";
    QTextCodec *pCodec = QTextCodec::codecForName(codeName.toLatin1());
    if(!pCodec)
        return pDes;
    QByteArray encodedString = pCodec->fromUnicode(pUnicode);
    pDes = encodedString.data();

    return pDes;
}

//获取宽字符内存，des提前申请好
int CCodeConvert::getUnicodeMemory(QString qsSrc,char *des)
{
    //char *pdata = qsSrc.toLatin1();
    return 1;
}

//Unicode编码转化为gbk编码
string CCodeConvert::ConvertUnicode2Gbk(QString strUnicode)
{
    QString codeName = "GB2312";
    string pGbk = ConvertFromUnicode(strUnicode,codeName);
    return pGbk;
}

//gbk编码转化为Unicode编码
QString CCodeConvert::ConvertGBk2Unicode(string pGbk)
{
    QString codeName = "GB2312";
    QString qsUnicode = Convert2Unicode(pGbk,codeName);
    return qsUnicode;
}

//Unicode编码转化为utf-8编码
string CCodeConvert::ConvertUnicode2Utf8(QString pSrc)
{
    QString codeName = "utf-8";
    string pUtf8 = ConvertFromUnicode(pSrc,codeName);
    return pUtf8;

}

//utf-8编码转化为Unicode编码
QString CCodeConvert::ConvertUtf82Unicode(string pUtf8)
{
    QString codeName = "utf-8";
    QString qsUnicode = Convert2Unicode(pUtf8,codeName);

//    wstring wstr = qsUnicode.toStdWString();
//    char *pwrite = (char*)wstr.c_str();
//    writeFileBina(pwrite,256,"record-unicode.dat");
    return qsUnicode;
}

//gbk转换为utf-8
string CCodeConvert::ConvertGbk2Utf8(string pGbk)
{
    QString qstr = Convert2Unicode(pGbk,"gb2312");
    string strUtf8 = ConvertFromUnicode(qstr,"utf-8");
    return strUtf8;
}

//utf-8转换为gbk
string CCodeConvert::ConvertUtf82Gbk(string pUtf8)
{
    QString qstr = Convert2Unicode(pUtf8,"utf-8");
    string strGbk = ConvertFromUnicode(qstr,"gb2312");
    return strGbk;
}


void CCodeConvert::cpyMulti2Wide(string pChar,string pwChar)
{

}

void CCodeConvert::cpyWide2Multi(string pwChar,string pChar)
{

}

//ANSI编码转化为utf-8编码
void  CCodeConvert::ConvertAnsi2Utf8(string pAnsi,string pUtf8)
{


}

//ANSI编码转化为Unicode编码
void CCodeConvert::ConvertAnsi2Unicode(string pAnsi,string pUnicode)
{

}

//utf-8编码转化为ANSI编码
void CCodeConvert::ConvertUtf82Ansi(string pUtf8,string pAnsi)
{

}

//Unicode编码转化为ANSI编码
void CCodeConvert::ConvertUnicode2Ansi(string pUnicode,string pAnsi)
{

}

void CCodeConvert::testCode()
{
    QString qstr = "我是汉字";
    QByteArray qb = qstr.toUtf8();
    qDebug()<<"utf-8"<<qb<<"-size"<<qb.size()<<"\n";
    string str = qb.data();
    string str2 = ConvertUtf82Gbk(str);
    qDebug()<<"gbk"<<str2.c_str()<<"-size"<<str2.size()<<"\n";

    string strNameUtf8 = "我是汉字.dat";
    writeFileBina(str2,strNameUtf8);
    str2 = ConvertUtf82Gbk(strNameUtf8);
    writeFileBina(str2,str2);

}

void CCodeConvert::writeFileBina(string src,string fileName)
{   
   FILE *fp = fopen(fileName.c_str(),"wb");
   if(fp == NULL)
       return;
   fwrite(src.c_str(),1,src.size(),fp);
   fclose(fp);
}

void CCodeConvert::writeFileBina(char* src,int size,string fileName)
{
    FILE *fp = fopen(fileName.c_str(),"wb");
    if(fp == NULL)
        return;
    fwrite(src,1,size,fp);
    fclose(fp);
}
