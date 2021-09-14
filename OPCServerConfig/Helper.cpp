#include "Helper.h"

tinyxml2::XMLDocument Helper::xmlDoc;
tinyxml2::XMLElement* Helper::pNode;
/*********************************************************************************************************
 * DEF : 
 * 
 * 
 *********************************************************************************************************/
tinyxml2::XMLElement* Helper::SetComboBox(tinyxml2::XMLElement* pItem, CComboBox& combo)
{
	std::string tmp = pItem->GetText();
	if (tmp == "false")
		combo.SetCurSel(0);
	else 
		combo.SetCurSel(1);
	return pItem->NextSiblingElement();
}

tinyxml2::XMLElement* Helper::FindSetComboBox(tinyxml2::XMLElement* pItem, CComboBox& combo)
{
	CString s2 = CA2T(pItem->GetText(), CP_UTF8);
	/*
	* UTF8'den UTF16'ya dönüþüm
	* MultibyteToWidechar methodunu kullan CA2W makrosunu kullan
	*/
	int nItem = combo.FindString(0, s2);
	if (nItem >= 0)
		combo.SetCurSel(nItem);
	return pItem->NextSiblingElement();
}

tinyxml2::XMLElement* Helper::SetEditBrowse(tinyxml2::XMLElement* pItem, CMFCEditBrowseCtrl& editBrowse)
{
	CString s2 = CA2T(pItem->GetText(), CP_UTF8);
	editBrowse.SetWindowTextW(s2);
	return pItem->NextSiblingElement();
}

void Helper::UpdateXmlFileTagEdit(const CString& cStr, const std::vector<std::string>& nodes)
{
	Helper::pNode = Helper::xmlDoc.RootElement()->FirstChildElement(nodes[0].c_str());
	for(int i = 1; i < nodes.size(); i++)
		Helper::pNode = Helper::pNode->FirstChildElement(nodes[i].c_str());
	std::string str(CW2A(cStr.GetString()));
	Helper::pNode->SetText(str.c_str());
//	xmlDoc.SaveFile("OpcServerConfig.xml");
}

void Helper::UpdateXmlFileTagCombo(const CString& cStr, const std::vector<std::string>& nodes)
{
	Helper::pNode = Helper::xmlDoc.RootElement()->FirstChildElement(nodes[0].c_str());
	for (int i = 1; i < nodes.size(); i++)
		Helper::pNode = Helper::pNode->FirstChildElement(nodes[i].c_str());
	std::string str(CW2A(cStr.GetString()));
	Helper::pNode->SetText(str.c_str());
//	xmlDoc.SaveFile("OpcServerConfig.xml");
}

void Helper::editbrowseToXML(CMFCEditBrowseCtrl& editBrowse, const std::vector<std::string>& nodes)
{
	CString cStr;
	editBrowse.GetWindowTextW(cStr);
	Helper::pNode = Helper::xmlDoc.RootElement()->FirstChildElement(nodes[0].c_str());
	for (int i = 1; i < nodes.size(); i++)
		Helper::pNode = Helper::pNode->FirstChildElement(nodes[i].c_str());
	std::string str(CW2A(cStr.GetString()));
	Helper::pNode->SetText(str.c_str());
//	xmlDoc.SaveFile("OpcServerConfig.xml");
}

