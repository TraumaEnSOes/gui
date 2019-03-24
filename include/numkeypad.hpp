#ifndef NUMKEYPAD_HPP
#define NUMKEYPAD_HPP

#include <QGridLayout>
#include <QPushButton>

class NumKeypad : public QWidget {
  Q_OBJECT

  int m_size = -1;
  QGridLayout *m_layout = new QGridLayout( this );
  QPushButton *m_buttons[12];
  QChar m_symbols[12];

public:
  // Códigos numéricos de la señal 'clicked( int )`.
  static int constexpr Key0 = 0;
  static int constexpr Key1 = 1;
  static int constexpr Key2 = 2;
  static int constexpr Key3 = 3;
  static int constexpr Key4 = 4;
  static int constexpr Key5 = 5;
  static int constexpr Key6 = 6;
  static int constexpr Key7 = 7;
  static int constexpr Key8 = 8;
  static int constexpr Key9 = 9;
  static int constexpr KeySign = 10;
  static int constexpr KeyPoint = 11;

  NumKeypad( const QStringView &symbols, QWidget *parent = nullptr );
  NumKeypad( QWidget *parent = nullptr ) : NumKeypad( QStringView( u"0123456789-." ), parent ) { }

  // Utilidades.
  QChar toQChar( int k ) const {
    return ( ( k < 0) || ( k > 11 ) ) ? QChar( 0 ) : QChar( m_symbols[k] );
  }
  QString toQString( int k) const {
    return ( ( k < 0 ) || ( k > 11 ) ) ? QString( ) : QString( m_symbols[k] );
  }
  QStringView toQStringView( int k ) const {
    return ( ( k < 0 ) || ( k > 11 ) ) ? QStringView( nullptr ) : QStringView( &( m_symbols[k] ), 1 );
  }

  bool minusEnabled( ) const { return m_buttons[KeySign]->isEnabled( ); }
  QSize buttonsSize( ) const { return m_buttons[0]->size( ); }

Q_SIGNALS:
  void clicked( int );

public Q_SLOTS:
  void enableButton( int key, bool state = true ) {
    if( ( key > -1 ) && ( key < 12 ) ) {
      m_buttons[key]->setEnabled( state );
    }
  }
  void disableButton( int key, bool state = true ) {
    if( ( key > -1 ) && ( key < 12 ) ) {
      m_buttons[key]->setEnabled( !state );
    }
  }
};

#endif
