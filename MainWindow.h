﻿#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidget>
#include <QAction>
#include <QMenu>

#include "NPC/NPCCard.h"
#include "NPC/NPCCardTab.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void updateTabText(const QString &text);
    void onCardClose(const int &index);
    void saveCard();
    void addCard(NPCCardTab *card);
    void createNewCard();

private:
    void createActions();
    void createMenus();

private:
    QTabWidget* m_pTabWidget{nullptr};
    QVector<NPCCardTab*> m_cards;

    QMenu *m_pHeroMenu{nullptr};
    QMenu *m_pChooseMenu{nullptr};
    QMenu *m_pRandomMenu{nullptr};
    QMenu *m_pGameMasterMenu{nullptr};
    QMenu *m_pCreationMenu{nullptr};

    QAction *m_pNewCardAction{nullptr};
    QAction *m_pSaveCardAction{nullptr};
    QAction *m_pLoadCardAction{nullptr};
    QAction *m_pRandomAttributesAction{nullptr};
    QAction *m_pRandomSicknessAction{nullptr};
    QAction *m_pTrickAction{nullptr};
    QAction *m_pExperienceAction{nullptr};
    QAction *m_pChooseOriginAction{nullptr};
    QAction *m_pChooseProfessionAction{nullptr};

};

#endif // MAINWINDOW_H
