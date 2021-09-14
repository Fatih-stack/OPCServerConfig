// TraceTab.cpp : implementation file
//

#include "OPCServerConfig.h"
#include "TraceTab.h"
#include "afxdialogex.h"

// TraceTab dialog

IMPLEMENT_DYNAMIC(TraceTab, CMFCPropertyPage)

TraceTab::TraceTab(CWnd* pParent /*=nullptr*/)
	: CMFCPropertyPage(IDD_TRACE_TAB)
{
	
}

TraceTab::~TraceTab()
{
}

void TraceTab::DoDataExchange(CDataExchange* pDX)
{
	CMFCPropertyPage::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_MFCEDITBROWSE_TraceFile, m_EditBrowseTraceFile);
	DDX_Control(pDX, IDC_MFCEDITBROWSE_RejectedCert, m_RjctdCertDir);
	DDX_Control(pDX, IDC_COMBO_ENStckTrace, m_EnStackTrace);
	DDX_Control(pDX, IDC_COMBO_StckTraceLevel, m_StckTraceLevel);
	DDX_Control(pDX, IDC_COMBO_EnSrvrAppTrcLevel, m_EnSrvrAppTrace);
	DDX_Control(pDX, IDC_COMBO_SrvrAppTrcLevel, m_SrvrAppTrcLevel);
	DDX_Control(pDX, IDC_COMBO_AppTraceDisFlush, m_AppTrcDisFlush);
	DDX_Control(pDX, IDC_COMBO_TraceEvents, m_TraceEvents);
	DDX_Control(pDX, IDC_COMBO_EnPubSubStckTrce, m_EnPubSubStckTrace);
	DDX_Control(pDX, IDC_COMBO_AllowDeprSecPolcy, m_AllowDepSecPolcy);
	DDX_Control(pDX, IDC_COMBO_ProvisionModeAct, m_PrvsionModeActive);
	DDX_Control(pDX, IDC_COMBO_DeactAftInitConf, m_DeactAftInitConf);
}


BEGIN_MESSAGE_MAP(TraceTab, CMFCPropertyPage)
	ON_EN_CHANGE(IDC_MFCEDITBROWSE_TraceFile, &TraceTab::OnEnChangeMfceditbrowseTracefile)
	ON_CBN_SELCHANGE(IDC_COMBO_ENStckTrace, &TraceTab::OnCbnSelchangeComboEnstcktrace)
	ON_CBN_SELCHANGE(IDC_COMBO_AppTraceDisFlush, &TraceTab::OnCbnSelchangeComboApptracedisflush)
	ON_EN_CHANGE(IDC_EDIT_RejectedCertCount, &TraceTab::OnEnChangeEditRejectedcertcount)
	ON_EN_CHANGE(IDC_EDIT_MaxTraceEntries, &TraceTab::OnEnChangeEditMaxtraceentries)
	ON_EN_CHANGE(IDC_EDIT_MaxBackupFiles, &TraceTab::OnEnChangeEditMaxbackupfiles)
	ON_CBN_SELCHANGE(IDC_COMBO_StckTraceLevel, &TraceTab::OnCbnSelchangeComboStcktracelevel)
	ON_CBN_SELCHANGE(IDC_COMBO_EnSrvrAppTrcLevel, &TraceTab::OnCbnSelchangeComboEnsrvrapptrclevel)
	ON_CBN_SELCHANGE(IDC_COMBO_SrvrAppTrcLevel, &TraceTab::OnCbnSelchangeComboSrvrapptrclevel)
	ON_CBN_SELCHANGE(IDC_COMBO_TraceEvents, &TraceTab::OnCbnSelchangeComboTraceevents)
	ON_CBN_SELCHANGE(IDC_COMBO_EnPubSubStckTrce, &TraceTab::OnCbnSelchangeComboEnpubsubstcktrce)
	ON_CBN_SELCHANGE(IDC_COMBO_AllowDeprSecPolcy, &TraceTab::OnCbnSelchangeComboAllowdeprsecpolcy)
	ON_CBN_SELCHANGE(IDC_COMBO_ProvisionModeAct, &TraceTab::OnCbnSelchangeComboProvisionmodeact)
	ON_CBN_SELCHANGE(IDC_COMBO_DeactAftInitConf, &TraceTab::OnCbnSelchangeComboDeactaftinitconf)
	ON_EN_CHANGE(IDC_MFCEDITBROWSE_RejectedCert, &TraceTab::OnEnChangeMfceditbrowseRejectedcert)
END_MESSAGE_MAP()

/******************************************************************************************************
* DEF  : Takes xml node and edit control then sets edit control with node value by making conversions
* ARGS : pItem => related xml node for edit control --- editControlName => related edit control on GUI
* OUTPUT : next node in xml
*******************************************************************************************************/
tinyxml2::XMLElement* TraceTab::SetEditControl(tinyxml2::XMLElement* pItem, int editControlName)
{
	CString s2 = CA2T(pItem->GetText(), CP_UTF8);
	SetDlgItemText(editControlName, s2);
	return pItem->NextSiblingElement();
}

/********************************************************************************************************
* DEF  : gets edit control and node strings then get edit control value and go to given place in xml file
*		 by using node strings write edit control's value to the given node in XML file
* ARGS : edit => related edit control --- nodes => all tags till the related node
* OUTPUT : Updates given xml tag's value in XML file
*********************************************************************************************************/
void TraceTab::GetComboTextUpdateXML(int combo, const std::vector<std::string>& nodes)
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
void TraceTab::GetEditTextUpdateXML(int edit, const std::vector<std::string>& nodes)
{
	CString cstr;
	GetDlgItemText(edit, cstr);
	Helper::UpdateXmlFileTagEdit(cstr, nodes);
}


void TraceTab::OnEnChangeMfceditbrowseTracefile()
{
	Helper::editbrowseToXML(m_EditBrowseTraceFile, {"UaServerConfig", "Trace", "UaAppTraceFile"});
}


void TraceTab::OnCbnSelchangeComboEnstcktrace()
{
	GetComboTextUpdateXML(IDC_COMBO_ENStckTrace, { "UaServerConfig", "Trace", "UaStackTraceEnabled"});
}


void TraceTab::OnCbnSelchangeComboApptracedisflush()
{
	GetComboTextUpdateXML(IDC_COMBO_AppTraceDisFlush, {"UaServerConfig", "Trace", "UaAppTraceDisableFlush"});
}


void TraceTab::OnEnChangeEditRejectedcertcount()
{
	GetEditTextUpdateXML(IDC_EDIT_RejectedCertCount, {"UaServerConfig", "RejectedCertificatesCount"});
}



void TraceTab::OnEnChangeEditMaxtraceentries()
{
	GetEditTextUpdateXML(IDC_EDIT_MaxTraceEntries, { "UaServerConfig", "Trace", "UaAppTraceMaxEntries" });
}


void TraceTab::OnEnChangeEditMaxbackupfiles()
{
	GetEditTextUpdateXML(IDC_EDIT_MaxBackupFiles, {"UaServerConfig", "Trace", "UaAppTraceMaxBackup"});
}


void TraceTab::OnCbnSelchangeComboStcktracelevel()
{
	GetComboTextUpdateXML(IDC_COMBO_StckTraceLevel, {"UaServerConfig", "Trace", "UaStackTraceLevel"});
}


void TraceTab::OnCbnSelchangeComboEnsrvrapptrclevel()
{
	GetComboTextUpdateXML(IDC_COMBO_EnSrvrAppTrcLevel, { "UaServerConfig", "Trace", "UaAppTraceEnabled" });
}


void TraceTab::OnCbnSelchangeComboSrvrapptrclevel()
{
	GetComboTextUpdateXML(IDC_COMBO_SrvrAppTrcLevel, { "UaServerConfig", "Trace", "UaAppTraceLevel" });
}


void TraceTab::OnCbnSelchangeComboTraceevents()
{
	GetComboTextUpdateXML(IDC_COMBO_TraceEvents, { "UaServerConfig", "Trace", "TraceEvents" });
}


void TraceTab::OnCbnSelchangeComboEnpubsubstcktrce()
{
	GetComboTextUpdateXML(IDC_COMBO_EnPubSubStckTrce, { "UaServerConfig", "Trace", "PubSubStackTraceEnabled"});
}


void TraceTab::OnCbnSelchangeComboAllowdeprsecpolcy()
{
	GetComboTextUpdateXML(IDC_COMBO_AllowDeprSecPolcy, { "UaServerConfig", "AllowDeprecatedSecurityPolicies" });
}


void TraceTab::OnCbnSelchangeComboProvisionmodeact()
{
	GetComboTextUpdateXML(IDC_COMBO_ProvisionModeAct, { "UaServerConfig", "ProvisioningModeSettings", "IsActive"});
}


void TraceTab::OnCbnSelchangeComboDeactaftinitconf()
{
	GetComboTextUpdateXML(IDC_COMBO_DeactAftInitConf, { "UaServerConfig", "ProvisioningModeSettings" 
		,"DeactivateAfterInitialConfiguration"});
}

// Calls on initialization read specific areas in xml file and insert these values to the related tools on GUI
BOOL TraceTab::OnInitDialog()
{
	CMFCPropertyPage::OnInitDialog();

	m_EditBrowseTraceFile.EnableFileBrowseButton(L"LOG", L"log files|*.log||");
	// TODO:  Add extra initialization here
	Helper::pNode = Helper::xmlDoc.RootElement();	//dosyanýn root'unu yükler
	Helper::pNode = Helper::pNode->FirstChildElement("UaServerConfig");
	tinyxml2::XMLElement* pItemTrace = Helper::pNode->FirstChildElement("Trace");
	Helper::pNode = pItemTrace->FirstChildElement();
	Helper::pNode = Helper::SetComboBox(Helper::pNode, m_EnStackTrace);
	Helper::pNode = Helper::FindSetComboBox(Helper::pNode, m_StckTraceLevel);
	Helper::pNode = Helper::SetComboBox(Helper::pNode, m_EnSrvrAppTrace);
	Helper::pNode = Helper::FindSetComboBox(Helper::pNode, m_SrvrAppTrcLevel);
	Helper::pNode = SetEditControl(Helper::pNode, IDC_EDIT_MaxTraceEntries);
	Helper::pNode = SetEditControl(Helper::pNode, IDC_EDIT_MaxBackupFiles);
	Helper::pNode = Helper::SetComboBox(Helper::pNode, m_AppTrcDisFlush);
	CString s2 = CA2T(Helper::pNode->GetText(), CP_UTF8);
	m_EditBrowseTraceFile.SetWindowTextW(s2);
	Helper::pNode = Helper::FindSetComboBox(Helper::pNode->NextSiblingElement(), m_TraceEvents);
	Helper::pNode = Helper::SetComboBox(Helper::pNode, m_EnPubSubStckTrace);
	s2 = CA2T(pItemTrace->NextSiblingElement()->NextSiblingElement()->GetText(), CP_UTF8);
	m_RjctdCertDir.SetWindowTextW(s2);
	Helper::pNode = pItemTrace->NextSiblingElement()->NextSiblingElement()->NextSiblingElement();
	Helper::pNode = SetEditControl(Helper::pNode, IDC_EDIT_RejectedCertCount);
	Helper::pNode = Helper::SetComboBox(Helper::pNode, m_AllowDepSecPolcy);
	Helper::pNode = Helper::pNode->FirstChildElement();
	Helper::pNode = Helper::SetComboBox(Helper::pNode, m_PrvsionModeActive);
	Helper::SetComboBox(Helper::pNode, m_DeactAftInitConf);


	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}


void TraceTab::OnEnChangeMfceditbrowseRejectedcert()
{
	Helper::editbrowseToXML(m_RjctdCertDir, { "UaServerConfig", "RejectedCertificatesDirectory" });
}
