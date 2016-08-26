/////////////////////////////////////////////////////////////////////////
//// Ftdc C++ => C Adapter
//// Author : shawn666.liu@hotmail.com   
//// Generated at 2016/8/26 21:22:40
/////////////////////////////////////////////////////////////////////////

#pragma once

/// <summary>
/// 所有的OnErrRtnXXXX回调事件
/// </summary>
enum class EnumOnErrRtnEvent
{
	None,
	OnErrRtnOrderInsert,
	OnErrRtnOrderAction,
	OnErrRtnExecOrderInsert,
	OnErrRtnExecOrderAction,
	OnErrRtnLockInsert,
	OnErrRtnSecurityTransfer,
	OnErrRtnCashRepayInsert,
};

/// <summary>
/// 所有的OnFrontXXXX回调事件
/// </summary>
enum class EnumOnFrontEvent
{
	None,
	OnFrontConnected,
	OnFrontDisconnected,
};

/// <summary>
/// 所有的OnRspXXXX回调事件
/// </summary>
enum class EnumOnRspEvent
{
	None,
	OnRspError,
	OnRspUserLogin,
	OnRspUserLogout,
	OnRspSubMarketData,
	OnRspUnSubMarketData,
	OnRspAuthenticate,
	OnRspUserPasswordUpdate,
	OnRspOrderInsert,
	OnRspOrderAction,
	OnRspQryExchange,
	OnRspQryDepthMarketData,
	OnRspQrySecurity,
	OnRspQryETFFile,
	OnRspQryETFBasket,
	OnRspQrySubscribingShares,
	OnRspQryPledgeOrderInfo,
	OnRspQryMarket,
	OnRspQrySecurityProduct,
	OnRspQrySecurityClass,
	OnRspQryOrder,
	OnRspQryTrade,
	OnRspQryTradingAccount,
	OnRspQryInvestorSecurityPosition,
	OnRspQryInvestorPledgePosition,
	OnRspQryInvestorPledgeInfo,
	OnRspQryOrderFundDetail,
	OnRspQryInvestor,
	OnRspQryTradingCode,
	OnRspQryInvestUnit,
	OnRspQryInvestUnitAndTradingAcct,
	OnRspQryInvestUnitAndUser,
	OnRspQryBrokerage,
	OnRspQrySubscribingSharesQuota,
	OnRspQryRepoRatio,
	OnRspQryRepurchaseMaxTimes,
	OnRspQryTransferFund,
	OnRspQryTransferPosition,
	OnRspExecOrderInsert,
	OnRspExecOrderAction,
	OnRspLockInsert,
	OnRspSecurityTransfer,
	OnRspQryInstrument,
	OnRspQryLock,
	OnRspQryExecOrder,
	OnRspQryLockPosition,
	OnRspQryMarginRate,
	OnRspQryLimitAmount,
	OnRspQryLimitPosition,
	OnRspQryExerciseAssignment,
	OnRspQryInvestorPosition,
	OnRspQrySecurityTransfer,
	OnRspQryLOFInfo,
	OnRspQryLOFSubInfo,
	OnRspCashRepayInsert,
	OnRspQryCashRepay,
	OnRspQryCreditInfo,
	OnRspQryCreditSecurityPosition,
	OnRspQryCreditContract,
	OnRspQryCreditRepayment,
	OnRspQryCreditUnderlying,
	OnRspQryCreditCollateral,
	OnRspQryCreditFundPosition,
};

/// <summary>
/// 所有的OnRtnXXXX回调事件
/// </summary>
enum class EnumOnRtnEvent
{
	None,
	OnRtnDepthMarketData,
	OnRtnOrder,
	OnRtnTrade,
	OnRtnTradingNotice,
	OnRtnTransferFund,
	OnRtnTransferPosition,
	OnRtnExecOrder,
	OnRtnLock,
	OnRtnSecurityTransfer,
	OnRtnCashRepay,
};

