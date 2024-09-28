#ifndef CONTROLUNIT_H
#define CONTROLUNIT_H

#include <QObject>
#include <vector>
#include "coin.h"

class ControlUnit : public QObject
{
    Q_OBJECT

    std::vector<Coin> coins;

public:
    ControlUnit(QObject *parent = nullptr): QObject(parent) {}
public slots:
    void updateCoins();
};
#endif // CONTROLUNIT_H
