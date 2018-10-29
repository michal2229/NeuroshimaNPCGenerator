﻿#ifndef NPCTRICKMANAGERDIALOG_H
#define NPCTRICKMANAGERDIALOG_H

#include <QDialog>
#include <QListWidget>
#include <QJsonArray>

#include "../Widgets/NPCAttributeWidget.h"
#include "../Widgets/NPCTrickWdgetItem.h"

class NPCTrickManagerDialog : public QDialog
{
public:
    NPCTrickManagerDialog(const QHash<QString, NPCAttributeWidget *> *attributes,
                          QWidget *parent = nullptr);

public slots:
    void distributeTricks();

private:
    void addTricks(const QJsonArray &tricks);



    bool isTrickAvailable(const NPCTrickWdgetItem *pItem) const;

private:
    const QHash<QString, NPCAttributeWidget*> *m_pAttributes;
    QListWidget *m_pAvailable{nullptr};
    QListWidget *m_pUnavailable{nullptr};
    QListWidget *m_pBougth{nullptr};

    QVector<NPCTrickWdgetItem*> m_allTricks;
};

#endif // NPCTRICKMANAGERDIALOG_H