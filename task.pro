TEMPLATE = app
SOURCES += main.cpp
contains(QT_VERSION, ^5.*) {
    QT += widgets
}
