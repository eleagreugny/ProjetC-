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
  grille_ = new Case**[H_] ;
  for (int i=0 ; i<H_ ; i++){
    grille_[i] = new Case*[W_] ;
  }
  for(int x=0 ; x<H_ ; x++){
    for(int y=0 ; y<W_ ; y++){
      grille_[x][y]= new Case(*(model.grille_[x][y])) ;
    }
  }
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

void Environnement::diffusion(){
  //on crée un nouveau tableau comme copie de l'instant t
  Case*** Oldgrille = new Case**[H_];
  for (int i=0 ; i<H_ ; i++){
    Oldgrille[i] = new Case*[W_] ;
  }
  for(int x=0 ; x<H_ ; x++){
    for(int y=0 ; y<W_ ; y++){
      Oldgrille[x][y]= new Case(*(grille_[x][y])) ;
    }
  }
  for(int x=0 ; x<H_ ; x++){
    for(int y=0 ; y<W_ ; y++){

      for(int i=-1 ; i<= 1 ; i++){
        for(int j=-1 ; j<=1 ; j++){
          int xf = x + i ;
          int yf = y + j ;
          //conditions thoriques
          if(xf >= H_){
            xf = 0 ;
          }
          if(xf < 0){
            xf = H_ -1 ;
          }
          if(yf >= W_){
            yf = 0 ;
          }
          if(yf < 0){
            yf = W_ -1 ;
          }
          grille_[x][y]->set_A(grille_[x][y]->A()+D_*Oldgrille[xf][yf]->A());
          grille_[x][y]->set_B(grille_[x][y]->B()+D_*Oldgrille[xf][yf]->B());
          grille_[x][y]->set_C(grille_[x][y]->C()+D_*Oldgrille[xf][yf]->C());
        }
      }

    }
  }

  for(int x=0 ; x<H_ ; x++){
    for(int y=0 ; y<W_ ; y++){
      grille_[x][y]->set_A(grille_[x][y]->A()-9*D_*Oldgrille[x][y]->A());
      grille_[x][y]->set_B(grille_[x][y]->B()-9*D_*Oldgrille[x][y]->B());
      grille_[x][y]->set_C(grille_[x][y]->C()-9*D_*Oldgrille[x][y]->C());
    }
  }

  for(int i =0 ; i<H_ ; i++){
    for(int j=0 ; j<W_ ; j++){
      delete Oldgrille[i][j] ;
    }
		delete[] Oldgrille[i] ;
	}
	delete[] Oldgrille ;
}

void Environnement::death_G(){
  for(int x=0 ; x<H_ ; x++){
    for(int y=0 ; y<W_ ; y++){
      if(!(grille_[x][y]->is_empty())){
        grille_[x][y]->kill();
      }
    }
  }
}

void Environnement::division(){
  std::vector<int> gap ;

  for(int x=0 ; x<H_ ; x++){
    for(int y=0 ; y<W_ ; y++){
      if(grille_[x][y]->is_empty()){
        gap.push_back(x * W_ + y) ;
        /* ici on transforme les coordonnées 2D en 1D pour pouvoir
         * les stocker simplement dans la liste.
         */
      }
    }
  }
  
  random_shuffle(gap.begin() , gap.end()) ;
  
  while(!(gap.empty())){
    //on récupère les coordonnées 2D du gap
    int c = gap.back();
    gap.pop_back() ;
    int x = c/W_ ;
    int y = c%W_ ;
    float wmax = Bacterie::WMIN ;
    /* plus grande fitness dans le voisinage du gap
     * en l'initialisant à WMIN, permet que les bact avec une fitness 
     * inférieure ne se divisent pas.
     */
    std::vector<int> winners ;
    /*liste de la ou des cases possédant la bactérie avec
     * la plus grande fitness.
     * même transfortmation des coordonnées que précédemment
     */
     for(int i=-1 ; i<= 1 ; i++){
        for(int j=-1 ; j<=1 ; j++){
          if(i!=0 && j!=0){
            int xf = x + i ;
            int yf = y + j ;
            //conditions thoriques
            if(xf >= H_){
              xf = 0 ;
            }
            if(xf < 0){
              xf = H_ -1 ;
            }
            if(yf >= W_){
              yf = 0 ;
            }
            if(yf < 0){
              yf = W_ -1 ;
            }
            if(!(grille_[xf][yf]->is_empty())){
              if((grille_[xf][yf]->bact())->w() >= wmax){
                if(!((grille_[xf][yf]->bact())->div())){
                  winners.push_back(xf * W_ + yf) ;
                  wmax = (grille_[xf][yf]->bact())->w() ;
                }
              }
            }
          }
        }
      }
      
      if(!(winners.empty())){
        random_shuffle(winners.begin() , winners.end());
        int d = winners.front() ;
        int xW = d/W_ ;
        int yW = d%W_ ;
        Case* Boss = grille_[xW][yW] ;
        //ajout de la bactérie fille au niveau du gap
        grille_[x][y]->set_bact(x,y,Boss->bact()->G());
        /*on set les concentrations de la fille sur la moitié
         * des concentrations de la mère.
         */ 
        (grille_[x][y]->bact())->set_A((Boss->bact())->A()/2);
        (grille_[x][y]->bact())->set_B((Boss->bact())->B()/2);
        (grille_[x][y]->bact())->set_C((Boss->bact())->C()/2);
        /* on diminue de moitié les concentrations de la mère
         */
        (Boss->bact())->set_A((Boss->bact())->A() /2) ;
        (Boss->bact())->set_B((Boss->bact())->B() /2) ;
        (Boss->bact())->set_C((Boss->bact())->C() /2) ;
        
        //on fait muter les deux cellules filles
        (grille_[x][y]->bact())->mutation() ;
        (Boss->bact())->mutation() ;
        
        //on met les booléens div des bactéries à true
        (grille_[x][y]->bact())->set_div(true);
        (Boss->bact())->set_div(true) ;
      }
  }
  
  //on remet les booléens div de toutes les bactéries à false
  for(int x=0 ; x<H_ ; x++){
    for(int y=0 ; y<W_ ; y++){
      if(!(grille_[x][y]->is_empty())){
        (grille_[x][y]->bact())->set_div(false);
      }
    }
  }
  
   
}

//fait métaboliser toutes les bactéries vivantes
void Environnement::developpement(){
  for(int x=0 ; x<H_ ; x++){
    for(int y=0 ; y<W_ ; y++){
      if(!(grille_[x][y]->is_empty())){
        grille_[x][y]->metabolisme_bact() ;
      }
    }
  }
}

void Environnement::changement_milieu() {
  for(int x=0 ; x<H_ ; x++){
    for(int y=0 ; y<W_ ; y++){
      grille_[x][y]->reset(Ainit_) ;
    }
  }
}

/* stocke dans un fichier l'etat de l'environnement :
 * 0 si mort , 1 si A, 2 si B
 */
void Environnement::etat_milieu(){
  std::ofstream f("simulation.txt", std::ios::out | std::ios::trunc) ;
  for(int x=0 ; x<H_ ; x++){
    for(int y=0 ; y<W_ ; y++){
      f << x << " " << y << " ";
      if(grille_[x][y]->is_empty()){
        f << 0 << std::endl ;
      } else {
        if(grille_[x][y]->bact()->G() == 'A'){
          f << 1 << std::endl ;
        } else {
          f << 2 << std::endl ;
        }
      }
    }
  }
  f.close() ; 
}


// ===========================================================================
//                              Protected Methods
// ===========================================================================


