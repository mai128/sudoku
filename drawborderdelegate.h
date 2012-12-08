#ifndef DRAWBORDERDELEGATE_H
#define DRAWBORDERDELEGATE_H

#include <QStyledItemDelegate>

class DrawBorderDelegate : public QStyledItemDelegate
{
    Q_OBJECT
public:
    explicit DrawBorderDelegate(QObject *parent = 0);
    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const;
signals:

public slots:

};

#endif // DRAWBORDERDELEGATE_H
