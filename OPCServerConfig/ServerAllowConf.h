#pragma once

#include "Helper.h"
// ServerAllowConf dialog

class ServerAllowConf : public CMFCPropertyPage
{
	DECLARE_DYNAMIC(ServerAllowConf)

public:
	ServerAllowConf(CWnd* pParent = nullptr);   // standard constructor
	virtual ~ServerAllowConf();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ServerAllowConf };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	void GetEditTextUpdateXML(int edit, const std::vector<std::string>& nodes);
	void SetEditControl(tinyxml2::XMLElement* pItem, int editControlName);
	tinyxml2::XMLElement* SetEditControls(tinyxml2::XMLElement* pItem, int editCName, int editCName2, int editCName3, int editCName4);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEditMaxreqage();
	afx_msg void OnEnChangeEditMaxsesscount();
	afx_msg void OnEnChangeEditMaxsesspercli();
	afx_msg void OnEnChangeEditMinsesstimeout();
	afx_msg void OnEnChangeEditMaxsesstimeout();
	afx_msg void OnEnChangeEditMaxbrowcontpoints();
	afx_msg void OnEnChangeEditMaxbrowsres();
	afx_msg void OnEnChangeEditMaxnodesbrowse();
	afx_msg void OnEnChangeEditMaxdataqueuesize();
	afx_msg void OnEnChangeEditMaxeventquesize();
	afx_msg void OnEnChangeEditMaxsubscount();
	afx_msg void OnEnChangeEditMinpublishinterval();
	afx_msg void OnEnChangeEditMaxpublishinterval();
	afx_msg void OnEnChangeEditMinkeepaliveinterval();
	afx_msg void OnEnChangeEditMaxnodeptbrowpath();
	afx_msg void OnEnChangeEditMaxnumnodesphistrd();
	afx_msg void OnEnChangeEditMaxnodephistrevnts();
	afx_msg void OnEnChangeEditMaxndphistupddata();
	afx_msg void OnEnChangeEditMaxndphistupdevnts();
	afx_msg void OnEnChangeEditMaxhistcontpoints();
	afx_msg void OnEnChangeEditMinsubslifetime();
	afx_msg void OnEnChangeEditMaxsubslifetime();
	afx_msg void OnEnChangeEditMaxretransquesize();
	afx_msg void OnEnChangeEditMaxnotfctionppublsh();
	afx_msg void OnEnChangeEditMaxsubspsess();
	afx_msg void OnEnChangeEditMaxmontrditemcnt();
	afx_msg void OnEnChangeEditMaxmntrditmpsubscnt();
	afx_msg void OnEnChangeEditMaxmntrditmpsesscnt();
	afx_msg void OnEnChangeEditMinsuppsmplerate();
	virtual BOOL OnInitDialog();
};
