// MySheet.cpp : implementation file
//

#include "pch.h"
#include "OPCServerConfig.h"
#include "MySheet.h"


// MySheet

IMPLEMENT_DYNAMIC(MySheet, CPropertySheet)

MySheet::MySheet(UINT nIDCaption, CWnd* pParentWnd, UINT iSelectPage)
	:CPropertySheet(nIDCaption, pParentWnd, iSelectPage)
{
	InitPages();
}

MySheet::MySheet(LPCTSTR pszCaption, CWnd* pParentWnd, UINT iSelectPage)
	:CPropertySheet(pszCaption, pParentWnd, iSelectPage)
{
	InitPages();
}

MySheet::~MySheet()
{
}


BEGIN_MESSAGE_MAP(MySheet, CPropertySheet)
END_MESSAGE_MAP()


// MySheet message handlers

void MySheet::InitPages()
{
	AddPage(&page1);
	AddPage(&page2);
	AddPage(&page3);
	AddPage(&page4);
	AddPage(&page5);
	AddPage(&page6);
	AddPage(&page7);
	AddPage(&page8);
}