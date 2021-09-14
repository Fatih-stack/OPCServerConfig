#pragma once

#include "Helper.h"
// CertificateStorage dialog

class CertificateStorage : public CMFCPropertyPage
{
	DECLARE_DYNAMIC(CertificateStorage)

public:
	CertificateStorage(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CertificateStorage();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CertificateStore };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeMfceditbrowseSrvrcert();
	afx_msg void OnEnUpdateMfceditbrowseSrvrcert();
	CMFCEditBrowseCtrl m_editBrowseSrvrCert;
	CMFCEditBrowseCtrl m_editBrowseSrvrPrvtKey;
	CMFCEditBrowseCtrl m_CertTrstListLoc;
	CMFCEditBrowseCtrl m_CertRvctionListLoc;
	CMFCEditBrowseCtrl m_IssuerCertLoc;
	CMFCEditBrowseCtrl m_IssuerRvctionListLoc;
	CComboBox m_SendCertChain;
	CComboBox m_GenerateCert;
	CComboBox m_CertKeyLength;
	CComboBox m_CertType;
	afx_msg void OnCbnSelchangeComboSendcertchain();
	tinyxml2::XMLElement* SetEditControl(tinyxml2::XMLElement* pItem, int editControlName);
	void GetComboTextUpdateXML(int combo, const std::vector<std::string>& nodes);
	void GetEditTextUpdateXML(int edit, const std::vector<std::string>& nodes);
	afx_msg void OnEnChangeMfceditbrowseIssuercert();
	afx_msg void OnEnChangeMfceditbrowseCerttrustlist();
	afx_msg void OnEnChangeMfceditbrowseCertrvctnlist();
	afx_msg void OnEnChangeMfceditbrowseIssuerrvctnlist();
	afx_msg void OnEnChangeMfceditbrowseSrvrprvtkey();
	afx_msg void OnCbnSelchangeComboGeneratecert();
	afx_msg void OnCbnSelchangeComboCertkeylngth();
	afx_msg void OnCbnSelchangeComboCerttype();
	afx_msg void OnEnChangeEditCommonname();
	afx_msg void OnEnChangeEditDomaincomponent();
	afx_msg void OnEnChangeEditOrganization();
	afx_msg void OnEnChangeEditOrganizationunit();
	afx_msg void OnEnChangeEditLocationname();
	afx_msg void OnEnChangeEditCountrylettercode();
	afx_msg void OnEnChangeEditValidyears();
	afx_msg void OnEnChangeEditDnsname();
	afx_msg void OnEnChangeEditMaxtrstlistsize();
	virtual BOOL OnInitDialog();
};
