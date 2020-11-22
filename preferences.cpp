#include "preferences.h"
#include "ui_preferences.h"
#include "address.h"
#include "location.h"

#include <QCheckBox>
#include <QMessageBox>

Preferences::Preferences(QWidget *parent):
    QMainWindow(parent),
    ui(new Ui::Preferences)
{
    ui->setupUi(this);
}

Preferences::~Preferences()
{
    delete ui;
}

//Preferences::savePreference()
//{
//}

//{
//    delete ui;
//}

//}
