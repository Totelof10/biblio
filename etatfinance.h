#ifndef ETATFINANCE_H
#define ETATFINANCE_H

#include <QWidget>



namespace Ui {
class EtatFinance;
}

class EtatFinance : public QWidget
{
    Q_OBJECT

public:
    explicit EtatFinance(QWidget *parent = nullptr);
    ~EtatFinance();

private slots:
    void afficherLesAbonnements();
    void recherche();
    void afficherGraph();
    void somme();
    void sommeParDates();
    void onDateChanged(const QDate &date);
    void clear();
    /*void afficherGraphiqueGlobal();
    void afficherGraphiqueParMois();
    void retour();
    // Dans EtatFinance.h
private:
    QChart *chartGlobal; // Chart pour les abonnements globaux
    QLineSeries *seriesGlobal; // Series pour les montants globaux
    QChart *chartMois; // Chart pour les abonnements par mois
    QBarSeries *seriesMois; // Series pour les montants par mois*/


private:
    Ui::EtatFinance *ui;
};

#endif // ETATFINANCE_H
