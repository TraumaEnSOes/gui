#ifndef MAINWIDGET_HPP
#define MAINWIDGET_HPP

#include <QListView>
#include <QTextEdit>
#include <QVBoxLayout>

#include "numkeypad.hpp"

class MainWidget : public QWidget {
  Q_OBJECT

  QVBoxLayout m_vlayout;
  QHBoxLayout m_hlayout;
  QListView m_products;
  QListView m_note;
  QTextEdit m_total;
  NumKeypad m_keypad;

  void connectSignals( );
  static void clearLayout( QLayout *l ) {
    QLayoutItem *child;

    while( ( child = l->takeAt( 0 ) ) ) delete child;
  }

public:
  static constexpr int Key0 = NumKeypad::Key0;

  QChar keypadToQChar( int k ) const { return m_keypad.toQChar( k ); }
  QString keypadToQString( int k) const { return m_keypad.toQString( k ); }
  QStringView keypadToQStringView( int k ) const { return m_keypad.toQStringView( k ); }

  MainWidget( QWidget *parent = nullptr );
  MainWidget( const MainWidget & ) = delete;
  MainWidget( MainWidget && ) = delete;
  MainWidget &operator=( const MainWidget & ) = delete;
  MainWidget &operator=( MainWidget &&) = delete;

public Q_SLOTS:
  void productsAtLeft( );
  void productsAtRight( );

Q_SIGNALS:
  void keypadClicked( int );
};

#endif
