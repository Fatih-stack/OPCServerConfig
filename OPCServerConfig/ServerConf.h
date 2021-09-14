#pragma once

#include "Helper.h"
// ServerConf dialog

class ServerConf : public CMFCPropertyPage
{
	DECLARE_DYNAMIC(ServerConf)

public:
	ServerConf(CWnd* pParent = nullptr);   // standard constructor
	virtual ~ServerConf();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SERVER_CONF };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CEdit m_LiveQueSize;
	CString m_CSLiveQSize;
	CComboBox m_DurableSubsEnabled;
	CComboBox m_AudioActivated;
	CMFCEditBrowseCtrl m_StorageDir;
	tinyxml2::XMLElement* SetEditControl(tinyxml2::XMLElement* pItem, int editControlName);
	void GetComboTextUpdateXML(int combo, const std::vector<std::string>& nodes);
	void GetEditTextUpdateXML(int edit, const std::vector<std::string>& nodes);
	afx_msg void OnCbnSelchangeComboDrblesubssuppen();
	afx_msg void OnCbnSelchangeComboAvailblsmplngrates();
	afx_msg void OnEnChangeEditHostname();
	afx_msg void OnEnChangeEditGeometry();
	afx_msg void OnEnChangeMfceditbrowseDrblesubs();
	afx_msg void OnEnChangeEditMaxsubslifetime();
	afx_msg void OnEnChangeEditMaxmonititmquesize();
	afx_msg void OnEnChangeEditLivequesize();
	afx_msg void OnCbnSelchangeComboAudioactivated();
	afx_msg void OnEnChangeEditProducturi();
	afx_msg void OnEnChangeEditManfcturername();
	afx_msg void OnEnChangeEditProductname();
	afx_msg void OnEnChangeEditSoftwareversion();
	afx_msg void OnEnChangeEditBuildnumber();
	afx_msg void OnEnChangeEditServeruri();
	afx_msg void OnEnChangeEditServername();
	virtual BOOL OnInitDialog();
};
