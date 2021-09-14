
// OPCServerConfigView.cpp : implementation of the COPCServerConfigView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "OPCServerConfig.h"
#endif

#include "OPCServerConfigDoc.h"
#include "OPCServerConfigView.h"
#include <memory>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// COPCServerConfigView

IMPLEMENT_DYNCREATE(COPCServerConfigView, CFormView)

BEGIN_MESSAGE_MAP(COPCServerConfigView, CFormView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &COPCServerConfigView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// COPCServerConfigView construction/destruction

COPCServerConfigView::COPCServerConfigView()
{
	// TODO: add construction code here
	
	
}

COPCServerConfigView::~COPCServerConfigView()
{
}

void COPCServerConfigView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	
}

BOOL COPCServerConfigView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CFormView::PreCreateWindow(cs);
}

void COPCServerConfigView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
//	ResizeParentToFit();
}


// COPCServerConfigView printing


void COPCServerConfigView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL COPCServerConfigView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void COPCServerConfigView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing

}

void COPCServerConfigView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void COPCServerConfigView::OnPrint(CDC* pDC, CPrintInfo* /*pInfo*/)
{
	// TODO: add customized printing code here
}

void COPCServerConfigView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
	
}

void COPCServerConfigView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// COPCServerConfigView diagnostics

#ifdef _DEBUG
void COPCServerConfigView::AssertValid() const
{
	CFormView::AssertValid();
}

void COPCServerConfigView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

COPCServerConfigDoc* COPCServerConfigView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(COPCServerConfigDoc)));
	return (COPCServerConfigDoc*)m_pDocument;
}
#endif //_DEBUG
// COPCServerConfigView message handlers
