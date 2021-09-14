#pragma once

#include "Helper.h"
// UAEndPointSecurity dialog

class UAEndPointSecurity : public CMFCPropertyPage
{
	DECLARE_DYNAMIC(UAEndPointSecurity)

public:
	UAEndPointSecurity(CWnd* pParent = nullptr);   // standard constructor
	virtual ~UAEndPointSecurity();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_UAEndPoint_Security };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnCbnSelchangeComboIsvisible();
	tinyxml2::XMLElement* SetEditControl(tinyxml2::XMLElement* pItem, int editControlName);
	void GetComboTextUpdateXML(int combo, const std::vector<std::string>& nodes);
	void GetEditTextUpdateXML(int edit, const std::vector<std::string>& nodes);
	void SecSettingUpdateXML(int edit, tinyxml2::XMLElement* pItem);
	CComboBox m_IsVisible;
	CComboBox m_IsDiscUrl;
	CComboBox m_AutoTrstAllClntCerts;
	CComboBox m_CreateSignWithChain;
	CComboBox m_DisErrCertTimeInvld;
	CComboBox m_DisErrCertIssTimeInvld;
	CComboBox m_DisErrCertRvctnUnknwn;
	CComboBox m_DisErrCertIssRvctnUnknwn;
	CComboBox m_DisErrCertKeyShort;
	CComboBox m_DisErrCertKeyLong;
	CComboBox m_DisAppUriCheck;
	CComboBox m_DisNonceLngthCheck;
	CComboBox m_DisUsrPolcyIdCheck;
	CComboBox m_DisCertSignAlgCheck;
	CComboBox m_DisCertUsageCheck;
	afx_msg void OnEnChangeEditSerializertype();
	afx_msg void OnEnChangeEditUrl();
	afx_msg void OnCbnSelchangeComboIsdiscurl();
	afx_msg void OnCbnSelchangeComboAutotrstallclientcert();
	afx_msg void OnCbnSelchangeComboCreatesgnchain();
	afx_msg void OnCbnSelchangeComboDiserrcerttimeinvld();
	afx_msg void OnCbnSelchangeComboDiserrcertisstimeinvld();
	afx_msg void OnCbnSelchangeComboDiserrcertrvctnunknwn();
	afx_msg void OnCbnSelchangeComboDiserrcertissrvctnunknwn();
	afx_msg void OnCbnSelchangeComboDiserrcertkeyshort();
	afx_msg void OnCbnSelchangeComboDiserrcertkeylong();
	afx_msg void OnCbnSelchangeComboDisappuricheck();
	afx_msg void OnCbnSelchangeComboDisnoncelngthchck();
	afx_msg void OnCbnSelchangeComboDisusertokenpolicychck();
	afx_msg void OnCbnSelchangeComboDiscertsignalgcheck();
	afx_msg void OnCbnSelchangeComboDiscertusagecheck();
	afx_msg void OnEnChangeEditSecpolicy();
	afx_msg void OnEnChangeEditMsgsecmode();
	afx_msg void OnEnChangeEditSecuritypolicy();
	afx_msg void OnEnChangeEditMsgscrtymode();
	afx_msg void OnEnChangeEditSecpolicy2();
	afx_msg void OnEnChangeEditMsgscrtymode3();
	afx_msg void OnEnUpdateEdit();
	afx_msg void OnEnChangeEditSecpolicy3();
	afx_msg void OnEnChangeEdit();
	afx_msg void OnEnChangeEdit2();
	afx_msg void OnEnChangeEditMsgscrtymode5();
	afx_msg void OnEnChangeEditMsgscrtymode6();
	virtual BOOL OnInitDialog();
};
