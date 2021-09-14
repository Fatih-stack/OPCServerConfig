// CertificateStorage.cpp : implementation file
//

#include "OPCServerConfig.h"
#include "CertificateStorage.h"
#include "afxdialogex.h"

// CertificateStorage dialog

IMPLEMENT_DYNAMIC(CertificateStorage, CMFCPropertyPage)

CertificateStorage::CertificateStorage(CWnd* pParent /*=nullptr*/)
	: CMFCPropertyPage(IDD_CertificateStore)
{
}

CertificateStorage::~CertificateStorage()
{
}

void CertificateStorage::DoDataExchange(CDataExchange* pDX)
{
	CMFCPropertyPage::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_MFCEDITBROWSE_SrvrCert, m_editBrowseSrvrCert);
	DDX_Control(pDX, IDC_MFCEDITBROWSE_SrvrPrvtKey, m_editBrowseSrvrPrvtKey);
	DDX_Control(pDX, IDC_COMBO_SendCertChain, m_SendCertChain);
	DDX_Control(pDX, IDC_MFCEDITBROWSE_CertTrustList, m_CertTrstListLoc);
	DDX_Control(pDX, IDC_MFCEDITBROWSE_CertRvctnList, m_CertRvctionListLoc);
	DDX_Control(pDX, IDC_MFCEDITBROWSE_IssuerCert, m_IssuerCertLoc);
	DDX_Control(pDX, IDC_MFCEDITBROWSE_IssuerRvctnList, m_IssuerRvctionListLoc);
	DDX_Control(pDX, IDC_COMBO_GenerateCert, m_GenerateCert);
	DDX_Control(pDX, IDC_COMBO_CertKeyLngth, m_CertKeyLength);
	DDX_Control(pDX, IDC_COMBO_CertType, m_CertType);
}


BEGIN_MESSAGE_MAP(CertificateStorage, CMFCPropertyPage)
	ON_EN_CHANGE(IDC_MFCEDITBROWSE_SrvrCert, &CertificateStorage::OnEnChangeMfceditbrowseSrvrcert)
	ON_EN_UPDATE(IDC_MFCEDITBROWSE_SrvrCert, &CertificateStorage::OnEnUpdateMfceditbrowseSrvrcert)
	ON_CBN_SELCHANGE(IDC_COMBO_SendCertChain, &CertificateStorage::OnCbnSelchangeComboSendcertchain)
	ON_EN_CHANGE(IDC_MFCEDITBROWSE_IssuerCert, &CertificateStorage::OnEnChangeMfceditbrowseIssuercert)
	ON_EN_CHANGE(IDC_MFCEDITBROWSE_CertTrustList, &CertificateStorage::OnEnChangeMfceditbrowseCerttrustlist)
	ON_EN_CHANGE(IDC_MFCEDITBROWSE_CertRvctnList, &CertificateStorage::OnEnChangeMfceditbrowseCertrvctnlist)
	ON_EN_CHANGE(IDC_MFCEDITBROWSE_IssuerRvctnList, &CertificateStorage::OnEnChangeMfceditbrowseIssuerrvctnlist)
	ON_EN_CHANGE(IDC_MFCEDITBROWSE_SrvrPrvtKey, &CertificateStorage::OnEnChangeMfceditbrowseSrvrprvtkey)
	ON_CBN_SELCHANGE(IDC_COMBO_GenerateCert, &CertificateStorage::OnCbnSelchangeComboGeneratecert)
	ON_CBN_SELCHANGE(IDC_COMBO_CertKeyLngth, &CertificateStorage::OnCbnSelchangeComboCertkeylngth)
	ON_CBN_SELCHANGE(IDC_COMBO_CertType, &CertificateStorage::OnCbnSelchangeComboCerttype)
	ON_EN_CHANGE(IDC_EDIT_CommonName, &CertificateStorage::OnEnChangeEditCommonname)
	ON_EN_CHANGE(IDC_EDIT_DomainComponent, &CertificateStorage::OnEnChangeEditDomaincomponent)
	ON_EN_CHANGE(IDC_EDIT_Organization, &CertificateStorage::OnEnChangeEditOrganization)
	ON_EN_CHANGE(IDC_EDIT_OrganizationUnit, &CertificateStorage::OnEnChangeEditOrganizationunit)
	ON_EN_CHANGE(IDC_EDIT_LocationName, &CertificateStorage::OnEnChangeEditLocationname)
	ON_EN_CHANGE(IDC_EDIT_CountryLetterCode, &CertificateStorage::OnEnChangeEditCountrylettercode)
	ON_EN_CHANGE(IDC_EDIT_ValidYears, &CertificateStorage::OnEnChangeEditValidyears)
	ON_EN_CHANGE(IDC_EDIT_DNSName, &CertificateStorage::OnEnChangeEditDnsname)
	ON_EN_CHANGE(IDC_EDIT_MaxTrstListSize, &CertificateStorage::OnEnChangeEditMaxtrstlistsize)
END_MESSAGE_MAP()

/*******************************************************************************************************
* DEF  : Takes xml node and edit control then sets edit control with node value by making conversions 
* ARGS : pItem => related xml node for edit control --- editControlName => related edit control on GUI
* OUTPUT : next node in xml
********************************************************************************************************/
tinyxml2::XMLElement* CertificateStorage::SetEditControl(tinyxml2::XMLElement* pItem, int editControlName)
{
	std::string strText = pItem->GetText();
	CString s2 = CA2T(strText.c_str(), CP_UTF8);
	SetDlgItemText(editControlName, s2);
	return pItem->NextSiblingElement();
}

/*******************************************************************************************************
* DEF  : gets combo control and node strings then get combo value and go to given place in xml file 
*		 by using node strings write combo value to the given node in XML file
* ARGS : combo => related combo control --- nodes => all tags till the related node
* OUTPUT : Updates given xml tag's value in XML file
********************************************************************************************************/
void CertificateStorage::GetComboTextUpdateXML(int combo, const std::vector<std::string>& nodes)
{
	CString cStr;
	CWnd* Pfield = GetDlgItem(combo);
	Pfield->GetWindowText(cStr);  //get combo text and assing it to cStr variable
	Helper::UpdateXmlFileTagCombo(cStr, nodes);	//update node in XML file
}

/*******************************************************************************************************
* DEF  : gets edit control and node strings then get edit control value and go to given place in xml file
*		 by using node strings write edit control's value to the given node in XML file
* ARGS : edit => related edit control --- nodes => all tags till the related node
* OUTPUT : Updates given xml tag's value in XML file
********************************************************************************************************/
void CertificateStorage::GetEditTextUpdateXML(int edit, const std::vector<std::string>& nodes)
{
	CString cstr;
	GetDlgItemText(edit, cstr);		//get edit control value and assign it to cstr
	Helper::UpdateXmlFileTagEdit(cstr, nodes);	//update given tag value in XML file
}

// CertificateStorage message handlers

void CertificateStorage::OnEnChangeMfceditbrowseSrvrcert()
{
	Helper::editbrowseToXML(m_editBrowseSrvrCert, { "UaServerConfig", "DefaultApplicationCertificateStore",
		"ServerCertificate", "OpenSSLStore", "ServerCertificate"});
}


void CertificateStorage::OnEnUpdateMfceditbrowseSrvrcert()
{

}


void CertificateStorage::OnCbnSelchangeComboSendcertchain()
{
	GetComboTextUpdateXML(IDC_COMBO_SendCertChain, { "UaServerConfig", "DefaultApplicationCertificateStore", 
		"SendCertificateChain" });
}


void CertificateStorage::OnEnChangeMfceditbrowseIssuercert()
{
	Helper::editbrowseToXML(m_IssuerCertLoc, { "UaServerConfig", "DefaultApplicationCertificateStore",
		"OpenSSLStore", "IssuersCertificatesLocation" });
}


void CertificateStorage::OnEnChangeMfceditbrowseCerttrustlist()
{
	Helper::editbrowseToXML(m_CertTrstListLoc, { "UaServerConfig", "DefaultApplicationCertificateStore",
		"OpenSSLStore", "CertificateTrustListLocation" });
}


void CertificateStorage::OnEnChangeMfceditbrowseCertrvctnlist()
{
	Helper::editbrowseToXML(m_CertRvctionListLoc, { "UaServerConfig", "DefaultApplicationCertificateStore",
		"OpenSSLStore", "CertificateRevocationListLocation" });
}


void CertificateStorage::OnEnChangeMfceditbrowseIssuerrvctnlist()
{
	Helper::editbrowseToXML(m_IssuerRvctionListLoc, { "UaServerConfig", "DefaultApplicationCertificateStore",
		"OpenSSLStore", "IssuersRevocationListLocation" });
}


void CertificateStorage::OnEnChangeMfceditbrowseSrvrprvtkey()
{
	Helper::editbrowseToXML(m_editBrowseSrvrPrvtKey, { "UaServerConfig", "DefaultApplicationCertificateStore",
		"ServerCertificate", "OpenSSLStore", "ServerPrivateKey" });
}


void CertificateStorage::OnCbnSelchangeComboGeneratecert()
{
	GetComboTextUpdateXML(IDC_COMBO_GenerateCert, { "UaServerConfig", "DefaultApplicationCertificateStore",
		"ServerCertificate", "GenerateCertificate" });
}


void CertificateStorage::OnCbnSelchangeComboCertkeylngth()
{
	CString cStr, cStr2;
	CWnd* Pfield = GetDlgItem(IDC_COMBO_CertKeyLngth);	
	Pfield->GetWindowText(cStr);	//get combo item's value and assign it to cStr
	int x = _ttoi(cStr);		//convert CString to int
	Pfield = GetDlgItem(IDC_COMBO_CertType);
	Pfield->GetWindowText(cStr2);		//get combo item's value and assign it to cStr2
	//check limitations according to xml file and update xml file
	if((cStr2 == L"RsaSha256" && x >= 2048) || (cStr2 == L"RsaMin" && x <= 2048) ) 
		GetComboTextUpdateXML(IDC_COMBO_CertKeyLngth, { "UaServerConfig", "DefaultApplicationCertificateStore",
			"ServerCertificate", "CertificateSettings", "KeyLength" });
}


void CertificateStorage::OnCbnSelchangeComboCerttype()
{
	CString cStr, cStr2;
	CWnd* Pfield = GetDlgItem(IDC_COMBO_CertKeyLngth);
	Pfield->GetWindowText(cStr);	//get combo item's value and assign it to cStr
	int x = _ttoi(cStr);		//convert CString to int
	Pfield = GetDlgItem(IDC_COMBO_CertType);
	Pfield->GetWindowText(cStr2);	//get combo item's value and assign it to cStr2
	//check limitations according to xml file and update xml file
	if ((cStr2 == L"RsaSha256" && x >= 2048) || (cStr2 == L"RsaMin" && x <= 2048))
		GetComboTextUpdateXML(IDC_COMBO_CertType, { "UaServerConfig", "DefaultApplicationCertificateStore",
			"ServerCertificate", "CertificateSettings", "CertificateType" });
}


void CertificateStorage::OnEnChangeEditCommonname()
{
	GetEditTextUpdateXML(IDC_EDIT_CommonName, { "UaServerConfig", "DefaultApplicationCertificateStore",
		"ServerCertificate", "CertificateSettings", "CommonName"});
}


void CertificateStorage::OnEnChangeEditDomaincomponent()
{
	GetEditTextUpdateXML(IDC_EDIT_DomainComponent, { "UaServerConfig", "DefaultApplicationCertificateStore",
		"ServerCertificate", "CertificateSettings", "DomainComponent" });
}


void CertificateStorage::OnEnChangeEditOrganization()
{
	GetEditTextUpdateXML(IDC_EDIT_Organization, { "UaServerConfig", "DefaultApplicationCertificateStore",
		"ServerCertificate", "CertificateSettings", "Organization" });
}


void CertificateStorage::OnEnChangeEditOrganizationunit()
{
	GetEditTextUpdateXML(IDC_EDIT_OrganizationUnit, { "UaServerConfig", "DefaultApplicationCertificateStore",
		"ServerCertificate", "CertificateSettings", "OrganizationUnit" });
}


void CertificateStorage::OnEnChangeEditLocationname()
{
	GetEditTextUpdateXML(IDC_EDIT_LocationName, { "UaServerConfig", "DefaultApplicationCertificateStore",
		"ServerCertificate", "CertificateSettings", "Locality" });
}


void CertificateStorage::OnEnChangeEditCountrylettercode()
{
	GetEditTextUpdateXML(IDC_EDIT_CountryLetterCode, { "UaServerConfig", "DefaultApplicationCertificateStore",
		"ServerCertificate", "CertificateSettings", "Country" });
}


void CertificateStorage::OnEnChangeEditValidyears()
{
	GetEditTextUpdateXML(IDC_EDIT_ValidYears, { "UaServerConfig", "DefaultApplicationCertificateStore",
		"ServerCertificate", "CertificateSettings", "YearsValidFor" });
}


void CertificateStorage::OnEnChangeEditDnsname()
{
	GetEditTextUpdateXML(IDC_EDIT_DNSName, { "UaServerConfig", "DefaultApplicationCertificateStore",
		"ServerCertificate", "CertificateSettings", "DNSName" });
}


void CertificateStorage::OnEnChangeEditMaxtrstlistsize()
{
	GetEditTextUpdateXML(IDC_EDIT_MaxTrstListSize, {"UaServerConfig","DefaultApplicationCertificateStore","MaxTrustListSize"});
}

// Calls on initialization read specific areas in xml file and insert related tools on GUI
// Also filter file extentions for browse buttons 
BOOL CertificateStorage::OnInitDialog()
{
	CMFCPropertyPage::OnInitDialog();
	m_editBrowseSrvrCert.EnableFileBrowseButton(L"DER", L"der files|*.der||");	//filter browse control with .der extension
	m_editBrowseSrvrPrvtKey.EnableFileBrowseButton(L"PEM", L"pem files|*.pem||");	//filter browse control with .pem extension

	tinyxml2::XMLElement* pXML = nullptr;	//xml dosyasý iþlemleri için deðiþken

	// XML root
	pXML = Helper::xmlDoc.RootElement();	//dosyanýn root'unu yükler
	if (nullptr == pXML)
		return FALSE;
	tinyxml2::XMLElement* pItems = pXML->FirstChildElement("UaServerConfig");
	tinyxml2::XMLElement* pItemTrace = pItems->FirstChildElement("Trace")->NextSiblingElement(); //DefaultApplicationCertificateStore
	tinyxml2::XMLElement* pItem = pItemTrace->FirstChildElement();
	Helper::pNode = pItemTrace->FirstChildElement();
	Helper::pNode = SetEditControl(Helper::pNode, IDC_EDIT_MaxTrstListSize);
	Helper::pNode = Helper::SetComboBox(Helper::pNode, m_SendCertChain);
	pItem = Helper::pNode;
	tinyxml2::XMLElement* pItem2 = Helper::pNode->NextSiblingElement(); //ServerCertificate node element

	//go to related areas on XML file read node value respectively 
	//sets related tools on GUI with these values and pass next node 
	Helper::pNode = Helper::pNode->FirstChildElement();		//OpenSSLStore
	Helper::pNode = Helper::SetEditBrowse(Helper::pNode, m_CertTrstListLoc);
	Helper::pNode = Helper::SetEditBrowse(Helper::pNode, m_CertRvctionListLoc);
	Helper::pNode = Helper::SetEditBrowse(Helper::pNode, m_IssuerCertLoc);
	Helper::pNode = Helper::SetEditBrowse(Helper::pNode, m_IssuerRvctionListLoc);

	Helper::pNode = pItem2->FirstChildElement()->FirstChildElement(); //SrvrCert->OpenSSLStore-->SrvrCert
	Helper::pNode = Helper::SetEditBrowse(Helper::pNode, m_editBrowseSrvrCert);
	Helper::pNode = Helper::SetEditBrowse(Helper::pNode, m_editBrowseSrvrPrvtKey);
	Helper::pNode = pItem2->FirstChildElement()->NextSiblingElement();	//Generate Certificate Node
	Helper::pNode = Helper::SetComboBox(Helper::pNode, m_GenerateCert);
	
	Helper::pNode = Helper::pNode->FirstChildElement();	//CertificateSettings Node
	Helper::pNode = SetEditControl(Helper::pNode, IDC_EDIT_CommonName);
	Helper::pNode = SetEditControl(Helper::pNode, IDC_EDIT_DomainComponent);
	Helper::pNode = SetEditControl(Helper::pNode, IDC_EDIT_Organization);
	Helper::pNode = SetEditControl(Helper::pNode, IDC_EDIT_OrganizationUnit);
	Helper::pNode = SetEditControl(Helper::pNode, IDC_EDIT_LocationName);
	Helper::pNode = Helper::pNode->NextSiblingElement(); //Split State
	Helper::pNode = SetEditControl(Helper::pNode, IDC_EDIT_CountryLetterCode);
	Helper::pNode = SetEditControl(Helper::pNode, IDC_EDIT_ValidYears);
	Helper::pNode = Helper::FindSetComboBox(Helper::pNode, m_CertKeyLength);
	Helper::pNode = Helper::FindSetComboBox(Helper::pNode, m_CertType);
	Helper::pNode = SetEditControl(Helper::pNode, IDC_EDIT_DNSName);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}
