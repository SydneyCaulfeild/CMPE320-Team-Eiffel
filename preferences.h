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

private:
    Ui::Preferences *ui;
};
#endif // PREFERENCES_H
