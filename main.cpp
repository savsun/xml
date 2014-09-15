#include <QCoreApplication>
#include <all.h>
#include <parser.h>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Parser handler;
    QFile file("/home/alexandra/N3716.xml");
    QXmlInputSource source(&file);
    QXmlSimpleReader reader;
    reader.setContentHandler(&handler);
    reader.parse(source);

    QString filename="/home/alexandra/N3716.mp4";
    VideoCapture capture;

    if(! capture.open(filename.toStdString()))
            throw 1;
    Mat frame;
    capture.read(frame);
    QMap<string,double> frameMap;

    int k=0;
    do
    {
        cout<<"Frame "<<k+1<<endl;
        imshow("frame",frame);
        frameMap.unite(handler.frames.at(k));

        QMap<string,double>::iterator it=frameMap.begin();
        for (;it != frameMap.end(); ++it)
        {
            cout<<it.key()<<" "<<it.value()<<endl;
        }
        frameMap.clear();
        k++;
        QTest::qWait(120);
    }
    while (capture.read(frame));

    return a.exec();
}
