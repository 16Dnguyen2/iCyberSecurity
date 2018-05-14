/** @file services.h
*	@brief Contains data in regard to company services.
*/

#ifndef SERVICES_H
#define SERVICES_H


#include <QtSql>

/**
* @brief  Holds property values for a type of service.
*/
class Services
{
public:
    Services();
    Services(QString, double);

private:
    QString serviceName;
    double  servicePrice;

    QString GetServiceName() const;
    double GetServicePrice() const;
};

#endif // SERVICES_H
