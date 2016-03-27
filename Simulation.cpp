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
  envir_ = new Environnement(*(model.envir_))
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




// ===========================================================================
//                              Protected Methods
// ===========================================================================


