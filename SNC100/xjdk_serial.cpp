#include "xjdk_serial.h"

xjdk_serial::xjdk_serial()
{

    QString path = "HKEY_LOCAL_MACHINE\\HARDWARE\\DEVICEMAP\\SERIALCOMM\\";
    QSettings *settings = new QSettings( path, QSettings::NativeFormat);
    QStringList key = settings->allKeys();
    int num = (int)key.size();
    QString value;
    for(int i=0; i<num; i++)
    {
       value = getcomm(i, "value");
       m_listcomboName<<value;
    }

}

QString xjdk_serial::getcomm(int index, QString keyorvalue)
{
    QString commresult;
    if(::RegOpenKeyEx(HKEY_LOCAL_MACHINE,TEXT("HARDWARE\\DEVICEMAP\\SERIALCOMM"),0,KEY_READ,&hKey)!=0)
    {
        QString error="Cannot open regedit!";//无法打开注册表时返回error
        return error;
    }//if(::RegOpenKeyEx(HKEY_LOCAL_MACHINE,subkey,0,KEY_READ,&hKey)!=0)
    QString keymessage;//键名
    QString message;
    QString valuemessage;//键值
    indexnum = index;//要读取键值的索引号
    keysize=sizeof(keyname);
    valuesize=sizeof(keyvalue);
    if(::RegEnumValue(hKey,indexnum,keyname,&keysize,0,&type,(BYTE*)keyvalue,&valuesize)==0)//列举键名和值
    {
        for(int i=0;i <keysize;i++)
        {
            message=keyname[i];
            keymessage.append(message);
        }// for(int i=0;i<=keysize;i++)    读取键名
        for(int j=0;j<valuesize;j++)
        {
            if(keyvalue[j]!=0x00)
            {
            valuemessage.append(keyvalue[j]);
            }
        }//for(int j=0;j<valuesize;j++) 读取键值
        if(keyorvalue=="key")
        {
            commresult=keymessage;
        }
        if(keyorvalue=="value")
        {
            commresult=valuemessage;
        }
    }
    else
    {
        commresult="nokey";
    } //if(::RegEnumValue(hKey,indexnum,keyname,&keysize,0,&type,(BYTE*)keyvalue,&valuesize)==0) 列举键名和值
    return commresult;
    ::RegCloseKey(hKey);//关闭注册表
}
