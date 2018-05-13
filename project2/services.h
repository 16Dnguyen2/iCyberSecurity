#ifndef SERVICES_H
#define SERVICES_H


#include <QtSql>

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
