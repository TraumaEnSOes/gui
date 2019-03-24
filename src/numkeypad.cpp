#include "numkeypad.hpp"

NumKeypad::NumKeypad( const QStringView &symbols, QWidget *parent ) : QWidget( parent ) {
  for( int idx = 0; idx < 12; ++idx ) {
    // Creamos el botón.
    m_buttons[idx] = new QPushButton( QString( symbols[idx] ), this );
    m_buttons[idx]->setSizePolicy( QSizePolicy( QSizePolicy::Ignored, QSizePolicy::Ignored ) );

    // Mapeamos las señales.
    connect( m_buttons[idx], &QPushButton::clicked, [ this, idx ]( ) { clicked( idx ); } );

    // Copiamos el símbolo.
    m_symbols[idx] = symbols.at( idx );
  }

  // Colocamos los botones en su sitio.
  m_layout->addWidget( m_buttons[7], 0, 0 );
  m_layout->addWidget( m_buttons[8], 0, 1 );
  m_layout->addWidget( m_buttons[9], 0, 2 );
  m_layout->addWidget( m_buttons[4], 1, 0 );
  m_layout->addWidget( m_buttons[5], 1, 1 );
  m_layout->addWidget( m_buttons[6], 1, 2 );
  m_layout->addWidget( m_buttons[1], 2, 0 );
  m_layout->addWidget( m_buttons[2], 2, 1 );
  m_layout->addWidget( m_buttons[3], 2, 2 );
  m_layout->addWidget( m_buttons[10], 3, 0 );
  m_layout->addWidget( m_buttons[0], 3, 1 );
  m_layout->addWidget( m_buttons[11], 3, 2 );

  // Establecemos nuestro layout como el que hay que usar.
  setLayout( m_layout );

  setVisible( true );
}
