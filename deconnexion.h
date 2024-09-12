#ifndef DECONNEXION_H
#define DECONNEXION_H

#include <QWidget>
#include "app.h"

namespace Ui {
class Deconnexion;
}

class Deconnexion : public QWidget
{
    Q_OBJECT

public:
    explicit Deconnexion(QWidget *parent = nullptr,  App *appWindow = nullptr);
    ~Deconnexion();

private slots:
    void oui();
    void non();
private:
    App *appWindow;  // Pointeur vers la fenêtre App

private:
    Ui::Deconnexion *ui;
};

#endif // DECONNEXION_H
