#ifndef CUSTOMERLIST_H
#define CUSTOMERLIST_H

#include <QtSql>
#include "customeraddress.h"

class CustomerList : public CustomerAddress
{
public:
    CustomerList();
    CustomerList(QString, QString, QString, QString, int, QString, QString);

    QString GetCustomerName() const;
    QString GetCustomerInterest() const;
    QString GetCustomerConsider() const;

private:
    QString customerName;
    QString customerInterest;
    QString customerConsider;
};

#endif // CUSTOMERLIST_H
