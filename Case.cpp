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
  if (model.bact_ != nullptr){
    bact_ = new Bacterie(*(model.bact_));
  } else {
    bact_ = nullptr ;
  }
}

Case::Case(float Ainit){
  A_ = Ainit ;
  B_ = 0 ;
  C_ = 0 ;
  bact_ = nullptr ;
}

Case::Case(float Ainit,char G,int x, int y){
  A_ = Ainit ;
  B_ = 0 ;
  C_ = 0 ;
  bact_ = new Bacterie(x,y,G) ;
}
// ===========================================================================
//                                 Destructor
// ===========================================================================
Case::~Case(){
  delete bact_ ;
}
// ===========================================================================
//                               Public Methods
// ===========================================================================
void Case::reset(float Ainit){
  A_ = Ainit ;
  B_ = 0 ;
  C_ = 0 ;
}

bool Case::is_empty(){
  bool empty = false ;
  if (bact_ == nullptr){
    empty = true ;
  }
  return empty ;
}

void Case::metabolisme_bact(){
  if(bact_ != nullptr){
    (*bact_).metabolisme(A_,B_) ;
  }
}

void Case::set_bact(int x, int y, char G){
  delete bact_ ;
  bact_ = new Bacterie(x,y,G) ;
}

void Case::kill(){
  bool dead = bact_->death();
  if(dead){
    A_ = A_ + bact_->A() ;
    B_ = B_ + bact_->B() ;
    C_ = C_ + bact_->C() ;
    delete bact_ ;
    bact_ = nullptr ;
  }
}
// ===========================================================================
//                              Protected Methods
// ===========================================================================
