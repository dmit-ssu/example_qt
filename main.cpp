#include <iostream>
#include <QCoreApplication>
#include <QTimer>

using namespace std;

class Task: public QObject
{
    Q_OBJECT
public:
    Task(QObject *parent = 0) : QObject(parent) {}

public slots:
    void run()
    {
        cout << "Hello, World!\n";

        emit finished();
    }

signals:
    void finished();
};

#include "main.moc"

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    Task *task = new Task(&app);

    QObject::connect(task, SIGNAL(finished()), &app, SLOT(quit()));

    QTimer::singleShot(500, task, SLOT(run()));

    return app.exec();
}
