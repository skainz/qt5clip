#include <QApplication>
#include <QClipboard>
#include <QMimeData>
#include <QDebug>
#include <QtPlugin>
Q_IMPORT_PLUGIN(QWindowsIntegrationPlugin)

int main(int argc, char **argv)
{
QApplication a(argc, argv);
QClipboard *clipboard = QApplication::clipboard();
const QMimeData *mimeData = clipboard->mimeData();

 if (mimeData->hasText())
   {
     QString originalText = clipboard->text();
     qDebug()<<originalText;
     
   }


}

