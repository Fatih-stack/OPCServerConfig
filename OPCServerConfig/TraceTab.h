#pragma once
#include "Helper.h"

// TraceTab dialog

class TraceTab : public CMFCPropertyPage
{
	DECLARE_DYNAMIC(TraceTab)

public:
	TraceTab(CWnd* pParent = nullptr);   // standard constructor
	
	virtual ~TraceTab();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TRACE_TAB };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CMFCEditBrowseCtrl m_EditBrowseTraceFile;
	CMFCEditBrowseCtrl m_RjctdCertDir;
	afx_msg void OnEnChangeMfceditbrowseTracefile();
	CComboBox m_EnStackTrace;
	afx_msg void OnCbnSelchangeComboEnstcktrace();
	CComboBox m_StckTraceLevel;
	CComboBox m_EnSrvrAppTrace;
	CComboBox m_SrvrAppTrcLevel;
	CComboBox m_AppTrcDisFlush;
	CComboBox m_TraceEvents;
	CComboBox m_EnPubSubStckTrace;
	CComboBox m_AllowDepSecPolcy;
	CComboBox m_PrvsionModeActive;
	CComboBox m_DeactAftInitConf;
	
	
	tinyxml2::XMLElement* SetEditControl(tinyxml2::XMLElement* pItem, int editControlName);
	void GetComboTextUpdateXML(int combo, const std::vector<std::string>& nodes);
	void GetEditTextUpdateXML(int edit, const std::vector<std::string>& nodes);
	afx_msg void OnCbnSelchangeComboApptracedisflush();
	afx_msg void OnEnChangeEditRejectedcertcount();
	afx_msg void OnEnChangeEditMaxtraceentries();
	afx_msg void OnEnChangeEditMaxbackupfiles();
	afx_msg void OnCbnSelchangeComboStcktracelevel();
	afx_msg void OnCbnSelchangeComboEnsrvrapptrclevel();
	afx_msg void OnCbnSelchangeComboSrvrapptrclevel();
	afx_msg void OnCbnSelchangeComboTraceevents();
	afx_msg void OnCbnSelchangeComboEnpubsubstcktrce();
	afx_msg void OnCbnSelchangeComboAllowdeprsecpolcy();
	afx_msg void OnCbnSelchangeComboProvisionmodeact();
	afx_msg void OnCbnSelchangeComboDeactaftinitconf();
	virtual BOOL OnInitDialog();
	afx_msg void OnEnChangeMfceditbrowseRejectedcert();
};
