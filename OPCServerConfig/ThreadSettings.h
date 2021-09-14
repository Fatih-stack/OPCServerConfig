#pragma once

#include "Helper.h"
// ThreadSettings dialog

class ThreadSettings : public CMFCPropertyPage
{
	DECLARE_DYNAMIC(ThreadSettings)

public:
	ThreadSettings(CWnd* pParent = nullptr);   // standard constructor
	virtual ~ThreadSettings();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ThreadSettings };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnCbnSelchangeComboEnstckthreadpool();
	CComboBox m_StackThreadPool;
	CComboBox m_BlockOnAdd;
	tinyxml2::XMLElement* SetEditControl(tinyxml2::XMLElement* pItem, int editControlName);
	void GetComboTextUpdateXML(int combo, const std::vector<std::string>& nodes);
	void GetEditTextUpdateXML(int edit, const std::vector<std::string>& nodes);
	afx_msg void OnCbnSelchangeComboBlockonadd();
	afx_msg void OnEnChangeEditMinthreads();
	afx_msg void OnEnChangeEditMaxthreads();
	afx_msg void OnEnChangeEditMaxjobs();
	afx_msg void OnEnChangeEditTimeout();
	afx_msg void OnEnChangeEditMinsizetransctionman();
	afx_msg void OnEnChangeEditMaxsizetransctionman();
	afx_msg void OnEnChangeEditMinsizesubsman();
	afx_msg void OnEnChangeEditMaxsizesubsman();
	virtual BOOL OnInitDialog();
};
