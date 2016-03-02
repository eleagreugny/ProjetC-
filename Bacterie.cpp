// ===========================================================================
//                                  Includes
// ===========================================================================
#include "Bacterie.h"


// ===========================================================================
//                       Definition of static attributes
// ===========================================================================
const float Bacterie::RAA = 0.1 ;
const float Bacterie::RAB = 0.1 ;
const float Bacterie::RBB = 0.1 ;
const float Bacterie::RBC = 0.1 ;

const float Bacterie::Pdeath = 0.02 ;
const float Bacterie::Pmut = 0 ;

const float Bacterie::WMIN = 0.001 ;
// ===========================================================================
//                                Constructors
// ===========================================================================
Bacterie::Bacterie(){
  x_ = 0 ;
  y_ = 0 ;
  G_ = '\0';
  A_ = 0 ;
  B_ = 0 ;
  C_ = 0 ;
  w_ = 0 ;
  div_ = false ;
}

Bacterie::Bacterie(const Bacterie& model){
  x_ = model.x_ ;
  y_ = model.y_ ;
  G_ = model.G_ ;
  A_ = model.A_ ;
  B_ = model.B_ ;
  C_ = model.C_ ;
  w_ = model.w_ ;
  div_ = model.div_ ;  
}

Bacterie::Bacterie(int x, int y, char G){
  x_ = x ;
  y_ = y ;
  G_ = G ;
  A_ = 0 ;
  B_ = 0 ;
  C_ = 0 ;
  w_ = 0 ;
  div_ = false ;
}
// ===========================================================================
//                                 Destructor
// ===========================================================================

// ===========================================================================
//                               Public Methods
// ===========================================================================
/* fait mourir la bactérie selon le résultat du tirage et retourne 
 * un booléen qui signale si la bactérie est morte ou non
 */
bool Bacterie::death(){
  bool dead = false ;
  float p = (float) rand()/(RAND_MAX+1.0) ;
  if(p <= Pdeath){
    dead = true ;
  }
  return dead ;
}

/* fait muter la bactérie selon le résultat du tirage et change la 
 * fitness si nécessaire
 */
/*void Bacterie::mutation(){
  float p = (float) rand()/(RAND_MAX+1.0) ;
  if (p <= Pmut){
    if(G_ == 'A'){
      G_ = 'B' ;
    } else {
      G_ = 'A' ;
    }
    fitness();
  }
}*/


// ===========================================================================
//                              Protected Methods
// ===========================================================================

