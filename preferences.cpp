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

Preferences::savePreference()
{
    // get all prefences
    bool power = ui->powerCheck->isChecked();
    bool outside = ui->outsideCheck->isChecked();
    bool internet = ui->internetCheck->isChecked();
    bool equipment = ui->equipmentCheck->isChecked();
    int volume = ui->volumeCheck->value();
    int distance = ui->maxDistance->value();
}

Preferences::displayLocations()
{

}
