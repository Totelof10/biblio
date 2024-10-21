#ifndef PARAMETRE_H
#define PARAMETRE_H

#include <QWidget>

namespace Ui {
class Parametre;
}

class Parametre : public QWidget
{
    Q_OBJECT

public:
    explicit Parametre(QWidget *parent = nullptr);
    ~Parametre();

private slots:
    void enregistrerParametre();
    void fermerFenetre();
    void reinitialiser();
    void ajustement();

signals:
    void ajoutArmoir();

private:
    Ui::Parametre *ui;
};

#endif // PARAMETRE_H
