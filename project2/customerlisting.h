#ifndef CUSTOMERLISTING_H
#define CUSTOMERLISTING_H

#include <QDialog>
#include "mainwindow.h"

namespace Ui {
class customerListing;
}

class customerListing : public QDialog
{
    Q_OBJECT

public:
    explicit customerListing(QWidget *parent = 0);
    ~customerListing();

private slots:
    void on_ViewAllCustomer_clicked();

    void on_SortbyName_clicked();

    void on_SortbyKey_clicked();

private:
    Ui::customerListing *ui;
};

#endif // CUSTOMERLISTING_H
