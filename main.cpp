#include <QCoreApplication>
#include <all.h>
#include <parser.h>

int main(int argc, char *argv[])
{
    int frameCount=1;
    QCoreApplication a(argc, argv);

    QString filename="/home/alexandra/N3716.mp4";
    VideoCapture capture;




    if(! capture.open(filename.toStdString()))
            throw 1;
    Mat frame;
    capture.read(frame);
    do
    {
        imshow("frame",frame);
        Parser handler(frameCount);
        QFile file("/home/alexandra/N3716.xml");
        QXmlInputSource source(&file);
        QXmlSimpleReader reader;
        reader.setContentHandler(&handler);
        reader.parse(source);
        cout<<frameCount<<endl;
        frameCount++;
        QTest::qWait(40);
    }
    while (capture.read(frame));

    return a.exec();
}
