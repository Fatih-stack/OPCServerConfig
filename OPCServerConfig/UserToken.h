#pragma once

#include "Helper.h"
// UserToken dialog

class UserToken : public CMFCPropertyPage
{
	DECLARE_DYNAMIC(UserToken)

public:
	UserToken(CWnd* pParent = nullptr);   // standard constructor
	virtual ~UserToken();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_UserToken };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnCbnSelchangeComboEncert();
	afx_msg void OnEnChangeMfceditbrowseCerttrustlst();
	CMFCEditBrowseCtrl m_RjctdUserCertDir;
	CMFCEditBrowseCtrl m_CertTrstListLoc;
	CMFCEditBrowseCtrl m_CertRvctionListLoc;
	CMFCEditBrowseCtrl m_IssuerCertLoc;
	CMFCEditBrowseCtrl m_IssuerRvctionListLoc;
	CComboBox m_AutoCertExchnge;
	CComboBox m_EnAnnymousLogin;
	CComboBox m_EnUserPassLogin;
	CComboBox m_EnableCert;
	CComboBox m_RdndncySupp;
	tinyxml2::XMLElement* SetEditControl(tinyxml2::XMLElement* pItem, int editControlName);
	void GetComboTextUpdateXML(int combo, const std::vector<std::string>& nodes);
	void GetEditTextUpdateXML(int edit, const std::vector<std::string>& nodes);
	afx_msg void OnCbnSelchangeComboEnannymslogin();
	afx_msg void OnCbnSelchangeComboEnuserpasslog();
	afx_msg void OnEnChangeEditSecpolicy();
	afx_msg void OnEnChangeMfceditbrowseCertrevoclist();
	afx_msg void OnEnChangeMfceditbrowseIssuercert();
	afx_msg void OnEnChangeMfceditbrowseIssuerrevoclist();
	afx_msg void OnEnChangeMfceditbrowseRjctedusrcert();
	afx_msg void OnEnChangeEditMaxrjctedusercertcnt();
	afx_msg void OnCbnSelchangeComboAutocertexchnge();
	afx_msg void OnEnChangeEditDiscsrvrstorename();
	afx_msg void OnEnChangeEditDiscsrvrcertname();
	afx_msg void OnEnChangeEditRegistrationinterval();
	afx_msg void OnEnChangeEditMaxmemoryalloc();
	afx_msg void OnEnChangeEditMaxstrnglngth();
	afx_msg void OnEnChangeEditMaxbytestrnglngth();
	afx_msg void OnEnChangeEditMaxarraylngth();
	afx_msg void OnEnChangeEditMaxmsgsize();
	afx_msg void OnCbnSelchangeComboRdndncysupp();
	virtual BOOL OnInitDialog();
};
