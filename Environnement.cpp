// ===========================================================================
//                                  Includes
// ===========================================================================
#include "Environnement.h"


// ===========================================================================
//                       Definition of static attributes
// ===========================================================================

// ===========================================================================
//                                Constructors
// ===========================================================================
Environnement::Environnement(){
  Ainit_ = 0 ;
  H_ = 0 ;
  W_ = 0 ;
  D_ = 0 ;
  grille_ = nullptr ;
}

Environnement::Environnement(const Environnement& model){
  Ainit_ = model.Ainit_ ;
  H_ = model.H_ ;
  W_ = model.W_ ;
  D_ = model.D_ ;
  grille_ = model.grille_ ;
}

Environnement::Environnement(float Ainit,int H, int W, float D){
  Ainit_ = Ainit ;
  H_ = H ;
  W_ = W ;
  D_ = D ;
  grille_ = new Case**[H_];
  for (int i=0 ; i<H_ ; i++){
    grille_[i] = new Case*[W_] ;
  }
  for(int x=0 ; x<H_ ; x++){
    for(int y=0 ; y<W_ ; y++){
      grille_[x][y]= new Case(Ainit_) ;
    }
  }
  
  int N = H_ * W_ ; //nb total de bacteries
  int nA = N/2 ; //nb de bacteries A restant à créer
  int nB = N/2 ; //nb de bacteries B restant à créer
  
  for(int x=0 ; x<H_ ; x++){
    for(int y=0 ; y<W_ ; y++){
      if(nA*nB != 0){
        float r = (float) rand() / RAND_MAX ;
        if(r<0.5){
          (grille_[x][y])->set_bact(x,y,'A');
          nA--;
        } else {
          (grille_[x][y])->set_bact(x,y,'B');
          nB--;          
        }
      } else {
        if(nA != 0){
          (grille_[x][y])->set_bact(x,y,'A');
          nA--;
        } else {
          (grille_[x][y])->set_bact(x,y,'B');
          nB--;
        }
      }
    }
  }
  
}
// ===========================================================================
//                                 Destructor
// ===========================================================================
Environnement::~Environnement(){
  for(int i =0 ; i<H_ ; i++){
    for(int j=0 ; j<W_ ; j++){
      delete grille_[i][j] ;
    }
		delete[] grille_[i] ;
	}
	delete[] grille_ ; //supprime les Cases
}
// ===========================================================================
//                               Public Methods
// ===========================================================================

 


// ===========================================================================
//                              Protected Methods
// ===========================================================================


