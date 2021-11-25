#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ccompiler.cpp"


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
    QString p_text = text->toPlainText();
    tokenize(p_text.toStdString());
}

