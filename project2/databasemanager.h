#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H


#include <QtSql>
#include <QList>
#include <QtCore/QCoreApplication>
#include "constants.h"
#include "customerlist.h"
#include <QSqlDatabase>

class DatabaseManager
{
public:
    static DatabaseManager& instance();
    bool isOpen() const;

    DatabaseManager(const DatabaseManager&) = delete; //delete copy constructor.
    void operator =(const DatabaseManager&) = delete; //delete = operator.

    bool AddCustomer(const CustomerList& newCustomer);
    bool RemoveCustomer(const CustomerList& customer);
    bool customerExist(const CustomerList& customer);
    bool purchaseExist(QString& purchaser);
    bool AddPurchase(QString Company, QString review);
    bool AddPackage(QString name, QString package, double price);

private:
    DatabaseManager();
    ~DatabaseManager();

    QSqlDatabase myDB;
};

#endif // DATABASEMANAGER_H
