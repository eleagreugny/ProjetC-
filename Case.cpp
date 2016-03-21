// ===========================================================================
//                                  Includes
// ===========================================================================
#include "Case.h"

// ===========================================================================
//                       Definition of static attributes
// ===========================================================================

// ===========================================================================
//                                Constructors
// ===========================================================================
Case::Case(){
  A_ = 0 ;
  B_ = 0 ;
  C_ = 0 ;
  bact_ = nullptr ;
}

Case::Case(const Case& model){
  A_ = model.A_ ;
  B_ = model.B_ ;
  C_ = model.C_ ;
  bact_ = model.bact_ ;
}

Case::Case(float Ainit,Bacterie* b){
  A_ = Ainit ;
  B_ = 0 ;
  C_ = 0 ;
  bact_ = b ;
}
// ===========================================================================
//                                 Destructor
// ===========================================================================

// ===========================================================================
//                               Public Methods
// ===========================================================================
void Case::reset(float Ainit){
  A_ = Ainit ;
  B_ = 0 ;
  C_ = 0 ;
}
// ===========================================================================
//                              Protected Methods
// ===========================================================================
