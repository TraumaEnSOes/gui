#include "mainwidget.hpp"

MainWidget::MainWidget( QWidget *parent ) : QWidget( parent ) {
  // Añadimos los widgets al layout vertical.
  m_vlayout.addWidget( &m_note );
  m_vlayout.addWidget( &m_total );
  m_vlayout.addWidget( &m_keypad );

  // Conectamos las señales de nuestros widgets internos.
  connectSignals( );

  // Finalmente, establecemos el layout horizontal como el principal.
  setLayout( &m_hlayout );

  // De momento, colocamos los productos a la izquierda.
  productsAtLeft( );
}

void MainWidget::connectSignals( ) {
  connect( &m_keypad, &NumKeypad::clicked, this, &MainWidget::keypadClicked );
}

void MainWidget::productsAtLeft( ) {
  setUpdatesEnabled( false );

  if( m_hlayout.count( ) ) {
    clearLayout( &m_hlayout );
  }

  m_hlayout.addWidget( &m_products );
  m_hlayout.addLayout( &m_vlayout );

  setUpdatesEnabled( true );
}

void MainWidget::productsAtRight( ) {
  setUpdatesEnabled( false );

  if( m_hlayout.count( ) ) {
    clearLayout( &m_hlayout );
  }

  m_hlayout.addLayout( &m_vlayout );
  m_hlayout.addWidget( &m_products );

  setUpdatesEnabled( true );
}
