#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    text = new QTextEdit;
    text->showNormal();
}
void Dialog::set(QFile* file) {
    QTextStream in(file);
    text->setText(in.readAll().toUtf8());
}

Dialog::~Dialog()
{
    delete ui;
}
