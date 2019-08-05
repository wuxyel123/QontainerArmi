#include "imageutility.h"
#include <QBuffer>
#include <QByteArray>

imageUtility::imageUtility(){}

std::string imageUtility::getRawData(const QImage &q)
{
    QByteArray byteArray;
    QBuffer buffer(&byteArray);
    q.save(&buffer, "PNG");

    return QString(byteArray.toBase64()).toStdString();
}

QPixmap imageUtility::getImage(const std::string &i)
{
    QImage* image= new QImage;
    QByteArray array= QByteArray(i.data());
    image->loadFromData(QByteArray::fromBase64(array), "PNG");

    QPixmap p=QPixmap::fromImage(*image);
    return p.scaled(500,600,Qt::AspectRatioMode::KeepAspectRatio);
}
