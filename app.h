#ifndef APP_H
#define APP_H

#include <QWidget>

namespace Ui {
class App;
}

class App : public QWidget
{
    Q_OBJECT

public:
    explicit App(QWidget *parent = nullptr);
    ~App();

private slots:
    void handleAccueil();
    void handleLivre();
    void handleMembre();
    void handleEmprunt();
    void handleEtudiant();
    void handleAdulte();
    void handleAfficherAjoutLivreForm();
    void afficherLivreDansTableau();
    void supprimerLivre();

private:
    Ui::App *ui;
};

#endif // APP_H
