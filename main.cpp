#include "common.h"
#include "mainwindow.h"

using namespace std;

int main(int argc, char *argv[])
{
    QApplication app(argc,argv);

    QWidget *widget = new MainWindow;

    widget->show();

    return app.exec();
}
