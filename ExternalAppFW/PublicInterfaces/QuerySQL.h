//===================================================================
// COPYRIGHT Tony 2016/11/21
//===================================================================
// QuerySQL.cpp
// Header definition of class QuerySQL
//===================================================================
//
// Usage notes:
//
//===================================================================
//  2016/11/21 Creation: Code generated by the 3DS wizard
//===================================================================

#ifndef QuerySQL_H
#define QuerySQL_H

#include "SQLHandler.h"

// connetction for sql-server
#import "C:\Program Files\Common Files\System\ado\msado15.dll" no_namespace rename("EOF","adoEOF") rename ("BOF","adoBOF")

#define SQLConnectionString  (_bstr_t)"Provider=SQLOLEDB;Server=yourServer;DataBase=yourDatabase;uid=yourUid;pwd=yourPassword;"

#include <vector>
using std::vector;
// System
#include "CATBaseUnknown.h"
#include "CATUnicodeString.h"
#include "CATSysBoolean.h"

//-----------------------------------------------------------------------
/**
* Excute a SQL string command  without quering result.
* @param strSQLCmdText
*   The input command string with SQL language.
*	@return
*   <dl>
*   <dt><tt>S_OK</tt>          <dd>if Excuting succeeds.
*   <dt><tt>E_FAIL</tt>        <dd>if ERROR happened.
*   </dl>
*/
ExportedBySQLHandler HRESULT ExecuteSQLCommand(const CATUnicodeString &strSQLCmdText);

/**
* Excute a SQL string command and put the quering result into double dimension string vector.
*   @param strSQLCmdText 
*      The input command string(SQL).
*   @param strVv
*      The input double dimension string vector. 
*   *<Role>*
*   the double dimension vector will be cleared and filled with quering result. 
*	@param strTitle
*   The string vector of colum title, the result will only contain the given titles' data.
*	Pay attention to the relation between command string and titles.
*	@return
*   <dl>
*   <dt><tt>S_OK</tt>          <dd>if Excuting succeeds.
*   <dt><tt>E_FAIL</tt>        <dd>if ERROR happened.
*   </dl>
*/
ExportedBySQLHandler HRESULT ExecuteSQLCommand(const CATUnicodeString &strSQLCmdText, vector<vector<CATUnicodeString>> &strVv, vector<CATUnicodeString> &strTitle);

//-----------------------------------------------------------------------

#endif
