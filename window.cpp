#include "Window.h"
double aValue, bValue, cValue;
Window::Window() : QWidget() {
    this->setMinimumSize(250, 130);

    this->setWindowTitle("Canonical Form");
    QLineEdit* a = new QLineEdit(this);
    QLineEdit* b = new QLineEdit(this);
    QLineEdit* c = new QLineEdit(this);
    a->setValidator(new QDoubleValidator(0, 100, 2, this));
    b->setValidator(new QDoubleValidator(0, 100, 2, this));
    c->setValidator(new QDoubleValidator(0, 100, 2, this));
    QFormLayout* layout = new QFormLayout;
    QVBoxLayout* mainLayout = new QVBoxLayout;
    layout->addRow("Value of a", a);
    layout->addRow("Value of b", b);
    layout->addRow("Value of c", c);

    mainLayout->addLayout(layout);

    QPushButton* submitButton = new QPushButton("Submit");

    mainLayout->addWidget(submitButton);
    this->setLayout(mainLayout);
    QObject::connect(a, SIGNAL(textChanged(QString)), this, SLOT(handleAChange(QString)));
    QObject::connect(b, SIGNAL(textChanged(QString)), this, SLOT(handleBChange(QString)));
    QObject::connect(c, SIGNAL(textChanged(QString)), this, SLOT(handleCChange(QString)));
    QObject::connect(submitButton, SIGNAL(clicked()), this, SLOT(submitForm()));
}

void Window::handleAChange(QString a) {
    bool ok = false;
    aValue = a.toDouble(&ok);
}

void Window::handleBChange(QString b) {
    bool ok = false;
    bValue = b.toDouble(&ok);
}

void Window::handleCChange(QString c) {
    bool ok = false;
    cValue = c.toDouble(&ok);
}

void Window::submitForm() {
    double delta = bValue * bValue - 4 * aValue * cValue;
    QMessageBox::information(this, "Delta", "Δ = " + QString::number(delta));

    double alpha = - bValue / (2 * aValue);
    printf("%d", alpha);
    QMessageBox::information(this, "Alpha", "α = " + QString::number(alpha));

    double beta =  - (bValue * bValue) - (4 * aValue * cValue) / (aValue * aValue);
    QMessageBox::information(this, "Beta", "ß = " + QString::number(beta));

    QString f = QString::number(aValue) + "(x + " + QString::number(bValue) + "/" + QString::number(aValue * 2) + ")² - " + QString::number(delta) + "/" + QString::number(4 * aValue);
    QMessageBox::information(this, "f(x)", "f(x) = " + f);

}
