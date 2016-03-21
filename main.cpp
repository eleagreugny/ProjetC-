#include "Bacterie.h"
#include "Environnement.h"
#include "Simulation.h"
#include "Case.h"
#include <iostream>
#include <ctime>
#include <cstdlib>

int main(){
  
  srand(time(0)) ;
  Bacterie b1 ;
  Bacterie b2(2,3,'A') ;
  std :: cout << b2.G() << std :: endl ;
  std :: cout <<b2.A()<<" "<<b2.B()<<" "<< b2.C() << std :: endl ;
  Bacterie b3(1,1,'B') ;
  std :: cout << b3.G() << std :: endl ;
  std :: cout << b3.A()<<" "<< b3.B()<<" "<< b3.C() << std :: endl ;
  float Aout = 5.0 ;
  float Bout = 5.0 ;
  b2.metabolisme(Aout,Bout) ;
  std :: cout << b2.A()<<" "<<b2.B()<<" "<< b2.C() << std :: endl ;
  std :: cout << Aout <<" "<< Bout << std :: endl ;
  b3.metabolisme(Aout,Bout) ;
  std :: cout << b3.A() <<" "<< b3.B() <<" "<< b3.C() << std :: endl ;
  std :: cout << Aout <<" "<< Bout << std :: endl ;
  
  //float r = (float) rand()/(RAND_MAX+1.0) ;
  //std :: cout << r << std :: endl ;
  //b2.set_div(true);
  //bool d = b2.death() ;
  //b2.mutation() ;
  Case C1 ;
  std :: cout << C1.is_empty() << std :: endl ;
  Case C2(3.0, &b2) ;
  std :: cout << C2.is_empty() << std :: endl ;
  std :: cout << C2.A() << std :: endl ;
  C2.reset(10) ;
  std :: cout << C2.A() << std :: endl ;
  
  return 0 ;
}
