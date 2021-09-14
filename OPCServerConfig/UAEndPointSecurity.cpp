// UAEndPointSecurity.cpp : implementation file
//

#include "pch.h"
#include "OPCServerConfig.h"
#include "UAEndPointSecurity.h"
#include "afxdialogex.h"


// UAEndPointSecurity dialog

IMPLEMENT_DYNAMIC(UAEndPointSecurity, CMFCPropertyPage)

UAEndPointSecurity::UAEndPointSecurity(CWnd* pParent /*=nullptr*/)
	: CMFCPropertyPage(IDD_UAEndPoint_Security)
{
}

UAEndPointSecurity::~UAEndPointSecurity()
{
}

void UAEndPointSecurity::DoDataExchange(CDataExchange* pDX)
{
	CMFCPropertyPage::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO_IsVisible, m_IsVisible);
	DDX_Control(pDX, IDC_COMBO_IsDiscUrl, m_IsDiscUrl);
	DDX_Control(pDX, IDC_COMBO_AutoTrstAllClientCert, m_AutoTrstAllClntCerts);
	DDX_Control(pDX, IDC_COMBO_CreateSgnChain, m_CreateSignWithChain);
	DDX_Control(pDX, IDC_COMBO_DisErrCertTimeInvld, m_DisErrCertTimeInvld);
	DDX_Control(pDX, IDC_COMBO_DisErrCertIssTimeInvld, m_DisErrCertIssTimeInvld);
	DDX_Control(pDX, IDC_COMBO_DisErrCertRvctnUnknwn, m_DisErrCertRvctnUnknwn);
	DDX_Control(pDX, IDC_COMBO_DisErrCertIssRvctnUnknwn, m_DisErrCertIssRvctnUnknwn);
	DDX_Control(pDX, IDC_COMBO_DisErrCertKeyShort, m_DisErrCertKeyShort);
	DDX_Control(pDX, IDC_COMBO_DisErrCertKeyLong, m_DisErrCertKeyLong);
	DDX_Control(pDX, IDC_COMBO_DisAppUriCheck, m_DisAppUriCheck);
	DDX_Control(pDX, IDC_COMBO_DisNonceLngthChck, m_DisNonceLngthCheck);
	DDX_Control(pDX, IDC_COMBO_DisUserTokenPolicyChck, m_DisUsrPolcyIdCheck);
	DDX_Control(pDX, IDC_COMBO_DisCertSignAlgCheck, m_DisCertSignAlgCheck);
	DDX_Control(pDX, IDC_COMBO_DisCertUsageCheck, m_DisCertUsageCheck);
}


BEGIN_MESSAGE_MAP(UAEndPointSecurity, CMFCPropertyPage)
	ON_CBN_SELCHANGE(IDC_COMBO_IsVisible, &UAEndPointSecurity::OnCbnSelchangeComboIsvisible)
	ON_EN_CHANGE(IDC_EDIT_SerializerType, &UAEndPointSecurity::OnEnChangeEditSerializertype)
	ON_EN_CHANGE(IDC_EDIT_URL, &UAEndPointSecurity::OnEnChangeEditUrl)
	ON_CBN_SELCHANGE(IDC_COMBO_IsDiscUrl, &UAEndPointSecurity::OnCbnSelchangeComboIsdiscurl)
	ON_CBN_SELCHANGE(IDC_COMBO_AutoTrstAllClientCert, &UAEndPointSecurity::OnCbnSelchangeComboAutotrstallclientcert)
	ON_CBN_SELCHANGE(IDC_COMBO_CreateSgnChain, &UAEndPointSecurity::OnCbnSelchangeComboCreatesgnchain)
	ON_CBN_SELCHANGE(IDC_COMBO_DisErrCertTimeInvld, &UAEndPointSecurity::OnCbnSelchangeComboDiserrcerttimeinvld)
	ON_CBN_SELCHANGE(IDC_COMBO_DisErrCertIssTimeInvld, &UAEndPointSecurity::OnCbnSelchangeComboDiserrcertisstimeinvld)
	ON_CBN_SELCHANGE(IDC_COMBO_DisErrCertRvctnUnknwn, &UAEndPointSecurity::OnCbnSelchangeComboDiserrcertrvctnunknwn)
	ON_CBN_SELCHANGE(IDC_COMBO_DisErrCertIssRvctnUnknwn, &UAEndPointSecurity::OnCbnSelchangeComboDiserrcertissrvctnunknwn)
	ON_CBN_SELCHANGE(IDC_COMBO_DisErrCertKeyShort, &UAEndPointSecurity::OnCbnSelchangeComboDiserrcertkeyshort)
	ON_CBN_SELCHANGE(IDC_COMBO_DisErrCertKeyLong, &UAEndPointSecurity::OnCbnSelchangeComboDiserrcertkeylong)
	ON_CBN_SELCHANGE(IDC_COMBO_DisAppUriCheck, &UAEndPointSecurity::OnCbnSelchangeComboDisappuricheck)
	ON_CBN_SELCHANGE(IDC_COMBO_DisNonceLngthChck, &UAEndPointSecurity::OnCbnSelchangeComboDisnoncelngthchck)
	ON_CBN_SELCHANGE(IDC_COMBO_DisUserTokenPolicyChck, &UAEndPointSecurity::OnCbnSelchangeComboDisusertokenpolicychck)
	ON_CBN_SELCHANGE(IDC_COMBO_DisCertSignAlgCheck, &UAEndPointSecurity::OnCbnSelchangeComboDiscertsignalgcheck)
	ON_CBN_SELCHANGE(IDC_COMBO_DisCertUsageCheck, &UAEndPointSecurity::OnCbnSelchangeComboDiscertusagecheck)
	ON_EN_CHANGE(IDC_EDIT_SecPolicy, &UAEndPointSecurity::OnEnChangeEditSecpolicy)
	ON_EN_CHANGE(IDC_EDIT_MsgSecMode, &UAEndPointSecurity::OnEnChangeEditMsgsecmode)
	ON_EN_CHANGE(IDC_EDIT_SecurityPolicy, &UAEndPointSecurity::OnEnChangeEditSecuritypolicy)
	ON_EN_CHANGE(IDC_EDIT_MsgScrtyMode, &UAEndPointSecurity::OnEnChangeEditMsgscrtymode)
	ON_EN_CHANGE(IDC_EDIT_SecPolicy2, &UAEndPointSecurity::OnEnChangeEditSecpolicy2)
	ON_EN_CHANGE(IDC_EDIT_MsgScrtyMode3, &UAEndPointSecurity::OnEnChangeEditMsgscrtymode3)
	ON_EN_UPDATE(IDC_EDIT__MsgScrtyMode4, &UAEndPointSecurity::OnEnUpdateEdit)
	ON_EN_CHANGE(IDC_EDIT_SecPolicy3, &UAEndPointSecurity::OnEnChangeEditSecpolicy3)
	ON_EN_CHANGE(IDC_EDIT__MsgScrtyMode2, &UAEndPointSecurity::OnEnChangeEdit2)
	ON_EN_CHANGE(IDC_EDIT__MsgScrtyMode4, &UAEndPointSecurity::OnEnChangeEdit)
	ON_EN_CHANGE(IDC_EDIT_MsgScrtyMode5, &UAEndPointSecurity::OnEnChangeEditMsgscrtymode5)
	ON_EN_CHANGE(IDC_EDIT_MsgScrtyMode6, &UAEndPointSecurity::OnEnChangeEditMsgscrtymode6)
END_MESSAGE_MAP()

/******************************************************************************************************
* DEF  : Takes xml node and edit control then sets edit control with node value by making conversions
* ARGS : pItem => related xml node for edit control --- editControlName => related edit control on GUI
* OUTPUT : next node in xml
*******************************************************************************************************/
tinyxml2::XMLElement* UAEndPointSecurity::SetEditControl(tinyxml2::XMLElement* pItem, int editControlName)
{
	std::string temp = pItem->GetText();
	CString cStr = CA2T(temp.c_str(), CP_UTF8);
	SetDlgItemText(editControlName, cStr);
	return pItem->NextSiblingElement();
}

/********************************************************************************************************
* DEF  : gets edit control and node strings then get edit control value and go to given place in xml file
*		 by using node strings write edit control's value to the given node in XML file
* ARGS : edit => related edit control --- nodes => all tags till the related node
* OUTPUT : Updates given xml tag's value in XML file
*********************************************************************************************************/
void UAEndPointSecurity::GetComboTextUpdateXML(int combo, const std::vector<std::string>& nodes)
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
void UAEndPointSecurity::GetEditTextUpdateXML(int edit, const std::vector<std::string>& nodes)
{
	CString cstr;
	GetDlgItemText(edit, cstr);
	Helper::UpdateXmlFileTagEdit(cstr, nodes);
}

/******************************************************************************************************
* DEF  : Takes xml node and edit control then sets xml node with edit value by making conversions
* ARGS : pItem => related xml node for edit control --- edit => related edit id control on GUI
*******************************************************************************************************/
void UAEndPointSecurity::SecSettingUpdateXML(int edit, tinyxml2::XMLElement* pItem)
{
	CString cstr;
	GetDlgItemText(edit, cstr);
	std::string str(CW2A(cstr.GetString()));
	pItem->SetText(str.c_str());
//	Helper::xmlDoc.SaveFile("OpcServerConfig.xml");
}

// UAEndPointSecurity message handlers


void UAEndPointSecurity::OnCbnSelchangeComboIsvisible()
{
	GetComboTextUpdateXML(IDC_COMBO_IsVisible, { "UaServerConfig", "UaEndpoint", "IsVisible" });
}


void UAEndPointSecurity::OnEnChangeEditSerializertype()
{
	GetEditTextUpdateXML(IDC_EDIT_SerializerType, { "UaServerConfig", "UaEndpoint", "SerializerType" });
}


void UAEndPointSecurity::OnEnChangeEditUrl()
{
	GetEditTextUpdateXML(IDC_EDIT_URL, { "UaServerConfig", "UaEndpoint", "Url" });
}


void UAEndPointSecurity::OnCbnSelchangeComboIsdiscurl()
{
	GetComboTextUpdateXML(IDC_COMBO_IsDiscUrl, { "UaServerConfig", "UaEndpoint", "IsDiscoveryUrl" });
}


void UAEndPointSecurity::OnCbnSelchangeComboAutotrstallclientcert()
{
	GetComboTextUpdateXML(IDC_COMBO_AutoTrstAllClientCert, { "UaServerConfig", "UaEndpoint", "AutomaticallyTrustAllClientCertificates" });
}


void UAEndPointSecurity::OnCbnSelchangeComboCreatesgnchain()
{
	GetComboTextUpdateXML(IDC_COMBO_CreateSgnChain, { "UaServerConfig", "UaEndpoint", "CreateSignatureWithChain" });
}


void UAEndPointSecurity::OnCbnSelchangeComboDiserrcerttimeinvld()
{
	GetComboTextUpdateXML(IDC_COMBO_DisErrCertTimeInvld, { "UaServerConfig", "UaEndpoint", 
		"SecurityCheckOverwrites", "DisableErrorCertificateTimeInvalid" });
}


void UAEndPointSecurity::OnCbnSelchangeComboDiserrcertisstimeinvld()
{
	GetComboTextUpdateXML(IDC_COMBO_DisErrCertIssTimeInvld, { "UaServerConfig", "UaEndpoint", "SecurityCheckOverwrites", 
		"DisableErrorCertificateIssuerTimeInvalid" });
}


void UAEndPointSecurity::OnCbnSelchangeComboDiserrcertrvctnunknwn()
{
	GetComboTextUpdateXML(IDC_COMBO_DisErrCertRvctnUnknwn, { "UaServerConfig", "UaEndpoint", "SecurityCheckOverwrites", 
		"DisableErrorCertificateRevocationUnknown" });
}


void UAEndPointSecurity::OnCbnSelchangeComboDiserrcertissrvctnunknwn()
{
	GetComboTextUpdateXML(IDC_COMBO_DisErrCertIssRvctnUnknwn, { "UaServerConfig", "UaEndpoint", "SecurityCheckOverwrites", 
		"DisableErrorCertificateIssuerRevocationUnknown" });
}


void UAEndPointSecurity::OnCbnSelchangeComboDiserrcertkeyshort()
{
	GetComboTextUpdateXML(IDC_COMBO_DisErrCertKeyShort, { "UaServerConfig", "UaEndpoint", 
		"SecurityCheckOverwrites", "DisableErrorCertificateKeyTooShort" });
}


void UAEndPointSecurity::OnCbnSelchangeComboDiserrcertkeylong()
{
	GetComboTextUpdateXML(IDC_COMBO_DisErrCertKeyLong, { "UaServerConfig", "UaEndpoint", 
		"SecurityCheckOverwrites", "DisableErrorCertificateKeyTooLong" });
}


void UAEndPointSecurity::OnCbnSelchangeComboDisappuricheck()
{
	GetComboTextUpdateXML(IDC_COMBO_DisAppUriCheck, {"UaServerConfig","UaEndpoint","SecurityCheckOverwrites","DisableApplicationUriCheck"});
}


void UAEndPointSecurity::OnCbnSelchangeComboDisnoncelngthchck()
{
	GetComboTextUpdateXML(IDC_COMBO_DisNonceLngthChck, {"UaServerConfig","UaEndpoint","SecurityCheckOverwrites","DisableNonceLengthCheck"});
}


void UAEndPointSecurity::OnCbnSelchangeComboDisusertokenpolicychck()
{
	GetComboTextUpdateXML(IDC_COMBO_DisUserTokenPolicyChck, { "UaServerConfig", "UaEndpoint",
		"SecurityCheckOverwrites", "DisableUserTokenPolicyIdCheck" });
}


void UAEndPointSecurity::OnCbnSelchangeComboDiscertsignalgcheck()
{
	GetComboTextUpdateXML(IDC_COMBO_DisCertSignAlgCheck, { "UaServerConfig", "UaEndpoint", 
		"SecurityCheckOverwrites", "DisableCertificateSignatureAlgorithmCheck" });
}


void UAEndPointSecurity::OnCbnSelchangeComboDiscertusagecheck()
{
	GetComboTextUpdateXML(IDC_COMBO_DisCertUsageCheck, { "UaServerConfig", "UaEndpoint", 
		"SecurityCheckOverwrites", "DisableCertificateUsageCheck" });
}


void UAEndPointSecurity::OnEnChangeEditSecpolicy()
{
	GetEditTextUpdateXML(IDC_EDIT_SecPolicy, { "UaServerConfig", "UaEndpoint", "SecuritySetting", "SecurityPolicy" });
}


void UAEndPointSecurity::OnEnChangeEditMsgsecmode()
{
	GetEditTextUpdateXML(IDC_EDIT_MsgSecMode, { "UaServerConfig", "UaEndpoint", "SecuritySetting", "MessageSecurityMode" });
}


void UAEndPointSecurity::OnEnChangeEditSecuritypolicy()
{
	Helper::pNode = Helper::xmlDoc.RootElement()->FirstChildElement("UaServerConfig")->FirstChildElement("UaEndpoint")
		->FirstChildElement("SecuritySetting")->NextSiblingElement()->FirstChildElement("SecurityPolicy");
	SecSettingUpdateXML(IDC_EDIT_SecurityPolicy, Helper::pNode);
}


void UAEndPointSecurity::OnEnChangeEditMsgscrtymode()
{
	Helper::pNode = Helper::xmlDoc.RootElement()->FirstChildElement("UaServerConfig")->FirstChildElement("UaEndpoint")
		->FirstChildElement("SecuritySetting")->NextSiblingElement()->FirstChildElement("MessageSecurityMode");
	SecSettingUpdateXML(IDC_EDIT_MsgScrtyMode, Helper::pNode);
}

void UAEndPointSecurity::OnEnChangeEditSecpolicy2()
{
	Helper::pNode = Helper::xmlDoc.RootElement()->FirstChildElement("UaServerConfig")->FirstChildElement("UaEndpoint")
		->FirstChildElement("SecuritySetting")->NextSiblingElement()->NextSiblingElement()->FirstChildElement("SecurityPolicy");
	SecSettingUpdateXML(IDC_EDIT_SecPolicy2, Helper::pNode);
}


void UAEndPointSecurity::OnEnChangeEditMsgscrtymode3()
{
	Helper::pNode = Helper::xmlDoc.RootElement()->FirstChildElement("UaServerConfig")->FirstChildElement("UaEndpoint")
		->FirstChildElement("SecuritySetting")->NextSiblingElement()->NextSiblingElement()->FirstChildElement("MessageSecurityMode");
	SecSettingUpdateXML(IDC_EDIT_MsgScrtyMode3, Helper::pNode);
}


void UAEndPointSecurity::OnEnUpdateEdit()
{
	
}


void UAEndPointSecurity::OnEnChangeEditSecpolicy3()
{
	Helper::pNode = Helper::xmlDoc.RootElement()->FirstChildElement("UaServerConfig")->FirstChildElement("UaEndpoint")
		->FirstChildElement("SecuritySetting")->NextSiblingElement()->NextSiblingElement()->NextSiblingElement()
		->FirstChildElement("SecurityPolicy");
	SecSettingUpdateXML(IDC_EDIT_SecPolicy3, Helper::pNode);
}


void UAEndPointSecurity::OnEnChangeEdit()
{
	Helper::pNode = Helper::xmlDoc.RootElement()->FirstChildElement("UaServerConfig")->FirstChildElement("UaEndpoint")
		->FirstChildElement("SecuritySetting")->NextSiblingElement()->NextSiblingElement()->FirstChildElement("MessageSecurityMode")
		->NextSiblingElement();
	SecSettingUpdateXML(IDC_EDIT__MsgScrtyMode4, Helper::pNode);
}

void UAEndPointSecurity::OnEnChangeEdit2()
{
	Helper::pNode = Helper::xmlDoc.RootElement()->FirstChildElement("UaServerConfig")->FirstChildElement("UaEndpoint")
		->FirstChildElement("SecuritySetting")->NextSiblingElement()->FirstChildElement("MessageSecurityMode")->NextSiblingElement();
	SecSettingUpdateXML(IDC_EDIT__MsgScrtyMode2, Helper::pNode);
}

void UAEndPointSecurity::OnEnChangeEditMsgscrtymode5()
{
	Helper::pNode = Helper::xmlDoc.RootElement()->FirstChildElement("UaServerConfig")->FirstChildElement("UaEndpoint")
		->FirstChildElement("SecuritySetting")->NextSiblingElement()->NextSiblingElement()->NextSiblingElement()
		->FirstChildElement("MessageSecurityMode");
	SecSettingUpdateXML(IDC_EDIT_MsgScrtyMode5, Helper::pNode);
}


void UAEndPointSecurity::OnEnChangeEditMsgscrtymode6()
{
	Helper::pNode = Helper::xmlDoc.RootElement()->FirstChildElement("UaServerConfig")->FirstChildElement("UaEndpoint")
		->FirstChildElement("SecuritySetting")->NextSiblingElement()->NextSiblingElement()->NextSiblingElement()
		->FirstChildElement("MessageSecurityMode")->NextSiblingElement();
	SecSettingUpdateXML(IDC_EDIT_MsgScrtyMode6, Helper::pNode);
}

// Calls on initialization read specific areas in xml file and insert these values to the related tools on GUI
BOOL UAEndPointSecurity::OnInitDialog()
{
	CMFCPropertyPage::OnInitDialog();

	// XML root
	auto pXML = Helper::xmlDoc.RootElement();	//dosyanýn root'unu yükler
	if (nullptr == pXML)
		return FALSE;
	Helper::pNode = pXML->FirstChildElement("UaServerConfig");	//Uzun ifadelerde auto kullan tinyxml2::XMLElement* yerine

	Helper::pNode = Helper::pNode->FirstChildElement("UaEndpoint");
	Helper::pNode = Helper::pNode->FirstChildElement();

	//go to UaEndpoint node's child then set gui controls with tag values read from xml then iterate node by node
	Helper::pNode = SetEditControl(Helper::pNode, IDC_EDIT_SerializerType);
	Helper::pNode = SetEditControl(Helper::pNode, IDC_EDIT_URL);
	Helper::pNode = Helper::SetComboBox(Helper::pNode, m_IsVisible);
	Helper::pNode = Helper::SetComboBox(Helper::pNode, m_IsDiscUrl);
	Helper::pNode = Helper::SetComboBox(Helper::pNode, m_AutoTrstAllClntCerts);
	Helper::pNode = Helper::SetComboBox(Helper::pNode, m_CreateSignWithChain);

	//SecurityCheckOverwrites
	Helper::pNode = Helper::pNode->FirstChildElement();
	Helper::pNode = Helper::SetComboBox(Helper::pNode, m_DisErrCertTimeInvld);
	Helper::pNode = Helper::SetComboBox(Helper::pNode, m_DisErrCertIssTimeInvld);
	Helper::pNode = Helper::SetComboBox(Helper::pNode, m_DisErrCertRvctnUnknwn);
	Helper::pNode = Helper::SetComboBox(Helper::pNode, m_DisErrCertIssRvctnUnknwn);
	Helper::pNode = Helper::SetComboBox(Helper::pNode, m_DisErrCertKeyShort);
	Helper::pNode = Helper::SetComboBox(Helper::pNode, m_DisErrCertKeyLong);
	Helper::pNode = Helper::SetComboBox(Helper::pNode, m_DisAppUriCheck);
	Helper::pNode = Helper::SetComboBox(Helper::pNode, m_DisNonceLngthCheck);
	Helper::pNode = Helper::SetComboBox(Helper::pNode, m_DisUsrPolcyIdCheck);
	Helper::pNode = Helper::SetComboBox(Helper::pNode, m_DisCertSignAlgCheck);
	Helper::SetComboBox(Helper::pNode, m_DisCertUsageCheck);
	Helper::pNode = pXML->FirstChildElement("UaServerConfig");
	Helper::pNode = Helper::pNode->FirstChildElement("UaEndpoint")->FirstChildElement("SecuritySetting")->FirstChildElement();
	Helper::pNode = SetEditControl(Helper::pNode, IDC_EDIT_SecPolicy);
	SetEditControl(Helper::pNode, IDC_EDIT_MsgSecMode);
	Helper::pNode = pXML->FirstChildElement("UaServerConfig");
	Helper::pNode = Helper::pNode->FirstChildElement("UaEndpoint")->FirstChildElement("SecuritySetting")
		->NextSiblingElement()->FirstChildElement();
	Helper::pNode = SetEditControl(Helper::pNode, IDC_EDIT_SecurityPolicy);
	Helper::pNode = SetEditControl(Helper::pNode, IDC_EDIT_MsgScrtyMode);
	SetEditControl(Helper::pNode, IDC_EDIT__MsgScrtyMode2);
	Helper::pNode = pXML->FirstChildElement("UaServerConfig");
	Helper::pNode = Helper::pNode->FirstChildElement("UaEndpoint")->FirstChildElement("SecuritySetting")->NextSiblingElement()
		->NextSiblingElement()->FirstChildElement();
	Helper::pNode = SetEditControl(Helper::pNode, IDC_EDIT_SecPolicy2);
	Helper::pNode = SetEditControl(Helper::pNode, IDC_EDIT_MsgScrtyMode3);
	SetEditControl(Helper::pNode, IDC_EDIT__MsgScrtyMode4);
	Helper::pNode = pXML->FirstChildElement("UaServerConfig");
	Helper::pNode = Helper::pNode->FirstChildElement("UaEndpoint")->FirstChildElement("SecuritySetting")->NextSiblingElement()
		->NextSiblingElement()->NextSiblingElement()->FirstChildElement();
	Helper::pNode = SetEditControl(Helper::pNode, IDC_EDIT_SecPolicy3);
	Helper::pNode = SetEditControl(Helper::pNode, IDC_EDIT_MsgScrtyMode5);
	SetEditControl(Helper::pNode, IDC_EDIT_MsgScrtyMode6);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}
