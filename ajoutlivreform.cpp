#include "ajoutlivreform.h"
#include "ui_ajoutlivreform.h"

AjoutLivreForm::AjoutLivreForm(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::AjoutLivreForm)
{
    ui->setupUi(this);
    connect(ui->btnAnnuler, &QPushButton::clicked, this, &AjoutLivreForm::handleAnnuler);
}

AjoutLivreForm::~AjoutLivreForm()
{
    delete ui;
}

void AjoutLivreForm::handleAnnuler(){
    this->close();
}
