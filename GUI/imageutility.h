#ifndef IMAGEUTILITY_H
#define IMAGEUTILITY_H

#include <QPixmap>
#include<iostream>

class imageUtility
{
public:
    imageUtility();
    static std::string getRawData(const QImage&);
    static QPixmap getImage(const std::string&);
};

#endif // IMAGEUTILITY_H
