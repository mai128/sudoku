#include "drawborderdelegate.h"
#include <QPainter>


DrawBorderDelegate::DrawBorderDelegate(QObject *parent) :
    QStyledItemDelegate(parent)
{
}

void DrawBorderDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    const QRect rect(option.rect);
   // painter->drawLine(rect.topLeft(), rect.topRight());

    if((index.column()%3)==0){
      painter->drawLine(rect.bottomLeft(), rect.topLeft());
    }
    if((index.row()%3)==0){
      painter->drawLine(rect.topLeft(), rect.topRight());
    }
    /*
    painter->drawLine(rect.bottomLeft(), rect.bottomRight());
    painter->drawLine(rect.bottomRight(), rect.topRight());
    */

    /*
    if(index.column()==0){
        painter->drawLine(rect.topRight(),rect.bottomRight());
    }

    if(index.column()== index.model()->columnCount()-1){
        painter->drawLine(rect.topRight(),rect.bottomRight());
    }*/
    QStyledItemDelegate::paint(painter,option,index);
}
