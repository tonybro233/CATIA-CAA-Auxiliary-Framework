//===================================================================
// COPYRIGHT Tony 2017/03/28
//===================================================================
// JNCTempTextRepComp.cpp
// Header definition of class JNCTempTextRepComp
//===================================================================
//
// Usage notes:
//
//===================================================================
//  2017/03/28 Creation: Code generated by the 3DS wizard
//===================================================================
#include <iostream>
using std::cout;
using std::endl;
#include "JNCTempTextRepComp.h"

CATImplementClass(JNCTempTextRepComp,Implementation,CATModelForRep3D,CATNull);

#include "TIE_JNCITempTextRep.h"
TIE_JNCITempTextRep(JNCTempTextRepComp);


//-----------------------------------------------------------------------------
// JNCTempTextRepComp : constructor
//-----------------------------------------------------------------------------
JNCTempTextRepComp::JNCTempTextRepComp():CATModelForRep3D()
{
}

//-----------------------------------------------------------------------------
// JNCTempTextRepComp : destructor
//-----------------------------------------------------------------------------
JNCTempTextRepComp::~JNCTempTextRepComp()
{
}


//------------------------------------
//	JNCITempTextRep
//------------------------------------
HRESULT JNCTempTextRepComp::CreateDefaultTypeText(CATMathPoint iOrigin,CATUnicodeString  strText) 
{
	HRESULT rc=E_FAIL;
	_mathPt = iOrigin;
	_strText = strText;

	CAT3DCustomRep * pRepForCenter = CAT3DCustomRep::CreateRep();

	CATMathPointf mathPoint(_mathPt); 
	CAT3DAnnotationTextGP * text = new CAT3DAnnotationTextGP(mathPoint, _strText, BOTTOM_LEFT,600,0);

	//set color
	CATGraphicAttributeSet attGP;
	attGP.SetColor(GREEN);
	attGP.SetColorRGBA(0,255,0);
	attGP.SetThickness(4);

	//add graphic primitive
	pRepForCenter->AddGP(text,attGP);

	SetGraphicRepresentation(pRepForCenter);
	return S_OK ;
} 

HRESULT JNCTempTextRepComp::SetGraphicRepresentation (CATRep *  iRep )
{
	SetRep(iRep);
	return S_OK ;
} 

HRESULT JNCTempTextRepComp::GetGraphicRepresentation (CATRep **  oRep) 
{
	(*oRep) = GiveRep();
	return S_OK;
} 

HRESULT JNCTempTextRepComp::GetInformation(CATMathPoint& oOrigin,CATUnicodeString& strText ) 
{
	oOrigin = _mathPt;
	strText = _strText;
	return S_OK;
} 






