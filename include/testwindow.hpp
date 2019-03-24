#ifndef TESTWINDOW_HPP
#define TESTWINDOW_HPP

#include <QMainWindow>

#include "numkeypad.hpp"

class TestWindow : public QMainWindow {
  Q_OBJECT

  NumKeypad m_keypad;

public:
  TestWindow( QWidget *parent = nullptr ) : QMainWindow( parent ) {
    setWindowTitle( "SI Funciona" );
    setCentralWidget( &m_keypad );
  }
};

#endif
