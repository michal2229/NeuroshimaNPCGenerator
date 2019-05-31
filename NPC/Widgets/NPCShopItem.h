#ifndef NPCSHOPITEM_H
#define NPCSHOPITEM_H

#include "NPCCustomWidget.h"

#include <QJsonObject>

class QFrame;
class QGridLayout;
class QLabel;
class QPushButton;

class NPCShopItem : public NPCCustomWidget
{
public:
    NPCShopItem(const QJsonObject &item, QWidget *parent = nullptr);

private:
    void handWeaponLayout();

    void addRequirements();
    void addDamage();
    void addPenetration();
    void addSpecial();
    void addDescription();
    void addAvailability();

private:
    QJsonObject m_item;
    QGridLayout *m_pLayout{nullptr};
    QLabel *m_pName{nullptr};
    QLabel *m_pPrice{nullptr};
    QFrame *m_pLine{nullptr};
    QPushButton *m_pBuyBtn{nullptr};

    int m_row{0};

    const QString m_nameStyle{
        "QLabel#Name{"
        " font: 11 bold;"
        "}"
    };
};

#endif // NPCSHOPITEM_H