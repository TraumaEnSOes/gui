#include <QDebug>

#include "mainwindow.hpp"

MainWindow::MainWindow( Application *app, QWidget *parent ) : QMainWindow( parent ), m_app( app ) {
  setWindowTitle( "NO funciona" );
  setCentralWidget( &m_mainWidget );

  // Conectamos las señales.
  connect( &m_mainWidget, &MainWidget::keypadClicked, this, &MainWindow::onKeypadClick );
}

MainWindow::~MainWindow( ) {

}

void MainWindow::onKeypadClick( int key ) {
  qDebug( ) << "Keypad code: " << key << ", char: " << m_mainWidget.keypadToQChar( key ) << '\n';
}
