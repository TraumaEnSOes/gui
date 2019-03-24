#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include <QApplication>

class Application : public QApplication {
public:
  Application( int &argc, char **argv ) : QApplication( argc, argv ) { }
};

#endif
