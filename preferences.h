#ifndef PREFERENCES_H
#define PREFERENCES_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Preferences; }
QT_END_NAMESPACE

class Preferences : public QMainWindow
{
    Q_OBJECT

public:
    Preferences(QWidget *parent = nullptr);
    ~Preferences();
    void savePreferences();
    void displayLocations();

private:
    Ui::Preferences *ui;

// slots for all user criteria
private slots:
    void on_savePreferences_clicked(); // save button (click)
    void on_powerCheck_isChecked(); // power (check box)
    void on_outsideCheck_isChecked(); // outside (check box)
    void on_internetCheck_isChecked(); // internet (check box)
    void on_equipmentCheck_isChecked(); // equipment (check box)
    void on_volumeCheck_valueChanged(); // volume level (1-10 level) (spin box)
    void on_maxDistance_valueChanged(); // max distance (1-30 km) (spin box)
};

#endif // PREFERENCES_H
