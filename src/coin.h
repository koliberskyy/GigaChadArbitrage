#ifndef COIN_H
#define COIN_H
#include <QString>
#include <unordered_map>
#include <QDateTime>
#include <memory>
#include <QJsonObject>
class Coin {

    QString name;
    std::shared_ptr<Coin> usdt;
    std::unordered_map<QString, double> price_usdt;
    std::unordered_map<QString, double> price_rub;
    std::unordered_map<QString, double> volume;
    std::unordered_map<QString, double> comission;
    std::vector<QString> avaibleMarkets;

public:
    Coin(std::shared_ptr<Coin> __usdt): ustd{__usdt}{}
    QJsonObject toJson() const;

    const double get_price(QString __market) const;
    const double get_bestPrice() const;
    const double get_worstPrice() const;

    void setPriceUsdt(double __price, QString __market);
    void setVolume(double __volume, QString __market);
    void setComission(double __comission, QString __market);
    void addAvaibleMarket(QString __market);
    void removeAvaibleMarket(QString __market);

private:

};

#endif // COIN_H
