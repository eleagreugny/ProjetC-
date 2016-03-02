#include "Bacterie.h"
#include "Environnement.h"
#include "Simulation.h"
#include <iostream>

int main(){
  
  Bacterie b1 ;
  Bacterie b2(2,3,'A') ;
  std :: cout << b2.G() << std :: endl ;
  b2.set_div(true);
  return 0 ;
}
