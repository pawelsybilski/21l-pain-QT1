/********************************************************************************
** Form generated from reading UI file 'modify_dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MODIFY_DIALOG_H
#define UI_MODIFY_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Modyfikacja
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_5;
    QVBoxLayout *verticalLayout;
    QLabel *label_8;
    QSpinBox *spinBox_8;
    QLabel *label_5;
    QSpinBox *spinBox_6;
    QLabel *label_7;
    QSpinBox *spinBox_7;
    QLabel *label_6;
    QSpinBox *spinBox_5;
    QPushButton *pushButton_4;
    QPushButton *pushButton;
    QWidget *layoutWidget_2;
    QVBoxLayout *verticalLayout_6;
    QTextBrowser *textBrowser;

    void setupUi(QDialog *Modyfikacja)
    {
        if (Modyfikacja->objectName().isEmpty())
            Modyfikacja->setObjectName(QStringLiteral("Modyfikacja"));
        Modyfikacja->resize(492, 363);
        layoutWidget = new QWidget(Modyfikacja);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(30, 20, 113, 240));
        verticalLayout_5 = new QVBoxLayout(layoutWidget);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label_8 = new QLabel(layoutWidget);
        label_8->setObjectName(QStringLiteral("label_8"));

        verticalLayout->addWidget(label_8);

        spinBox_8 = new QSpinBox(layoutWidget);
        spinBox_8->setObjectName(QStringLiteral("spinBox_8"));
        spinBox_8->setMinimum(1);
        spinBox_8->setMaximum(30);
        spinBox_8->setSingleStep(1);
        spinBox_8->setValue(1);

        verticalLayout->addWidget(spinBox_8);

        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));

        verticalLayout->addWidget(label_5);

        spinBox_6 = new QSpinBox(layoutWidget);
        spinBox_6->setObjectName(QStringLiteral("spinBox_6"));
        spinBox_6->setMinimum(1);
        spinBox_6->setMaximum(255);
        spinBox_6->setSingleStep(10);

        verticalLayout->addWidget(spinBox_6);

        label_7 = new QLabel(layoutWidget);
        label_7->setObjectName(QStringLiteral("label_7"));

        verticalLayout->addWidget(label_7);

        spinBox_7 = new QSpinBox(layoutWidget);
        spinBox_7->setObjectName(QStringLiteral("spinBox_7"));
        spinBox_7->setMinimum(100);
        spinBox_7->setMaximum(4500);
        spinBox_7->setSingleStep(100);

        verticalLayout->addWidget(spinBox_7);

        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName(QStringLiteral("label_6"));

        verticalLayout->addWidget(label_6);

        spinBox_5 = new QSpinBox(layoutWidget);
        spinBox_5->setObjectName(QStringLiteral("spinBox_5"));
        spinBox_5->setMinimum(100);
        spinBox_5->setMaximum(4500);
        spinBox_5->setSingleStep(100);

        verticalLayout->addWidget(spinBox_5);


        verticalLayout_5->addLayout(verticalLayout);

        pushButton_4 = new QPushButton(layoutWidget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));

        verticalLayout_5->addWidget(pushButton_4);

        pushButton = new QPushButton(Modyfikacja);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(370, 320, 93, 28));
        layoutWidget_2 = new QWidget(Modyfikacja);
        layoutWidget_2->setObjectName(QStringLiteral("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(160, 10, 258, 229));
        verticalLayout_6 = new QVBoxLayout(layoutWidget_2);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        textBrowser = new QTextBrowser(layoutWidget_2);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));

        verticalLayout_6->addWidget(textBrowser);


        retranslateUi(Modyfikacja);

        QMetaObject::connectSlotsByName(Modyfikacja);
    } // setupUi

    void retranslateUi(QDialog *Modyfikacja)
    {
        Modyfikacja->setWindowTitle(QApplication::translate("Modyfikacja", "Dialog", Q_NULLPTR));
        label_8->setText(QApplication::translate("Modyfikacja", "number of element", Q_NULLPTR));
        label_5->setText(QApplication::translate("Modyfikacja", "colour of element", Q_NULLPTR));
        label_7->setText(QApplication::translate("Modyfikacja", "coordinates x", Q_NULLPTR));
        label_6->setText(QApplication::translate("Modyfikacja", "coordinates y", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("Modyfikacja", "modify", Q_NULLPTR));
        pushButton->setText(QApplication::translate("Modyfikacja", "Back", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Modyfikacja: public Ui_Modyfikacja {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODIFY_DIALOG_H
