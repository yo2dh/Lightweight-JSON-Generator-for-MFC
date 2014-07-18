
// JsonMfcTestDlg.cpp : implementation file
//

#include "stdafx.h"
#include "JsonMfcTest.h"
#include "JsonMfcTestDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CJsonMfcTestDlg dialog




CJsonMfcTestDlg::CJsonMfcTestDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CJsonMfcTestDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CJsonMfcTestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CJsonMfcTestDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_GENERATE, &CJsonMfcTestDlg::OnBnClickedButtonGenerate)
END_MESSAGE_MAP()


// CJsonMfcTestDlg message handlers

BOOL CJsonMfcTestDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	Initialize();
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CJsonMfcTestDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CJsonMfcTestDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CJsonMfcTestDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CJsonMfcTestDlg::OnBnClickedButtonGenerate()
{
}

void CJsonMfcTestDlg::Initialize()
{

	CJsonStringBuffer sb;
	sb.Append( _T("test test sdlkjflsjdf" ) );
	sb.Append( _T("test test sdlkjflsjdf" ) );
	sb.Append( _T("test test sdlkjflsjdf" ) );
	
	CString strOutput;
	sb.ToString( strOutput );
	TRACE ( _T("%s\n") , strOutput );

	CJsonObject json;
	json.SetValue( _T("Int") , 3 );
	json.SetValue( _T("Float") , 3.5 );

	CJsonArray* pArray = new CJsonArray;
	pArray->Push( 3.5 );
	pArray->Push( _T("arraydata") );
	pArray->Push( 5 );

	CJsonObject* pData1 = new CJsonObject;
	pData1->SetValue( _T("Data") , _T("test") );
	pData1->SetValue( _T("Int") , 3 );
	pData1->SetValue( _T("Float") , 3.5 );

	CJsonObject* pData2 = new CJsonObject;
	pData2->SetValue( _T("Int") , 3 );
	pData2->SetValue( _T("Float") , 3.5 );

	json.SetValue( _T("Data1") , pData1 );
	pData1->SetValue( _T("Data2") , pData2 );
	pData1->SetValue( _T("Array") , pArray );

	CString strJson;
	json.ToString( strJson );

	TRACE ( _T("Json : %s\n") , strJson );
}