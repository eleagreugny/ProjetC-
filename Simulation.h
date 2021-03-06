
#ifndef SIMULATION_H_
#define SIMULATION_H_
#include "Environnement.h"

// ===========================================================================
//                                  Includes
// ===========================================================================
class Simulation{
	public :
   // =========================================================================
  //                               Attribut classe
  // =========================================================================


  // =========================================================================
  //                               Constructors
  // =========================================================================
  Simulation() ;
  Simulation(const Simulation& model) ;
  Simulation(int T,float Ainit, int H, int W, float D);
  // =========================================================================
  //                                Destructor
  // =========================================================================
  ~Simulation();
  // =========================================================================
  //                                  Getters
  // =========================================================================

  // =========================================================================
  //                                  Setters
  // =========================================================================
  inline void set_T(int t) ;
  // =========================================================================
  //                                 Operators
  // =========================================================================

  // =========================================================================
  //                              Public Methods
  // =========================================================================
  int run();


	protected :
  // =========================================================================
  //                             Protected Methods
  // =========================================================================

  // =========================================================================
  //                                Attributes
  // =========================================================================
  int T_ ; //période de simulation
  Environnement* envir_ ;
};
// ===========================================================================
//                            Getters' definitions
// ===========================================================================


// ===========================================================================
//                            Setters' definitions
// ===========================================================================
inline void Simulation::set_T(int t){
  T_ = t ;
}
// ===========================================================================
//                           Operators' definitions
// ===========================================================================

// ===========================================================================
//                        Inline functions' definition
// ===========================================================================


#endif

