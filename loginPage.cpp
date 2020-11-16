#include "loginPage.h"
//#include "ui_loginPage.h"
#include <QMessageBox>
#include "user.h"
#include <QTimer>

LoginPage::LoginPage(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LoginPage)
{
    ui->setupUi(this);

    ui->loginButton->setStyleSheet("background-color: mediumblue; color : white; border-radius : 5px");
    ui->signupButton->setStyleSheet("background-color: mediumblue; color : white; border-radius : 5px");
    ui->usernameInput->setStyleSheet("border-color: black; border-radius : 5px");
    ui->passwordInput->setStyleSheet("border-color: black; border-radius : 5px");
    QTimer::singleShot(0, ui->usernameInput, SLOT(setFocus()));
    //ui->label->setStyleSheet("color : mediumblue");

    QFont font("SimSun", 11, 75);
    ui->label_2->setFont(font);
    ui->label_3->setFont(font);
    ui->loginButton->setFont(font);
    ui->signupButton->setFont(font);
}

LoginPage::~LoginPage()
{
    delete ui;
}

list <User> users;
void LoginPage::on_loginButton_clicked()
{
    QString username = ui->usernameInput->text();
    QString password = ui->passwordInput->text();
    if(username.isEmpty() || password.isEmpty())
    {
        QMessageBox :: information(this, "Login", "Empty username or password");
    }

    else{
        QString username = ui->usernameInput->text();
        QString password = ui->passwordInput->text();
        User currentUser;
        User nullUser;
        bool userExists = false;

        //check if username is registered
        list <User> users;
            for (User i : users) {
                if ((i.getLogin()).getUserName() == username.toStdString()) {
                    userExists = true;	//Validates credentials and assigns instance to correct user
                }
            }

//            //username exists
//            if (userExists == true) {
//                Login enteredCreds = Login(username.toStdString(), password.toStdString());
//                for (User i : users) {
//                    if (i.getLogin() == enteredCreds) {
//                        currentUser = i;	//Validates credentials and assigns instance to correct user
//                    }
//                }
//                if (currentUser == nullUser) {	//incorrect password
//                    cout << "\nIncorrect Password!" << endl;
//                }
//            }

//            while (currentUser != nullUser) {
//                //functionality available to user once logged in
//            }


    }

}

void LoginPage::on_signupButton_clicked()
{
    hide();
    signupPage = new signup(this);
    signupPage->show();
}

void LoginPage::on_usernameInput_returnPressed()
{
    on_loginButton_clicked();
}

void LoginPage::on_passwordInput_returnPressed()
{
    on_loginButton_clicked();
}
