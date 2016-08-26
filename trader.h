/////////////////////////////////////////////////////////////////////////
//// Ftdc C++ => C Adapter
//// Author : shawn666.liu@hotmail.com   
//// Generated at 2016/8/26 21:23:15
/////////////////////////////////////////////////////////////////////////

#pragma once
#include <ZQThostFtdcTraderApi.h>
#include "enums.h"

class Trader : public CZQThostFtdcTraderSpi
{
public:
	CZQThostFtdcTraderApi* RawApi{ nullptr };
	CbOnErrRtnEvent mOnErrRtnEvent{ nullptr };
	CbOnFrontEvent mOnFrontEvent{ nullptr };
	CbOnRspEvent mOnRspEvent{ nullptr };
	CbOnRtnEvent mOnRtnEvent{ nullptr };
	void* pObject;

	Trader(const char* pszFlowPath, const bool bIsUsingUdp) {
		RawApi = CZQThostFtdcTraderApi::CreateFtdcTraderApi(pszFlowPath, bIsUsingUdp);
		RawApi->RegisterSpi(this);
		pObject = this;
	}


	virtual ~Trader() {
		if (RawApi){
			RawApi->RegisterSpi(nullptr);
			RawApi->Release();
			RawApi = nullptr;
		}
	};

	virtual void OnFrontConnected() {
		mOnFrontEvent(pObject, (int)EnumOnFrontEvent::OnFrontConnected, 0);
	};
	virtual void OnFrontDisconnected(int nReason) {
		mOnFrontEvent(pObject, (int)EnumOnFrontEvent::OnFrontDisconnected, nReason);
	};
	virtual void OnHeartBeatWarning(int nTimeLapse) {
	};
	virtual void OnRspAuthenticate(CZQThostFtdcRspAuthenticateField* pRspAuthenticateField, CZQThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) {
		mOnRspEvent(pObject, (int)EnumOnRspEvent::OnRspAuthenticate, pRspAuthenticateField, pRspInfo, nRequestID, bIsLast);
	};
	virtual void OnRspError(CZQThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) {
		mOnRspEvent(pObject, (int)EnumOnRspEvent::OnRspError, nullptr, pRspInfo, nRequestID, bIsLast);
	};
	virtual void OnRspUserLogin(CZQThostFtdcRspUserLoginField* pRspUserLogin, CZQThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) {
		mOnRspEvent(pObject, (int)EnumOnRspEvent::OnRspUserLogin, pRspUserLogin, pRspInfo, nRequestID, bIsLast);
	};
	virtual void OnRspUserLogout(CZQThostFtdcUserLogoutField* pUserLogout, CZQThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) {
		mOnRspEvent(pObject, (int)EnumOnRspEvent::OnRspUserLogout, pUserLogout, pRspInfo, nRequestID, bIsLast);
	};
	virtual void OnRspUserPasswordUpdate(CZQThostFtdcUserPasswordUpdateField* pUserPasswordUpdate, CZQThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) {
		mOnRspEvent(pObject, (int)EnumOnRspEvent::OnRspUserPasswordUpdate, pUserPasswordUpdate, pRspInfo, nRequestID, bIsLast);
	};
	virtual void OnRspOrderInsert(CZQThostFtdcInputOrderField* pInputOrder, CZQThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) {
		mOnRspEvent(pObject, (int)EnumOnRspEvent::OnRspOrderInsert, pInputOrder, pRspInfo, nRequestID, bIsLast);
	};
	virtual void OnRspOrderAction(CZQThostFtdcInputOrderActionField* pInputOrderAction, CZQThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) {
		mOnRspEvent(pObject, (int)EnumOnRspEvent::OnRspOrderAction, pInputOrderAction, pRspInfo, nRequestID, bIsLast);
	};
	virtual void OnRtnOrder(CZQThostFtdcOrderField* pOrder) {
		mOnRtnEvent(pObject, (int)EnumOnRtnEvent::OnRtnOrder, pOrder);
	};
	virtual void OnRtnTrade(CZQThostFtdcTradeField* pTrade) {
		mOnRtnEvent(pObject, (int)EnumOnRtnEvent::OnRtnTrade, pTrade);
	};
	virtual void OnErrRtnOrderInsert(CZQThostFtdcInputOrderField* pInputOrder, CZQThostFtdcRspInfoField* pRspInfo) {
		mOnErrRtnEvent(pObject, (int)EnumOnErrRtnEvent::OnErrRtnOrderInsert, pInputOrder, pRspInfo);
	};
	virtual void OnErrRtnOrderAction(CZQThostFtdcOrderActionField* pOrderAction, CZQThostFtdcRspInfoField* pRspInfo) {
		mOnErrRtnEvent(pObject, (int)EnumOnErrRtnEvent::OnErrRtnOrderAction, pOrderAction, pRspInfo);
	};
	virtual void OnRtnTradingNotice(CZQThostFtdcTradingNoticeInfoField* pTradingNoticeInfo) {
		mOnRtnEvent(pObject, (int)EnumOnRtnEvent::OnRtnTradingNotice, pTradingNoticeInfo);
	};
	virtual void OnRtnTransferFund(CZQThostFtdcTransferFundField* pTransferFund) {
		mOnRtnEvent(pObject, (int)EnumOnRtnEvent::OnRtnTransferFund, pTransferFund);
	};
	virtual void OnRtnTransferPosition(CZQThostFtdcTransferPositionField* pTransferPosition) {
		mOnRtnEvent(pObject, (int)EnumOnRtnEvent::OnRtnTransferPosition, pTransferPosition);
	};
	virtual void OnRspQryExchange(CZQThostFtdcExchangeField* pExchange, CZQThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) {
		mOnRspEvent(pObject, (int)EnumOnRspEvent::OnRspQryExchange, pExchange, pRspInfo, nRequestID, bIsLast);
	};
	virtual void OnRspQryDepthMarketData(CZQThostFtdcDepthMarketDataField* pDepthMarketData, CZQThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) {
		mOnRspEvent(pObject, (int)EnumOnRspEvent::OnRspQryDepthMarketData, pDepthMarketData, pRspInfo, nRequestID, bIsLast);
	};
	virtual void OnRspQrySecurity(CZQThostFtdcSecurityField* pSecurity, CZQThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) {
		mOnRspEvent(pObject, (int)EnumOnRspEvent::OnRspQrySecurity, pSecurity, pRspInfo, nRequestID, bIsLast);
	};
	virtual void OnRspQryETFFile(CZQThostFtdcETFFileField* pETFFile, CZQThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) {
		mOnRspEvent(pObject, (int)EnumOnRspEvent::OnRspQryETFFile, pETFFile, pRspInfo, nRequestID, bIsLast);
	};
	virtual void OnRspQryETFBasket(CZQThostFtdcETFBasketField* pETFBasket, CZQThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) {
		mOnRspEvent(pObject, (int)EnumOnRspEvent::OnRspQryETFBasket, pETFBasket, pRspInfo, nRequestID, bIsLast);
	};
	virtual void OnRspQrySubscribingShares(CZQThostFtdcSubscribingSharesField* pSubscribingShares, CZQThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) {
		mOnRspEvent(pObject, (int)EnumOnRspEvent::OnRspQrySubscribingShares, pSubscribingShares, pRspInfo, nRequestID, bIsLast);
	};
	virtual void OnRspQryPledgeOrderInfo(CZQThostFtdcPledgeOrderInfoField* pPledgeOrderInfo, CZQThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) {
		mOnRspEvent(pObject, (int)EnumOnRspEvent::OnRspQryPledgeOrderInfo, pPledgeOrderInfo, pRspInfo, nRequestID, bIsLast);
	};
	virtual void OnRspQryMarket(CZQThostFtdcMarketField* pMarket, CZQThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) {
		mOnRspEvent(pObject, (int)EnumOnRspEvent::OnRspQryMarket, pMarket, pRspInfo, nRequestID, bIsLast);
	};
	virtual void OnRspQrySecurityProduct(CZQThostFtdcSecurityProductField* pSecurityProduct, CZQThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) {
		mOnRspEvent(pObject, (int)EnumOnRspEvent::OnRspQrySecurityProduct, pSecurityProduct, pRspInfo, nRequestID, bIsLast);
	};
	virtual void OnRspQrySecurityClass(CZQThostFtdcSecurityClassField* pSecurityClass, CZQThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) {
		mOnRspEvent(pObject, (int)EnumOnRspEvent::OnRspQrySecurityClass, pSecurityClass, pRspInfo, nRequestID, bIsLast);
	};
	virtual void OnRspQryOrder(CZQThostFtdcOrderField* pOrder, CZQThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) {
		mOnRspEvent(pObject, (int)EnumOnRspEvent::OnRspQryOrder, pOrder, pRspInfo, nRequestID, bIsLast);
	};
	virtual void OnRspQryTrade(CZQThostFtdcTradeField* pTrade, CZQThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) {
		mOnRspEvent(pObject, (int)EnumOnRspEvent::OnRspQryTrade, pTrade, pRspInfo, nRequestID, bIsLast);
	};
	virtual void OnRspQryTradingAccount(CZQThostFtdcTradingAccountField* pTradingAccount, CZQThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) {
		mOnRspEvent(pObject, (int)EnumOnRspEvent::OnRspQryTradingAccount, pTradingAccount, pRspInfo, nRequestID, bIsLast);
	};
	virtual void OnRspQryInvestorSecurityPosition(CZQThostFtdcInvestorSecurityPositionField* pInvestorSecurityPosition, CZQThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) {
		mOnRspEvent(pObject, (int)EnumOnRspEvent::OnRspQryInvestorSecurityPosition, pInvestorSecurityPosition, pRspInfo, nRequestID, bIsLast);
	};
	virtual void OnRspQryInvestorPledgePosition(CZQThostFtdcInvestorPledgePositionField* pInvestorPledgePosition, CZQThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) {
		mOnRspEvent(pObject, (int)EnumOnRspEvent::OnRspQryInvestorPledgePosition, pInvestorPledgePosition, pRspInfo, nRequestID, bIsLast);
	};
	virtual void OnRspQryInvestorPledgeInfo(CZQThostFtdcInvestorPledgeInfoField* pInvestorPledgeInfo, CZQThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) {
		mOnRspEvent(pObject, (int)EnumOnRspEvent::OnRspQryInvestorPledgeInfo, pInvestorPledgeInfo, pRspInfo, nRequestID, bIsLast);
	};
	virtual void OnRspQryOrderFundDetail(CZQThostFtdcOrderFundDetailField* pOrderFundDetail, CZQThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) {
		mOnRspEvent(pObject, (int)EnumOnRspEvent::OnRspQryOrderFundDetail, pOrderFundDetail, pRspInfo, nRequestID, bIsLast);
	};
	virtual void OnRspQryInvestor(CZQThostFtdcInvestorField* pInvestor, CZQThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) {
		mOnRspEvent(pObject, (int)EnumOnRspEvent::OnRspQryInvestor, pInvestor, pRspInfo, nRequestID, bIsLast);
	};
	virtual void OnRspQryTradingCode(CZQThostFtdcTradingCodeField* pTradingCode, CZQThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) {
		mOnRspEvent(pObject, (int)EnumOnRspEvent::OnRspQryTradingCode, pTradingCode, pRspInfo, nRequestID, bIsLast);
	};
	virtual void OnRspQryInvestUnit(CZQThostFtdcInvestUnitField* pInvestUnit, CZQThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) {
		mOnRspEvent(pObject, (int)EnumOnRspEvent::OnRspQryInvestUnit, pInvestUnit, pRspInfo, nRequestID, bIsLast);
	};
	virtual void OnRspQryInvestUnitAndTradingAcct(CZQThostFtdcInvestUnitAndTradingAcctField* pInvestUnitAndTradingAcct, CZQThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) {
		mOnRspEvent(pObject, (int)EnumOnRspEvent::OnRspQryInvestUnitAndTradingAcct, pInvestUnitAndTradingAcct, pRspInfo, nRequestID, bIsLast);
	};
	virtual void OnRspQryInvestUnitAndUser(CZQThostFtdcInvestUnitAndUserField* pInvestUnitAndUser, CZQThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) {
		mOnRspEvent(pObject, (int)EnumOnRspEvent::OnRspQryInvestUnitAndUser, pInvestUnitAndUser, pRspInfo, nRequestID, bIsLast);
	};
	virtual void OnRspQryBrokerage(CZQThostFtdcBrokerageField* pBrokerage, CZQThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) {
		mOnRspEvent(pObject, (int)EnumOnRspEvent::OnRspQryBrokerage, pBrokerage, pRspInfo, nRequestID, bIsLast);
	};
	virtual void OnRspQrySubscribingSharesQuota(CZQThostFtdcSubscribingSharesQuotaField* pSubscribingSharesQuota, CZQThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) {
		mOnRspEvent(pObject, (int)EnumOnRspEvent::OnRspQrySubscribingSharesQuota, pSubscribingSharesQuota, pRspInfo, nRequestID, bIsLast);
	};
	virtual void OnRspQryRepoRatio(CZQThostFtdcRepoRatioField* pRepoRatio, CZQThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) {
		mOnRspEvent(pObject, (int)EnumOnRspEvent::OnRspQryRepoRatio, pRepoRatio, pRspInfo, nRequestID, bIsLast);
	};
	virtual void OnRspQryRepurchaseMaxTimes(CZQThostFtdcRepurchaseMaxTimesField* pRepurchaseMaxTimes, CZQThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) {
		mOnRspEvent(pObject, (int)EnumOnRspEvent::OnRspQryRepurchaseMaxTimes, pRepurchaseMaxTimes, pRspInfo, nRequestID, bIsLast);
	};
	virtual void OnRspQryTransferFund(CZQThostFtdcTransferFundField* pTransferFund, CZQThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) {
		mOnRspEvent(pObject, (int)EnumOnRspEvent::OnRspQryTransferFund, pTransferFund, pRspInfo, nRequestID, bIsLast);
	};
	virtual void OnRspQryTransferPosition(CZQThostFtdcTransferPositionField* pTransferPosition, CZQThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) {
		mOnRspEvent(pObject, (int)EnumOnRspEvent::OnRspQryTransferPosition, pTransferPosition, pRspInfo, nRequestID, bIsLast);
	};
	virtual void OnRspExecOrderInsert(CZQThostFtdcInputExecOrderField* pInputExecOrder, CZQThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) {
		mOnRspEvent(pObject, (int)EnumOnRspEvent::OnRspExecOrderInsert, pInputExecOrder, pRspInfo, nRequestID, bIsLast);
	};
	virtual void OnRtnExecOrder(CZQThostFtdcExecOrderField* pExecOrder) {
		mOnRtnEvent(pObject, (int)EnumOnRtnEvent::OnRtnExecOrder, pExecOrder);
	};
	virtual void OnErrRtnExecOrderInsert(CZQThostFtdcInputExecOrderField* pInputExecOrder, CZQThostFtdcRspInfoField* pRspInfo) {
		mOnErrRtnEvent(pObject, (int)EnumOnErrRtnEvent::OnErrRtnExecOrderInsert, pInputExecOrder, pRspInfo);
	};
	virtual void OnRspExecOrderAction(CZQThostFtdcInputExecOrderActionField* pInputExecOrderAction, CZQThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) {
		mOnRspEvent(pObject, (int)EnumOnRspEvent::OnRspExecOrderAction, pInputExecOrderAction, pRspInfo, nRequestID, bIsLast);
	};
	virtual void OnErrRtnExecOrderAction(CZQThostFtdcExecOrderActionField* pExecOrderAction, CZQThostFtdcRspInfoField* pRspInfo) {
		mOnErrRtnEvent(pObject, (int)EnumOnErrRtnEvent::OnErrRtnExecOrderAction, pExecOrderAction, pRspInfo);
	};
	virtual void OnRspLockInsert(CZQThostFtdcInputLockField* pInputLock, CZQThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) {
		mOnRspEvent(pObject, (int)EnumOnRspEvent::OnRspLockInsert, pInputLock, pRspInfo, nRequestID, bIsLast);
	};
	virtual void OnRtnLock(CZQThostFtdcLockField* pLock) {
		mOnRtnEvent(pObject, (int)EnumOnRtnEvent::OnRtnLock, pLock);
	};
	virtual void OnErrRtnLockInsert(CZQThostFtdcInputLockField* pInputLock, CZQThostFtdcRspInfoField* pRspInfo) {
		mOnErrRtnEvent(pObject, (int)EnumOnErrRtnEvent::OnErrRtnLockInsert, pInputLock, pRspInfo);
	};
	virtual void OnRspSecurityTransfer(CZQThostFtdcInputSecurityTransferField* pInputSecurityTransfer, CZQThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) {
		mOnRspEvent(pObject, (int)EnumOnRspEvent::OnRspSecurityTransfer, pInputSecurityTransfer, pRspInfo, nRequestID, bIsLast);
	};
	virtual void OnRtnSecurityTransfer(CZQThostFtdcSecurityTransferField* pSecurityTransfer) {
		mOnRtnEvent(pObject, (int)EnumOnRtnEvent::OnRtnSecurityTransfer, pSecurityTransfer);
	};
	virtual void OnErrRtnSecurityTransfer(CZQThostFtdcInputSecurityTransferField* pInputSecurityTransfer, CZQThostFtdcRspInfoField* pRspInfo) {
		mOnErrRtnEvent(pObject, (int)EnumOnErrRtnEvent::OnErrRtnSecurityTransfer, pInputSecurityTransfer, pRspInfo);
	};
	virtual void OnRspQryInstrument(CZQThostFtdcInstrumentField* pInstrument, CZQThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) {
		mOnRspEvent(pObject, (int)EnumOnRspEvent::OnRspQryInstrument, pInstrument, pRspInfo, nRequestID, bIsLast);
	};
	virtual void OnRspQryLock(CZQThostFtdcLockField* pLock, CZQThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) {
		mOnRspEvent(pObject, (int)EnumOnRspEvent::OnRspQryLock, pLock, pRspInfo, nRequestID, bIsLast);
	};
	virtual void OnRspQryExecOrder(CZQThostFtdcExecOrderField* pExecOrder, CZQThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) {
		mOnRspEvent(pObject, (int)EnumOnRspEvent::OnRspQryExecOrder, pExecOrder, pRspInfo, nRequestID, bIsLast);
	};
	virtual void OnRspQryLockPosition(CZQThostFtdcLockPositionField* pLockPosition, CZQThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) {
		mOnRspEvent(pObject, (int)EnumOnRspEvent::OnRspQryLockPosition, pLockPosition, pRspInfo, nRequestID, bIsLast);
	};
	virtual void OnRspQryMarginRate(CZQThostFtdcMarginRateField* pMarginRate, CZQThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) {
		mOnRspEvent(pObject, (int)EnumOnRspEvent::OnRspQryMarginRate, pMarginRate, pRspInfo, nRequestID, bIsLast);
	};
	virtual void OnRspQryLimitAmount(CZQThostFtdcLimitAmountField* pLimitAmount, CZQThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) {
		mOnRspEvent(pObject, (int)EnumOnRspEvent::OnRspQryLimitAmount, pLimitAmount, pRspInfo, nRequestID, bIsLast);
	};
	virtual void OnRspQryLimitPosition(CZQThostFtdcLimitPositionField* pLimitPosition, CZQThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) {
		mOnRspEvent(pObject, (int)EnumOnRspEvent::OnRspQryLimitPosition, pLimitPosition, pRspInfo, nRequestID, bIsLast);
	};
	virtual void OnRspQryExerciseAssignment(CZQThostFtdcExerciseAssignmentField* pExerciseAssignment, CZQThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) {
		mOnRspEvent(pObject, (int)EnumOnRspEvent::OnRspQryExerciseAssignment, pExerciseAssignment, pRspInfo, nRequestID, bIsLast);
	};
	virtual void OnRspQryInvestorPosition(CZQThostFtdcInvestorPositionField* pInvestorPosition, CZQThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) {
		mOnRspEvent(pObject, (int)EnumOnRspEvent::OnRspQryInvestorPosition, pInvestorPosition, pRspInfo, nRequestID, bIsLast);
	};
	virtual void OnRspQrySecurityTransfer(CZQThostFtdcSecurityTransferField* pSecurityTransfer, CZQThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) {
		mOnRspEvent(pObject, (int)EnumOnRspEvent::OnRspQrySecurityTransfer, pSecurityTransfer, pRspInfo, nRequestID, bIsLast);
	};
	virtual void OnRspQryLOFInfo(CZQThostFtdcLOFInfoField* pLOFInfo, CZQThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) {
		mOnRspEvent(pObject, (int)EnumOnRspEvent::OnRspQryLOFInfo, pLOFInfo, pRspInfo, nRequestID, bIsLast);
	};
	virtual void OnRspQryLOFSubInfo(CZQThostFtdcLOFSubInfoField* pLOFSubInfo, CZQThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) {
		mOnRspEvent(pObject, (int)EnumOnRspEvent::OnRspQryLOFSubInfo, pLOFSubInfo, pRspInfo, nRequestID, bIsLast);
	};
	virtual void OnRspCashRepayInsert(CZQThostFtdcInputCashRepayField* pInputCashRepay, CZQThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) {
		mOnRspEvent(pObject, (int)EnumOnRspEvent::OnRspCashRepayInsert, pInputCashRepay, pRspInfo, nRequestID, bIsLast);
	};
	virtual void OnRtnCashRepay(CZQThostFtdcCashRepayField* pCashRepay) {
		mOnRtnEvent(pObject, (int)EnumOnRtnEvent::OnRtnCashRepay, pCashRepay);
	};
	virtual void OnErrRtnCashRepayInsert(CZQThostFtdcInputCashRepayField* pInputCashRepay, CZQThostFtdcRspInfoField* pRspInfo) {
		mOnErrRtnEvent(pObject, (int)EnumOnErrRtnEvent::OnErrRtnCashRepayInsert, pInputCashRepay, pRspInfo);
	};
	virtual void OnRspQryCashRepay(CZQThostFtdcCashRepayField* pCashRepay, CZQThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) {
		mOnRspEvent(pObject, (int)EnumOnRspEvent::OnRspQryCashRepay, pCashRepay, pRspInfo, nRequestID, bIsLast);
	};
	virtual void OnRspQryCreditInfo(CZQThostFtdcCreditInfoField* pCreditInfo, CZQThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) {
		mOnRspEvent(pObject, (int)EnumOnRspEvent::OnRspQryCreditInfo, pCreditInfo, pRspInfo, nRequestID, bIsLast);
	};
	virtual void OnRspQryCreditSecurityPosition(CZQThostFtdcCreditSecurityPositionField* pCreditSecurityPosition, CZQThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) {
		mOnRspEvent(pObject, (int)EnumOnRspEvent::OnRspQryCreditSecurityPosition, pCreditSecurityPosition, pRspInfo, nRequestID, bIsLast);
	};
	virtual void OnRspQryCreditContract(CZQThostFtdcCreditContractField* pCreditContract, CZQThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) {
		mOnRspEvent(pObject, (int)EnumOnRspEvent::OnRspQryCreditContract, pCreditContract, pRspInfo, nRequestID, bIsLast);
	};
	virtual void OnRspQryCreditRepayment(CZQThostFtdcCreditRepaymentField* pCreditRepayment, CZQThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) {
		mOnRspEvent(pObject, (int)EnumOnRspEvent::OnRspQryCreditRepayment, pCreditRepayment, pRspInfo, nRequestID, bIsLast);
	};
	virtual void OnRspQryCreditUnderlying(CZQThostFtdcCreditUnderlyingField* pCreditUnderlying, CZQThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) {
		mOnRspEvent(pObject, (int)EnumOnRspEvent::OnRspQryCreditUnderlying, pCreditUnderlying, pRspInfo, nRequestID, bIsLast);
	};
	virtual void OnRspQryCreditCollateral(CZQThostFtdcCreditCollateralField* pCreditCollateral, CZQThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) {
		mOnRspEvent(pObject, (int)EnumOnRspEvent::OnRspQryCreditCollateral, pCreditCollateral, pRspInfo, nRequestID, bIsLast);
	};
	virtual void OnRspQryCreditFundPosition(CZQThostFtdcCreditFundPositionField* pCreditFundPosition, CZQThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) {
		mOnRspEvent(pObject, (int)EnumOnRspEvent::OnRspQryCreditFundPosition, pCreditFundPosition, pRspInfo, nRequestID, bIsLast);
	};

}; // end of class