#include "customerlisting.h"
#include "ui_customerlisting.h"

customerListing::customerListing(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::customerListing)
{
    ui->setupUi(this);
}

customerListing::~customerListing()
{
    delete ui;
}

void customerListing::on_ViewAllCustomer_clicked()
{
    QSqlQueryModel * model = new QSqlQueryModel();
    QSqlQuery query;

    query.prepare("SELECT * FROM customers");
    query.exec();

    model->setQuery(query);
    ui->customerTable->setModel(model);
}

void customerListing::on_SortbyName_clicked()
{
    QSqlQueryModel * model = new QSqlQueryModel();
    QSqlQuery query;

    query.prepare("SELECT name,street,city,state,zipcode,interest,consider FROM customers ORDER BY name ASC");
    query.exec();

    model->setQuery(query);
    ui->customerTable->setModel(model);
}

void customerListing::on_SortbyKey_clicked()
{
    QSqlQueryModel * model = new QSqlQueryModel();
    QSqlQuery query;

    query.prepare("SELECT name,street,city,state,zipcode,interest,consider FROM customers WHERE consider = 'key' or consider = 'Key'");
    query.exec();

    model->setQuery(query);
    ui->customerTable->setModel(model);
}
