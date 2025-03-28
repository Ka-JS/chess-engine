#include <QtTest>
#include "../gameboard.hh"

// add necessary includes here

class pathtest : public QObject
{
    Q_OBJECT

public:
    pathtest();
    ~pathtest();

private slots:
    void initTestCase();
    void cleanupTestCase();
    void testSuccessfulMove();
    void testUnsuccessfulMove();
    void testMove_data();
    void testMove();


};

pathtest::pathtest() {}

pathtest::~pathtest() {}

void pathtest::initTestCase() {}

void pathtest::cleanupTestCase() {}



void pathtest::testSuccessfulMove() {
    GameBoard board;
    board.initialFill();
    QVERIFY(board.move({0, 0}, {0, 1}));  // we assume move succeeds
    board.print();  // Print the game board to detect possible errors
}

void pathtest::testUnsuccessfulMove() {
    GameBoard board;
    board.initialFill();
    QVERIFY(!board.move({0, 0}, {0, 0})); // we assume move fails
    board.print();
}

void pathtest::testMove_data() {
    QTest::addColumn<Location>("start");
    QTest::addColumn<Location>("destination");
    QTest::addColumn<bool>("expected");

    QTest::newRow("valid move") << Location{0, 0} << Location{0, 1} << true;
    QTest::newRow("invalid move") << Location{0, 0} << Location{0, 0} << false;
}

void pathtest::testMove() {
    QFETCH(Location, start);
    QFETCH(Location, destination);
    QFETCH(bool, expected);

    GameBoard board;
    board.initialFill();
    bool result = board.move(start, destination);
    QCOMPARE(result, expected);
    board.print();
}

QTEST_APPLESS_MAIN(pathtest)

#include "tst_pathtest.moc"
