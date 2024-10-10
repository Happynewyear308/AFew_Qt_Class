#include "iconbutton.h"
#include <QDebug>

IconButton::IconButton(QWidget *parent)
    :QPushButton(parent){
    // 设置初始图标
//    setIcon(QIcon(":/image/show_label.png"));
//    setFixedSize(parent->width(), parent->height());  // 设置图标大小
    ischecked = true;
}

IconButton::~IconButton() {

}

void IconButton::mousePressEvent(QMouseEvent *event) {
    if(event->button() == Qt::LeftButton) {
        ischecked = !ischecked;
        updateIcon();
        emit checked(ischecked);
    } else if(event->button() == Qt::RightButton) {
        emit clicked_right();
    }
}

void IconButton::updateIcon() {
    if(ischecked) {
        setIcon(pixmap_checked);
    }
    else {
        setIcon(pixmap_unchecked);
    }
}

void IconButton::setChecked(bool check) {
    ischecked = check;
    updateIcon();
}

void IconButton::setCheckIcon(QIcon checkedIcon, QIcon uncheckedIcon) {
    pixmap_checked = checkedIcon;
    pixmap_unchecked = uncheckedIcon;
}

bool IconButton::getIsChecked() {
    return ischecked;
}
