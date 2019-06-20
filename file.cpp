#include "file.h"

QString attach_qstring(QString qstr)//convert  some thing  to some~thing
{
    for(int i=0;i<qstr.length();i++)
    {
        if(qstr[i]==' ') qstr[i]='~';
    }
    return qstr;
}
QString separate_qstring(QString qstr)//convert some~thing to some thinf
{
    for(int i=0;i<qstr.length();i++)
    {
        if(qstr[i]=='~') qstr[i]=' ';
    }
    return qstr;
}
