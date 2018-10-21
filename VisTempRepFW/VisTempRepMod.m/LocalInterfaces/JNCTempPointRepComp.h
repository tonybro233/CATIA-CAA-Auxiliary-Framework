
//===================================================================
// COPYRIGHT Tony 2017/04/17
//===================================================================
// JNCTempPointRepComp.cpp
// Header definition of class JNCTempPointRepComp
//===================================================================
//
// Usage notes:
//
//===================================================================
//  2017/04/17 Creation: Code generated by the 3DS wizard
//===================================================================

#ifndef JNCTempPointRepComp_H
#define JNCTempPointRepComp_H

#include "CATModelForRep3D.h"

//Mathematics 
#include "CATMathPoint.h"
#include "CATMathPlane.h"

//VisualizationFoundation 
#include "CATRep.h"
#include "CAT3DPointRep.h"
#include "CAT3DCustomRep.h"

//VisualizationCore
#include "CATSymbolType.h"

//-----------------------------------------------------------------------

class JNCTempPointRepComp: public CATModelForRep3D

{
CATDeclareClass;

public:

	// Standard constructors and destructors
	// -------------------------------------
	JNCTempPointRepComp ();
	virtual ~JNCTempPointRepComp ();


	virtual HRESULT CreateDefaultPoint(CATMathPoint *iOrigin,int color1=0,int color2=255,int color3=0, CATSymbolType SymType = CATSymbolType::CROSS) ;

	virtual HRESULT SetGraphicRepresentation (CATRep *  iRep ) ;

	virtual HRESULT GetGraphicRepresentation (CATRep **  oRep ) ;

	virtual HRESULT GetPoint(CATMathPoint &ioMathPoint) ;


private:
	// Copy constructor and equal operator
	// -----------------------------------
	JNCTempPointRepComp (JNCTempPointRepComp &);
	JNCTempPointRepComp& operator=(JNCTempPointRepComp&);

	CATMathPoint _mathPt;

};

//-----------------------------------------------------------------------

#endif

