#ifndef HISTORIQUE_H
#define HISTORIQUE_H

#include <QWidget>

namespace Ui {
class Historique;
}

class Historique : public QWidget
{
    Q_OBJECT

public:
    explicit Historique(QWidget *parent = nullptr);
    ~Historique();

private slots:
    void afficherHistoriqueEmprunt();
    void rechercheHistoriqueEmprunt();
    void viderHistorique();

private:
    Ui::Historique *ui;
};

#endif // HISTORIQUE_H
