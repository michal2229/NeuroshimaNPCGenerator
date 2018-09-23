﻿#ifndef NPCATTRIBUTEWIDGET_H
#define NPCATTRIBUTEWIDGET_H

#include <QWidget>

#include <QLabel>
#include <QPair>
#include <QJsonArray>
#include <QHash>

#include "NPCSkillPackWidget.h"

class NPCAttributeWidget : public QWidget
{
    Q_OBJECT
public:
    explicit NPCAttributeWidget(const QString& name,
                                const QJsonArray &skillPacks,
                                const QVector<QPair<QString, int>> &mods,
                                QWidget *parent = nullptr);
signals:
    void skillPackBougth(const bool &checked, const QStringList &specs);

public slots:

private:
    QWidget *createTitleBar(const QVector<QPair<QString, int>> &mods);
    QWidget *createValueWidget(const QString &name, const int &value);
    void createSkillPackWidget(const QJsonValue &skillPack);

private:
    int m_value{0};
    QLabel* m_pName{nullptr};
    QVector<QLabel*> m_values;
    QHash<const QString&, NPCSkillPackWidget*> m_skillPacks;

    const QString m_nameStyle{ "QLabel#NameStyle{"
                                    " font: bold 15px;"
                                    " padding-right: 5px;"
                                    "}" };
    const QString m_titleStyle{ "QWidget#TitleStyle{"
                           " border: 1px solid;"
                           " background-color: gray;"
                           "}" };
    const QString m_labelStyle{ "QLabel#LabelStyle{"
                                " font: 7px;"
                                " padding-top: 3px;"
                                "}" };
    const QString m_valueStyle{ "QWidget#ValueStyle{"
                               " font: solid 11px;"
                               " border: 1px solid;"
                               " border-radius: 10px;"
                               " background-color: white;"
                               "}" };


};

#endif // NPCATTRIBUTEWIDGET_H