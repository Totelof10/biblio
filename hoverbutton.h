#ifndef HOVERBUTTON_H
#define HOVERBUTTON_H

#include <QPushButton>

class HoverButton : public QPushButton
{
    Q_OBJECT

public:
    explicit HoverButton(QWidget *parent = nullptr);

protected:
    void enterEvent(QEnterEvent *event) override;
    void leaveEvent(QEvent *event) override;

private:
    void animateColor(const QString &startColor, const QString &endColor);
};

#endif // HOVERBUTTON_H
