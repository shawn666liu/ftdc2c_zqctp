/////////////////////////////////////////////////////////////////////////
//// Ftdc C++ => C Adapter
//// Author : shawn666.liu@hotmail.com   
//// Generated at 2016/8/26 21:23:15
/////////////////////////////////////////////////////////////////////////

#pragma once
#include <ZQThostFtdcMdApi.h>
#include "enums.h"

class Quoter : public CZQThostFtdcMdSpi
{
public:
	CZQThostFtdcMdApi* RawApi{ nullptr };
	CbOnFrontEvent mOnFrontEvent{ nullptr };
	CbOnRspEvent mOnRspEvent{ nullptr };
	CbOnRtnEvent mOnRtnEvent{ nullptr };
	void* pObject;

	Quoter(const char* pszFlowPath, const bool bIsUsingUdp) {
		RawApi = CZQThostFtdcMdApi::CreateFtdcMdApi(pszFlowPath, bIsUsingUdp);
		RawApi->RegisterSpi(this);
		pObject = this;
	}


	virtual ~Quoter() {
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
	virtual void OnRspError(CZQThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) {
		mOnRspEvent(pObject, (int)EnumOnRspEvent::OnRspError, nullptr, pRspInfo, nRequestID, bIsLast);
	};
	virtual void OnRspUserLogin(CZQThostFtdcRspUserLoginField* pRspUserLogin, CZQThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) {
		mOnRspEvent(pObject, (int)EnumOnRspEvent::OnRspUserLogin, pRspUserLogin, pRspInfo, nRequestID, bIsLast);
	};
	virtual void OnRspUserLogout(CZQThostFtdcUserLogoutField* pUserLogout, CZQThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) {
		mOnRspEvent(pObject, (int)EnumOnRspEvent::OnRspUserLogout, pUserLogout, pRspInfo, nRequestID, bIsLast);
	};
	virtual void OnRspSubMarketData(CZQThostFtdcSpecificInstrumentField* pSpecificInstrument, CZQThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) {
		mOnRspEvent(pObject, (int)EnumOnRspEvent::OnRspSubMarketData, pSpecificInstrument, pRspInfo, nRequestID, bIsLast);
	};
	virtual void OnRspUnSubMarketData(CZQThostFtdcSpecificInstrumentField* pSpecificInstrument, CZQThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) {
		mOnRspEvent(pObject, (int)EnumOnRspEvent::OnRspUnSubMarketData, pSpecificInstrument, pRspInfo, nRequestID, bIsLast);
	};
	virtual void OnRtnDepthMarketData(CZQThostFtdcDepthMarketDataField* pDepthMarketData) {
		mOnRtnEvent(pObject, (int)EnumOnRtnEvent::OnRtnDepthMarketData, pDepthMarketData);
	};

}; // end of class