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

private:
    Ui::EtatFinance *ui;
};

#endif // ETATFINANCE_H
