/********************************************************************************
** Form generated from reading UI file 'files_search.ui'
**
** Created by: Qt User Interface Compiler version 5.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FILES_SEARCH_H
#define UI_FILES_SEARCH_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTreeView>

QT_BEGIN_NAMESPACE

class Ui_Files_search
{
public:
    QTreeView *treeView;
    QPushButton *pushButton;

    void setupUi(QDialog *Files_search)
    {
        if (Files_search->objectName().isEmpty())
            Files_search->setObjectName(QStringLiteral("Files_search"));
        Files_search->resize(577, 464);
        treeView = new QTreeView(Files_search);
        treeView->setObjectName(QStringLiteral("treeView"));
        treeView->setGeometry(QRect(0, 0, 311, 381));
        pushButton = new QPushButton(Files_search);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(410, 160, 93, 28));

        retranslateUi(Files_search);

        QMetaObject::connectSlotsByName(Files_search);
    } // setupUi

    void retranslateUi(QDialog *Files_search)
    {
        Files_search->setWindowTitle(QApplication::translate("Files_search", "Dialog", Q_NULLPTR));
        pushButton->setText(QApplication::translate("Files_search", "PushButton", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Files_search: public Ui_Files_search {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILES_SEARCH_H
