#include <QCoreApplication>
#include <QCommandLineParser>
#include <QFile>
#include "qcodepage437codec.h"
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);
    QCoreApplication::setApplicationName("ShowAnsi");
    QCoreApplication::setApplicationVersion("1.1a");

    QByteArray h;
    QFile f(":/txt/help");
    if (f.open(QFile::ReadOnly)) {
        h = f.readAll();
        f.close();
    }

    QCommandLineParser parser;
    parser.setApplicationDescription(h);
    parser.addHelpOption();
    parser.addVersionOption();
    parser.addPositionalArgument("file", QCoreApplication::translate("main", "File to show."));
    parser.process(app);

    const QStringList args = parser.positionalArguments();
    // source is args.at(0), destination is args.at(1)
    if (args.length() == 0) {
        parser.showHelp();
        exit(0);
    }

    f.setFileName(args.at(0));
    if (f.open(QFile::ReadOnly)) {
        h = f.readAll();
        f.close();
        QByteArray q;
        q.append('\x1a');
        q.append("SAUCE00");
        int pos = h.indexOf(q);
        if (pos>=0){
            h = h.left(pos);
        }

        QCodePage437Codec *qc = new QCodePage437Codec();
        QString res = qc->toUnicode(h);
        cout << res.toLocal8Bit().data() << endl;
        cout << '\x1b' << "[0m" << endl;
        exit(0);
    }

    return app.exec();
}
