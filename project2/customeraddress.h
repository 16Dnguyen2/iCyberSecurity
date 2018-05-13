#ifndef CUSTOMERADDRESS_H
#define CUSTOMERADDRESS_H

#include <QtSql>

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
