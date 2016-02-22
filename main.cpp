#include <QtGlobal>
#if QT_VERSION < 0x050000
#include <QtGui>
#else
#include <QtWidgets>
#endif

using namespace std;

int main(int argc, char *argv[])
{
    QApplication app(argc,argv);

    QWidget *widget = new QWidget;
    QPushButton *quitButton = new QPushButton("Quit");
    QPushButton *aboutButton = new QPushButton("About QT");

    QVBoxLayout *buttonLayout = new QVBoxLayout;
    buttonLayout->addWidget(quitButton);
    buttonLayout->addWidget(aboutButton);

    QObject::connect(quitButton,SIGNAL(clicked()),qApp,SLOT(quit()));
    QObject::connect(aboutButton,SIGNAL(clicked()),qApp,SLOT(aboutQt()));

    widget->setLayout(buttonLayout);
    widget->setWindowFlags(Qt::Window);
    widget->show();

    return app.exec();
}
