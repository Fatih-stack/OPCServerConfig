// ThreadSettings.cpp : implementation file
//

#include "pch.h"
#include "OPCServerConfig.h"
#include "ThreadSettings.h"
#include "afxdialogex.h"


// ThreadSettings dialog

IMPLEMENT_DYNAMIC(ThreadSettings, CMFCPropertyPage)

ThreadSettings::ThreadSettings(CWnd* pParent /*=nullptr*/)
	: CMFCPropertyPage(IDD_ThreadSettings)
{
}

ThreadSettings::~ThreadSettings()
{
}

void ThreadSettings::DoDataExchange(CDataExchange* pDX)
{
	CMFCPropertyPage::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO_EnStckThreadPool, m_StackThreadPool);
	DDX_Control(pDX, IDC_COMBO_BlockOnAdd, m_BlockOnAdd);
}


BEGIN_MESSAGE_MAP(ThreadSettings, CMFCPropertyPage)
	ON_CBN_SELCHANGE(IDC_COMBO_EnStckThreadPool, &ThreadSettings::OnCbnSelchangeComboEnstckthreadpool)
	ON_CBN_SELCHANGE(IDC_COMBO_BlockOnAdd, &ThreadSettings::OnCbnSelchangeComboBlockonadd)
	ON_EN_CHANGE(IDC_EDIT_MinThreads, &ThreadSettings::OnEnChangeEditMinthreads)
	ON_EN_CHANGE(IDC_EDIT_MaxThreads, &ThreadSettings::OnEnChangeEditMaxthreads)
	ON_EN_CHANGE(IDC_EDIT_MaxJobs, &ThreadSettings::OnEnChangeEditMaxjobs)
	ON_EN_CHANGE(IDC_EDIT_Timeout, &ThreadSettings::OnEnChangeEditTimeout)
	ON_EN_CHANGE(IDC_EDIT_MinSizeTransctionMan, &ThreadSettings::OnEnChangeEditMinsizetransctionman)
	ON_EN_CHANGE(IDC_EDIT_MaxSizeTransctionMan, &ThreadSettings::OnEnChangeEditMaxsizetransctionman)
	ON_EN_CHANGE(IDC_EDIT_MinSizeSubsMan, &ThreadSettings::OnEnChangeEditMinsizesubsman)
	ON_EN_CHANGE(IDC_EDIT_MaxSizeSubsMan, &ThreadSettings::OnEnChangeEditMaxsizesubsman)
END_MESSAGE_MAP()

/******************************************************************************************************
* DEF  : Takes xml node and edit control then sets edit control with node value by making conversions
* ARGS : pItem => related xml node for edit control --- editControlName => related edit control on GUI
* OUTPUT : next node in xml
*******************************************************************************************************/
tinyxml2::XMLElement* ThreadSettings::SetEditControl(tinyxml2::XMLElement* pItem, int editControlName)
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
void ThreadSettings::GetComboTextUpdateXML(int combo, const std::vector<std::string>& nodes)
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
void ThreadSettings::GetEditTextUpdateXML(int edit, const std::vector<std::string>& nodes)
{
	CString cstr;
	GetDlgItemText(edit, cstr);
	Helper::UpdateXmlFileTagEdit(cstr, nodes);
}

// ThreadSettings message handlers


void ThreadSettings::OnCbnSelchangeComboEnstckthreadpool()
{
	GetComboTextUpdateXML(IDC_COMBO_EnStckThreadPool, { "UaServerConfig", "StackThreadPoolSettings", "Enabled" });
}


void ThreadSettings::OnCbnSelchangeComboBlockonadd()
{
	GetComboTextUpdateXML(IDC_COMBO_BlockOnAdd, { "UaServerConfig", "StackThreadPoolSettings", "BlockOnAdd" });
}


void ThreadSettings::OnEnChangeEditMinthreads()
{
	GetEditTextUpdateXML(IDC_EDIT_MinThreads, { "UaServerConfig", "StackThreadPoolSettings", "MinThreads" });
}


void ThreadSettings::OnEnChangeEditMaxthreads()
{
	GetEditTextUpdateXML(IDC_EDIT_MaxThreads, { "UaServerConfig", "StackThreadPoolSettings", "MaxThreads" });
}


void ThreadSettings::OnEnChangeEditMaxjobs()
{
	GetEditTextUpdateXML(IDC_EDIT_MaxJobs, { "UaServerConfig", "StackThreadPoolSettings", "MaxJobs" });
}


void ThreadSettings::OnEnChangeEditTimeout()
{
	GetEditTextUpdateXML(IDC_EDIT_Timeout, { "UaServerConfig", "StackThreadPoolSettings", "Timeout" });
}


void ThreadSettings::OnEnChangeEditMinsizetransctionman()
{
	GetEditTextUpdateXML(IDC_EDIT_MinSizeTransctionMan, { "UaServerConfig", "ThreadPoolSettings", "MinSizeTransactionManager" });
}


void ThreadSettings::OnEnChangeEditMaxsizetransctionman()
{
	GetEditTextUpdateXML(IDC_EDIT_MaxSizeTransctionMan, { "UaServerConfig", "ThreadPoolSettings", "MaxSizeTransactionManager" });
}


void ThreadSettings::OnEnChangeEditMinsizesubsman()
{
	GetEditTextUpdateXML(IDC_EDIT_MinSizeSubsMan, { "UaServerConfig", "ThreadPoolSettings", "MinSizeSubscriptionManager" });
}


void ThreadSettings::OnEnChangeEditMaxsizesubsman()
{
	GetEditTextUpdateXML(IDC_EDIT_MaxSizeSubsMan, { "UaServerConfig", "ThreadPoolSettings", "MaxSizeSubscriptionManager" });
}

// Calls on initialization read specific areas in xml file and insert these values to the related tools on GUI
BOOL ThreadSettings::OnInitDialog()
{
	CMFCPropertyPage::OnInitDialog();

	// XML root
	Helper::pNode = Helper::xmlDoc.RootElement();	//dosyanýn root'unu yükler
	if (nullptr == Helper::pNode)
		return FALSE;
	tinyxml2::XMLElement* pItems = Helper::pNode->FirstChildElement("UaServerConfig");
	Helper::pNode = pItems->FirstChildElement("StackThreadPoolSettings");
	Helper::pNode = Helper::pNode->FirstChildElement();
	Helper::pNode = Helper::FindSetComboBox(Helper::pNode, m_StackThreadPool);
	Helper::pNode = SetEditControl(Helper::pNode, IDC_EDIT_MinThreads);
	Helper::pNode = SetEditControl(Helper::pNode, IDC_EDIT_MaxThreads);
	Helper::pNode = SetEditControl(Helper::pNode, IDC_EDIT_MaxJobs);
	Helper::pNode = Helper::FindSetComboBox(Helper::pNode, m_BlockOnAdd);
	SetEditControl(Helper::pNode, IDC_EDIT_Timeout);
	Helper::pNode = pItems->FirstChildElement("ThreadPoolSettings");
	Helper::pNode = Helper::pNode->FirstChildElement();
	Helper::pNode = SetEditControl(Helper::pNode, IDC_EDIT_MinSizeTransctionMan);
	Helper::pNode = SetEditControl(Helper::pNode, IDC_EDIT_MaxSizeTransctionMan);
	Helper::pNode = SetEditControl(Helper::pNode, IDC_EDIT_MinSizeSubsMan);
	SetEditControl(Helper::pNode, IDC_EDIT_MaxSizeSubsMan);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}
