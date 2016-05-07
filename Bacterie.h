
#ifndef BACTERIE_H_
#define BACTERIE_H_
#include <iostream>
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
  static float RAA ;
  static float RAB ;
  static float RBB ;
  static float RBC ;
  //probabilités de mort et de mutation
  static float Pdeath ;
  static float Pmut ;
  //fitness minimum
  static float WMIN ;


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
  inline void set_A(float a);
  inline void set_B(float b);
  inline void set_C(float c);
  // =========================================================================
  //                                 Operators
  // =========================================================================

  // =========================================================================
  //                              Public Methods
  // =========================================================================
  bool death() ;
  void mutation() ;
  void fitness();
  void metabolisme(float& Aout, float& Bout);

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

inline void Bacterie::set_A(float a){
  A_ = a ;
}

inline void Bacterie::set_B(float b){
  B_ = b ;
}

inline void Bacterie::set_C(float c){
  C_ = c ;
}
// ===========================================================================
//                           Operators' definitions
// ===========================================================================

// ===========================================================================
//                        Inline functions' definition
// ===========================================================================


#endif
