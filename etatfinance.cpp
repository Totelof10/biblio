#include "etatfinance.h"
#include "ui_etatfinance.h"

EtatFinance::EtatFinance(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::EtatFinance)
{
    ui->setupUi(this);
}

EtatFinance::~EtatFinance()
{
    delete ui;
}
