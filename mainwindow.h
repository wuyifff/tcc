#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QToolBar>
#include <QStatusBar>
#include <QTextEdit>
#include <QLabel>
#include <QDebug>
#include <QTabWidget>
#include <QFileDialog>
#include <QColorDialog>
#include <QFontDialog>
#include <QInputDialog>
#include <QMessageBox>
#include <QKeyEvent>
#include <QDateTime>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
//private slots:
//    void FileNew();
//    void FileOpen();
//    void FileSave();
//    void FileSaveas();
//    void FileFont();
//    void FileColor();
//    void FileCopy();
//    void FilePaste();
//    void FileFind();

    void on_actionopen_triggered();

    void on_actionsave_triggered();

    void on_actionsave_as_triggered();

    void on_actiontokenize_triggered();

    void on_actiontoken_table_triggered();

    void on_actiontoken_table_2_triggered();

    void on_actionobjcode_triggered();

private:
    Ui::MainWindow *ui;
    QTabWidget *tab;
    QTextEdit *text;
    QString file_name;       //文件路径
    int paint_timer;        //开启界面刷新timer
    int x;                  //横坐标
    int y;                  //纵坐标
    QDateTime current_date_time;    //时间
    QString current_date;           //时间字符串
    QStatusBar *stbar;  //状态栏
    QLabel *lab;        //标签
    QDialog *p;
};
#endif // MAINWINDOW_H
