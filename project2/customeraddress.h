/** @file customeraddress.h
*	@brief Contains data in regard to customer addresses.
*/

#ifndef CUSTOMERADDRESS_H
#define CUSTOMERADDRESS_H

#include <QtSql>

/**
* @brief  Holds property values for a singular customer address.
*/
class CustomerAddress
{
public:
    CustomerAddress();
    CustomerAddress(QString, QString, QString, int);

    QString GetStreet() const;
    QString GetCity() const;
    QString GetState() const;
    int GetZipCode() const;

private:
    QString street;
    QString city;
    QString state;
    int zipcode;
};

#endif // CUSTOMERADDRESS_H
