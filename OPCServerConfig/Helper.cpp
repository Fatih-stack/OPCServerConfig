#include "Helper.h"

tinyxml2::XMLDocument Helper::xmlDoc;
tinyxml2::XMLElement* Helper::pNode;
/*********************************************************************************************************
 * DEF  : take node item and combo item sets combo index according to node val false : 0, true : 1
 * ARGS : pItem => xml node item --- combo => Combobox control item
 * RET  : Returns next node item
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

/*********************************************************************************************************
 * DEF  : take node item and combo item sets combo index according to node val by making conversions
 * ARGS : pItem => xml node item --- combo => Combobox control item
 * RET  : Returns next node item
 *********************************************************************************************************/
tinyxml2::XMLElement* Helper::FindSetComboBox(tinyxml2::XMLElement* pItem, CComboBox& combo)
{
	CString s2 = CA2T(pItem->GetText(), CP_UTF8);
	int nItem = combo.FindString(0, s2);
	if (nItem >= 0)
		combo.SetCurSel(nItem);
	return pItem->NextSiblingElement();
}

/*********************************************************************************************************
 * DEF  : take node item and EditBrowse item sets edit browse text with node item's value
 * ARGS : pItem => xml node item --- editBrowse => EditBrowse control item
 * RET  : Returns next node item
 *********************************************************************************************************/
tinyxml2::XMLElement* Helper::SetEditBrowse(tinyxml2::XMLElement* pItem, CMFCEditBrowseCtrl& editBrowse)
{
	CString s2 = CA2T(pItem->GetText(), CP_UTF8);
	editBrowse.SetWindowTextW(s2);
	return pItem->NextSiblingElement();
}

/***************************************************************************
 * DEF  : go to the node's place in XML file and 
 * update its value with CString variable after converted to std::string
 * ARGS : cStr => edit control's text --- nodes=> tags till the given node
 ***************************************************************************/
void Helper::UpdateXmlFileTagEdit(const CString& cStr, const std::vector<std::string>& nodes)
{
	Helper::pNode = Helper::xmlDoc.RootElement()->FirstChildElement(nodes[0].c_str());
	for(int i = 1; i < nodes.size(); i++)
		Helper::pNode = Helper::pNode->FirstChildElement(nodes[i].c_str());
	std::string str(CW2A(cStr.GetString()));
	Helper::pNode->SetText(str.c_str());
//	xmlDoc.SaveFile("OpcServerConfig.xml");
}

/***************************************************************************
 * DEF  : go to the node's place in XML file and
 * update its value with CString variable after converted to std::string
 * ARGS : cStr => combo control's text --- nodes=> tags till the given node
 ***************************************************************************/
void Helper::UpdateXmlFileTagCombo(const CString& cStr, const std::vector<std::string>& nodes)
{
	Helper::pNode = Helper::xmlDoc.RootElement()->FirstChildElement(nodes[0].c_str());
	for (int i = 1; i < nodes.size(); i++)
		Helper::pNode = Helper::pNode->FirstChildElement(nodes[i].c_str());
	std::string str(CW2A(cStr.GetString()));
	Helper::pNode->SetText(str.c_str());
//	xmlDoc.SaveFile("OpcServerConfig.xml");
}

/***************************************************************************
 * DEF  : take editBrowse text and go to the node's place in XML file and
 * update its value with CString variable after converted to std::string
 * ARGS : cStr => GUI control's text --- nodes=> tags till the given node
 ***************************************************************************/
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

