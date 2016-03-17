
#ifndef CASE_H_
#define CASE_H_
#include <cstdlib>
#include "Bacterie.h"
// ===========================================================================
//                                  Includes
// ===========================================================================
class Case{
	public :
   // =========================================================================
  //                               Attribut classe
  // =========================================================================

  
  // =========================================================================
  //                               Constructors
  // =========================================================================
  Case();
  Case(const Case& model);
  Case(float Ainit,Bacterie* b) ;
  // =========================================================================
  //                                Destructor
  // =========================================================================
  ~Case() = default;
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
  inline void set_bact(Bacterie* b);
  // =========================================================================
  //                                 Operators
  // =========================================================================

  // =========================================================================
  //                              Public Methods
  // =========================================================================
	void reset(float Ainit) ;
  void metabolisme() ;
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
