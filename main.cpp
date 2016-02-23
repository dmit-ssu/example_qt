#include <iostream>
#include <QCoreApplication>

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    cout << "Hello, World!\n";

    return app.exec();
}
