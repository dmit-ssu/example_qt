#include <QtTest>
#include "myclass.h"

class UnittestTest: public QObject
{
    Q_OBJECT

public:
    UnittestTest() {}

private Q_SLOTS:
    void testCase1_data();
    void testCase1();
};

void UnittestTest::testCase1_data()
{
    QTest::addColumn<int>("first");
    QTest::addColumn<int>("second");
    QTest::addColumn<int>("expected");

    QTest::newRow("compare01") << 0 << 0 << 0;
    QTest::newRow("compare02") << 5 << 10 << -1;
    QTest::newRow("compare03") << 10 << 5 << 1;
    QTest::newRow("compare04") << -5 << -10 << 1;
    QTest::newRow("compare05") << -10 << -5 << -1;
    QTest::newRow("compare06") << 5 << -10 << 1;
    QTest::newRow("compare07") << -5 << 10 << -1;
    QTest::newRow("compare08") << 2000000000 << 10 << 1;
    QTest::newRow("compare09") << -10 << 2000000000 << -1;
    QTest::newRow("compare10") << 10 << -2000000000 << 1;
}

void UnittestTest::testCase1()
{
    myclass mc;

    QFETCH(int, first);
    QFETCH(int, second);
    QFETCH(int, expected);

    int actual = mc.compare(first, second);
    QCOMPARE(actual, expected);
}

QTEST_APPLESS_MAIN(UnittestTest)

#include "main.moc"
