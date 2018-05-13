#include "databasemanager.h"

DatabaseManager::DatabaseManager()
{
    myDB = QSqlDatabase::addDatabase("QSQLITE");
    myDB.setDatabaseName(DB_PATH);

    if( QFile::exists(DB_PATH) )
    {
        if (!myDB.open()) //be careful, SQLITE will create the db if it doesn't exist and return true.
        {
            qDebug() << "Error: could not open connection to database.";
        }
        else
        {
            qDebug() << "Database connection opened.";
        }
    }
    else
    {
        qDebug() << "Cannot open database because the DB Path does not exist.";
    }
}

DatabaseManager::~DatabaseManager()
{
     myDB = QSqlDatabase::addDatabase("QSQLITE");
    if (myDB.isOpen())
    {
        myDB.close();
    }

    qDebug() << "Destroying Databasemanager";
}

bool DatabaseManager::isOpen() const
{
    return myDB.isOpen();
}

DatabaseManager& DatabaseManager::instance()
{
    static DatabaseManager dmInstance;

    return dmInstance;
}

// Member functions for the Database
bool DatabaseManager::customerExist(const CustomerList& customer)
{
    bool exists = false;
    QSqlQuery query;
    QString name = customer.GetCustomerName();

    query.prepare("SELECT name FROM customers WHERE name = (:name)");
    query.bindValue(":name", name);

    if(query.exec())
    {
        if(query.next())
        {
            exists = true;
        }
    }

    return exists;
}

bool DatabaseManager::AddCustomer(const CustomerList& newCustomer)
{
    if(newCustomer.GetCustomerName().isEmpty() || newCustomer.GetStreet().isEmpty() || newCustomer.GetCity().isEmpty() || newCustomer.GetState().isEmpty() || newCustomer.GetZipCode() == 0
        || newCustomer.GetCustomerInterest().isEmpty() || newCustomer.GetCustomerConsider().isEmpty())
    {
        qDebug() << "Cannot create a client record if any of their information is not filled";
        return false;
    }

    QSqlQuery query;
    QString name;
    QString street;
    QString city;
    QString state;
    int zipCode;
    QString interest;
    QString consider;

    name = newCustomer.GetCustomerName();
    street = newCustomer.GetStreet();
    city = newCustomer.GetCity();
    state = newCustomer.GetState();
    zipCode = newCustomer.GetZipCode();
    interest = newCustomer.GetCustomerInterest();
    consider = newCustomer.GetCustomerConsider();

    query.prepare("INSERT INTO customers (name, street, city, state, zipcode, interest, consider) VALUES (:name, :street, :city, :state, :zipcode, :interest, :consider)");
    query.bindValue(":name", name);
    query.bindValue(":street", street);
    query.bindValue(":city", city);
    query.bindValue(":state", state);
    query.bindValue(":zipcode", zipCode);
    query.bindValue(":interest", interest);
    query.bindValue(":consider", consider);

    if(query.exec())
    {
        qDebug() << "AddCustomer success:";
        return true;
    }
    else
    {
        qDebug() << "AddCustomer fail:"
                 << query.lastError();
        return false;
    }
}

bool DatabaseManager::RemoveCustomer(const CustomerList& customer)
{
    QSqlQuery query;
    QString name = customer.GetCustomerName();

    if(customerExist(customer))
    {
        query.prepare("DELETE FROM customers WHERE name = (:name)");
        query.bindValue(":name", name);

        if( query.exec() )
        {
            qDebug() << "Customer deleted!";
            return true;
        }
        else
        {
            qDebug() << "Delete Customer failed: " << query.lastError();
            return false;
        }
    }
    return false;
}

bool DatabaseManager::purchaseExist(QString& purchaser)
{
    bool exists = false;
    QSqlQuery query;
    QString Company = purchaser;


    query.prepare("SELECT Company FROM Purchases WHERE Company = (:Company)");
    query.bindValue(":Company", Company);

    if(query.exec())
    {
        if(query.next())
        {
            exists = true;
        }
    }

    return exists;
}

bool DatabaseManager::AddPurchase(QString Company, QString review)
{
    QSqlQuery query;

    query.prepare("INSERT INTO reviews (Company, review) VALUES (:Company, :review)");
    query.bindValue(":Company", Company);
    query.bindValue(":review", review);

    if(query.exec())
    {
        qDebug() << "addPurchase success:";
        return true;
    }
    else
    {
        qDebug() << "addPurchase fail:"
                 << query.lastError();
        return false;
    }
}

bool DatabaseManager::AddPackage(QString name, QString package, double price){
    QSqlQuery query;

    query.prepare("SELECT * FROM Purchases ");
    query.prepare("INSERT INTO Purchases (company, package, price) VALUES (:company, :package, :price)");
    query.bindValue(":company", name);
    query.bindValue(":package", package);
    query.bindValue(":price", price);
    query.exec();
}



