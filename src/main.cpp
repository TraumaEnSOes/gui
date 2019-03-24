#include "mainwindow.hpp"
#include "testwindow.hpp"

#include "application.hpp"

int main( int argc, char *argv[] ) {
  Application app( argc, argv );
  MainWindow mainWindow( &app );
  TestWindow test;

  mainWindow.show( );
  test.show( );

  return app.exec( );
}
