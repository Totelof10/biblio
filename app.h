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

public:
    void mettreAJourLigne(int ligne, const QString &titre, const QString &genre, const QString &auteur,
                          const QString &maisonEdition, const QString &proprietes, int quantite, const QString &armoire);

private slots:
    //Auth
    void deconnexion();
    //Gestion Livres
    void handleAccueil();
    void handleLivre();
    void handleMembre();
    void handleEmprunt();
    void handleEtudiant();
    void handleAdulte();
    void handleAfficherAjoutLivreForm();
    void afficherLivreDansTableau();
    void supprimerLivre();
    void afficherFormulaireModif();
    void rechercheDeLivre();
    void filtreArmoire();
    void filtreGenre();
    void handleAfficheParam();
    void comboArmoireAfficher();

    //Gestion Membre
private:
    Ui::App *ui;
};

#endif // APP_H
