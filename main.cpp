#include "Bacterie.h"
#include "Environnement.h"
#include "Simulation.h"
#include <iostream>
#include <ctime>
#include <cstdlib>

int main(){
  
  srand(time(0)) ;
  Bacterie b1 ;
  Bacterie b2(2,3,'A') ;
  std :: cout << b2.G() << std :: endl ;
  //float r = (float) rand()/(RAND_MAX+1.0) ;
  //std :: cout << r << std :: endl ;
  b2.set_div(true);
  bool d = b2.death() ;
  return 0 ;
}
