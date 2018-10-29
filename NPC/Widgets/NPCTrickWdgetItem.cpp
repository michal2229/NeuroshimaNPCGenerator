﻿#include "NPCTrickWdgetItem.h"

#include <QJsonValue>
#include <QJsonObject>

NPCTrickWdgetItem::NPCTrickWdgetItem(const QString &name,
                                     const QString &description,
                                     const QString &action,
                                     const QJsonArray &attributes,
                                     const QJsonArray &skills, const QJsonArray &orSkills)
    : QListWidgetItem (name),
      m_description(description),
      m_action(action)
{
    for ( const QJsonValue &tAttribute: attributes ) {
        const QJsonObject &attribute = tAttribute.toObject();
        if ( !attribute.isEmpty() )
            m_attributes.insert( attribute.value("name").toString(), attribute.value("value").toInt() );
    }

    for ( const QJsonValue &tSkill: skills ) {
        const QJsonObject &skill = tSkill.toObject();
        if ( !skill.isEmpty() )
            m_skills.insert( skill.value("name").toString(), skill.value("value").toInt() );
    }

    for ( const QJsonValue &tOrSkill: orSkills ) {
        const QJsonObject &skill = tOrSkill.toObject();
        if ( !skill.isEmpty() )
            m_orSkills.insert( skill.value("name").toString(), skill.value("value").toInt() );
    }

    setToolTip( toolTipText() );
}

NPCTrickWdgetItem::NPCTrickWdgetItem(const QString &name,
                                     const QString &description,
                                     const QString &action)
    : QListWidgetItem (name),
      m_description(description),
      m_action(action)
{

}

const QHash<QString, int> *NPCTrickWdgetItem::attributes() const
{
    return &m_attributes;
}

const QHash<QString, int> *NPCTrickWdgetItem::skills() const
{
    return &m_skills;
}

const QHash<QString, int> *NPCTrickWdgetItem::orSkills() const
{
    return &m_orSkills;
}

void NPCTrickWdgetItem::addAttribute(const QString &name, const int &value)
{
    m_attributes.insert( name, value );
}

void NPCTrickWdgetItem::addSkill(const QString &name, const int &value)
{
    m_skills.insert( name, value );
}

void NPCTrickWdgetItem::addOrSkill(const QString &name, const int &value)
{
    m_orSkills.insert( name, value );
}

void NPCTrickWdgetItem::createTooltipText()
{
    setToolTip( toolTipText() );
}

QString NPCTrickWdgetItem::toolTipText() const
{
    QString requirements{""};

    for ( const QString &name: m_attributes.keys() ) {
        requirements = requirements +" "+ name +" "+ QString::number(m_attributes.value(name))+",";
    }

    int skillKeyCount = m_skills.keys().count();
    for ( const QString &name: m_skills.keys() ) {
        requirements = requirements +" "+ name +" "+ QString::number(m_skills.value(name));
        --skillKeyCount;
        if ( 0 < skillKeyCount )
            requirements += ",";
    }

    int keyCount = m_orSkills.keys().count();
    for ( const QString &name: m_orSkills.keys() ) {
        requirements = requirements +" "+ name +" "+ QString::number(m_orSkills.value(name));
        --keyCount;
        if ( 0 < keyCount )
            requirements += " lub ";
    }

    if ( requirements.isEmpty() )
        requirements = "Brak";

    return QString( "<div style=\"width: 200px; word-wrap: break-word;\" align=\"justify\">"
                    "<b>%1</b><br><br>"
                    "<b>Wymagania:</b> %2<br><br>"
                    "<b >Opis:</b> %3<br><br>"
                    "<b>Działanie:</b> %4"
                    "</div>")
            .arg(text())
            .arg(requirements)
            .arg(m_description)
            .arg(m_action);
}
