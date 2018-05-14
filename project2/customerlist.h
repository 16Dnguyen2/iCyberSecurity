/** @file customerlist.h
*	@brief Contains data in regard to customers.
*/

#ifndef CUSTOMERLIST_H
#define CUSTOMERLIST_H

#include <QtSql>
#include "customeraddress.h"

/**
* @brief  Holds property values for a singular customer.
*/
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
