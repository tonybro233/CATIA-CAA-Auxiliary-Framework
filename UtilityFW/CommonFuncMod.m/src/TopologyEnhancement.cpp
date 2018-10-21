//===================================================================
// COPYRIGHT Tony 2017/03/24
//===================================================================
// TopologyEnhancement.cpp
// Header definition of class TopologyEnhancement
//===================================================================
//
// Usage notes:
//
//===================================================================
//  2017/03/24 Creation: Code generated by the 3DS wizard
//===================================================================

#include "TopologyEnhancement.h"

namespace JNCTonySpace{

CATBody_var GetBodyFromFeature(CATBaseUnknown_var ispBaseKnown)
{
	HRESULT hr;
	CATBody_var spBody = NULL_var;
	CATCell_var spCell_final = NULL_var;

	do { 
		if( ispBaseKnown==NULL_var )  break; 

		CATIMmiUseMfBRep_var spBRepOnFeature = ispBaseKnown; 
		if( !!spBRepOnFeature )
		{ 
			hr= spBRepOnFeature->GetBody(spBody); 
		} 
		else
		{ 
			CATIMmiUseGeometricalElement_var spGeometricalElementOnFeature = ispBaseKnown; 
			if( !!spGeometricalElementOnFeature ) 
			{ 
				hr = spGeometricalElementOnFeature->GetBodyResult(spBody); 

			} 
			else
			{ 
				CATIBodyRequest_var spBodyRequestOnModel = ispBaseKnown; 
				if( spBodyRequestOnModel == NULL_var) break; 

				CATListValCATBaseUnknown_var listResult; 
				HRESULT rc = spBodyRequestOnModel->GetResults("MfDefault3DView",listResult);
				if(FAILED(rc) ||  listResult.Size() <= 0)   break; 

				CATIMmiUseGeometricalElement_var spGeometricalElementOnBody = listResult[1]; 
				if(spGeometricalElementOnBody==NULL_var)  break;    
				hr = spGeometricalElementOnBody->GetBodyResult(spBody);
			} 
		}

		if( spBody==NULL_var) break;
	} while(FALSE); 

	return spBody;
}

HRESULT GetDistanceBetweenCellLists( CATLISTP(CATCell)& iList1, CATLISTP(CATCell)& iList2, double& ioDis )
{
	if (iList1.Size() == 0 || iList2.Size() ==0)
		return E_UNEXPECTED;

	CATSoftwareConfiguration *pSoftwareConfig = new CATSoftwareConfiguration();
	CATTopData *pTopData = CATTopData::CATCreateTopData(pSoftwareConfig);
	CATGeoFactory* pGeomFactory = ::CATCreateCGMContainer() ;

	// 拷贝两组cell

	// 第一组
	CATMathTransformation MathTrans_Occ; 
	CATTransfoManager CurveGeo_TransMnger(MathTrans_Occ,pGeomFactory,CATTransfoManager::Duplicate);
	CATLISTP(CATCell) ReList1;
	for (int idx1 = 1; idx1 <= iList1.Size(); idx1++)
		CurveGeo_TransMnger.Add(iList1.operator[](idx1));
	CurveGeo_TransMnger.Run();
	for (int idx1 = 1; idx1 <= iList1.Size(); idx1++)
		ReList1.Append((CATCell *)CurveGeo_TransMnger.ReadImage(iList1.operator[](idx1)));

	// 第二组
	CATMathTransformation MathTrans_Occ2; 
	CATTransfoManager CurveGeo_TransMnger2(MathTrans_Occ2,pGeomFactory,CATTransfoManager::Duplicate);
	CATLISTP(CATCell) ReList2;
	for (int idx2 = 1; idx2 <= iList2.Size(); idx2++)
		CurveGeo_TransMnger2.Add(iList2.operator[](idx2));
	CurveGeo_TransMnger2.Run();
	for (int idx2 = 1; idx2 <= iList2.Size(); idx2++)
		ReList2.Append((CATCell *)CurveGeo_TransMnger2.ReadImage(iList2.operator[](idx2)));

	// 取得距离
	CATICGMDistanceBodyBody* Dis_op = CATCGMCreateDistanceBodyBodyOp(pGeomFactory,pTopData,ReList1,ReList2);
	Dis_op->Run();
	ioDis = Dis_op->GetDistance();

	::CATCloseCGMContainer(pGeomFactory);

	return S_OK;
}

HRESULT GetDistanceBetweenPointAndBody( CATMathPoint iPoint, CATBody_var& oBody, double& ioDis )
{
	CATGeoFactory* pGeomFactory = ::CATCreateCGMContainer() ;
	CATMathTransformation MathTrans_Occ;
	CATTransfoManager CurveGeo_TransMnger(MathTrans_Occ,pGeomFactory,CATTransfoManager::Duplicate);

	CATBody_var spCopyBody = NULL_var;
	CurveGeo_TransMnger.Add(oBody);
	CurveGeo_TransMnger.Run();

	spCopyBody = (CATBody *)CurveGeo_TransMnger.ReadImage(oBody);
	if (NULL_var == spCopyBody)
		return E_FAIL;

	// 检查距离
	CATSoftwareConfiguration *pSoftwareConfig = new CATSoftwareConfiguration();
	CATTopData *pTopData = CATTopData::CATCreateTopData(pSoftwareConfig);

	CATICGMDistancePointBody* Dis_Op = CATCGMCreateDistancePointBody( spCopyBody, pTopData);
	Dis_Op->SetSignMode(CATDistanceSignModeZero);  // 点在body内部时距离为0
	Dis_Op->SetPoint(iPoint);
	Dis_Op->Run();
	ioDis = Dis_Op->GetResultDistance();

	::CATCloseCGMContainer(pGeomFactory);

	return S_OK;
}

}

