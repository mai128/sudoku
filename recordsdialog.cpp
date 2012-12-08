#include <QSqlTableModel>
#include "recordsdialog.h"
#include "ui_recordsdialog.h"

RecordsDialog::RecordsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RecordsDialog)
{
    ui->setupUi(this);
    mModel= new QSqlTableModel(this);
    mModel->setTable("records");
    mModel->setSort(4,Qt::AscendingOrder);
    mModel->setHeaderData(0,Qt::Horizontal,"Id");
    mModel->setHeaderData(1,Qt::Horizontal,"Game Id");
    mModel->setHeaderData(2,Qt::Horizontal,"Name");
    mModel->setHeaderData(3,Qt::Horizontal,"Error Count");
    mModel->setHeaderData(4,Qt::Horizontal,"Duration");
    mModel->select();
    ui->tableView->setModel(mModel);
    ui->tableView->resizeColumnsToContents();
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    QHeaderView *header = ui->tableView->horizontalHeader();
    header->setStretchLastSection(true);
}

RecordsDialog::~RecordsDialog()
{
    delete ui;
}


