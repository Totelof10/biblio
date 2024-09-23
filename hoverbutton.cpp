#include "hoverbutton.h"
#include <QPropertyAnimation>

HoverButton::HoverButton(QWidget *parent) : QPushButton(parent)
{
    // Initialisation si nécessaire
}

void HoverButton::enterEvent(QEnterEvent *event)
{
    animateColor("lightgray", "lightblue");
    QPushButton::enterEvent(event);  // Appelle la méthode parente
}

void HoverButton::leaveEvent(QEvent *event)
{
    animateColor("lightblue", "lightgray");
    QPushButton::leaveEvent(event);  // Appelle la méthode parente
}

void HoverButton::animateColor(const QString &startColor, const QString &endColor)
{
    QPropertyAnimation *colorAnimation = new QPropertyAnimation(this, "styleSheet");
    colorAnimation->setDuration(300);
    colorAnimation->setStartValue(QString("background-color: %1;").arg(startColor));
    colorAnimation->setEndValue(QString("background-color: %1;").arg(endColor));
    colorAnimation->start(QAbstractAnimation::DeleteWhenStopped);
}
