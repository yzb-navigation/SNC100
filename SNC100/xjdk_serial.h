#ifndef XJDK_SERIAL_H
#define XJDK_SERIAL_H

#include <QWidget>
#include <QMessageBox>
#include <qt_windows.h>
#include <QSettings>

class xjdk_serial
{
public:
    xjdk_serial();

    QStringList m_listcomboName;
    HKEY hKey;
    LPCWSTR subkey;
    wchar_t keyname[256]; //键名数组
    char keyvalue[256];  //键值数组
    DWORD keysize,type,valuesize;
    int indexnum;
    QString getcomm(int index, QString keyorvalue);

};

#endif // XJDK_SERIAL_H
