#include "numberselectiondialog.h"
#include "ui_numberselectiondialog.h"

NumberSelectionDialog::NumberSelectionDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NumberSelectionDialog)
{
    ui->setupUi(this);
}

NumberSelectionDialog::~NumberSelectionDialog()
{
    delete ui;
}

int NumberSelectionDialog::myValue()
{
    return mValue;
}



void NumberSelectionDialog::on_toolButton_clicked()
{

    mValue=1;
    accept();

}

void NumberSelectionDialog::on_toolButton_2_clicked()
{
    mValue=2;
    accept();
}

void NumberSelectionDialog::on_toolButton_3_clicked()
{
    mValue=3;
    accept();
}

void NumberSelectionDialog::on_toolButton_4_clicked()
{
    mValue=4;
    accept();
}

void NumberSelectionDialog::on_toolButton_5_clicked()
{
    mValue=5;
    accept();
}

void NumberSelectionDialog::on_toolButton_6_clicked()
{
    mValue=6;
    accept();
}

void NumberSelectionDialog::on_toolButton_7_clicked()
{
    mValue=7;
    accept();
}

void NumberSelectionDialog::on_toolButton_8_clicked()
{
    mValue=8;
    accept();
}

void NumberSelectionDialog::on_toolButton_9_clicked()
{
    mValue=9;
    accept();
}

void NumberSelectionDialog::on_toolButton_10_clicked()
{
    mValue=0;
    accept();
}

void NumberSelectionDialog::set_mValue(int value)
{
    mValue=value;
    accept();
}
