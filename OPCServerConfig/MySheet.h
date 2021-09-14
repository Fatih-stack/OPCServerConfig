#pragma once

#include "TraceTab.h"
#include "UserToken.h"
#include "ServerAllowConf.h"
#include "ServerConf.h"
#include "CertificateStorage.h"
#include "ThreadSettings.h"
#include "UAEndPointSecurity.h"
#include "ServerAvailablities.h"

// MySheet

class MySheet : public CPropertySheet
{
	DECLARE_DYNAMIC(MySheet)

public:
	MySheet(UINT nIDCaption, CWnd* pParentWnd = nullptr, UINT iSelectPage = 0);
	MySheet(LPCTSTR pszCaption, CWnd* pParentWnd = nullptr, UINT iSelectPage = 0);
	virtual ~MySheet();

protected:
	DECLARE_MESSAGE_MAP()

	void InitPages();
private:
	TraceTab page1;
	ServerAllowConf page2;
	ServerConf page3;
	UserToken page4;
	CertificateStorage page5;
	ThreadSettings page6;
	UAEndPointSecurity page7;
	ServerAvailablities page8;
};


