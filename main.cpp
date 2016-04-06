#include "Bacterie.h"
#include "Environnement.h"
#include "Simulation.h"
#include "Case.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>


void passage(float Amin,float Amax,float Astep,int Tmin,int Tmax,int Tstep){
  std::ofstream f("diagramme.txt", std::ios::out | std::ios::trunc) ;
  float A;
  float T = Tmin ;
  while(T <= Tmax){
    A = Amin ;
    while(A <= Amax){
      Simulation S(T,A,32,32,0.1) ;
      int R = S.run();
      f << T << " "<< A <<" "<< R << std::endl ;
      A += Astep ;
    }
    T += Tstep ;
  }
}
  
int main(){

  srand(time(0)) ;

  /*
  Bacterie b1 ;
  Bacterie b2(2,3,'A') ;
  std :: cout << b2.G() << std :: endl ;
  std :: cout <<b2.A()<<" "<<b2.B()<<" "<< b2.C() << std :: endl ;
  Bacterie b3(1,1,'B') ;
  std :: cout << b3.G() << std :: endl ;
  std :: cout << b3.A()<<" "<< b3.B()<<" "<< b3.C() << std :: endl ;
  */

  /*float Aout = 5.0 ;
  float Bout = 5.0 ;
  b2.metabolisme(Aout,Bout) ;
  std :: cout << b2.A()<<" "<<b2.B()<<" "<< b2.C() << std :: endl ;
  std :: cout << Aout <<" "<< Bout << std :: endl ;
  b3.metabolisme(Aout,Bout) ;
  std :: cout << b3.A() <<" "<< b3.B() <<" "<< b3.C() << std :: endl ;
  std :: cout << Aout <<" "<< Bout << std :: endl ;
  */

  //float r = (float) rand()/(RAND_MAX+1.0) ;
  //std :: cout << r << std :: endl ;
  //b2.set_div(true);
  //bool d = b2.death() ;
  //b2.mutation() ;

  /*Case C1 ;
  std :: cout << C1.is_empty() << std :: endl ;
  Case C2(3.0, 2,4,'A') ;
  std :: cout << C2.is_empty() << std :: endl ;
  std :: cout << C2.A() << std :: endl ;
  C2.metabolisme_bact();
  std :: cout << C2.A() << std :: endl ;
  std :: cout << b2.A()<<" "<<b2.B()<<" "<< b2.C() << std :: endl ;
  */

  //Environnement E;
  //Environnement E2(5.0, 3,3, 0.1) ;
  /*E2.diffusion() ;
  E2.death_G() ;
  E2.division() ;
  E2.developpement() ;
  */
  //Simulation S1(100,20,32,32,0.1);
  //int R = S1.run();
  
  passage(0.0,50.0,1.0,1,100,1) ;
  
  return 0 ;
}
