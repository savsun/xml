#include "parser.h"

Parser::Parser(int countFrame)
{
    _countFrame=countFrame;
}

bool Parser::startElement(const QString &, const QString &,const QString& teg, const QXmlAttributes& attrs)
{
    if (teg == "frame")
    {
        if (k==_countFrame)
        {
           cout<<"Frame "<<k<<endl;
        }
    }
  /*cout<<attrs.count();
  if (attrs.value(0)=="double")
    {
     cout<<teg.toStdString()<<strText.toDouble()<<endl;
    }*/
   return true;
}

bool Parser::characters(const QString& _strText)
{
   strText=_strText;
   return true;
}


bool Parser::endElement (const QString&, const QString&, const QString& str)
{
    if (str=="frame"){k++;}

    if (str!="amv"&&str!="frame")
    {
        if (k==_countFrame)
        {
            cout<<str.toStdString()<<" "<<strText.toDouble()<<endl;
        }
    }
    return true;
}

bool Parser::fatalError (const QXmlParseException &exception)
{
    cout<<"Line: "<<exception.lineNumber()<<", Column: "<<exception.columnNumber()<<", Message: "<<exception.message().toStdString();
    return false;
}
