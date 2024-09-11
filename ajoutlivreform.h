#ifndef AJOUTLIVREFORM_H
#define AJOUTLIVREFORM_H

#include <QWidget>

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

private:
    Ui::AjoutLivreForm *ui;
};

#endif // AJOUTLIVREFORM_H
