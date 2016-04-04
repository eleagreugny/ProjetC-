// ===========================================================================
//                                  Includes
// ===========================================================================
#include "Simulation.h"


// ===========================================================================
//                       Definition of static attributes
// ===========================================================================

// ===========================================================================
//                                Constructors
// ===========================================================================
Simulation::Simulation(){
  T_ = 0 ;
  envir_ = nullptr;
}

Simulation::Simulation(const Simulation& model){
  T_ = model.T_ ;
  envir_ = new Environnement(*(model.envir_)) ;
}

Simulation::Simulation(int T,float Ainit, int H, int W, float D){
  T_ = T ;
  envir_ = new Environnement(Ainit,H,W,D);
}

// ===========================================================================
//                                 Destructor
// ===========================================================================
Simulation::~Simulation(){
  delete envir_ ;
}
// ===========================================================================
//                               Public Methods
// ===========================================================================

/* enchainement des étapes
 * renvoie 1 si extinction, 2 si cohabitation
 * 3 si exclusion.
 */
int Simulation::run(){
  for(int i=0 ; i<10000 ; i++){
    if(i%T_ == 0){
      envir_-> changement_milieu() ;
    }
    envir_ -> diffusion() ;
    envir_ -> death_G() ;
    envir_ -> division() ;
    envir_ -> developpement() ;
  }
  int r = envir_->etat_milieu() ;
  return r ;
}

// ===========================================================================
//                              Protected Methods
// ===========================================================================


