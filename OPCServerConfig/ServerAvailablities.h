#pragma once

#include "Helper.h"

// ServerAvailablities dialog

class ServerAvailablities : public CMFCPropertyPage
{
	DECLARE_DYNAMIC(ServerAvailablities)

public:
	ServerAvailablities(CWnd* pParent = nullptr);   // standard constructor
	virtual ~ServerAvailablities();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SERVER_AVAILABLITIES };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()

public:
	// The list control object
	CListBox m_listCtrlSR;		// The list control object	CListCtrl m_listCtrlLocalId;
	CListBox m_listCtrlSrvrProfiles;
	CListBox m_listCtrlSrvrCaps;
	CListBox m_listLocalIds;
	void SetListBox(tinyxml2::XMLElement* pItem, CListBox& listBoxCtrl);
	void GetListBox(int edit, CListBox& listBoxCtrl);
	void UpdateNode(const std::string& node, CListBox& listBoxCtrl, int edit);
	afx_msg void OnBnClickedButtonInsertsr();
	void InsertToXML(const std::string& node, const std::string& childNode, int edit, CListBox& listBoxCtrl);
	void deleteNode(const std::string& node, CListBox& listBoxCtrl);
	afx_msg void OnBnClickedButtonInsertlocalids();
	afx_msg void OnBnClickedButtonInsertsp();
	afx_msg void OnBnClickedButtonInsertscaps();
	afx_msg void OnBnClickedButtonDeletesr();
	afx_msg void OnBnClickedButtonDeletelids();
	afx_msg void OnBnClickedButtonDeletesp();
	afx_msg void OnBnClickedButtonDeletesc();
	afx_msg void OnLbnSelchangeListSamplerates();
	afx_msg void OnBnClickedButtonUpdatesr();
	afx_msg void OnLbnSelchangeListLocalIds();
	afx_msg void OnLbnSelchangeListServerprofiles();
	afx_msg void OnLbnSelchangeListServercaps();
	afx_msg void OnBnClickedButtonUpdatescaps();
	afx_msg void OnBnClickedButtonUpdatelocalids();
	afx_msg void OnBnClickedButtonUpdatesp();
};
