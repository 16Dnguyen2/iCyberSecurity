#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

QString interest;
QString consideration;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);

    if(DatabaseManager::instance().isOpen())
    {
        ui->dbConnect->setText("Success! Connected to database");
    }
    else
    {
        ui->dbConnect->setText("Failed to connect to database");
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_admin_button_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_login_clicked()
{
    QString username;
    QString password;

    username = ui->lineEdit_username->text();
    password = ui->lineEdit_password->text();

    if(username == "admin" && password == "password123")
    {
        ui->stackedWidget->setCurrentIndex(2);
        ui->lineEdit_password->setText("");
        ui->lineEdit_username->setText("");
    }
    else
    {
        ui->label_error->setText("ERROR: THE USERNAME/PASSWORD WAS INCORRECT");
        ui->lineEdit_password->setText("");
        ui->lineEdit_username->setText("");
    }
}

// INTRODUCTION PUSH BUTTONS
void MainWindow::on_intro_clicked()
{
    ui->stackedWidget->setCurrentIndex(7);
}

void MainWindow::on_purchase_clicked()
{
    ui->stackedWidget->setCurrentIndex(8);
}

void MainWindow::on_compatability_home_clicked()
{
    ui->stackedWidget->setCurrentIndex(9);
}

void MainWindow::on_reviews_clicked()
{
    ui->stackedWidget->setCurrentIndex(10);

    QSqlQueryModel * model = new QSqlQueryModel();
    QSqlQuery query;

    query.prepare("SELECT Company, review FROM reviews");
    query.exec();

    model->setQuery(query);
    ui->reviewsTable->setModel(model);
    ui->reviewsTable->resizeColumnsToContents();
}

void MainWindow::on_guarantee_clicked()
{
    ui->stackedWidget->setCurrentIndex(11);
}

void MainWindow::on_help_clicked()
{
    ui->stackedWidget->setCurrentIndex(12);
}

// INTRODUCTION BACK BUTTONS


void MainWindow::on_addDeleteCustomer_Button_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_addCustomerBackButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_searchCustomerBackButton_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_deleteCustomerBackButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_listByKeyBackButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_purchaseTableBackButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_listByNameBackButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_AllCustomersBack_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_CustomerPampletBackButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_customerList_Button_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);

//    QSqlQueryModel * model = new QSqlQueryModel();
//    QSqlQuery query;

//    query.prepare("SELECT * FROM customers");
//    query.exec();
//    model->setQuery(query);
//    ui->AllCustomersTableView->setModel(model);

//    query.prepare("SELECT name,street,city,state,zipcode,interest,consider FROM customers ORDER BY name ASC");
//    query.exec();
//    model->setQuery(query);
//    ui->listByName->setModel(model);

//    query.prepare("SELECT name,street,city,state,zipcode,interest,consider FROM customers WHERE consider = 'key' or consider = 'Key'");
//    query.exec();
//    model->setQuery(query);
//    ui->listByKey->setModel(model);

}

void MainWindow::on_AddItem_clicked()
{
    QString name;
    QString street;
    QString city;
    QString state;
    int zipCode;
    QString interest;
    QString consider;

    name = ui->cName->text();
    street = ui->cStreet->text();
    city = ui->cCity->text();
    state = ui->cState->text();
    zipCode = ui->cZipCode->value();
    interest = ui->InterestComboBox->currentText();
    consider = ui->considerationComboBox->currentText();

    if(!DatabaseManager::instance().customerExist(CustomerList(name,street,city,state,zipCode,interest,consider)))
    {
        if(DatabaseManager::instance().AddCustomer(CustomerList(name,street,city,state,zipCode,interest,consider)))
        {
//            ui->message->setText("Customer Added");
            QMessageBox::information(this, tr("UPDATE"),tr("Customer Added"));

        }
        else
        {
//            ui->message->setText("Failed To Add Customer'");
            QMessageBox::critical(this, tr("ERROR"),tr("Failed To Add Customer"));
        }
    }
    else
    {
//        ui->message->setText("Item already exists");
        QMessageBox::critical(this, tr("ERROR"),tr("Customer Already Exists"));
    }


}

void MainWindow::on_DeleteCustomer_clicked()
{
    QString name;
    QString street;
    QString city;
    QString state;
    int zipCode;
    QString interest;
    QString consider;

    name = ui->DeleteCustomerName->text();

    if(DatabaseManager::instance().customerExist(CustomerList(name,street,city,state,zipCode,interest,consider)))
    {
        if(DatabaseManager::instance().RemoveCustomer(CustomerList(name,street,city,state,zipCode,interest,consider)))
        {
//            ui->deleteMessage->setText("Customer Removed");
            QMessageBox::information(this, tr("UPDATE"),tr("Customer Removed"));
        }
        else
        {
//            ui->deleteMessage->setText("Failed To Remove Customer'");
            QMessageBox::critical(this, tr("ERROR"),tr("Failed To Remove Customer"));
        }
    }
    else
    {
//        ui->deleteMessage->setText("Customer Could Not Be Found");
        QMessageBox::critical(this, tr("ERROR"),tr("Customer Could Not Be Found"));
    }

}

void MainWindow::on_searchCustomer_clicked()
{
    QString name;
    QString street;
    QString city;
    QString state;
    int zipCode;
    QString interest;
    QString consider;
    QString pamphlet;

    QSqlQueryModel * model = new QSqlQueryModel();
    QSqlQuery query;

    name = ui->updateCustomer->text();

    if(DatabaseManager::instance().customerExist(CustomerList(name,street,city,state,zipCode,interest,consider)))
    {
//        ui->searchMessage->setText("Customer Found");
        QMessageBox::information(this, tr("UPDATE"),tr("Customer Found"));

    }
    else
    {
//        ui->searchMessage->setText("Customer Could Not Be Found");
        QMessageBox::critical(this, tr("ERROR"),tr("Customer Could Not Be Found"));
    }

    query.prepare("SELECT name,street,city,state,zipcode,interest,consider,pamphlet FROM customers WHERE name = :name");
    query.bindValue(":name", name);
    query.bindValue(":street", street);
    query.bindValue(":city", city);
    query.bindValue(":state", state);
    query.bindValue(":zipcode", zipCode);
    query.bindValue(":interest", interest);
    query.bindValue(":consider", consider);
    query.bindValue(":pamphlet", pamphlet);
    query.exec();

    model->setQuery(query);
    ui->foundCustomer->setModel(model);
    ui->foundCustomer->resizeColumnsToContents();

}

void MainWindow::on_loadCustomerListByName_clicked()
{
    QSqlQueryModel * model = new QSqlQueryModel();
    QSqlQuery query;

    query.prepare("SELECT name,street,city,state,zipcode,interest,consider FROM customers ORDER BY name ASC");
    query.exec();

    model->setQuery(query);
    ui->listByName->setModel(model);
    ui->listByName->resizeColumnsToContents();
}

void MainWindow::on_loadCustomersByPamplet_clicked()
{
    QSqlQueryModel * model = new QSqlQueryModel();
    QSqlQuery query;

    query.prepare("SELECT name,interest,consider,pamphlet FROM customers WHERE pamphlet = 'Sent'");
    query.exec();

    model->setQuery(query);
    ui->listByPamplet->setModel(model);
    ui->listByPamplet->resizeColumnsToContents();
}

void MainWindow::on_loadCustomerListByKey_clicked()
{
    QSqlQueryModel * model = new QSqlQueryModel();
    QSqlQuery query;

    query.prepare("SELECT name,street,city,state,zipcode,interest,consider FROM customers WHERE consider = 'key' or consider = 'Key'");
    query.exec();

    model->setQuery(query);
    ui->listByKey->setModel(model);
    ui->listByKey->resizeColumnsToContents();
}

void MainWindow::on_InterestComboBox_activated(int index)
{
    if(index == 1)
    {
        interest = "not interested";
    }
    else if(index == 2)
    {
        interest = "somewhat interested";
    }
    else if(index == 3)
    {
        interest = "very interested";
    }
}

void MainWindow::on_considerationComboBox_activated(int index)
{
    if(index == 1)
    {
        consideration = "nice to have";
    }
    else if(index == 2)
    {
        consideration = "key";
    }
}

void MainWindow::on_tabWidget_currentChanged(int index)
{
    QSqlQueryModel * model = new QSqlQueryModel();
    QSqlQuery query;

    qDebug() << index;

    if(index == 0)
    {
        query.prepare("SELECT * FROM customers");
        query.exec();
        model->setQuery(query);
        ui->AllCustomersTableView->setModel(model);
    } else if (index == 1)
    {
        query.prepare("SELECT name,street,city,state,zipcode,interest,consider FROM customers ORDER BY name ASC");
        query.exec();
        model->setQuery(query);
        ui->listByName->setModel(model);
    }
    else if(index == 2)
    {
        query.prepare("SELECT name,street,city,state,zipcode,interest,consider FROM customers WHERE consider = 'key' or consider = 'Key'");
        query.exec();
        model->setQuery(query);
        ui->listByKey->setModel(model);
    }



}

void MainWindow::on_tabWidget_tabBarClicked(int index)
{
//    QSqlQueryModel * model = new QSqlQueryModel();
//    QSqlQuery query;


//    qDebug() << index;
//    if(index = 0)
//    {
//        query.prepare("SELECT * FROM customers");
//        query.exec();
//    } else if (index = 1)
//    {
//        query.prepare("SELECT name,street,city,state,zipcode,interest,consider FROM customers ORDER BY name ASC");
//        query.exec();
//    }
//    else if(index = 2)
//    {
//        query.prepare("SELECT name,street,city,state,zipcode,interest,consider FROM customers WHERE consider = 'key' or consider = 'Key'");
//        query.exec();
//    }
//    if(index = 0)
//    {
//        model->setQuery(query);
//        ui->AllCustomersTableView->setModel(model);
//    } else if (index = 1)
//    {
//        model->setQuery(query);
//        ui->listByName->setModel(model);
//    }
//    else if(index = 2)
//    {
//        model->setQuery(query);
//        ui->listByKey->setModel(model);
//    }
}

void MainWindow::on_LoadAllCustomers_clicked()
{
    QSqlQueryModel * model = new QSqlQueryModel();
    QSqlQuery query;

    query.prepare("SELECT * FROM customers");
    query.exec();
    model->setQuery(query);
    ui->AllCustomersTableView->setModel(model);
    ui->AllCustomersTableView->resizeColumnsToContents();
}



void MainWindow::on_searchCustomerToUpdate_clicked()
{
    QString name;
    QString street;
    QString city;
    QString state;
    int zipCode;
    QString interest;
    QString consider;

    QSqlQuery query;

    name = ui->updateCustomer_2->text();

    if(DatabaseManager::instance().customerExist(CustomerList(name,street,city,state,zipCode,interest,consider)))
    {
        ui->updateCustomerFound->setText("Customer Found");
    }
    else
    {
        ui->updateCustomerFound->setText("Customer Could Not Be Found");
    }

    query.prepare("SELECT name,street,city,state,zipcode,interest,consider FROM customers WHERE name = :name");
    query.bindValue(":name", name);
    query.bindValue(":street", street);
    query.bindValue(":city", city);
    query.bindValue(":state", state);
    query.bindValue(":zipcode", zipCode);
    query.bindValue(":interest", interest);
    query.bindValue(":consider", consider);
    query.exec();

    while(query.next())
    {
        name = query.value(0).toString();
        street = query.value(1).toString();
        city = query.value(2).toString();
        state = query.value(3).toString();
        zipCode = query.value(4).toInt();
        interest = query.value(5).toString();
        consider = query.value(6).toString();
    }

    int considerIndex = 0;
    int interestIndex = 0;
    if(interest == "Not Interested")
    {
        interestIndex = 1;
    }
    else if(interest == "Somewhat Interested")
    {
        interestIndex = 2;
    }
    else if(interest == "Very Interested")
    {
        interestIndex = 3;
    }

    if(consider == "Key")
    {
        considerIndex = 1;
    }
    else if(consider == "Nice to Have")
    {
        considerIndex = 2;
    }

    ui->cName_2->setText(name);
    ui->cStreet_2->setText(street);
    ui->cCity_2->setText(city);
    ui->cState_2->setText(state);
    ui->cZipCode_2->setValue(zipCode);
    ui->InterestComboBox_2->setCurrentIndex(interestIndex);
    ui->considerationComboBox_2->setCurrentIndex(considerIndex);
}

void MainWindow::on_updateCustomer_Button_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}


void MainWindow::on_updateCustomerDatabase_clicked()
{
    QString name;
    QString street;
    QString city;
    QString state;
    int zipCode;
    QString interest;
    QString consider;

    QSqlQuery query;

    query.prepare("UPDATE customers SET name = :name, street = :street, city = :city, state = :state, zipcode = :zipCode, interest = :interest, consider = :consider WHERE name = :name");
    query.bindValue(":name", ui->cName_2->text());
    query.bindValue(":street", ui->cStreet_2->text());
    query.bindValue(":city", ui->cCity_2->text());
    query.bindValue(":state", ui->cState_2->text());
    query.bindValue(":zipCode", ui->cZipCode_2->value());
    query.bindValue(":interest", ui->InterestComboBox_2->currentText());
    query.bindValue(":consider", ui->considerationComboBox_2->currentText());
    if(query.exec())
    {
        ui->UpdateMessage->setText("Customer Update Success!");
        qDebug() << "Update Success";
    }
    else
    {
        ui->UpdateMessage->setText("Customer Update Failed!");
        qDebug() << "FAILED" << query.lastError();
    }

}



void MainWindow::on_help_exit_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_guarantee_exit_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_review_exit_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_compatability_exit_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_purchase_exit_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
    ui->lineEdit->clear();
    ui->checkBox_Basic->setChecked(0);
    ui->checkBox_Advanced->setChecked(0);
    ui->checkBox_Premium->setChecked(0);
}

void MainWindow::on_intro_exit_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_updateCustomerBackButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_adminExit_Button_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_adminExit_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_loadPurchases_clicked()
{
    QSqlQueryModel * model = new QSqlQueryModel();
    QSqlQuery query;

    query.prepare("SELECT * FROM Purchases");
    query.exec();
    model->setQuery(query);
    ui->listByPurchases->setModel(model);
    ui->listByPurchases->resizeColumnsToContents();
}

void MainWindow::on_reviewBackButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(10);
}

void MainWindow::on_leaveYourReview_clicked()
{
    QString Company;
    QString review;
    QSqlQuery query;

    Company = ui->reviewerName->text();
    review = ui->review->text();

    if(DatabaseManager::instance().purchaseExist(Company))
    {
        if(DatabaseManager::instance().AddPurchase(Company, review))
        {
//            ui->reviewMessage->setText("Review added!");
            QMessageBox::information(this, tr("Review"), tr("Review added!"));
        }
    }
    else
    {
//        ui->reviewMessage->setText("Review Failed To Add since company has not made a purchase");
        QMessageBox::critical(this, tr("Review"), tr("Review Failed To Add since company has not made a purchase!"));
    }
    // add error messsage
}

void MainWindow::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(13);
}

void MainWindow::on_lineEdit_returnPressed()
{
    QSqlQuery query;
    QString name, street, city, state, consider;
    int zipCode;

    name = ui->lineEdit->text();

    if(DatabaseManager::instance().customerExist(CustomerList(name,street,city,state,zipCode,interest,consider))){

        qDebug() << "exist";
    }
    else{
        ui->lineEdit->setText("NOT VALID CUSTOMER");
    }

}

void MainWindow::on_pushButton_purchase_clicked()
{
    QString name, package, street, city, state, consider;
    int zipCode;
    double price;
    QSqlQuery query;
    name = ui->lineEdit->text();


    if(DatabaseManager::instance().customerExist(CustomerList(name,street,city,state,zipCode,interest,consider))){

        if(ui->checkBox_Basic->isChecked() && ui->checkBox_Advanced->isChecked() && ui->checkBox_Premium->isChecked()){
//            ui->lineEdit->setText("SELECT ONE OPTION");
            QMessageBox::critical(this, tr("ERROR"),tr("SELECT ONE OPTION"));
            ui->checkBox_Basic->setChecked(0);
            ui->checkBox_Advanced->setChecked(0);
            ui->checkBox_Premium->setChecked(0);
        }
        else if( (ui->checkBox_Basic->isChecked() && ui->checkBox_Advanced->isChecked() )
                  || ( ui->checkBox_Basic->isChecked() && ui->checkBox_Premium->isChecked() )
                  || ( ui->checkBox_Advanced->isChecked() && ui->checkBox_Premium->isChecked() ) ){

//            ui->lineEdit->setText("SELECT ONE OPTION");
            QMessageBox::critical(this, tr("ERROR"),tr("SELECT ONE OPTION"));
            ui->checkBox_Basic->setChecked(0);
            ui->checkBox_Advanced->setChecked(0);
            ui->checkBox_Premium->setChecked(0);
        }
        else{
            if(ui->checkBox_Basic->isChecked()){
                package = "Basic";
                price = 39.99;
            }
            else if(ui->checkBox_Advanced->isChecked()){
                package = "Advanced";
                price = 79.99;
            }
            else if(ui->checkBox_Premium->isChecked()){
                package = "Premium";
                price = 105.99;
            }

            query.prepare("INSERT INTO Purchases (company, package, price) VALUES (:company, :package, :price)");
            query.bindValue(":company", name);
            query.bindValue(":package", package);
            query.bindValue(":price", price);
            query.next();

            if(query.exec()){

                query.finish();
                qDebug() << "Updating Database";
//                ui->lineEdit->setText("ITEM ADDED");
                QMessageBox::information(this, tr("UPDATE"), tr("ITEM ADDED"));
                ui->checkBox_Basic->setChecked(0);
                ui->checkBox_Advanced->setChecked(0);
                ui->checkBox_Premium->setChecked(0);

            }
            else{
                query.finish();
                qDebug() << "Updating Database";
                query.prepare("UPDATE Purchases SET package = :package, price = :price WHERE company = :company");
                query.bindValue(":company", name);
                query.bindValue(":package", package);
                query.bindValue(":price", price);
                query.exec();
                query.next();
                query.finish();
//                ui->lineEdit->setText("ITEM UPDATED");
                QMessageBox::information(this, tr("UPDATE"), tr("ITEM ADDED"));
                ui->checkBox_Basic->setChecked(0);
                ui->checkBox_Advanced->setChecked(0);
                ui->checkBox_Premium->setChecked(0);
            }
        }
    }
    else{
//        ui->lineEdit->setText("NOT VALID CUSTOMER");
        QMessageBox::critical(this, tr("ERROR"),tr("NOT VALID CUSTOMER"));
        ui->checkBox_Basic->setChecked(0);
        ui->checkBox_Advanced->setChecked(0);
        ui->checkBox_Premium->setChecked(0);
    }
}


void MainWindow::on_CustomerTab_tabBarClicked(int index)
{
    QSqlQueryModel * model = new QSqlQueryModel();
    QSqlQuery query;

    query.prepare("SELECT * FROM customers");
    query.exec();
    model->setQuery(query);
    ui->AllCustomersTableView->setModel(model);

//    query.prepare("SELECT name,street,city,state,zipcode,interest,consider FROM customers ORDER BY name ASC");
//    query.exec();
//    model->setQuery(query);
//    ui->listByName->setModel(model);

//    query.prepare("SELECT name,street,city,state,zipcode,interest,consider FROM customers WHERE consider = 'key' or consider = 'Key'");
//    query.exec();
//    model->setQuery(query);
//    ui->listByKey->setModel(model);
}

void MainWindow::on_requestPamphlet_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
}

void MainWindow::on_introTutorial_clicked()
{
    ui->stackedWidget->setCurrentIndex(7);
}

void MainWindow::on_compatabilityTutorial_clicked()
{
    ui->stackedWidget->setCurrentIndex(9);
}

void MainWindow::on_GuaranteeTutorial_clicked()
{
    ui->stackedWidget->setCurrentIndex(11);
}

void MainWindow::on_purchaseTutorial_clicked()
{
    ui->stackedWidget->setCurrentIndex(8);
}

void MainWindow::on_reviewTutorial_clicked()
{
    ui->stackedWidget->setCurrentIndex(10);
    QSqlQueryModel * model = new QSqlQueryModel();
    QSqlQuery query;

    query.prepare("SELECT Company, review FROM reviews");
    query.exec();

    model->setQuery(query);
    ui->reviewsTable->setModel(model);
    ui->reviewsTable->resizeColumnsToContents();
}

void MainWindow::on_Done_button_clicked()
{
    ui->stackedWidget->setCurrentIndex(12);
}

void MainWindow::on_tutorialPushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(14);
}

void MainWindow::on_SentPamphletPushButton_clicked()
{
    QString name, street, city, state, pamphlet;
    int zipCode;
    QSqlQuery query;

    name     = ui->Pname->  text();
    street   = ui->Pstreet->text();
    city     = ui->Pcity->  text();
    state    = ui->Pstate-> text();
    zipCode  = ui->spinZip->value();
    pamphlet = "Sent";

    if(name == "" || street == "" || city == "" || state == "" || zipCode == 0)
    {
       QMessageBox::critical(this, tr("ERROR"),tr("One or more boxes isn't filled out"));
    }
    else
    {
        QMessageBox::information(this, tr("Success"),tr("Success! Your pamphlet is on the way!"));
        query.prepare("INSERT INTO customers (name, street, city, state, zipcode, pamphlet) VALUES (:name, :street, :city, :state, :zipcode, :pamphlet)");
        query.bindValue(":name", name);
        query.bindValue(":street", street);
        query.bindValue(":city", city);
        query.bindValue(":state", state);
        query.bindValue(":zipcode", zipCode);
        query.bindValue(":pamphlet", pamphlet);
        query.exec();

        ui->Pname->  setText("");
        ui->Pstreet->setText("");
        ui->Pcity->  setText("");
        ui->Pstate-> setText("");
        ui->spinZip->setValue(0);

        ui->stackedWidget->setCurrentIndex(0);
    }
}

void MainWindow::on_Pexit_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}
