//===================================================================
// COPYRIGHT Tony 2017/03/24
//===================================================================
// StringEnhancement.cpp
// Header definition of class StringEnhancement
//===================================================================
//
// Usage notes:
//
//===================================================================
//  2017/03/24 Creation: Code generated by the 3DS wizard
//===================================================================

#ifndef StringEnhancement_H
#define StringEnhancement_H

#include "CommonFuncMod.h"

#include <tchar.h>
#include <string>

// System
#include "CATBaseUnknown.h"
#include "CATBaseUnknown_var.h"
#include "CATUnicodeString.h"
#include "CATCollec.h"
#include "CATListOfCATUnicodeString.h"
#include "CATString.h"


namespace JNCTonySpace
{
	/**
	* Convert capital letter to integer. Notice that in this algorithm ,'A' equals to 1 .
	*   @param istrCapitalLetter 
	*      The capital letters to be converted.
	*   @param oDecimal
	*      The output result integer. 
	*   
	*   This method doesn't check the input, please don't input illegal value.
	*/
	ExportedByCommonFuncMod void ConvertCapitalLetterToInt(CATUnicodeString istrCapitalLetter, int &oDecimal);

	/**
	* Convert integer to capital letters. Notice that in this algorithm ,1 equals to 'A' .
	*   @param iDecimal 
	*      The integer to be converted.
	*   @param ostrCapitalLetter
	*      The output string contains result capital letters. 
	*   
	*   Do not input 0, or the method will return without any convertion.
	*/
	ExportedByCommonFuncMod void ConvertIntToCapitalLetter(unsigned int iDecimal, CATUnicodeString &ostrCapitalLetter);

	/**
	* Split a string by given separator, Returns a zero-based, one-dimensional array containing a specified 
	* number of substrings.
	*   @param iString 
	*      String expression containing substrings and Separator. 
	*   @param iSeparator
	*      String character used to identify substring limits.
	*	@param oStrList
	*	   The list contains result substrings.
	*	@return
	*   <dl>
	*   <dt><tt>S_OK</tt>          <dd>if split succeeds.
	*   <dt><tt>E_FAIL</tt>        <dd>if not find the separator in input string.
	*   </dl>
	*
	* <b>Role</b>: The input list will be cleared at first. If split failed, the list will contain the input
	*              string.
	*/
	ExportedByCommonFuncMod HRESULT SplitString(CATUnicodeString iString, CATUnicodeString iSeparator, CATListOfCATUnicodeString &oStrList);

	/**
	* Convert CATUnicodeString to std::wstring 
	*   @param iString :  String to be convert.  
	*/
	ExportedByCommonFuncMod std::wstring ConvertToWideString(CATUnicodeString iString);
};

//-----------------------------------------------------------------------

#endif
