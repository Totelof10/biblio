#ifndef AJOUTLIVREFORM_H
#define AJOUTLIVREFORM_H

#include <QWidget>
#include <QDate>

namespace Ui {
class AjoutLivreForm;
}

class AjoutLivreForm : public QWidget
{
    Q_OBJECT

public:
    explicit AjoutLivreForm(QWidget *parent = nullptr);
    ~AjoutLivreForm();

private slots:
    void handleAnnuler();
    void handleAjouterLivre();
    void clearForm();
    void comboArmoireAfficher();
    void comboGenreAfficher();

signals:
    void ajoutLivre();

private:
    Ui::AjoutLivreForm *ui;
};

#endif // AJOUTLIVREFORM_H
