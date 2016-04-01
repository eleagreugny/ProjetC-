
#ifndef ENVIRONNEMENT_H_
#define ENVIRONNEMENT_H_
#include <iostream>
#include <cstdlib>
#include "Case.h"
// ===========================================================================
//                                  Includes
// ===========================================================================
class Environnement{
	public :
   // =========================================================================
  //                               Attribut classe
  // =========================================================================


  // =========================================================================
  //                               Constructors
  // =========================================================================
  Environnement();
  Environnement(const Environnement& model) ;
  Environnement(float Ainit,int H, int W, float D) ;
  // =========================================================================
  //                                Destructor
  // =========================================================================
  ~Environnement();
  // =========================================================================
  //                                  Getters
  // =========================================================================

  // =========================================================================
  //                                  Setters
  // =========================================================================

  // =========================================================================
  //                                 Operators
  // =========================================================================

  // =========================================================================
  //                              Public Methods
  // =========================================================================
  void diffusion() ;
  void death_G() ;
  void division() ;

	protected :
  // =========================================================================
  //                             Protected Methods
  // =========================================================================

  // =========================================================================
  //                                Attributes
  // =========================================================================
  int H_ ; //hauteur (x)
  int W_ ; //largeur (y)
  float D_ ; //constante de diffusion
  Case*** grille_ ;
  float Ainit_ ;
};
// ===========================================================================
//                            Getters' definitions
// ===========================================================================


// ===========================================================================
//                            Setters' definitions
// ===========================================================================

// ===========================================================================
//                           Operators' definitions
// ===========================================================================

// ===========================================================================
//                        Inline functions' definition
// ===========================================================================


#endif

