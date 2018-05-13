#include "services.h"

Services::Services()
{
    serviceName = "";
    servicePrice = 0.00;
}
Services::Services(QString sName, double sPrice)
{
    serviceName = sName;
    servicePrice = sPrice;
}

QString Services::GetServiceName() const
{
    return serviceName;
}

double Services::GetServicePrice() const
{
    return servicePrice;
}
