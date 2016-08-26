/////////////////////////////////////////////////////////////////////////
//// Ftdc C++ => C Adapter
//// Author : shawn666.liu@hotmail.com   
//// Generated at 2016/8/26 21:22:41
/////////////////////////////////////////////////////////////////////////

#pragma once

#ifdef WIN32
// Windows
#ifdef FTDC2C_EXPORTS
#define FTDC2C_API extern __declspec(dllexport)
#else
#define FTDC2C_API extern __declspec(dllimport)
#endif
#define MYDECL	__stdcall
#else
// Linux
#define FTDC2C_API extern
#define MYDECL  __attribute__((stdcall))
#endif




#include <ZQThostFtdcUserApiStruct.h>

#ifdef __cplusplus
extern "C" {
#endif

	typedef void(MYDECL *CbOnErrRtnEvent)(void* pObject, int type, void* pParam, void* pRspInfo);
	typedef void(MYDECL *CbOnFrontEvent)(void* pObject, int type, int Reason);
	typedef void(MYDECL *CbOnRspEvent)(void* pObject, int type, void* pParam, void* pRspInfo, int nRequestID, bool bIsLast);
	typedef void(MYDECL *CbOnRtnEvent)(void* pObject, int type, void* pParam);

	FTDC2C_API void MYDECL MdDestroyApi(void* pApi);
	FTDC2C_API void MYDECL MdRegisterCallback(void* pApi, CbOnFrontEvent c1, CbOnRspEvent c2, CbOnRtnEvent c3, void* pObject);
	FTDC2C_API void* MYDECL MdCreateApi(const char* pszFlowPath, const bool bIsUsingUdp);
	FTDC2C_API const char* MYDECL MdGetApiVersion();
	FTDC2C_API void MYDECL MdInit(void* pApi);
	FTDC2C_API void MYDECL MdRegisterFront(void* pApi, char* pszFrontAddress);
	FTDC2C_API int MYDECL MdSubscribeMarketData(void* pApi, char* ppInstrumentID[], int nCount, char* pExchageID);
	FTDC2C_API int MYDECL MdUnSubscribeMarketData(void* pApi, char* ppInstrumentID[], int nCount, char* pExchageID);
	FTDC2C_API int MYDECL MdReqUserLogin(void* pApi, CZQThostFtdcReqUserLoginField* pReqUserLoginField, int nRequestID);
	FTDC2C_API int MYDECL MdReqUserLogout(void* pApi, CZQThostFtdcUserLogoutField* pUserLogout, int nRequestID);

	FTDC2C_API void MYDECL TdDestroyApi(void* pApi);
	FTDC2C_API void MYDECL TdRegisterCallback(void* pApi, CbOnErrRtnEvent c1, CbOnFrontEvent c2, CbOnRspEvent c3, CbOnRtnEvent c4, void* pObject);
	FTDC2C_API void* MYDECL TdCreateApi(const char* pszFlowPath, const bool bIsUsingUdp);
	FTDC2C_API const char* MYDECL TdGetApiVersion();
	FTDC2C_API void MYDECL TdInit(void* pApi);
	FTDC2C_API void MYDECL TdRegisterFront(void* pApi, char* pszFrontAddress);
	FTDC2C_API void MYDECL TdSubscribePrivateTopic(void* pApi, ZQTHOST_TE_RESUME_TYPE nResumeType);
	FTDC2C_API void MYDECL TdSubscribePublicTopic(void* pApi, ZQTHOST_TE_RESUME_TYPE nResumeType);
	FTDC2C_API int MYDECL TdReqAuthenticate(void* pApi, CZQThostFtdcReqAuthenticateField* pReqAuthenticateField, int nRequestID);
	FTDC2C_API int MYDECL TdReqUserLogin(void* pApi, CZQThostFtdcReqUserLoginField* pReqUserLoginField, int nRequestID);
	FTDC2C_API int MYDECL TdReqUserLogout(void* pApi, CZQThostFtdcUserLogoutField* pUserLogout, int nRequestID);
	FTDC2C_API int MYDECL TdReqUserPasswordUpdate(void* pApi, CZQThostFtdcUserPasswordUpdateField* pUserPasswordUpdate, int nRequestID);
	FTDC2C_API int MYDECL TdReqOrderInsert(void* pApi, CZQThostFtdcInputOrderField* pInputOrder, int nRequestID);
	FTDC2C_API int MYDECL TdReqOrderAction(void* pApi, CZQThostFtdcInputOrderActionField* pInputOrderAction, int nRequestID);
	FTDC2C_API int MYDECL TdReqQryExchange(void* pApi, CZQThostFtdcQryExchangeField* pQryExchange, int nRequestID);
	FTDC2C_API int MYDECL TdReqQryDepthMarketData(void* pApi, CZQThostFtdcQryDepthMarketDataField* pQryDepthMarketData, int nRequestID);
	FTDC2C_API int MYDECL TdReqQrySecurity(void* pApi, CZQThostFtdcQrySecurityField* pQrySecurity, int nRequestID);
	FTDC2C_API int MYDECL TdReqQryETFFile(void* pApi, CZQThostFtdcQryETFFileField* pQryETFFile, int nRequestID);
	FTDC2C_API int MYDECL TdReqQryETFBasket(void* pApi, CZQThostFtdcQryETFBasketField* pQryETFBasket, int nRequestID);
	FTDC2C_API int MYDECL TdReqQrySubscribingShares(void* pApi, CZQThostFtdcQrySubscribingSharesField* pQrySubscribingShares, int nRequestID);
	FTDC2C_API int MYDECL TdReqQryPledgeOrderInfo(void* pApi, CZQThostFtdcQryPledgeOrderInfoField* pQryPledgeOrderInfo, int nRequestID);
	FTDC2C_API int MYDECL TdReqQryMarket(void* pApi, CZQThostFtdcQryMarketField* pQryMarket, int nRequestID);
	FTDC2C_API int MYDECL TdReqQrySecurityProduct(void* pApi, CZQThostFtdcQrySecurityProductField* pQrySecurityProduct, int nRequestID);
	FTDC2C_API int MYDECL TdReqQrySecurityClass(void* pApi, CZQThostFtdcQrySecurityClassField* pQrySecurityClass, int nRequestID);
	FTDC2C_API int MYDECL TdReqQryOrder(void* pApi, CZQThostFtdcQryOrderField* pQryOrder, int nRequestID);
	FTDC2C_API int MYDECL TdReqQryTrade(void* pApi, CZQThostFtdcQryTradeField* pQryTrade, int nRequestID);
	FTDC2C_API int MYDECL TdReqQryTradingAccount(void* pApi, CZQThostFtdcQryTradingAccountField* pQryTradingAccount, int nRequestID);
	FTDC2C_API int MYDECL TdReqQryInvestorSecurityPosition(void* pApi, CZQThostFtdcQryInvestorSecurityPositionField* pQryInvestorSecurityPosition, int nRequestID);
	FTDC2C_API int MYDECL TdReqQryInvestorPledgePosition(void* pApi, CZQThostFtdcQryInvestorPledgePositionField* pQryInvestorPledgePosition, int nRequestID);
	FTDC2C_API int MYDECL TdReqQryInvestorPledgeInfo(void* pApi, CZQThostFtdcQryInvestorPledgeInfoField* pQryInvestorPledgeInfo, int nRequestID);
	FTDC2C_API int MYDECL TdReqQryOrderFundDetail(void* pApi, CZQThostFtdcQryOrderFundDetailField* pQryOrderFundDetail, int nRequestID);
	FTDC2C_API int MYDECL TdReqQryInvestor(void* pApi, CZQThostFtdcQryInvestorField* pQryInvestor, int nRequestID);
	FTDC2C_API int MYDECL TdReqQryTradingCode(void* pApi, CZQThostFtdcQryTradingCodeField* pQryTradingCode, int nRequestID);
	FTDC2C_API int MYDECL TdReqQryInvestUnit(void* pApi, CZQThostFtdcQryInvestUnitField* pQryInvestUnit, int nRequestID);
	FTDC2C_API int MYDECL TdReqQryInvestUnitAndTradingAcct(void* pApi, CZQThostFtdcQryInvestUnitAndTradingAcctField* pQryInvestUnitAndTradingAcct, int nRequestID);
	FTDC2C_API int MYDECL TdReqQryInvestUnitAndUser(void* pApi, CZQThostFtdcQryInvestUnitAndUserField* pQryInvestUnitAndUser, int nRequestID);
	FTDC2C_API int MYDECL TdReqQryBrokerage(void* pApi, CZQThostFtdcQryBrokerageField* pQryBrokerage, int nRequestID);
	FTDC2C_API int MYDECL TdReqQrySubscribingSharesQuota(void* pApi, CZQThostFtdcQrySubscribingSharesQuotaField* pQrySubscribingSharesQuota, int nRequestID);
	FTDC2C_API int MYDECL TdReqQryRepoRatio(void* pApi, CZQThostFtdcQryRepoRatioField* pQryRepoRatio, int nRequestID);
	FTDC2C_API int MYDECL TdReqQryRepurchaseMaxTimes(void* pApi, CZQThostFtdcQryRepurchaseMaxTimesField* pQryRepurchaseMaxTimes, int nRequestID);
	FTDC2C_API int MYDECL TdReqQryTransferFund(void* pApi, CZQThostFtdcQryTransferFundField* pQryTransferFund, int nRequestID);
	FTDC2C_API int MYDECL TdReqQryTransferPosition(void* pApi, CZQThostFtdcQryTransferPositionField* pQryTransferPosition, int nRequestID);
	FTDC2C_API int MYDECL TdReqExecOrderInsert(void* pApi, CZQThostFtdcInputExecOrderField* pInputExecOrder, int nRequestID);
	FTDC2C_API int MYDECL TdReqExecOrderAction(void* pApi, CZQThostFtdcInputExecOrderActionField* pInputExecOrderAction, int nRequestID);
	FTDC2C_API int MYDECL TdReqLockInsert(void* pApi, CZQThostFtdcInputLockField* pInputLock, int nRequestID);
	FTDC2C_API int MYDECL TdReqSecurityTransfer(void* pApi, CZQThostFtdcInputSecurityTransferField* pInputSecurityTransfer, int nRequestID);
	FTDC2C_API int MYDECL TdReqQryInstrument(void* pApi, CZQThostFtdcQryInstrumentField* pQryInstrument, int nRequestID);
	FTDC2C_API int MYDECL TdReqQryLock(void* pApi, CZQThostFtdcQryLockField* pQryLock, int nRequestID);
	FTDC2C_API int MYDECL TdReqQryExecOrder(void* pApi, CZQThostFtdcQryExecOrderField* pQryExecOrder, int nRequestID);
	FTDC2C_API int MYDECL TdReqQryLockPosition(void* pApi, CZQThostFtdcQryLockPositionField* pQryLockPosition, int nRequestID);
	FTDC2C_API int MYDECL TdReqQryMarginRate(void* pApi, CZQThostFtdcQryMarginRateField* pQryMarginRate, int nRequestID);
	FTDC2C_API int MYDECL TdReqQryLimitAmount(void* pApi, CZQThostFtdcQryLimitAmountField* pQryLimitAmount, int nRequestID);
	FTDC2C_API int MYDECL TdReqQryLimitPosition(void* pApi, CZQThostFtdcQryLimitPositionField* pQryLimitPosition, int nRequestID);
	FTDC2C_API int MYDECL TdReqQryExerciseAssignment(void* pApi, CZQThostFtdcQryExerciseAssignmentField* pQryExerciseAssignment, int nRequestID);
	FTDC2C_API int MYDECL TdReqQryInvestorPosition(void* pApi, CZQThostFtdcQryInvestorPositionField* pQryInvestorPosition, int nRequestID);
	FTDC2C_API int MYDECL TdReqQrySecurityTransfer(void* pApi, CZQThostFtdcQrySecurityTransferField* pQrySecurityTransfer, int nRequestID);
	FTDC2C_API int MYDECL TdReqQryLOFInfo(void* pApi, CZQThostFtdcQryLOFInfoField* pQryLOFInfo, int nRequestID);
	FTDC2C_API int MYDECL TdReqQryLOFSubInfo(void* pApi, CZQThostFtdcQryLOFSubInfoField* pQryLOFSubInfo, int nRequestID);
	FTDC2C_API int MYDECL TdReqCashRepayInsert(void* pApi, CZQThostFtdcInputCashRepayField* pInputCashRepay, int nRequestID);
	FTDC2C_API int MYDECL TdReqQryCashRepay(void* pApi, CZQThostFtdcQryCashRepayField* pQryCashRepay, int nRequestID);
	FTDC2C_API int MYDECL TdReqQryCreditInfo(void* pApi, CZQThostFtdcQryCreditInfoField* pQryCreditInfo, int nRequestID);
	FTDC2C_API int MYDECL TdReqQryCreditSecurityPosition(void* pApi, CZQThostFtdcQryCreditSecurityPositionField* pQryCreditSecurityPosition, int nRequestID);
	FTDC2C_API int MYDECL TdReqQryCreditContract(void* pApi, CZQThostFtdcQryCreditContractField* pQryCreditContract, int nRequestID);
	FTDC2C_API int MYDECL TdReqQryCreditRepayment(void* pApi, CZQThostFtdcQryCreditRepaymentField* pQryCreditRepayment, int nRequestID);
	FTDC2C_API int MYDECL TdReqQryCreditUnderlying(void* pApi, CZQThostFtdcQryCreditUnderlyingField* pQryCreditUnderlying, int nRequestID);
	FTDC2C_API int MYDECL TdReqQryCreditCollateral(void* pApi, CZQThostFtdcQryCreditCollateralField* pQryCreditCollateral, int nRequestID);
	FTDC2C_API int MYDECL TdReqQryCreditFundPosition(void* pApi, CZQThostFtdcQryCreditFundPositionField* pQryCreditFundPosition, int nRequestID);


#ifdef __cplusplus
}
#endif
