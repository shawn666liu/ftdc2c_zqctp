/////////////////////////////////////////////////////////////////////////
//// Ftdc C++ => C Adapter
//// Author : shawn666.liu@hotmail.com   
//// Generated at 2016/8/26 21:22:42
/////////////////////////////////////////////////////////////////////////

#include "ftdc2c_zqctp.h"
#include "quoter.h"
#include "trader.h"

FTDC2C_API void MYDECL MdDestroyApi(void* pApi) {
	delete static_cast<Quoter*>(pApi);
}

FTDC2C_API void MYDECL MdRegisterCallback(void* pApi, CbOnFrontEvent c1, CbOnRspEvent c2, CbOnRtnEvent c3, void* pObject) {
	Quoter *p = static_cast<Quoter*>(pApi);
	p->mOnFrontEvent = c1;
	p->mOnRspEvent = c2;
	p->mOnRtnEvent = c3;
	if (pObject == nullptr)
		pObject = pApi;
	p->pObject = pObject;
}


FTDC2C_API void* MYDECL MdCreateApi(const char* pszFlowPath, const bool bIsUsingUdp) {
	return new Quoter(pszFlowPath, bIsUsingUdp);
}

FTDC2C_API const char* MYDECL MdGetApiVersion() {
	return CZQThostFtdcMdApi::GetApiVersion();
}

FTDC2C_API void MYDECL MdInit(void* pApi) {
	(static_cast<Quoter*>(pApi))->RawApi->Init();
}

FTDC2C_API void MYDECL MdRegisterFront(void* pApi, char* pszFrontAddress) {
	(static_cast<Quoter*>(pApi))->RawApi->RegisterFront(pszFrontAddress);
}

FTDC2C_API int MYDECL MdSubscribeMarketData(void* pApi, char* ppInstrumentID[], int nCount, char* pExchageID) {
	return (static_cast<Quoter*>(pApi))->RawApi->SubscribeMarketData(ppInstrumentID, nCount, pExchageID);
}

FTDC2C_API int MYDECL MdUnSubscribeMarketData(void* pApi, char* ppInstrumentID[], int nCount, char* pExchageID) {
	return (static_cast<Quoter*>(pApi))->RawApi->UnSubscribeMarketData(ppInstrumentID, nCount, pExchageID);
}

FTDC2C_API int MYDECL MdReqUserLogin(void* pApi, CZQThostFtdcReqUserLoginField* pReqUserLoginField, int nRequestID) {
	return (static_cast<Quoter*>(pApi))->RawApi->ReqUserLogin(pReqUserLoginField, nRequestID);
}

FTDC2C_API int MYDECL MdReqUserLogout(void* pApi, CZQThostFtdcUserLogoutField* pUserLogout, int nRequestID) {
	return (static_cast<Quoter*>(pApi))->RawApi->ReqUserLogout(pUserLogout, nRequestID);
}

FTDC2C_API void MYDECL TdDestroyApi(void* pApi) {
	delete static_cast<Trader*>(pApi);
}

FTDC2C_API void MYDECL TdRegisterCallback(void* pApi, CbOnErrRtnEvent c1, CbOnFrontEvent c2, CbOnRspEvent c3, CbOnRtnEvent c4, void* pObject) {
	Trader *p = static_cast<Trader*>(pApi);
	p->mOnErrRtnEvent = c1;
	p->mOnFrontEvent = c2;
	p->mOnRspEvent = c3;
	p->mOnRtnEvent = c4;
	if (pObject == nullptr)
		pObject = pApi;
	p->pObject = pObject;
}


FTDC2C_API void* MYDECL TdCreateApi(const char* pszFlowPath, const bool bIsUsingUdp) {
	return new Trader(pszFlowPath, bIsUsingUdp);
}

FTDC2C_API const char* MYDECL TdGetApiVersion() {
	return CZQThostFtdcTraderApi::GetApiVersion();
}

FTDC2C_API void MYDECL TdInit(void* pApi) {
	(static_cast<Trader*>(pApi))->RawApi->Init();
}

FTDC2C_API void MYDECL TdRegisterFront(void* pApi, char* pszFrontAddress) {
	(static_cast<Trader*>(pApi))->RawApi->RegisterFront(pszFrontAddress);
}

FTDC2C_API void MYDECL TdSubscribePrivateTopic(void* pApi, ZQTHOST_TE_RESUME_TYPE nResumeType) {
	(static_cast<Trader*>(pApi))->RawApi->SubscribePrivateTopic(nResumeType);
}

FTDC2C_API void MYDECL TdSubscribePublicTopic(void* pApi, ZQTHOST_TE_RESUME_TYPE nResumeType) {
	(static_cast<Trader*>(pApi))->RawApi->SubscribePublicTopic(nResumeType);
}

FTDC2C_API int MYDECL TdReqAuthenticate(void* pApi, CZQThostFtdcReqAuthenticateField* pReqAuthenticateField, int nRequestID) {
	return (static_cast<Trader*>(pApi))->RawApi->ReqAuthenticate(pReqAuthenticateField, nRequestID);
}

FTDC2C_API int MYDECL TdReqUserLogin(void* pApi, CZQThostFtdcReqUserLoginField* pReqUserLoginField, int nRequestID) {
	return (static_cast<Trader*>(pApi))->RawApi->ReqUserLogin(pReqUserLoginField, nRequestID);
}

FTDC2C_API int MYDECL TdReqUserLogout(void* pApi, CZQThostFtdcUserLogoutField* pUserLogout, int nRequestID) {
	return (static_cast<Trader*>(pApi))->RawApi->ReqUserLogout(pUserLogout, nRequestID);
}

FTDC2C_API int MYDECL TdReqUserPasswordUpdate(void* pApi, CZQThostFtdcUserPasswordUpdateField* pUserPasswordUpdate, int nRequestID) {
	return (static_cast<Trader*>(pApi))->RawApi->ReqUserPasswordUpdate(pUserPasswordUpdate, nRequestID);
}

FTDC2C_API int MYDECL TdReqOrderInsert(void* pApi, CZQThostFtdcInputOrderField* pInputOrder, int nRequestID) {
	return (static_cast<Trader*>(pApi))->RawApi->ReqOrderInsert(pInputOrder, nRequestID);
}

FTDC2C_API int MYDECL TdReqOrderAction(void* pApi, CZQThostFtdcInputOrderActionField* pInputOrderAction, int nRequestID) {
	return (static_cast<Trader*>(pApi))->RawApi->ReqOrderAction(pInputOrderAction, nRequestID);
}

FTDC2C_API int MYDECL TdReqQryExchange(void* pApi, CZQThostFtdcQryExchangeField* pQryExchange, int nRequestID) {
	return (static_cast<Trader*>(pApi))->RawApi->ReqQryExchange(pQryExchange, nRequestID);
}

FTDC2C_API int MYDECL TdReqQryDepthMarketData(void* pApi, CZQThostFtdcQryDepthMarketDataField* pQryDepthMarketData, int nRequestID) {
	return (static_cast<Trader*>(pApi))->RawApi->ReqQryDepthMarketData(pQryDepthMarketData, nRequestID);
}

FTDC2C_API int MYDECL TdReqQrySecurity(void* pApi, CZQThostFtdcQrySecurityField* pQrySecurity, int nRequestID) {
	return (static_cast<Trader*>(pApi))->RawApi->ReqQrySecurity(pQrySecurity, nRequestID);
}

FTDC2C_API int MYDECL TdReqQryETFFile(void* pApi, CZQThostFtdcQryETFFileField* pQryETFFile, int nRequestID) {
	return (static_cast<Trader*>(pApi))->RawApi->ReqQryETFFile(pQryETFFile, nRequestID);
}

FTDC2C_API int MYDECL TdReqQryETFBasket(void* pApi, CZQThostFtdcQryETFBasketField* pQryETFBasket, int nRequestID) {
	return (static_cast<Trader*>(pApi))->RawApi->ReqQryETFBasket(pQryETFBasket, nRequestID);
}

FTDC2C_API int MYDECL TdReqQrySubscribingShares(void* pApi, CZQThostFtdcQrySubscribingSharesField* pQrySubscribingShares, int nRequestID) {
	return (static_cast<Trader*>(pApi))->RawApi->ReqQrySubscribingShares(pQrySubscribingShares, nRequestID);
}

FTDC2C_API int MYDECL TdReqQryPledgeOrderInfo(void* pApi, CZQThostFtdcQryPledgeOrderInfoField* pQryPledgeOrderInfo, int nRequestID) {
	return (static_cast<Trader*>(pApi))->RawApi->ReqQryPledgeOrderInfo(pQryPledgeOrderInfo, nRequestID);
}

FTDC2C_API int MYDECL TdReqQryMarket(void* pApi, CZQThostFtdcQryMarketField* pQryMarket, int nRequestID) {
	return (static_cast<Trader*>(pApi))->RawApi->ReqQryMarket(pQryMarket, nRequestID);
}

FTDC2C_API int MYDECL TdReqQrySecurityProduct(void* pApi, CZQThostFtdcQrySecurityProductField* pQrySecurityProduct, int nRequestID) {
	return (static_cast<Trader*>(pApi))->RawApi->ReqQrySecurityProduct(pQrySecurityProduct, nRequestID);
}

FTDC2C_API int MYDECL TdReqQrySecurityClass(void* pApi, CZQThostFtdcQrySecurityClassField* pQrySecurityClass, int nRequestID) {
	return (static_cast<Trader*>(pApi))->RawApi->ReqQrySecurityClass(pQrySecurityClass, nRequestID);
}

FTDC2C_API int MYDECL TdReqQryOrder(void* pApi, CZQThostFtdcQryOrderField* pQryOrder, int nRequestID) {
	return (static_cast<Trader*>(pApi))->RawApi->ReqQryOrder(pQryOrder, nRequestID);
}

FTDC2C_API int MYDECL TdReqQryTrade(void* pApi, CZQThostFtdcQryTradeField* pQryTrade, int nRequestID) {
	return (static_cast<Trader*>(pApi))->RawApi->ReqQryTrade(pQryTrade, nRequestID);
}

FTDC2C_API int MYDECL TdReqQryTradingAccount(void* pApi, CZQThostFtdcQryTradingAccountField* pQryTradingAccount, int nRequestID) {
	return (static_cast<Trader*>(pApi))->RawApi->ReqQryTradingAccount(pQryTradingAccount, nRequestID);
}

FTDC2C_API int MYDECL TdReqQryInvestorSecurityPosition(void* pApi, CZQThostFtdcQryInvestorSecurityPositionField* pQryInvestorSecurityPosition, int nRequestID) {
	return (static_cast<Trader*>(pApi))->RawApi->ReqQryInvestorSecurityPosition(pQryInvestorSecurityPosition, nRequestID);
}

FTDC2C_API int MYDECL TdReqQryInvestorPledgePosition(void* pApi, CZQThostFtdcQryInvestorPledgePositionField* pQryInvestorPledgePosition, int nRequestID) {
	return (static_cast<Trader*>(pApi))->RawApi->ReqQryInvestorPledgePosition(pQryInvestorPledgePosition, nRequestID);
}

FTDC2C_API int MYDECL TdReqQryInvestorPledgeInfo(void* pApi, CZQThostFtdcQryInvestorPledgeInfoField* pQryInvestorPledgeInfo, int nRequestID) {
	return (static_cast<Trader*>(pApi))->RawApi->ReqQryInvestorPledgeInfo(pQryInvestorPledgeInfo, nRequestID);
}

FTDC2C_API int MYDECL TdReqQryOrderFundDetail(void* pApi, CZQThostFtdcQryOrderFundDetailField* pQryOrderFundDetail, int nRequestID) {
	return (static_cast<Trader*>(pApi))->RawApi->ReqQryOrderFundDetail(pQryOrderFundDetail, nRequestID);
}

FTDC2C_API int MYDECL TdReqQryInvestor(void* pApi, CZQThostFtdcQryInvestorField* pQryInvestor, int nRequestID) {
	return (static_cast<Trader*>(pApi))->RawApi->ReqQryInvestor(pQryInvestor, nRequestID);
}

FTDC2C_API int MYDECL TdReqQryTradingCode(void* pApi, CZQThostFtdcQryTradingCodeField* pQryTradingCode, int nRequestID) {
	return (static_cast<Trader*>(pApi))->RawApi->ReqQryTradingCode(pQryTradingCode, nRequestID);
}

FTDC2C_API int MYDECL TdReqQryInvestUnit(void* pApi, CZQThostFtdcQryInvestUnitField* pQryInvestUnit, int nRequestID) {
	return (static_cast<Trader*>(pApi))->RawApi->ReqQryInvestUnit(pQryInvestUnit, nRequestID);
}

FTDC2C_API int MYDECL TdReqQryInvestUnitAndTradingAcct(void* pApi, CZQThostFtdcQryInvestUnitAndTradingAcctField* pQryInvestUnitAndTradingAcct, int nRequestID) {
	return (static_cast<Trader*>(pApi))->RawApi->ReqQryInvestUnitAndTradingAcct(pQryInvestUnitAndTradingAcct, nRequestID);
}

FTDC2C_API int MYDECL TdReqQryInvestUnitAndUser(void* pApi, CZQThostFtdcQryInvestUnitAndUserField* pQryInvestUnitAndUser, int nRequestID) {
	return (static_cast<Trader*>(pApi))->RawApi->ReqQryInvestUnitAndUser(pQryInvestUnitAndUser, nRequestID);
}

FTDC2C_API int MYDECL TdReqQryBrokerage(void* pApi, CZQThostFtdcQryBrokerageField* pQryBrokerage, int nRequestID) {
	return (static_cast<Trader*>(pApi))->RawApi->ReqQryBrokerage(pQryBrokerage, nRequestID);
}

FTDC2C_API int MYDECL TdReqQrySubscribingSharesQuota(void* pApi, CZQThostFtdcQrySubscribingSharesQuotaField* pQrySubscribingSharesQuota, int nRequestID) {
	return (static_cast<Trader*>(pApi))->RawApi->ReqQrySubscribingSharesQuota(pQrySubscribingSharesQuota, nRequestID);
}

FTDC2C_API int MYDECL TdReqQryRepoRatio(void* pApi, CZQThostFtdcQryRepoRatioField* pQryRepoRatio, int nRequestID) {
	return (static_cast<Trader*>(pApi))->RawApi->ReqQryRepoRatio(pQryRepoRatio, nRequestID);
}

FTDC2C_API int MYDECL TdReqQryRepurchaseMaxTimes(void* pApi, CZQThostFtdcQryRepurchaseMaxTimesField* pQryRepurchaseMaxTimes, int nRequestID) {
	return (static_cast<Trader*>(pApi))->RawApi->ReqQryRepurchaseMaxTimes(pQryRepurchaseMaxTimes, nRequestID);
}

FTDC2C_API int MYDECL TdReqQryTransferFund(void* pApi, CZQThostFtdcQryTransferFundField* pQryTransferFund, int nRequestID) {
	return (static_cast<Trader*>(pApi))->RawApi->ReqQryTransferFund(pQryTransferFund, nRequestID);
}

FTDC2C_API int MYDECL TdReqQryTransferPosition(void* pApi, CZQThostFtdcQryTransferPositionField* pQryTransferPosition, int nRequestID) {
	return (static_cast<Trader*>(pApi))->RawApi->ReqQryTransferPosition(pQryTransferPosition, nRequestID);
}

FTDC2C_API int MYDECL TdReqExecOrderInsert(void* pApi, CZQThostFtdcInputExecOrderField* pInputExecOrder, int nRequestID) {
	return (static_cast<Trader*>(pApi))->RawApi->ReqExecOrderInsert(pInputExecOrder, nRequestID);
}

FTDC2C_API int MYDECL TdReqExecOrderAction(void* pApi, CZQThostFtdcInputExecOrderActionField* pInputExecOrderAction, int nRequestID) {
	return (static_cast<Trader*>(pApi))->RawApi->ReqExecOrderAction(pInputExecOrderAction, nRequestID);
}

FTDC2C_API int MYDECL TdReqLockInsert(void* pApi, CZQThostFtdcInputLockField* pInputLock, int nRequestID) {
	return (static_cast<Trader*>(pApi))->RawApi->ReqLockInsert(pInputLock, nRequestID);
}

FTDC2C_API int MYDECL TdReqSecurityTransfer(void* pApi, CZQThostFtdcInputSecurityTransferField* pInputSecurityTransfer, int nRequestID) {
	return (static_cast<Trader*>(pApi))->RawApi->ReqSecurityTransfer(pInputSecurityTransfer, nRequestID);
}

FTDC2C_API int MYDECL TdReqQryInstrument(void* pApi, CZQThostFtdcQryInstrumentField* pQryInstrument, int nRequestID) {
	return (static_cast<Trader*>(pApi))->RawApi->ReqQryInstrument(pQryInstrument, nRequestID);
}

FTDC2C_API int MYDECL TdReqQryLock(void* pApi, CZQThostFtdcQryLockField* pQryLock, int nRequestID) {
	return (static_cast<Trader*>(pApi))->RawApi->ReqQryLock(pQryLock, nRequestID);
}

FTDC2C_API int MYDECL TdReqQryExecOrder(void* pApi, CZQThostFtdcQryExecOrderField* pQryExecOrder, int nRequestID) {
	return (static_cast<Trader*>(pApi))->RawApi->ReqQryExecOrder(pQryExecOrder, nRequestID);
}

FTDC2C_API int MYDECL TdReqQryLockPosition(void* pApi, CZQThostFtdcQryLockPositionField* pQryLockPosition, int nRequestID) {
	return (static_cast<Trader*>(pApi))->RawApi->ReqQryLockPosition(pQryLockPosition, nRequestID);
}

FTDC2C_API int MYDECL TdReqQryMarginRate(void* pApi, CZQThostFtdcQryMarginRateField* pQryMarginRate, int nRequestID) {
	return (static_cast<Trader*>(pApi))->RawApi->ReqQryMarginRate(pQryMarginRate, nRequestID);
}

FTDC2C_API int MYDECL TdReqQryLimitAmount(void* pApi, CZQThostFtdcQryLimitAmountField* pQryLimitAmount, int nRequestID) {
	return (static_cast<Trader*>(pApi))->RawApi->ReqQryLimitAmount(pQryLimitAmount, nRequestID);
}

FTDC2C_API int MYDECL TdReqQryLimitPosition(void* pApi, CZQThostFtdcQryLimitPositionField* pQryLimitPosition, int nRequestID) {
	return (static_cast<Trader*>(pApi))->RawApi->ReqQryLimitPosition(pQryLimitPosition, nRequestID);
}

FTDC2C_API int MYDECL TdReqQryExerciseAssignment(void* pApi, CZQThostFtdcQryExerciseAssignmentField* pQryExerciseAssignment, int nRequestID) {
	return (static_cast<Trader*>(pApi))->RawApi->ReqQryExerciseAssignment(pQryExerciseAssignment, nRequestID);
}

FTDC2C_API int MYDECL TdReqQryInvestorPosition(void* pApi, CZQThostFtdcQryInvestorPositionField* pQryInvestorPosition, int nRequestID) {
	return (static_cast<Trader*>(pApi))->RawApi->ReqQryInvestorPosition(pQryInvestorPosition, nRequestID);
}

FTDC2C_API int MYDECL TdReqQrySecurityTransfer(void* pApi, CZQThostFtdcQrySecurityTransferField* pQrySecurityTransfer, int nRequestID) {
	return (static_cast<Trader*>(pApi))->RawApi->ReqQrySecurityTransfer(pQrySecurityTransfer, nRequestID);
}

FTDC2C_API int MYDECL TdReqQryLOFInfo(void* pApi, CZQThostFtdcQryLOFInfoField* pQryLOFInfo, int nRequestID) {
	return (static_cast<Trader*>(pApi))->RawApi->ReqQryLOFInfo(pQryLOFInfo, nRequestID);
}

FTDC2C_API int MYDECL TdReqQryLOFSubInfo(void* pApi, CZQThostFtdcQryLOFSubInfoField* pQryLOFSubInfo, int nRequestID) {
	return (static_cast<Trader*>(pApi))->RawApi->ReqQryLOFSubInfo(pQryLOFSubInfo, nRequestID);
}

FTDC2C_API int MYDECL TdReqCashRepayInsert(void* pApi, CZQThostFtdcInputCashRepayField* pInputCashRepay, int nRequestID) {
	return (static_cast<Trader*>(pApi))->RawApi->ReqCashRepayInsert(pInputCashRepay, nRequestID);
}

FTDC2C_API int MYDECL TdReqQryCashRepay(void* pApi, CZQThostFtdcQryCashRepayField* pQryCashRepay, int nRequestID) {
	return (static_cast<Trader*>(pApi))->RawApi->ReqQryCashRepay(pQryCashRepay, nRequestID);
}

FTDC2C_API int MYDECL TdReqQryCreditInfo(void* pApi, CZQThostFtdcQryCreditInfoField* pQryCreditInfo, int nRequestID) {
	return (static_cast<Trader*>(pApi))->RawApi->ReqQryCreditInfo(pQryCreditInfo, nRequestID);
}

FTDC2C_API int MYDECL TdReqQryCreditSecurityPosition(void* pApi, CZQThostFtdcQryCreditSecurityPositionField* pQryCreditSecurityPosition, int nRequestID) {
	return (static_cast<Trader*>(pApi))->RawApi->ReqQryCreditSecurityPosition(pQryCreditSecurityPosition, nRequestID);
}

FTDC2C_API int MYDECL TdReqQryCreditContract(void* pApi, CZQThostFtdcQryCreditContractField* pQryCreditContract, int nRequestID) {
	return (static_cast<Trader*>(pApi))->RawApi->ReqQryCreditContract(pQryCreditContract, nRequestID);
}

FTDC2C_API int MYDECL TdReqQryCreditRepayment(void* pApi, CZQThostFtdcQryCreditRepaymentField* pQryCreditRepayment, int nRequestID) {
	return (static_cast<Trader*>(pApi))->RawApi->ReqQryCreditRepayment(pQryCreditRepayment, nRequestID);
}

FTDC2C_API int MYDECL TdReqQryCreditUnderlying(void* pApi, CZQThostFtdcQryCreditUnderlyingField* pQryCreditUnderlying, int nRequestID) {
	return (static_cast<Trader*>(pApi))->RawApi->ReqQryCreditUnderlying(pQryCreditUnderlying, nRequestID);
}

FTDC2C_API int MYDECL TdReqQryCreditCollateral(void* pApi, CZQThostFtdcQryCreditCollateralField* pQryCreditCollateral, int nRequestID) {
	return (static_cast<Trader*>(pApi))->RawApi->ReqQryCreditCollateral(pQryCreditCollateral, nRequestID);
}

FTDC2C_API int MYDECL TdReqQryCreditFundPosition(void* pApi, CZQThostFtdcQryCreditFundPositionField* pQryCreditFundPosition, int nRequestID) {
	return (static_cast<Trader*>(pApi))->RawApi->ReqQryCreditFundPosition(pQryCreditFundPosition, nRequestID);
}

