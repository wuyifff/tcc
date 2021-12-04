#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <QProcess>
#include "dialog.h"
static bool is_compiled = false;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QLabel *status=new QLabel("start",this);
    ui->statusBar->addWidget(status);
    text = new QTextEdit;
    this->setCentralWidget(text);
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_actionopen_triggered()
{
    qDebug()<<"open ";
    file_name = QFileDialog::getOpenFileName(this, tr("Open File"),QDir::currentPath()); //获取路径
    qDebug()<<file_name;
    QFile *file=new QFile;
    file->setFileName(file_name);
    bool ok = file->open(QIODevice::ReadOnly);      //只读打开
    if(ok)
    {
          QTextStream in(file);
          text->setText((in.readAll().toUtf8()));
          file->close();
          delete file;
    }
    else
    {
        qDebug()<< "open cancel" << file_name;
        delete file;
    }
}



void MainWindow::on_actionsave_triggered()
{
    qDebug()<<"save ";
    QFile *file = new QFile;
    file->setFileName(file_name);
    bool ok = file->open(QIODevice::WriteOnly);     //只写打开
    if(ok)
    {
        QString p_text = text->toPlainText();//这里是取出textEdit当中的纯文本
        qDebug()<< file_name;
        QTextStream writefiletext(file); //写入文件路径
        writefiletext << p_text;             //写入内容
        file->close();
        delete file;
    }
    else
    {
        QMessageBox::warning(NULL, "warning", "new file need save as", QMessageBox::Yes, QMessageBox::Yes);
        return;
    }
}


void MainWindow::on_actionsave_as_triggered()
{
    qDebug()<<"saveas ";
    QString fileName = QFileDialog::getSaveFileName(this,"Save File",QDir::currentPath()); //获取路径
    QFile *file = new QFile;
    file->setFileName(fileName);
    bool ok = file->open(QIODevice::WriteOnly);     //只写打开
    if(ok)
    {
        QString p_text = text->toPlainText();//这里是取出textEdit当中的纯文本
        qDebug()<<p_text;
        QTextStream writefiletext(file); //写入文件路径
        writefiletext<<p_text;             //写入内容
        file->close();
        delete file;
    }
}


void MainWindow::on_actiontokenize_triggered()
{
    if(file_name.isEmpty())
    {
       qDebug() << "need to save";
       QMessageBox::warning(NULL, "warning", "please save first", QMessageBox::Yes, QMessageBox::Yes);
       return;
    }
    QProcess p(0);
    p.start("cmd");
    p.waitForStarted();
    p.write("cd D:/test_code/Qt/tcc\n");
    p.write(" D:/test_code/Qt/tcc/compiler.exe ");
    p.write(file_name.toLatin1());
    p.write("> temp.txt\n");
    p.closeWriteChannel();
    p.waitForFinished();
    is_compiled = true;
    QMessageBox::information(NULL, "提醒", "编译完成,请查看结果！", QMessageBox::Yes, QMessageBox::Yes);
//    qDebug()<<QString::fromLocal8Bit(p.readAllStandardOutput());
}


void MainWindow::on_actiontoken_table_triggered()
{
    QString fileName = "D:/test_code/Qt/tcc/temp.txt"; //获取路径
    QFile *file = new QFile;
    file->setFileName(fileName);
    bool ok = file->open(QIODevice::ReadOnly);
    Dialog a;
    a.show();
    if(ok)
    {
        while(!file->atEnd()) {
            QByteArray line = file->readLine();
            QString str(line);
            qDebug()<< str;
//            QTextStream in(file);
            a.set(file);
        }
        file->close();
        delete file;
    }
}




void MainWindow::on_actionobjcode_triggered()
{
    QString fileName = "D:/test_code/Qt/tcc/object.s"; //获取路径
    QFile *file = new QFile;
    file->setFileName(fileName);
    bool ok = file->open(QIODevice::ReadOnly);
    Dialog a;
    a.show();
    if(ok)
        a.set(file);
    file->close();
    delete file;
}

