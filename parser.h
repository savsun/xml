#ifndef PARSER_H
#define PARSER_H
#include <all.h>

class Parser: public QXmlDefaultHandler
{
public:
    Parser(int countFrame);
private:
    QString strText;
    int k=1;
    int _countFrame;

public:
    bool startElement(const QString &, const QString &,const QString& teg, const QXmlAttributes& attrs);
    bool characters(const QString& _strText);
    bool endElement (const QString&, const QString&, const QString& str);
    bool fatalError (const QXmlParseException &exception);
};

#endif // PARSER_H
