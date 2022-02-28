#include "common.h"
#include "mainwindow.h"
#include "ui_widget.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    setCentralWidget(ui->graphicsView);

    m_topLeftButton = new QPushButton("Top Left", ui->graphicsView);
    m_topRightButton = new QPushButton("Top Right", ui->graphicsView);
    m_bottomLeftButton = new QPushButton("Bottom Left", ui->graphicsView);
    m_bottomRightButton = new QPushButton("Bottom Right", ui->graphicsView);

    updateButtonsPosition();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::resizeEvent(QResizeEvent *event)
{
    Q_UNUSED(event);

    qDebug() << "MainWindow::resizeEvent";
    updateButtonsPosition();
}

void MainWindow::updateButtonsPosition()
{
    QRect graphicsViewGeometry = ui->graphicsView->geometry();
    m_topLeftButton->setGeometry({25,
                                  25,
                                  m_topLeftButton->geometry().width(),
                                  m_topLeftButton->geometry().height()});
    m_topRightButton->setGeometry({graphicsViewGeometry.width() - m_topRightButton->geometry().width() - 25,
                                   25,
                                   m_topRightButton->geometry().width(),
                                   m_topRightButton->geometry().height()});
    m_bottomLeftButton->setGeometry({25,
                                     graphicsViewGeometry.height() - m_bottomLeftButton->geometry().height() - 25,
                                     m_bottomLeftButton->geometry().width(),
                                     m_bottomLeftButton->geometry().height()});
    m_bottomRightButton->setGeometry({graphicsViewGeometry.width() - m_bottomRightButton->geometry().width() - 25,
                                      graphicsViewGeometry.height() - m_bottomRightButton->geometry().height() - 25,
                                      m_bottomRightButton->geometry().width(),
                                      m_bottomRightButton->geometry().height()});
}
