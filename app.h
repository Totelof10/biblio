#ifndef APP_H
#define APP_H

#include <QWidget>
#include <QSqlError>
#include <QFile>
#include<QTextStream>
#include<QFileDialog>


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
    void handleAfficherAjoutLivreForm();
    void afficherLivreDansTableau();
    void supprimerLivre();
    void afficherFormulaireModif();
    void rechercheDeLivre();
    void filtreArmoire();
    void filtreGenre();
    void handleAfficheParam();
    void comboArmoireAfficher();
    void importerCsv();
    //Gestion Membre
    void enregistrerMembre();
    void afficherMembreDansTableau();
    void ajoutBtnTableau();
    void supprimerMembre(int row);
    void clearForm();
    void modifierDates(int row);
    void rechercheMembres();
    void comboBoxEmprunt();
    void filtrageComboMembre();
    void filtrageComboLivre();
    void ajoutEmprunt();
    void ajoutBtnTableauEmprunt();
    void clearFormEmprunt();
    void afficherEmprunt();
    void supprimerEmprunt(int row);
signals:
    void ajoutMemebre();
private:
    Ui::App *ui;
};

#endif // APP_H
