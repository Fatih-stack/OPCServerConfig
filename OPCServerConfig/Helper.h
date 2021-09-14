#pragma once
#include "pch.h"
#include "tinyxml2.h"
#include <string>
#include <vector>

class Helper
{
public:
	static tinyxml2::XMLElement* pNode;
	static tinyxml2::XMLDocument xmlDoc;
	static tinyxml2::XMLElement* SetComboBox(tinyxml2::XMLElement* pItem, CComboBox& combo);
	static tinyxml2::XMLElement* FindSetComboBox(tinyxml2::XMLElement* pItem, CComboBox& combo);
	static tinyxml2::XMLElement* SetEditBrowse(tinyxml2::XMLElement* pItem, CMFCEditBrowseCtrl& editBrowse);
	static void UpdateXmlFileTagEdit(const CString& cStr, const std::vector<std::string>& nodes);
	static void UpdateXmlFileTagCombo(const CString& cStr, const std::vector<std::string>& nodes);
	static void editbrowseToXML(CMFCEditBrowseCtrl& editBrowse, const std::vector<std::string>& nodes);
};

