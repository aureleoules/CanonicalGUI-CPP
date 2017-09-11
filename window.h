#ifndef WINDOW_H
#define WINDOW_H

#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QFormLayout>
#include <QVBoxLayout>
#include <QMessageBox>
#include <QDoubleValidator>

class Window : public QWidget {

    Q_OBJECT

    public:
        Window();

    public slots:
        void submitForm();
        void handleAChange(QString a);
        void handleBChange(QString b);
        void handleCChange(QString c);
    private:
        QPushButton *submitButton;
        QFormLayout *layout;
        QVBoxLayout *mainLayout;
        QLineEdit *a;
        QLineEdit *b;
        QLineEdit *c;
};

#endif // WINDOW_H
