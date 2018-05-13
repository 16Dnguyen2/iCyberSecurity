/********************************************************************************
** Form generated from reading UI file 'customerlisting.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CUSTOMERLISTING_H
#define UI_CUSTOMERLISTING_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_customerListing
{
public:
    QTableWidget *customerTable2;
    QTableView *customerTable;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QPushButton *ViewAllCustomer;
    QPushButton *SortbyName;
    QPushButton *SortbyKey;
    QPushButton *SortbyPamphlet;

    void setupUi(QDialog *customerListing)
    {
        if (customerListing->objectName().isEmpty())
            customerListing->setObjectName(QStringLiteral("customerListing"));
        customerListing->resize(819, 569);
        customerTable2 = new QTableWidget(customerListing);
        customerTable2->setObjectName(QStringLiteral("customerTable2"));
        customerTable2->setGeometry(QRect(60, 110, 631, 391));
        customerTable = new QTableView(customerListing);
        customerTable->setObjectName(QStringLiteral("customerTable"));
        customerTable->setGeometry(QRect(70, 120, 591, 361));
        widget = new QWidget(customerListing);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(60, 80, 631, 25));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        ViewAllCustomer = new QPushButton(widget);
        ViewAllCustomer->setObjectName(QStringLiteral("ViewAllCustomer"));

        horizontalLayout->addWidget(ViewAllCustomer);

        SortbyName = new QPushButton(widget);
        SortbyName->setObjectName(QStringLiteral("SortbyName"));

        horizontalLayout->addWidget(SortbyName);

        SortbyKey = new QPushButton(widget);
        SortbyKey->setObjectName(QStringLiteral("SortbyKey"));

        horizontalLayout->addWidget(SortbyKey);

        SortbyPamphlet = new QPushButton(widget);
        SortbyPamphlet->setObjectName(QStringLiteral("SortbyPamphlet"));

        horizontalLayout->addWidget(SortbyPamphlet);


        retranslateUi(customerListing);

        QMetaObject::connectSlotsByName(customerListing);
    } // setupUi

    void retranslateUi(QDialog *customerListing)
    {
        customerListing->setWindowTitle(QApplication::translate("customerListing", "Dialog", nullptr));
        ViewAllCustomer->setText(QApplication::translate("customerListing", "View All Customers", nullptr));
        SortbyName->setText(QApplication::translate("customerListing", "Sort by Name", nullptr));
        SortbyKey->setText(QApplication::translate("customerListing", "Sort by Key", nullptr));
        SortbyPamphlet->setText(QApplication::translate("customerListing", "Sort by Pamphlet", nullptr));
    } // retranslateUi

};

namespace Ui {
    class customerListing: public Ui_customerListing {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CUSTOMERLISTING_H
