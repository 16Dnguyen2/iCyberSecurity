#include "customeraddress.h"

CustomerAddress::CustomerAddress()
{
    street = "";
    city = "";
    state = "";
    zipcode = 0;
}

CustomerAddress::CustomerAddress(QString cStreet, QString cCity, QString cState, int cZipCode)
{
    street = cStreet;
    city = cCity;
    state = cState;
    zipcode = cZipCode;
}

QString CustomerAddress::GetStreet() const
{
    return street;
}

QString CustomerAddress::GetCity() const
{
    return city;
}

QString CustomerAddress::GetState() const
{
    return state;
}

int CustomerAddress::GetZipCode() const
{
    return zipcode;
}

