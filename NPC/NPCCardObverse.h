﻿#ifndef NPCCARDOBVERSE_H
#define NPCCARDOBVERSE_H

#include <QWidget>

#include <QHash>
#include <QJsonArray>
#include <QJsonObject>
#include <QListWidgetItem>

#include "Widgets/NPCAttributesModsInfoWidget.h"

class QComboBox;
class QDialog;
class QLabel;
class QLineEdit;
class QPushButton;
class QVBoxLayout;

class NPCAttributeView;
class NPCAttributeWidget;
class NPCOtherSkillsView;
class NPCSkillpackView;
class NPCReputationView;

class NPCCardObverse : public QWidget
{
    Q_OBJECT
public:
    explicit NPCCardObverse(QWidget *parent = nullptr);

    const QHash<QString, NPCAttributeView *> *attributes() const;

    QPixmap portrait() const;
    const QString heroName() const;
    const QString origin() const;
    const QString profession() const;
    const QString specialization() const;
    const QString sickness() const;
    const QString originFeature() const;
    const QString professionFeature() const;
    const QString originFeatureDescription() const;
    const QString professionFeatureDescription() const;
    NPCReputationView *reputation() const;

    const QListWidget *tricks() const;
    NPCOtherSkillsView *otherSkills();

public slots:
    void setName(const QString &name);
    void setPortrait(const QPixmap portrait);
    void setOrigin(const QString &name);
    void setOriginFeature(const QString &name, const QString &description);
    void setProfession(const QString &name);
    void setProfessionFeature(const QString &name, const QString &description);
    void setSpecialization(const QString &spec);
    void setAttributeModValue(const QString &name, const int &value);
    void setAttribute(const QString &name, const int &value);
    void setTricks(QVector<QListWidgetItem*> tricks);
    void setSickness(const QString &name, const QString &description);
    void setSkill(const QString &attribute,
                  const QString &skillpack,
                  const QString &skill,
                  const int &value);
    void setOtherSkill(const QString &name,
                       const QString &attribute,
                       const int &value);
    void setOriginBonus(const QString &bonus);
    void setProfessionBonus(const QString &bonus);

private:
    QLabel *createSpecialLabel(const QString &text,
                               const QString &objName = "",
                               const QString &style = "",
                               const int &width = 0,
                               const int &heigth = 0,
                               Qt::Alignment aligment = Qt::AlignHCenter);
    QWidget *createPersonalSection();

    NPCSkillpackView *createSkillPack(const QJsonObject &skillPack);

    void setAttributes(const QJsonArray &attributes);

    void updateBonusLabel();

    QDialog *createReputationDialog();

    QVBoxLayout *column1();
    QVBoxLayout *column2();
    QVBoxLayout *column3();
    QVBoxLayout *column4();

private:
    // Personal Section Variables
    QLabel *m_pPortrait{nullptr};
    QLineEdit *m_pName{nullptr};
    QLineEdit *m_pOrigin{nullptr};
    QLineEdit *m_pProfession{nullptr};
    QLineEdit *m_pSpecialization{nullptr};
    QLineEdit *m_pSickness{nullptr};
    QLineEdit *m_pOriginFeature{nullptr};
    QLineEdit *m_pProfessionFeature{nullptr};
    QPushButton *m_pReputation{nullptr};
    QLabel *m_pFame{nullptr};
    QLabel *m_pBonus{nullptr};

    QString m_originBonus;
    QString m_professionBonus;

    QString m_originFeatureDescription;
    QString m_professionFeaturesDescription;

    // Others widgets
    QListWidget *m_pTricks{nullptr};
    NPCAttributesModsInfoWidget *m_pAttributesModsInfo{nullptr};
    NPCOtherSkillsView *m_pOtherSkills{nullptr};
    NPCReputationView *m_pReputationView{nullptr};

    QDialog *m_pReputationDialog{nullptr};

    // Data containers
    QHash<QString, NPCAttributeView*> m_attributes{};
    QJsonArray m_attributesMods;

    // Data
    const QVector<QPair<QString, int>> m_mods{
        QPair<QString, int>("Łat.", 2),
        QPair<QString, int>("Prze.", 0),
        QPair<QString, int>("Prob.", -2),
        QPair<QString, int>("Trud.", -5),
        QPair<QString, int>("B.Tr.", -8),
        QPair<QString, int>("Ch.T.", -11),
        QPair<QString, int>("Fuks", -15)
    };

    // Styles
    const QString m_titleStyle{
        "QLabel#Title{"
        " padding: 5px;"
        " background-color: black;"
        " color: white;"
        " border-radius: 5px;"
        " font: 20px;"
        "}"
    };

    const QString m_bonusLabel {
        "QLabel#Bonus{"
        " border: 1px solid black;"
        " border-radius: 5px;"
        " padding: 5px;"
        "}"
    };
};

#endif // NPCCARDOBVERSE_H
