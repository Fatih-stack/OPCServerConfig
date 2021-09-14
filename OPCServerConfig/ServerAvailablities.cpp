// ServerAvailablities.cpp : implementation file
//

#include "pch.h"
#include "OPCServerConfig.h"
#include "ServerAvailablities.h"
#include "afxdialogex.h"


// ServerAvailablities dialog

IMPLEMENT_DYNAMIC(ServerAvailablities, CMFCPropertyPage)

ServerAvailablities::ServerAvailablities(CWnd* pParent /*=nullptr*/)
	: CMFCPropertyPage(IDD_SERVER_AVAILABLITIES)
{
}

ServerAvailablities::~ServerAvailablities()
{
}

void ServerAvailablities::DoDataExchange(CDataExchange* pDX)
{
	CMFCPropertyPage::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_SampleRates, m_listCtrlSR);
	DDX_Control(pDX, IDC_LIST_ServerProfiles, m_listCtrlSrvrProfiles);
	DDX_Control(pDX, IDC_LIST_ServerCaps, m_listCtrlSrvrCaps);
	DDX_Control(pDX, IDC_LIST_Local_Ids, m_listLocalIds);
}


BEGIN_MESSAGE_MAP(ServerAvailablities, CMFCPropertyPage)
	ON_BN_CLICKED(IDC_BUTTON_InsertSR, &ServerAvailablities::OnBnClickedButtonInsertsr)
	ON_BN_CLICKED(IDC_BUTTON_InsertLocalIds, &ServerAvailablities::OnBnClickedButtonInsertlocalids)
	ON_BN_CLICKED(IDC_BUTTON_InsertSP, &ServerAvailablities::OnBnClickedButtonInsertsp)
	ON_BN_CLICKED(IDC_BUTTON_InsertSCaps, &ServerAvailablities::OnBnClickedButtonInsertscaps)
	ON_BN_CLICKED(IDC_BUTTON_DeleteSR, &ServerAvailablities::OnBnClickedButtonDeletesr)
	ON_BN_CLICKED(IDC_BUTTON_DeleteLIds, &ServerAvailablities::OnBnClickedButtonDeletelids)
	ON_BN_CLICKED(IDC_BUTTON_DeleteSP, &ServerAvailablities::OnBnClickedButtonDeletesp)
	ON_BN_CLICKED(IDC_BUTTON_DeleteSC, &ServerAvailablities::OnBnClickedButtonDeletesc)
	ON_LBN_SELCHANGE(IDC_LIST_SampleRates, &ServerAvailablities::OnLbnSelchangeListSamplerates)
	ON_BN_CLICKED(IDC_BUTTON_UpdateSR, &ServerAvailablities::OnBnClickedButtonUpdatesr)
	ON_LBN_SELCHANGE(IDC_LIST_Local_Ids, &ServerAvailablities::OnLbnSelchangeListLocalIds)
	ON_LBN_SELCHANGE(IDC_LIST_ServerProfiles, &ServerAvailablities::OnLbnSelchangeListServerprofiles)
	ON_LBN_SELCHANGE(IDC_LIST_ServerCaps, &ServerAvailablities::OnLbnSelchangeListServercaps)
	ON_BN_CLICKED(IDC_BUTTON_UpdateSCaps, &ServerAvailablities::OnBnClickedButtonUpdatescaps)
	ON_BN_CLICKED(IDC_BUTTON_UpdateLocalIds, &ServerAvailablities::OnBnClickedButtonUpdatelocalids)
	ON_BN_CLICKED(IDC_BUTTON_UpdateSP, &ServerAvailablities::OnBnClickedButtonUpdatesp)
END_MESSAGE_MAP()

/*******************************************************************************************************
* DEF  : Takes xml node value and convert it to CString then adds this value to listbox
* ARGS : pItem => related xml node for edit control --- listBoxCtrl => related list box's control on GUI
* OUTPUT : add string value to the listbox on GUI
********************************************************************************************************/
void ServerAvailablities::SetListBox(tinyxml2::XMLElement* pItem, CListBox& listBoxCtrl)
{
	while (pItem != nullptr)
	{
		std::string temp = pItem->GetText();
		CString cStr = CA2T(temp.c_str(), CP_UTF8);
		listBoxCtrl.AddString(cStr);
		pItem = pItem->NextSiblingElement();
	}
}

/*********************************************************************************************************************
* DEF  : get edit control value and check whether listbox is selected or not if selected adds this value over
* selected item in listbox and xml by taking index value find node place by using parent and child node names
* ARGS : node => parent node name, childNode => child node name, edit => edit control, listBoxCtrl => list box control
* OUTPUT : add string value to the listbox on GUI and also add this value to proper place in xml file.
**********************************************************************************************************************/
void ServerAvailablities::InsertToXML(const std::string& node, const std::string& childNode, int edit, CListBox& listBoxCtrl)
{
	CString cStr;
	GetDlgItemText(edit, cStr);
	std::string str(CW2A(cStr.GetString()));
	//go to xml node
	Helper::pNode = Helper::xmlDoc.RootElement()->FirstChildElement("UaServerConfig")->FirstChildElement(node.c_str());
	auto x = Helper::pNode->FirstChildElement();
	int nSel = listBoxCtrl.GetCurSel();	// get selected index value
	if(nSel >= 0 )	//check whether list box is checked or not
	{
		listBoxCtrl.InsertString(nSel, cStr);	//insert string over selected item on GUI
		while (nSel > 1){	//go to previous item before selected item in xml file iteratively
			x = x->NextSiblingElement();	
			nSel--;
		}
		tinyxml2::XMLElement* inserted;
		//insert to xml
		Helper::pNode->InsertAfterChild(x, inserted = Helper::pNode->InsertNewChildElement(childNode.c_str()));
		inserted->SetText(str.c_str());
	}
	else
	{
		listBoxCtrl.AddString(cStr);	//add string end of the list box
		Helper::pNode = Helper::pNode->InsertNewChildElement(childNode.c_str());	//add string end of the xml node
		Helper::pNode->SetText(str.c_str());
	}
//	Helper::xmlDoc.SaveFile("OpcServerConfig.xml");
}

// ServerAvailablities message handlers


void ServerAvailablities::OnBnClickedButtonInsertsr()
{
	InsertToXML("AvailableSamplingRates", "SamplingRate", IDC_EDIT_InsrtSmplngRate, m_listCtrlSR);	
}


void ServerAvailablities::OnBnClickedButtonInsertlocalids()
{
	
	InsertToXML("AvailableLocaleIds", "LocaleId", IDC_EDIT_InsrtLocalId, m_listLocalIds);
}


void ServerAvailablities::OnBnClickedButtonInsertsp()
{
	InsertToXML("AvailableServerProfiles", "ServerProfileUri", IDC_EDIT_InsrtSrvrPrfiles, m_listCtrlSrvrProfiles);
}


void ServerAvailablities::OnBnClickedButtonInsertscaps()
{
	InsertToXML("ServerCapabilities", "ServerCapability", IDC_EDIT_InsertSCaps, m_listCtrlSrvrCaps);
}

//take node string, listbox controller as input and also take selected item text on listbox
//go to node place in xml file and delete node from xml and also delete it from listbox
void ServerAvailablities::deleteNode(const std::string& node, CListBox& listBoxCtrl)
{
	Helper::pNode = Helper::xmlDoc.RootElement()->FirstChildElement("UaServerConfig")
		->FirstChildElement(node.c_str())->FirstChildElement();
	int nSel = listBoxCtrl.GetCurSel();
	CString ItemSelected;
	if (nSel != LB_ERR)
	{
		listBoxCtrl.GetText(nSel, ItemSelected);
	}
	std::string str(CW2A(ItemSelected.GetString()));
	while (Helper::pNode->GetText() != str)
		Helper::pNode = Helper::pNode->NextSiblingElement();
	if (Helper::pNode)
	{
		//delete node and save xml file as this node is deleted
		Helper::xmlDoc.DeleteNode(Helper::pNode);
//		Helper::xmlDoc.SaveFile("OpcServerConfig.xml");
		listBoxCtrl.DeleteString(nSel);
	}
}

//take node string, listbox controller and edit control id as input and also take selected item text on listbox
//go to node place in xml file and update node in xml and also in listbox
void ServerAvailablities::UpdateNode(const std::string& node, CListBox& listBoxCtrl, int edit)
{
	Helper::pNode = Helper::xmlDoc.RootElement()->FirstChildElement("UaServerConfig")
		->FirstChildElement(node.c_str())->FirstChildElement();
	CString cStr;
	int nSel = listBoxCtrl.GetCurSel();
	GetDlgItemText(edit, cStr);
	std::string str(CW2A(cStr.GetString()));
	int counter = 0;
	while (counter != nSel)
	{
		Helper::pNode = Helper::pNode->NextSiblingElement();
		counter++;
	}
	Helper::pNode->SetText(str.c_str());
	listBoxCtrl.InsertString(nSel, cStr);
	listBoxCtrl.DeleteString(nSel+1);
//	Helper::xmlDoc.SaveFile("OpcServerConfig.xml");
}

void ServerAvailablities::OnBnClickedButtonDeletesr()
{
	deleteNode("AvailableSamplingRates", m_listCtrlSR);
}


void ServerAvailablities::OnBnClickedButtonDeletelids()
{
	deleteNode("AvailableLocaleIds", m_listLocalIds);
}


void ServerAvailablities::OnBnClickedButtonDeletesp()
{
	deleteNode("AvailableServerProfiles", m_listCtrlSrvrProfiles);
}


void ServerAvailablities::OnBnClickedButtonDeletesc()
{
	deleteNode("ServerCapabilities", m_listCtrlSrvrCaps);
}


void ServerAvailablities::OnLbnSelchangeListSamplerates()
{
	GetListBox(IDC_EDIT_InsrtSmplngRate, m_listCtrlSR);
}


void ServerAvailablities::GetListBox(int edit, CListBox& listBoxCtrl)
{
	int nSel = listBoxCtrl.GetCurSel();
	CString ItemSelected;
	if (nSel != LB_ERR)
	{
		listBoxCtrl.GetText(nSel, ItemSelected);
	}
	SetDlgItemText(edit, ItemSelected);
}

void ServerAvailablities::OnBnClickedButtonUpdatesr()
{
	UpdateNode("AvailableSamplingRates", m_listCtrlSR, IDC_EDIT_InsrtSmplngRate);
}

// Calls on initialization read specific areas in xml file and insert these values to the related tools on GUI
BOOL ServerAvailablities::OnInitDialog()
{
	CMFCPropertyPage::OnInitDialog();

	Helper::pNode = Helper::xmlDoc.RootElement();	//dosyanýn root'unu yükler
	if (nullptr == Helper::pNode)
		return FALSE;
	tinyxml2::XMLElement* pItems = Helper::pNode->FirstChildElement("UaServerConfig");
	Helper::pNode = pItems->FirstChildElement("AvailableSamplingRates")->FirstChildElement();
	SetListBox(Helper::pNode, m_listCtrlSR);
	Helper::pNode = pItems->FirstChildElement("AvailableLocaleIds")->FirstChildElement();
	SetListBox(Helper::pNode, m_listLocalIds);
	Helper::pNode = pItems->FirstChildElement("AvailableServerProfiles")->FirstChildElement();
	SetListBox(Helper::pNode, m_listCtrlSrvrProfiles);
	Helper::pNode = pItems->FirstChildElement("ServerCapabilities")->FirstChildElement();
	SetListBox(Helper::pNode, m_listCtrlSrvrCaps);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}

void ServerAvailablities::OnLbnSelchangeListLocalIds()
{
	GetListBox(IDC_EDIT_InsrtLocalId, m_listLocalIds);
}


void ServerAvailablities::OnLbnSelchangeListServerprofiles()
{
	GetListBox(IDC_EDIT_InsrtSrvrPrfiles, m_listCtrlSrvrProfiles);
}


void ServerAvailablities::OnLbnSelchangeListServercaps()
{
	GetListBox(IDC_EDIT_InsertSCaps, m_listCtrlSrvrCaps);
}


void ServerAvailablities::OnBnClickedButtonUpdatescaps()
{
	UpdateNode("ServerCapabilities", m_listCtrlSrvrCaps, IDC_EDIT_InsertSCaps);
}


void ServerAvailablities::OnBnClickedButtonUpdatelocalids()
{
	UpdateNode("AvailableLocaleIds", m_listLocalIds, IDC_EDIT_InsrtLocalId);
}


void ServerAvailablities::OnBnClickedButtonUpdatesp()
{
	UpdateNode("AvailableServerProfiles", m_listCtrlSrvrProfiles, IDC_EDIT_InsrtSrvrPrfiles);
}
