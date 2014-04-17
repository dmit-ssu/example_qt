#include <QtTest>

class UnittestTest: public QObject
{
    Q_OBJECT

public:
    UnittestTest() {}

private Q_SLOTS:
    void testCase1();
};

void UnittestTest::testCase1()
{
}

QTEST_APPLESS_MAIN(UnittestTest)

#include "main.moc"
