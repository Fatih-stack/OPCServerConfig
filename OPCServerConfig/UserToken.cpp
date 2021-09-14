// UserToken.cpp : implementation file
//

#include "OPCServerConfig.h"
#include "UserToken.h"
#include "afxdialogex.h"

// UserToken dialog

IMPLEMENT_DYNAMIC(UserToken, CMFCPropertyPage)

UserToken::UserToken(CWnd* pParent /*=nullptr*/)
	: CMFCPropertyPage(IDD_UserToken)
{
}

UserToken::~UserToken()
{
}

void UserToken::DoDataExchange(CDataExchange* pDX)
{
	CMFCPropertyPage::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO_EnAnnymsLogin, m_EnAnnymousLogin);
	DDX_Control(pDX, IDC_COMBO_EnUserPassLog, m_EnUserPassLogin);
	DDX_Control(pDX, IDC_COMBO_EnCert, m_EnableCert);
	DDX_Control(pDX, IDC_COMBO_AutoCertExchnge, m_AutoCertExchnge);
	DDX_Control(pDX, IDC_COMBO_RdndncySupp, m_RdndncySupp);
	DDX_Control(pDX, IDC_MFCEDITBROWSE_CertTrustLst, m_CertTrstListLoc);
	DDX_Control(pDX, IDC_MFCEDITBROWSE_CertRevocList, m_CertRvctionListLoc);
	DDX_Control(pDX, IDC_MFCEDITBROWSE_IssuerCert, m_IssuerCertLoc);
	DDX_Control(pDX, IDC_MFCEDITBROWSE_IssuerRevocList, m_IssuerRvctionListLoc);
	DDX_Control(pDX, IDC_MFCEDITBROWSE_RjctedUsrCert, m_RjctdUserCertDir);
}


BEGIN_MESSAGE_MAP(UserToken, CMFCPropertyPage)
	ON_CBN_SELCHANGE(IDC_COMBO_EnCert, &UserToken::OnCbnSelchangeComboEncert)
	ON_EN_CHANGE(IDC_MFCEDITBROWSE_CertTrustLst, &UserToken::OnEnChangeMfceditbrowseCerttrustlst)
	ON_CBN_SELCHANGE(IDC_COMBO_EnAnnymsLogin, &UserToken::OnCbnSelchangeComboEnannymslogin)
	ON_CBN_SELCHANGE(IDC_COMBO_EnUserPassLog, &UserToken::OnCbnSelchangeComboEnuserpasslog)
	ON_EN_CHANGE(IDC_EDIT_SecPolicy, &UserToken::OnEnChangeEditSecpolicy)
	ON_EN_CHANGE(IDC_MFCEDITBROWSE_CertRevocList, &UserToken::OnEnChangeMfceditbrowseCertrevoclist)
	ON_EN_CHANGE(IDC_MFCEDITBROWSE_IssuerCert, &UserToken::OnEnChangeMfceditbrowseIssuercert)
	ON_EN_CHANGE(IDC_MFCEDITBROWSE_IssuerRevocList, &UserToken::OnEnChangeMfceditbrowseIssuerrevoclist)
	ON_EN_CHANGE(IDC_MFCEDITBROWSE_RjctedUsrCert, &UserToken::OnEnChangeMfceditbrowseRjctedusrcert)
	ON_EN_CHANGE(IDC_EDIT_MaxRjctedUserCertCnt, &UserToken::OnEnChangeEditMaxrjctedusercertcnt)
	ON_CBN_SELCHANGE(IDC_COMBO_AutoCertExchnge, &UserToken::OnCbnSelchangeComboAutocertexchnge)
	ON_EN_CHANGE(IDC_EDIT_DiscSrvrStoreName, &UserToken::OnEnChangeEditDiscsrvrstorename)
	ON_EN_CHANGE(IDC_EDIT_DiscSrvrCertName, &UserToken::OnEnChangeEditDiscsrvrcertname)
	ON_EN_CHANGE(IDC_EDIT_RegistrationInterval, &UserToken::OnEnChangeEditRegistrationinterval)
	ON_EN_CHANGE(IDC_EDIT_MaxMemoryAlloc, &UserToken::OnEnChangeEditMaxmemoryalloc)
	ON_EN_CHANGE(IDC_EDIT_MaxStrngLngth, &UserToken::OnEnChangeEditMaxstrnglngth)
	ON_EN_CHANGE(IDC_EDIT_MaxByteStrngLngth, &UserToken::OnEnChangeEditMaxbytestrnglngth)
	ON_EN_CHANGE(IDC_EDIT_MaxArrayLngth, &UserToken::OnEnChangeEditMaxarraylngth)
	ON_EN_CHANGE(IDC_EDIT_MaxMsgSize, &UserToken::OnEnChangeEditMaxmsgsize)
	ON_CBN_SELCHANGE(IDC_COMBO_RdndncySupp, &UserToken::OnCbnSelchangeComboRdndncysupp)
END_MESSAGE_MAP()

/******************************************************************************************************
* DEF  : Takes xml node and edit control then sets edit control with node value by making conversions
* ARGS : pItem => related xml node for edit control --- editControlName => related edit control on GUI
* OUTPUT : next node in xml
*******************************************************************************************************/
tinyxml2::XMLElement* UserToken::SetEditControl(tinyxml2::XMLElement* pItem, int editControlName)
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
void UserToken::GetComboTextUpdateXML(int combo, const std::vector<std::string>& nodes)
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
void UserToken::GetEditTextUpdateXML(int edit, const std::vector<std::string>& nodes)
{
	CString cstr;
	GetDlgItemText(edit, cstr);
	Helper::UpdateXmlFileTagEdit(cstr, nodes);
}

// UserToken message handlers


void UserToken::OnCbnSelchangeComboEncert()
{
	GetComboTextUpdateXML(IDC_COMBO_EnCert, { "UaServerConfig", "UserIdentityTokens", "EnableCertificate" });
}


void UserToken::OnEnChangeMfceditbrowseCerttrustlst()
{
	Helper::editbrowseToXML(m_CertTrstListLoc, { "UaServerConfig", "UserIdentityTokens", "DefaultUserCertificateStore", 
		"CertificateTrustListLocation" });
}


void UserToken::OnCbnSelchangeComboEnannymslogin()
{
	GetComboTextUpdateXML(IDC_COMBO_EnAnnymsLogin, { "UaServerConfig", "UserIdentityTokens", "EnableAnonymous" });
}


void UserToken::OnCbnSelchangeComboEnuserpasslog()
{
	GetComboTextUpdateXML(IDC_COMBO_EnUserPassLog, { "UaServerConfig", "UserIdentityTokens", "EnableUserPw" });
}


void UserToken::OnEnChangeEditSecpolicy()
{
	GetEditTextUpdateXML(IDC_EDIT_SecPolicy, { "UaServerConfig", "UserIdentityTokens", "SecurityPolicy" });
}


void UserToken::OnEnChangeMfceditbrowseCertrevoclist()
{
	Helper::editbrowseToXML(m_CertRvctionListLoc, { "UaServerConfig", "UserIdentityTokens", "DefaultUserCertificateStore",
		"CertificateRevocationListLocation" });
}


void UserToken::OnEnChangeMfceditbrowseIssuercert()
{
	Helper::editbrowseToXML(m_IssuerCertLoc, { "UaServerConfig", "UserIdentityTokens", "DefaultUserCertificateStore",
		"IssuersCertificatesLocation" });
}


void UserToken::OnEnChangeMfceditbrowseIssuerrevoclist()
{
	Helper::editbrowseToXML(m_IssuerRvctionListLoc, { "UaServerConfig", "UserIdentityTokens", "DefaultUserCertificateStore",
		"IssuersRevocationListLocation" });
}


void UserToken::OnEnChangeMfceditbrowseRjctedusrcert()
{
	Helper::editbrowseToXML(m_RjctdUserCertDir, { "UaServerConfig", "UserIdentityTokens", "RejectedUserCertificatesDirectory" });
}


void UserToken::OnEnChangeEditMaxrjctedusercertcnt()
{
	GetEditTextUpdateXML(IDC_EDIT_MaxRjctedUserCertCnt, { "UaServerConfig", "UserIdentityTokens", "RejectedUserCertificatesCount" });
}


void UserToken::OnCbnSelchangeComboAutocertexchnge()
{
	GetComboTextUpdateXML(IDC_COMBO_AutoCertExchnge, { "UaServerConfig", "DiscoveryRegistration", "AutomaticCertificateExchange" });
}


void UserToken::OnEnChangeEditDiscsrvrstorename()
{
	GetEditTextUpdateXML(IDC_EDIT_DiscSrvrStoreName, { "UaServerConfig", "DiscoveryRegistration", "DiscoveryServerStoreName" });
}


void UserToken::OnEnChangeEditDiscsrvrcertname()
{
	GetEditTextUpdateXML(IDC_EDIT_DiscSrvrCertName, { "UaServerConfig", "DiscoveryRegistration", "DiscoveryServerCertificateName" });
}


void UserToken::OnEnChangeEditRegistrationinterval()
{
	GetEditTextUpdateXML(IDC_EDIT_RegistrationInterval, { "UaServerConfig", "DiscoveryRegistration", "RegistrationInterval" });
}


void UserToken::OnEnChangeEditMaxmemoryalloc()
{
	GetEditTextUpdateXML(IDC_EDIT_MaxMemoryAlloc, { "UaServerConfig", "Serializer", "MaxAlloc" });
}


void UserToken::OnEnChangeEditMaxstrnglngth()
{
	GetEditTextUpdateXML(IDC_EDIT_MaxStrngLngth, { "UaServerConfig", "Serializer", "MaxStringLength" });
}


void UserToken::OnEnChangeEditMaxbytestrnglngth()
{
	GetEditTextUpdateXML(IDC_EDIT_MaxByteStrngLngth, { "UaServerConfig", "Serializer", "MaxByteStringLength" });
}


void UserToken::OnEnChangeEditMaxarraylngth()
{
	GetEditTextUpdateXML(IDC_EDIT_MaxArrayLngth, { "UaServerConfig", "Serializer", "MaxArrayLength" });
}


void UserToken::OnEnChangeEditMaxmsgsize()
{
	GetEditTextUpdateXML(IDC_EDIT_MaxMsgSize, { "UaServerConfig", "Serializer", "MaxMessageSize" });
}


void UserToken::OnCbnSelchangeComboRdndncysupp()
{
	GetComboTextUpdateXML(IDC_COMBO_RdndncySupp, { "UaServerConfig", "RedundancySettings", "RedundancySupport" });
}

// Calls on initialization read specific areas in xml file and insert these values to the related tools on GUI
BOOL UserToken::OnInitDialog()
{
	CMFCPropertyPage::OnInitDialog();
	
	// XML root
	Helper::pNode = Helper::xmlDoc.RootElement();	//dosyanýn root'unu yükler
	if (nullptr == Helper::pNode)
		return FALSE;
	tinyxml2::XMLElement* pItems = Helper::pNode->FirstChildElement("UaServerConfig");
	//Helper::pNode = pItems->FirstChildElement("RejectedCertificatesDirectory");

	////go to RejectedCertificatesDirectory's first child node and 
	////insert xml values to related controls on GUI by iterating node
	//Helper::pNode = Helper::SetEditBrowse(Helper::pNode, m_RjctdUserCertDir);
	//Helper::pNode = SetEditControl(Helper::pNode, IDC_EDIT_MaxRjctedUserCertCnt);
	Helper::pNode = pItems->FirstChildElement("UserIdentityTokens");
	Helper::pNode = Helper::pNode->FirstChildElement();
	Helper::pNode = Helper::SetComboBox(Helper::pNode, m_EnAnnymousLogin);
	Helper::pNode = Helper::SetComboBox(Helper::pNode, m_EnUserPassLogin);
	Helper::pNode = Helper::SetComboBox(Helper::pNode, m_EnableCert);
	Helper::pNode = SetEditControl(Helper::pNode, IDC_EDIT_SecPolicy);
	tinyxml2::XMLElement* pItem = Helper::pNode->NextSiblingElement();
	Helper::pNode = Helper::pNode->FirstChildElement();
	Helper::pNode = Helper::SetEditBrowse(Helper::pNode, m_CertTrstListLoc);
	Helper::pNode = Helper::SetEditBrowse(Helper::pNode, m_CertRvctionListLoc);
	Helper::pNode = Helper::SetEditBrowse(Helper::pNode, m_IssuerCertLoc);
	Helper::pNode = Helper::SetEditBrowse(Helper::pNode, m_IssuerRvctionListLoc);

	Helper::pNode = pItem;
	Helper::pNode = Helper::SetEditBrowse(Helper::pNode, m_RjctdUserCertDir);
	SetEditControl(Helper::pNode, IDC_EDIT_MaxRjctedUserCertCnt);

	//Parse Discovery Registration Part
	Helper::pNode = pItems->FirstChildElement("DiscoveryRegistration")->FirstChildElement();
	Helper::pNode = Helper::SetComboBox(Helper::pNode, m_AutoCertExchnge);
	Helper::pNode = Helper::pNode->NextSiblingElement();
	Helper::pNode = SetEditControl(Helper::pNode, IDC_EDIT_DiscSrvrStoreName);
	Helper::pNode = SetEditControl(Helper::pNode, IDC_EDIT_DiscSrvrCertName);
	SetEditControl(Helper::pNode, IDC_EDIT_RegistrationInterval);

	//Parse Serializer Part
	Helper::pNode = pItems->FirstChildElement("Serializer")->FirstChildElement();
	Helper::pNode = SetEditControl(Helper::pNode, IDC_EDIT_MaxMemoryAlloc);
	Helper::pNode = SetEditControl(Helper::pNode, IDC_EDIT_MaxStrngLngth);
	Helper::pNode = SetEditControl(Helper::pNode, IDC_EDIT_MaxByteStrngLngth);
	Helper::pNode = SetEditControl(Helper::pNode, IDC_EDIT_MaxArrayLngth);
	Helper::pNode = SetEditControl(Helper::pNode, IDC_EDIT_MaxMsgSize);

	Helper::pNode = pItems->FirstChildElement("RedundancySettings")->FirstChildElement();
	Helper::FindSetComboBox(Helper::pNode, m_RdndncySupp);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}
