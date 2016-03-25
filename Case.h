
#ifndef CASE_H_
#define CASE_H_
#include <iostream>
#include <cstdlib>
#include "Bacterie.h"
// ===========================================================================
//                                  Includes
// ===========================================================================
class Case{
	public :
    friend void Bacterie::metabolisme(float& Aout, float& Bout);
   // =========================================================================
  //                               Attribut classe
  // =========================================================================

  
  // =========================================================================
  //                               Constructors
  // =========================================================================
  Case();
  Case(const Case& model);
  Case(float Ainit) ;
  Case(float Ainit,char G, int x, int y) ;
  // =========================================================================
  //                                Destructor
  // =========================================================================
  ~Case();
  // =========================================================================
  //                                  Getters
  // =========================================================================
  inline float A() const;
  inline float B() const;
  inline float C() const;
  inline Bacterie* bact() const;
  // =========================================================================
  //                                  Setters
  // =========================================================================
  void set_bact(int x, int y, char G);
  inline void set_A(float a) ;
  inline void set_B(float b) ;
  inline void set_C(float c) ;
  // =========================================================================
  //                                 Operators
  // =========================================================================

  // =========================================================================
  //                              Public Methods
  // =========================================================================
	void reset(float Ainit) ;
  bool is_empty() ;
  void metabolisme_bact();
	protected :
  // =========================================================================
  //                             Protected Methods
  // =========================================================================

  // =========================================================================
  //                                Attributes
  // =========================================================================
  float A_ ;
  float B_ ;
  float C_ ;
  Bacterie* bact_ ;
};
// ===========================================================================
//                            Getters' definitions
// ===========================================================================
inline float Case::A() const{
  return A_ ;
}

inline float Case::B() const{
  return B_ ;
}

inline float Case::C() const{
  return C_ ;
}

inline Bacterie* Case::bact() const{
  return bact_ ;
}

inline void Case::set_A(float a) {
  A_ = a ;
}

inline void Case::set_B(float b) {
  B_ = b ;
}

inline void Case::set_C(float c) {
  C_ = c ;
}

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
