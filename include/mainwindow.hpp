#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QListView>
#include <QTextEdit>
#include <QMainWindow>

#include "mainwidget.hpp"
#include "application.hpp"

class MainWindow : public QMainWindow {
  Q_OBJECT

  Application *m_app;
  MainWidget m_mainWidget;

public:
  MainWindow( Application *app, QWidget *parent = 0 );
  ~MainWindow( );

public Q_SLOTS:
  void onKeypadClick( int );
};

#endif
