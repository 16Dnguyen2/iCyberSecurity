#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCore/QCoreApplication>
#include <QDebug>
#include <iostream>
#include <QtSql>
#include <QtDebug>
#include <QFileInfo>
#include "databasemanager.h"
#include <QApplication>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QTableView>
#include <QDoubleSpinBox>

using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_AddItem_clicked();

    void on_DeleteCustomer_clicked();

    void on_searchCustomer_clicked();

    void on_loadCustomerListByName_clicked();

    void on_loadCustomerListByKey_clicked();

    void on_admin_button_clicked();

    void on_pushButton_login_clicked();

    void on_addDeleteCustomer_Button_clicked();

    void on_addCustomerBackButton_clicked();

    void on_searchCustomerBackButton_3_clicked();

    void on_deleteCustomerBackButton_2_clicked();

    void on_listByKeyBackButton_clicked();

    void on_listByNameBackButton_clicked();

    void on_customerList_Button_clicked();

//    void on_IntersetComboBox_activated(int index);

    void on_InterestComboBox_activated(int index);

    void on_considerationComboBox_activated(int index);

    void on_tabWidget_currentChanged(int index);

    void on_tabWidget_tabBarClicked(int index);

    void on_LoadAllCustomers_clicked();

    void on_AllCustomersBack_clicked();

    void on_searchCustomerToUpdate_clicked();

    void on_updateCustomer_Button_clicked();

    void on_updateCustomerDatabase_clicked();

    void on_intro_clicked();

    void on_purchase_clicked();

    void on_compatability_home_clicked();

    void on_reviews_clicked();

    void on_guarantee_clicked();

    void on_help_clicked();

    void on_help_exit_clicked();

    void on_guarantee_exit_clicked();

    void on_review_exit_clicked();

    void on_compatability_exit_clicked();

    void on_purchase_exit_clicked();

    void on_intro_exit_clicked();

    void on_updateCustomerBackButton_clicked();

    void on_adminExit_Button_clicked();

    void on_adminExit_clicked();

    void on_loadPurchases_clicked();

    void on_reviewBackButton_clicked();

    void on_leaveYourReview_clicked();

    void on_pushButton_clicked();

    void on_lineEdit_returnPressed();

    void on_pushButton_purchase_clicked();

    void on_CustomerTab_tabBarClicked(int index);

    void on_requestPamphlet_clicked();

    void on_introTutorial_clicked();

    void on_compatabilityTutorial_clicked();

    void on_GuaranteeTutorial_clicked();

    void on_purchaseTutorial_clicked();

    void on_reviewTutorial_clicked();

    void on_Done_button_clicked();

    void on_tutorialPushButton_clicked();

    void on_purchaseTableBackButton_clicked();

    void on_loadCustomersByPamplet_clicked();

    void on_CustomerPampletBackButton_clicked();

    void on_SentPamphletPushButton_clicked();

    void on_Pexit_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
