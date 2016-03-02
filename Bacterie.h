
#ifndef BACTERIE_H_
#define BACTERIE_H_
#include <cstdlib>
// ===========================================================================
//                                  Includes
// ===========================================================================
class Bacterie{
	public :
   // =========================================================================
  //                               Attribut classe
  // =========================================================================
  //taux d'absorption ou de conversion des molécules
  static const float RAA ;
  static const float RAB ;
  static const float RBB ;
  static const float RBC ;
  //probabilités de mort et de mutation
  static const float Pdeath ;
  static const float Pmut ;
  //fitness minimum
  static const float WMIN ;

  
  // =========================================================================
  //                               Constructors
  // =========================================================================
  Bacterie() ;
  Bacterie(const Bacterie& model) ;
  Bacterie(int x , int y, char G) ;
  // =========================================================================
  //                                Destructor
  // =========================================================================
  ~Bacterie() = default ;
  // =========================================================================
  //                                  Getters
  // =========================================================================
  inline int x() const;
  inline int y() const;
  inline char G() const;
  inline float A() const;
  inline float B() const;
  inline float C() const;
  inline float w() const;
  inline bool div() const;
  // =========================================================================
  //                                  Setters
  // =========================================================================
  inline void set_div(bool d);
  // =========================================================================
  //                                 Operators
  // =========================================================================

  // =========================================================================
  //                              Public Methods
  // =========================================================================
  bool death() ;
  //void mutation() ;
  //void fitness();
	
	protected :
  // =========================================================================
  //                             Protected Methods
  // =========================================================================

  // =========================================================================
  //                                Attributes
  // =========================================================================
  //position dans l'environnement
  int x_ ;
  int y_ ;
  //génotype, égal à A ou B
  char G_ ; 
  //concentrations internes
  float A_ ;
  float B_ ;
  float C_ ;
  //fitness
  float w_ ;
  //booléen pour savoir si la bactérie s'est déjà divisée ou non
  bool div_ ;
  
};
// ===========================================================================
//                            Getters' definitions
// ===========================================================================
inline int Bacterie::x() const{
  return x_ ;
}

inline int Bacterie::y() const{
  return y_ ;
}

inline char Bacterie::G() const{
  return G_ ;
}

inline float Bacterie::A() const{
  return A_ ;
}

inline float Bacterie::B() const{
  return B_ ;
}

inline float Bacterie::C() const{
  return C_ ;
}

inline float Bacterie::w() const{
  return w_ ;
}

inline bool Bacterie::div() const{
  return div_ ;
}
// ===========================================================================
//                            Setters' definitions
// ===========================================================================
inline void Bacterie::set_div(bool d){
  div_ = d ;
}
// ===========================================================================
//                           Operators' definitions
// ===========================================================================

// ===========================================================================
//                        Inline functions' definition
// ===========================================================================


#endif
