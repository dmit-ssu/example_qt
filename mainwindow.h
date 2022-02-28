#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>

namespace Ui {
class Widget;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
    virtual void resizeEvent(QResizeEvent *event) override;

private:
    void updateButtonsPosition();

    Ui::Widget *ui;

    QPushButton* m_topLeftButton;
    QPushButton* m_topRightButton;
    QPushButton* m_bottomLeftButton;
    QPushButton* m_bottomRightButton;
};

#endif // MAINWINDOW_H
