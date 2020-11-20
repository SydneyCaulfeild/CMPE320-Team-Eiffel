#ifndef LOGINPAGE_H
#define LOGINPAGE_H

#include <QMainWindow>
#include "login.h"
#include "signup.h"
#include "ui_loginPage.h"

QT_BEGIN_NAMESPACE
namespace Ui { class LoginPage; }
QT_END_NAMESPACE

class LoginPage : public QMainWindow
{
    Q_OBJECT

public:
    LoginPage(QWidget *parent = nullptr);
    ~LoginPage();
    signup *signupPage; //New dialog for signup

private slots:
    void on_loginButton_clicked();

    void on_signupButton_clicked();

    void on_usernameInput_returnPressed();

    void on_passwordInput_returnPressed();

private:
    Ui::LoginPage *ui;

};
#endif // LOGINPAGE_H
