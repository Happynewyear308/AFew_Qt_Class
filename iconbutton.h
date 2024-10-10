#ifndef IconButton_H
#define IconButton_H

#include <QPushButton>
#include <QIcon>
#include <QMouseEvent>

class IconButton : public QPushButton
{
    Q_OBJECT
public:
    IconButton(QWidget *parent = nullptr);
    ~IconButton();

    void setChecked(bool check);
    void setCheckIcon(QIcon checkedIcon, QIcon uncheckedIcon);
    void updateIcon();
    bool getIsChecked();

protected:
    void mousePressEvent(QMouseEvent *event) override;

private:
    bool ischecked;
    QIcon pixmap_checked;
    QIcon pixmap_unchecked;
signals:
    void checked(bool check);
    void clicked_right();
};

#endif // IconButton_H
