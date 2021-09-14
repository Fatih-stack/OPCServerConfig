// ServerConf.cpp : implementation file
//

#include "pch.h"
#include "OPCServerConfig.h"
#include "ServerConf.h"
#include "afxdialogex.h"
#include "tinyxml2.h"

// ServerConf dialog

IMPLEMENT_DYNAMIC(ServerConf, CMFCPropertyPage)

ServerConf::ServerConf(CWnd* pParent /*=nullptr*/)
	: CMFCPropertyPage(IDD_SERVER_CONF)
{
}

ServerConf::~ServerConf()
{
}

void ServerConf::DoDataExchange(CDataExchange* pDX)
{
	CMFCPropertyPage::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_LiveQueSize, m_LiveQueSize);
	GetDlgItem(IDC_EDIT_LiveQueSize)->SetWindowText(m_CSLiveQSize);
	DDX_Control(pDX, IDC_COMBO_DrbleSubsSuppEn, m_DurableSubsEnabled);
	DDX_Control(pDX, IDC_COMBO_AudioActivated, m_AudioActivated);
	DDX_Control(pDX, IDC_MFCEDITBROWSE_DrbleSubs, m_StorageDir);
}


BEGIN_MESSAGE_MAP(ServerConf, CMFCPropertyPage)
	ON_CBN_SELCHANGE(IDC_COMBO_DrbleSubsSuppEn, &ServerConf::OnCbnSelchangeComboDrblesubssuppen)
	ON_CBN_SELCHANGE(IDC_COMBO_AvailblSmplngRates, &ServerConf::OnCbnSelchangeComboAvailblsmplngrates)
	ON_EN_CHANGE(IDC_EDIT_HostName, &ServerConf::OnEnChangeEditHostname)
	ON_EN_CHANGE(IDC_EDIT_Geometry, &ServerConf::OnEnChangeEditGeometry)
	ON_EN_CHANGE(IDC_MFCEDITBROWSE_DrbleSubs, &ServerConf::OnEnChangeMfceditbrowseDrblesubs)
	ON_EN_CHANGE(IDC_EDIT_MaxSubsLifeTime, &ServerConf::OnEnChangeEditMaxsubslifetime)
	ON_EN_CHANGE(IDC_EDIT_MaxMonitItmQueSize, &ServerConf::OnEnChangeEditMaxmonititmquesize)
	ON_EN_CHANGE(IDC_EDIT_LiveQueSize, &ServerConf::OnEnChangeEditLivequesize)
	ON_CBN_SELCHANGE(IDC_COMBO_AudioActivated, &ServerConf::OnCbnSelchangeComboAudioactivated)
	ON_EN_CHANGE(IDC_EDIT_ProductUri, &ServerConf::OnEnChangeEditProducturi)
	ON_EN_CHANGE(IDC_EDIT_ManfcturerName, &ServerConf::OnEnChangeEditManfcturername)
	ON_EN_CHANGE(IDC_EDIT_ProductName, &ServerConf::OnEnChangeEditProductname)
	ON_EN_CHANGE(IDC_EDIT_SoftwareVersion, &ServerConf::OnEnChangeEditSoftwareversion)
	ON_EN_CHANGE(IDC_EDIT_BuildNumber, &ServerConf::OnEnChangeEditBuildnumber)
	ON_EN_CHANGE(IDC_EDIT_ServerUri, &ServerConf::OnEnChangeEditServeruri)
	ON_EN_CHANGE(IDC_EDIT_ServerName, &ServerConf::OnEnChangeEditServername)
END_MESSAGE_MAP()

/*******************************************************************************************************
* DEF  : Takes xml node and edit control then sets edit control with node value by making conversions
* ARGS : pItem => related xml node for edit control --- editControlName => related edit control on GUI
* OUTPUT : next node in xml
********************************************************************************************************/
tinyxml2::XMLElement* ServerConf::SetEditControl(tinyxml2::XMLElement* pItem, int editControlName)
{
	std::string temp = pItem->GetText();
	CString cStr = CA2T(temp.c_str(), CP_UTF8);
	SetDlgItemText(editControlName, cStr);
	return pItem->NextSiblingElement();
}


/*******************************************************************************************************
* DEF  : gets combo control and node strings then get combo value and go to given place in xml file
*		 by using node strings write combo value to the given node in XML file
* ARGS : combo => related combo control --- nodes => all tags till the related node
* OUTPUT : Updates given xml tag's value in XML file
********************************************************************************************************/
void ServerConf::GetComboTextUpdateXML(int combo, const std::vector<std::string>& nodes)
{
	CString cStr;
	CWnd* Pfield = GetDlgItem(combo);
	Pfield->GetWindowText(cStr);
	Helper::UpdateXmlFileTagCombo(cStr, nodes);
}


/*********************************************************************************************************
* DEF  : gets edit control and node strings then get edit control value and go to given place in xml file
*		 by using node strings write edit control's value to the given node in XML file
* ARGS : edit => related edit control --- nodes => all tags till the related node
* OUTPUT : Updates given xml tag's value in XML file
**********************************************************************************************************/
void ServerConf::GetEditTextUpdateXML(int edit, const std::vector<std::string>& nodes)
{
	CString cstr;
	GetDlgItemText(edit, cstr);
	Helper::UpdateXmlFileTagEdit(cstr, nodes);
}

// ServerConf message handlers


void ServerConf::OnCbnSelchangeComboDrblesubssuppen()
{
	GetComboTextUpdateXML(IDC_COMBO_DrbleSubsSuppEn, { "UaServerConfig", "DurableSubscription", "Enabled" });
}


void ServerConf::OnCbnSelchangeComboAvailblsmplngrates()
{
	
}


void ServerConf::OnEnChangeEditHostname()
{
	GetEditTextUpdateXML(IDC_EDIT_HostName, { "ConfigTools", "AdminDialog", "Hostname" });
}


void ServerConf::OnEnChangeEditGeometry()
{
	GetEditTextUpdateXML(IDC_EDIT_Geometry, { "ConfigTools", "AdminDialog", "Geometry" });
}


void ServerConf::OnEnChangeMfceditbrowseDrblesubs()
{
	Helper::editbrowseToXML(m_StorageDir, { "UaServerConfig", "DurableSubscription", "StorageDirectory" });
}


void ServerConf::OnEnChangeEditMaxsubslifetime()
{
	GetEditTextUpdateXML(IDC_EDIT_MaxSubsLifeTime, { "UaServerConfig", "DurableSubscription", "MaxSubscriptionLifetimeInHours" });
}


void ServerConf::OnEnChangeEditMaxmonititmquesize()
{
	GetEditTextUpdateXML(IDC_EDIT_MaxMonitItmQueSize, { "UaServerConfig", "DurableSubscription", "MaxMonitoredItemQueueSize" });
}


void ServerConf::OnEnChangeEditLivequesize()
{
	GetEditTextUpdateXML(IDC_EDIT_LiveQueSize, { "UaServerConfig", "DurableSubscription", "LiveQueueSize" });
}


void ServerConf::OnCbnSelchangeComboAudioactivated()
{
	GetComboTextUpdateXML(IDC_COMBO_AudioActivated, { "UaServerConfig", "IsAuditActivated" });
}


void ServerConf::OnEnChangeEditProducturi()
{
	GetEditTextUpdateXML(IDC_EDIT_ProductUri, { "UaServerConfig", "ProductUri"});
}


void ServerConf::OnEnChangeEditManfcturername()
{
	GetEditTextUpdateXML(IDC_EDIT_ManfcturerName, { "UaServerConfig", "ManufacturerName" });
}


void ServerConf::OnEnChangeEditProductname()
{
	GetEditTextUpdateXML(IDC_EDIT_ProductName, { "UaServerConfig", "ProductName" });
}


void ServerConf::OnEnChangeEditSoftwareversion()
{
	GetEditTextUpdateXML(IDC_EDIT_SoftwareVersion, { "UaServerConfig", "SoftwareVersion" });
}


void ServerConf::OnEnChangeEditBuildnumber()
{
	GetEditTextUpdateXML(IDC_EDIT_BuildNumber, { "UaServerConfig", "BuildNumber" });
}


void ServerConf::OnEnChangeEditServeruri()
{
	GetEditTextUpdateXML(IDC_EDIT_ServerUri, { "UaServerConfig", "ServerUri" });
}


void ServerConf::OnEnChangeEditServername()
{
	GetEditTextUpdateXML(IDC_EDIT_ServerName, { "UaServerConfig", "ServerName" });
}

// Calls on initialization read specific areas in xml file and insert these values to the related tools on GUI
BOOL ServerConf::OnInitDialog()
{
	CMFCPropertyPage::OnInitDialog();

	m_LiveQueSize.GetWindowTextW(m_CSLiveQSize);
	int local = _ttoi(m_CSLiveQSize);
	if (local < 10)
		m_CSLiveQSize = "100";

	// XML root
	auto pXML = Helper::xmlDoc.RootElement();	//dosyanýn root'unu yükler
	if (nullptr == pXML)
		return FALSE;
	tinyxml2::XMLElement* pItems = pXML->FirstChildElement("UaServerConfig");
	Helper::pNode = pItems->FirstChildElement("DurableSubscription")->FirstChildElement();
	Helper::pNode = Helper::SetComboBox(Helper::pNode, m_DurableSubsEnabled);
	Helper::pNode = Helper::SetEditBrowse(Helper::pNode, m_StorageDir);
	Helper::pNode = SetEditControl(Helper::pNode, IDC_EDIT_MaxSubsLifeTime);
	Helper::pNode = SetEditControl(Helper::pNode, IDC_EDIT_MaxMonitItmQueSize);
	Helper::pNode = SetEditControl(Helper::pNode, IDC_EDIT_LiveQueSize);
	Helper::pNode = pItems->FirstChildElement("IsAuditActivated");
	Helper::pNode = Helper::SetComboBox(Helper::pNode, m_AudioActivated);
	Helper::pNode = Helper::pNode->NextSiblingElement();
	Helper::pNode = SetEditControl(Helper::pNode, IDC_EDIT_ProductUri);
	Helper::pNode = SetEditControl(Helper::pNode, IDC_EDIT_ManfcturerName);
	Helper::pNode = SetEditControl(Helper::pNode, IDC_EDIT_ProductName);
	Helper::pNode = SetEditControl(Helper::pNode, IDC_EDIT_SoftwareVersion);
	Helper::pNode = SetEditControl(Helper::pNode, IDC_EDIT_BuildNumber);
	Helper::pNode = SetEditControl(Helper::pNode, IDC_EDIT_ServerUri);
	Helper::pNode = SetEditControl(Helper::pNode, IDC_EDIT_ServerName);
	Helper::pNode = pXML->FirstChildElement("ConfigTools")->FirstChildElement()->FirstChildElement();
	Helper::pNode = SetEditControl(Helper::pNode, IDC_EDIT_HostName);
	SetEditControl(Helper::pNode, IDC_EDIT_Geometry);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}
