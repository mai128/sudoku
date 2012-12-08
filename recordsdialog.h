#ifndef RECORDSDIALOG_H
#define RECORDSDIALOG_H

#include <QDialog>

class QSqlTableModel;

namespace Ui {
class RecordsDialog;
}

class RecordsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit RecordsDialog(QWidget *parent = 0);
    ~RecordsDialog();


private:
    Ui::RecordsDialog *ui;
    QSqlTableModel *mModel;
};

#endif // RECORDSDIALOG_H
