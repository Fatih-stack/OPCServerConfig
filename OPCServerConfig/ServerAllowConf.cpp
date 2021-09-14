// ServerAllowConf.cpp : implementation file
//

#include "OPCServerConfig.h"
#include "ServerAllowConf.h"
#include "afxdialogex.h"

// ServerAllowConf dialog

IMPLEMENT_DYNAMIC(ServerAllowConf, CMFCPropertyPage)

ServerAllowConf::ServerAllowConf(CWnd* pParent /*=nullptr*/)
	: CMFCPropertyPage(IDD_ServerAllowConf)
{
}

ServerAllowConf::~ServerAllowConf()
{
}

void ServerAllowConf::DoDataExchange(CDataExchange* pDX)
{
	CMFCPropertyPage::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(ServerAllowConf, CMFCPropertyPage)
	ON_EN_CHANGE(IDC_EDIT_MaxReqAge, &ServerAllowConf::OnEnChangeEditMaxreqage)
	ON_EN_CHANGE(IDC_EDIT_MaxSessCount, &ServerAllowConf::OnEnChangeEditMaxsesscount)
	ON_EN_CHANGE(IDC_EDIT_MaxSessPerCli, &ServerAllowConf::OnEnChangeEditMaxsesspercli)
	ON_EN_CHANGE(IDC_EDIT_MinSessTimeout, &ServerAllowConf::OnEnChangeEditMinsesstimeout)
	ON_EN_CHANGE(IDC_EDIT_MaxSessTimeout, &ServerAllowConf::OnEnChangeEditMaxsesstimeout)
	ON_EN_CHANGE(IDC_EDIT_MaxBrowContPoints, &ServerAllowConf::OnEnChangeEditMaxbrowcontpoints)
	ON_EN_CHANGE(IDC_EDIT_MaxBrowsRes, &ServerAllowConf::OnEnChangeEditMaxbrowsres)
	ON_EN_CHANGE(IDC_EDIT_MaxNodesBrowse, &ServerAllowConf::OnEnChangeEditMaxnodesbrowse)
	ON_EN_CHANGE(IDC_EDIT_MaxDataQueueSize, &ServerAllowConf::OnEnChangeEditMaxdataqueuesize)
	ON_EN_CHANGE(IDC_EDIT_MaxEventQueSize, &ServerAllowConf::OnEnChangeEditMaxeventquesize)
	ON_EN_CHANGE(IDC_EDIT_MaxSubsCount, &ServerAllowConf::OnEnChangeEditMaxsubscount)
	ON_EN_CHANGE(IDC_EDIT_MinPublishInterval, &ServerAllowConf::OnEnChangeEditMinpublishinterval)
	ON_EN_CHANGE(IDC_EDIT_MaxPublishInterval, &ServerAllowConf::OnEnChangeEditMaxpublishinterval)
	ON_EN_CHANGE(IDC_EDIT_MinKeepAliveInterval, &ServerAllowConf::OnEnChangeEditMinkeepaliveinterval)
	ON_EN_CHANGE(IDC_EDIT_MaxNodePTBrowPath, &ServerAllowConf::OnEnChangeEditMaxnodeptbrowpath)
	ON_EN_CHANGE(IDC_EDIT_MaxNumNodesPHistRD, &ServerAllowConf::OnEnChangeEditMaxnumnodesphistrd)
	ON_EN_CHANGE(IDC_EDIT_MaxNodePHistREvnts, &ServerAllowConf::OnEnChangeEditMaxnodephistrevnts)
	ON_EN_CHANGE(IDC_EDIT_MaxNdPHistUpdData, &ServerAllowConf::OnEnChangeEditMaxndphistupddata)
	ON_EN_CHANGE(IDC_EDIT_MaxNdPHistUpdEvnts, &ServerAllowConf::OnEnChangeEditMaxndphistupdevnts)
	ON_EN_CHANGE(IDC_EDIT_MaxHistContPoints, &ServerAllowConf::OnEnChangeEditMaxhistcontpoints)
	ON_EN_CHANGE(IDC_EDIT_MinSubsLifeTime, &ServerAllowConf::OnEnChangeEditMinsubslifetime)
	ON_EN_CHANGE(IDC_EDIT_MaxSubsLifeTime, &ServerAllowConf::OnEnChangeEditMaxsubslifetime)
	ON_EN_CHANGE(IDC_EDIT_MaxRetransQueSize, &ServerAllowConf::OnEnChangeEditMaxretransquesize)
	ON_EN_CHANGE(IDC_EDIT_MaxNotfctionPPublsh, &ServerAllowConf::OnEnChangeEditMaxnotfctionppublsh)
	ON_EN_CHANGE(IDC_EDIT_MaxSubsPSess, &ServerAllowConf::OnEnChangeEditMaxsubspsess)
	ON_EN_CHANGE(IDC_EDIT_MaxMontrdItemCnt, &ServerAllowConf::OnEnChangeEditMaxmontrditemcnt)
	ON_EN_CHANGE(IDC_EDIT_MaxMntrdItmPSubsCnt, &ServerAllowConf::OnEnChangeEditMaxmntrditmpsubscnt)
	ON_EN_CHANGE(IDC_EDIT_MaxMntrdItmPSessCnt, &ServerAllowConf::OnEnChangeEditMaxmntrditmpsesscnt)
	ON_EN_CHANGE(IDC_EDIT_MinSuppSmpleRate, &ServerAllowConf::OnEnChangeEditMinsuppsmplerate)
END_MESSAGE_MAP()


// ServerAllowConf message handlers
/*******************************************************************************************************
* DEF  : Takes xml node and edit control then sets edit control with node value by making conversions
* ARGS : pItem => related xml node for edit control --- editControlName => related edit control on GUI
* OUTPUT : next node in xml
********************************************************************************************************/
void ServerAllowConf::SetEditControl(tinyxml2::XMLElement* pItem, int editControlName)
{
	std::string temp = pItem->GetText();
	CString cStr = CA2T(temp.c_str(), CP_UTF8);
	SetDlgItemText(editControlName, cStr);
}

//take xml node and 4 edit control and sets 4 edits respectively by iterating node
tinyxml2::XMLElement* ServerAllowConf::SetEditControls(tinyxml2::XMLElement* pItem, int edit1, int edit2, int edit3, int edit4)
{
	SetEditControl(pItem, edit1);
	SetEditControl(pItem->NextSiblingElement(), edit2);
	SetEditControl(pItem->NextSiblingElement()->NextSiblingElement(), edit3);
	SetEditControl(pItem->NextSiblingElement()->NextSiblingElement()->NextSiblingElement(), edit4);
	return pItem->NextSiblingElement()->NextSiblingElement()->NextSiblingElement()->NextSiblingElement();
}

/*******************************************************************************************************
* DEF  : gets edit control and node strings then get edit control value and go to given place in xml file
*		 by using node strings write edit control's value to the given node in XML file
* ARGS : edit => related edit control --- nodes => all tags till the related node
* OUTPUT : Updates given xml tag's value in XML file
********************************************************************************************************/
void ServerAllowConf::GetEditTextUpdateXML(int edit, const std::vector<std::string>& nodes)
{
	CString cstr;
	GetDlgItemText(edit, cstr);
	Helper::UpdateXmlFileTagEdit(cstr, nodes);
}

void ServerAllowConf::OnEnChangeEditMaxreqage()
{
	GetEditTextUpdateXML(IDC_EDIT_MaxReqAge, { "UaServerConfig", "MaxRequestAge" });
}


void ServerAllowConf::OnEnChangeEditMaxsesscount()
{
	GetEditTextUpdateXML(IDC_EDIT_MaxSessCount, { "UaServerConfig", "MaxSessionCount" });
}


void ServerAllowConf::OnEnChangeEditMaxsesspercli()
{
	GetEditTextUpdateXML(IDC_EDIT_MaxSessPerCli, { "UaServerConfig", "MaxSessionsPerClient" });
}


void ServerAllowConf::OnEnChangeEditMinsesstimeout()
{
	GetEditTextUpdateXML(IDC_EDIT_MinSessTimeout, { "UaServerConfig", "MinSessionTimeout" });
}


void ServerAllowConf::OnEnChangeEditMaxsesstimeout()
{
	GetEditTextUpdateXML(IDC_EDIT_MaxSessTimeout, { "UaServerConfig", "MaxSessionTimeout" });
}


void ServerAllowConf::OnEnChangeEditMaxbrowcontpoints()
{
	GetEditTextUpdateXML(IDC_EDIT_MaxBrowContPoints, { "UaServerConfig", "MaxBrowseContinuationPoints" });
}


void ServerAllowConf::OnEnChangeEditMaxbrowsres()
{
	GetEditTextUpdateXML(IDC_EDIT_MaxBrowsRes, { "UaServerConfig", "MaxBrowseResults" });
}


void ServerAllowConf::OnEnChangeEditMaxnodesbrowse()
{
	GetEditTextUpdateXML(IDC_EDIT_MaxNodesBrowse, { "UaServerConfig", "MaxNodesToBrowse" });
}


void ServerAllowConf::OnEnChangeEditMaxdataqueuesize()
{
	GetEditTextUpdateXML(IDC_EDIT_MaxDataQueueSize, { "UaServerConfig", "MaxDataQueueSize" });
}


void ServerAllowConf::OnEnChangeEditMaxeventquesize()
{
	GetEditTextUpdateXML(IDC_EDIT_MaxEventQueSize, { "UaServerConfig", "MaxEventQueueSize" });
}


void ServerAllowConf::OnEnChangeEditMaxsubscount()
{
	GetEditTextUpdateXML(IDC_EDIT_MaxSubsCount, { "UaServerConfig", "MaxSubscriptionCount" });
}


void ServerAllowConf::OnEnChangeEditMinpublishinterval()
{
	GetEditTextUpdateXML(IDC_EDIT_MinPublishInterval, { "UaServerConfig", "MinPublishingInterval" });
}


void ServerAllowConf::OnEnChangeEditMaxpublishinterval()
{
	GetEditTextUpdateXML(IDC_EDIT_MaxPublishInterval, { "UaServerConfig", "MaxPublishingInterval" });
}


void ServerAllowConf::OnEnChangeEditMinkeepaliveinterval()
{
	GetEditTextUpdateXML(IDC_EDIT_MinKeepAliveInterval, { "UaServerConfig", "MinKeepAliveInterval" });
}


void ServerAllowConf::OnEnChangeEditMaxnodeptbrowpath()
{
	GetEditTextUpdateXML(IDC_EDIT_MaxNodePTBrowPath, { "UaServerConfig", "MaxNodesPerTranslateBrowsePathsToNodeIds" });
}


void ServerAllowConf::OnEnChangeEditMaxnumnodesphistrd()
{
	GetEditTextUpdateXML(IDC_EDIT_MaxNumNodesPHistRD, { "UaServerConfig", "MaxNodesPerHistoryReadData" });
}


void ServerAllowConf::OnEnChangeEditMaxnodephistrevnts()
{
	GetEditTextUpdateXML(IDC_EDIT_MaxNodePHistREvnts, { "UaServerConfig", "MaxNodesPerHistoryReadEvents" });
}


void ServerAllowConf::OnEnChangeEditMaxndphistupddata()
{
	GetEditTextUpdateXML(IDC_EDIT_MaxNdPHistUpdData, { "UaServerConfig", "MaxNodesPerHistoryUpdateData" });
}


void ServerAllowConf::OnEnChangeEditMaxndphistupdevnts()
{
	GetEditTextUpdateXML(IDC_EDIT_MaxNdPHistUpdEvnts, { "UaServerConfig", "MaxNodesPerHistoryUpdateEvents" });
}


void ServerAllowConf::OnEnChangeEditMaxhistcontpoints()
{
	GetEditTextUpdateXML(IDC_EDIT_MaxHistContPoints, { "UaServerConfig", "MaxHistoryContinuationPoints" });
}


void ServerAllowConf::OnEnChangeEditMinsubslifetime()
{
	GetEditTextUpdateXML(IDC_EDIT_MinSubsLifeTime, { "UaServerConfig", "MinSubscriptionLifetime" });
}


void ServerAllowConf::OnEnChangeEditMaxsubslifetime()
{
	GetEditTextUpdateXML(IDC_EDIT_MaxSubsLifeTime, { "UaServerConfig", "MaxSubscriptionLifetime" });
}


void ServerAllowConf::OnEnChangeEditMaxretransquesize()
{
	GetEditTextUpdateXML(IDC_EDIT_MaxRetransQueSize, { "UaServerConfig", "MaxRetransmissionQueueSize" });
}


void ServerAllowConf::OnEnChangeEditMaxnotfctionppublsh()
{
	GetEditTextUpdateXML(IDC_EDIT_MaxNotfctionPPublsh, { "UaServerConfig", "MaxNotificationsPerPublish" });
}


void ServerAllowConf::OnEnChangeEditMaxsubspsess()
{
	GetEditTextUpdateXML(IDC_EDIT_MaxSubsPSess, { "UaServerConfig", "MaxSubscriptionsPerSession" });
}


void ServerAllowConf::OnEnChangeEditMaxmontrditemcnt()
{
	GetEditTextUpdateXML(IDC_EDIT_MaxMontrdItemCnt, { "UaServerConfig", "MaxMonitoredItemCount" });
}


void ServerAllowConf::OnEnChangeEditMaxmntrditmpsubscnt()
{
	GetEditTextUpdateXML(IDC_EDIT_MaxMntrdItmPSubsCnt, { "UaServerConfig", "MaxMonitoredItemPerSubscriptionCount" });
}


void ServerAllowConf::OnEnChangeEditMaxmntrditmpsesscnt()
{
	GetEditTextUpdateXML(IDC_EDIT_MaxMntrdItmPSessCnt, { "UaServerConfig", "MaxMonitoredItemPerSessionCount" });
}


void ServerAllowConf::OnEnChangeEditMinsuppsmplerate()
{
	GetEditTextUpdateXML(IDC_EDIT_MinSuppSmpleRate, { "UaServerConfig", "MinSupportedSampleRate" });
}

// Calls on initialization read specific areas in xml file and insert XML values to the related tools on GUI
BOOL ServerAllowConf::OnInitDialog()
{
	CMFCPropertyPage::OnInitDialog();

	// XML root
	Helper::pNode = Helper::xmlDoc.RootElement();	//dosyanýn root'unu yükler
	if (nullptr == Helper::pNode)
		return FALSE;
	Helper::pNode = Helper::pNode->FirstChildElement("UaServerConfig");
	Helper::pNode = Helper::pNode->FirstChildElement("MaxRequestAge");		//related tag in XML file
	
	//Set edit controls 4 by 4 and iterate node in XML
	Helper::pNode = SetEditControls(Helper::pNode, IDC_EDIT_MaxReqAge, IDC_EDIT_MaxSessCount,
		IDC_EDIT_MaxSessPerCli, IDC_EDIT_MinSessTimeout);
	Helper::pNode = SetEditControls(Helper::pNode, IDC_EDIT_MaxSessTimeout, IDC_EDIT_MaxBrowContPoints,
		IDC_EDIT_MaxBrowsRes, IDC_EDIT_MaxNodesBrowse);
	Helper::pNode = SetEditControls(Helper::pNode, IDC_EDIT_MaxNodePTBrowPath, IDC_EDIT_MaxNumNodesPHistRD,
		IDC_EDIT_MaxNodePHistREvnts, IDC_EDIT_MaxNdPHistUpdData);
	Helper::pNode = SetEditControls(Helper::pNode, IDC_EDIT_MaxNdPHistUpdEvnts, IDC_EDIT_MaxHistContPoints,
		IDC_EDIT_MinPublishInterval, IDC_EDIT_MaxPublishInterval);
	Helper::pNode = SetEditControls(Helper::pNode, IDC_EDIT_MinKeepAliveInterval, IDC_EDIT_MinSubsLifeTime,
		IDC_EDIT_MaxSubsLifeTime, IDC_EDIT_MaxRetransQueSize);
	Helper::pNode = SetEditControls(Helper::pNode, IDC_EDIT_MaxNotfctionPPublsh, IDC_EDIT_MaxDataQueueSize,
		IDC_EDIT_MaxEventQueSize, IDC_EDIT_MaxSubsCount);
	Helper::pNode = SetEditControls(Helper::pNode, IDC_EDIT_MaxSubsPSess, IDC_EDIT_MaxMontrdItemCnt,
		IDC_EDIT_MaxMntrdItmPSubsCnt, IDC_EDIT_MaxMntrdItmPSessCnt);
	SetEditControl(Helper::pNode, IDC_EDIT_MinSuppSmpleRate);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}
