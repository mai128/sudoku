#ifndef NUMBERSELECTIONDIALOG_H
#define NUMBERSELECTIONDIALOG_H

#include <QDialog>

namespace Ui {
class NumberSelectionDialog;
}

class NumberSelectionDialog : public QDialog
{
    Q_OBJECT

public:
    explicit NumberSelectionDialog(QWidget *parent = 0);
    ~NumberSelectionDialog();
    int myValue();

private slots:
    void on_toolButton_clicked();

    void on_toolButton_2_clicked();

    void on_toolButton_3_clicked();

    void on_toolButton_4_clicked();

    void on_toolButton_5_clicked();

    void on_toolButton_6_clicked();

    void on_toolButton_7_clicked();

    void on_toolButton_8_clicked();

    void on_toolButton_9_clicked();

    void on_toolButton_10_clicked();

    void set_mValue(int value);


private:
    Ui::NumberSelectionDialog *ui;
    int mValue;

};

#endif // NUMBERSELECTIONDIALOG_H
