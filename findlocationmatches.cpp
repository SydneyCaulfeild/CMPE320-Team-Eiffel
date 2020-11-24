#include "findlocationmatches.h"
#include "ui_findlocationmatches.h"
#include "login.h"
#include "user.h"
#include "address.h"
#include "initialize.h"
#include "loginPage.h"


#include <QMessageBox>
#include <QFile>
#include <QObject>
#include <QFileDialog>



findLocationMatches::findLocationMatches(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::findLocationMatches)
{
    ui->setupUi(this);

    QFont font("Times New Roman", 11, 75);
    ui->label->setFont(font);
    ui->label_2->setFont(font);
    ui->label_3->setFont(font);
    ui->label_4->setFont(font);
    ui->label_5->setFont(font);
    ui->label_6->setFont(font);
    ui->label_7->setFont(font);
    ui->label_8->setFont(font);
    ui->label_9->setFont(font);
    ui->wifi->setFont(font);
    ui->power->setFont(font);
    ui->equipment->setFont(font);
    ui->volumeLevel->setFont(font);
    ui->InOrOut->setFont(font);
    ui->closeProgram->setFont(font);
    ui->findMatches->setFont(font);
    ui->logout->setFont(font);

    // fill in inOrOut combobox
    ui->InOrOut->addItem("Indoor");
    ui->InOrOut->addItem("Outdoor");
    ui->InOrOut->addItem("Either");

    //fill in volume level
    for (int i = 1; i <= 10; i++) {
        QString s = QString::number(i);
        ui->volumeLevel->addItem(s);
    }

}

findLocationMatches::~findLocationMatches()
{
    delete ui;
}

list<Location> createValidList(list<Location> allLocations, User u) { //function to return a list of valid locations for a given user u
    list<Location> validLocations;
    for (std::list<Location>::iterator it = allLocations.begin(); it != allLocations.end(); ++it) { //iterate through all locations
        //Location loc(it);
        if ((*it).checkPreferences(u) == true)
            validLocations.push_back(*it);
    }
    return validLocations;
}

void findLocationMatches::on_findMatches_clicked()
{

    QString longitude = ui->longitude->text();
    float longit = longitude.toFloat();
    QString latitude = ui->latitude->text();
    float lat = latitude.toFloat();
    QString addressName = ui->addressName->text();
    std::string addressStr = addressName.toStdString();
    Address userAddress(longit, lat, addressStr);

    int vol = ui->volumeLevel->currentIndex();
    vol++;  //the value is one more than the index
    int inOrOutIndex = ui->InOrOut->currentIndex();
    string inOrOut;
    if (inOrOutIndex == 0) {
        inOrOut = "inside";
    }
    else if (inOrOutIndex == 1) {
        inOrOut = "outside";
    }
    else {
        inOrOut = "either";
    }

    QString maxDistance = ui->maxDistance->text();
    double maxTravelDistance = maxDistance.toDouble();

    bool wifi, power, equipment;
    if (ui->wifi->isChecked()) {
        wifi = true;
    }
    else {
        wifi = false;
    }
    if (ui->power->isChecked()) {
        power = true;
    }
    else {
        power = false;
    }
    if (ui->equipment->isChecked()) {
        equipment = true;
    }
    else{
        equipment = false;
    }

    User currentUser(vol, userAddress, inOrOut, wifi, power, equipment, maxTravelDistance, Login("randomusername", "randompassword"));

    Initialize initialize;
    list <Location> allLocations; //list of all locations
    list <Location> validLocations; //list of locations that meet the user specified criteria


//    string s = "/kingstonStudySpots.txt";
//    int n = s.length();

//        // declaring character array
//        char char_array[n + 1];

//        // copying the contents of the
//        // string to char array
//        strcpy(char_array, s.c_str());

    allLocations = initialize.createList("./kingstonStudySpots.txt"); //return a list of all locations (reading data from input file)
    validLocations = createValidList(allLocations, currentUser); //return a list of all locations that meet the preference criteria

    if (validLocations.size() == 0) {
        ui->output->append("Sorry, no locations with these requirements were found within your max distance.");
    }
    else {
        ui->output->append("Here are the names of the locations that meet your requirements:\n");
        for (Location loc : validLocations) {
            string outputMessage = loc.getLocation().getAddressName();
            QString qstr = QString::fromStdString(outputMessage);
            ui->output->append(qstr);
        }
    }
}

void findLocationMatches::on_logout_clicked()
{
    //make user log out, or does this happen already?
    hide();
    LoginPage *loginPage = new LoginPage(this);
    loginPage->show();
}
