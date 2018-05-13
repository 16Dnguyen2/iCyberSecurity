#include "customerlist.h"
#include "customeraddress.h"

CustomerList::CustomerList()
{
    customerName = "";
    customerInterest = "";
    customerConsider = "";
}

CustomerList::CustomerList(QString cName, QString street, QString city, QString state, int zipcode, QString cInterest, QString cConsider)
                           : CustomerAddress(street, city, state, zipcode)
{
    customerName = cName;
    customerInterest = cInterest;
    customerConsider = cConsider;
}

QString CustomerList::GetCustomerName() const
{
    return customerName;
}


QString CustomerList::GetCustomerInterest() const
{
    return customerInterest;
}

QString CustomerList::GetCustomerConsider() const
{
    return customerConsider;
}
