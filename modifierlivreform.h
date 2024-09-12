#ifndef MODIFIERLIVREFORM_H
#define MODIFIERLIVREFORM_H

#include <QWidget>

namespace Ui {
class ModifierLivreForm;
}

class ModifierLivreForm : public QWidget
{
    Q_OBJECT

public:
    explicit ModifierLivreForm(QWidget *parent = nullptr);
     ModifierLivreForm(QString titre, QString genre, QString auteur, QString maison_edition, QString proprietes, int quantite, QString armoire, QWidget *parent = nullptr);
    //void setFormValues(QString titre, QString genre, QString auteur, QString maison_edition, QString proprietes, int quantite, QString armoire);
    ~ModifierLivreForm();
 private:
    QString ancienTitre;
 private slots:
    void modifierLivre();
    void annulerModif();
    void comboArmoireAfficher();
    void comboGenreAfficher();

 signals:
    void modifieLivre(const QString &titre, const QString &genre, const QString &auteur,
                       const QString &maisonEdition, const QString &proprietes, int quantite, const QString &armoire);

private:
    Ui::ModifierLivreForm *ui;
};

#endif // MODIFIERLIVREFORM_H
