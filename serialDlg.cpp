// serialDlg.cpp : implementation file
//

#include "stdafx.h"
#include "serial.h"
#include "serialDlg.h"
#include "SerialPort.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSerialDlg dialog

CSerialDlg::CSerialDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSerialDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSerialDlg)
	m_rec1 = 0;
	m_rec2 = 0;
	m_send1 = 0;
	m_send2 = 0;
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CSerialDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSerialDlg)
	DDX_Text(pDX, IDC_REC1, m_rec1);
	DDX_Text(pDX, IDC_REC2, m_rec2);
	DDX_Text(pDX, IDC_SEND1, m_send1);
	DDX_Text(pDX, IDC_SEND2, m_send2);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CSerialDlg, CDialog)
	//{{AFX_MSG_MAP(CSerialDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_OPENSERIAL, OnOpenserial)
	ON_BN_CLICKED(IDC_CLOSESERIAL, OnCloseserial)
	ON_BN_CLICKED(IDC_SEND, OnSend)
	ON_MESSAGE(WM_COMM_RXCHAR, OnComm)
	ON_BN_CLICKED(IDCANCEL2, OnCancel2)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSerialDlg message handlers

BOOL CSerialDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
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
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CSerialDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CSerialDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

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
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CSerialDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CSerialDlg::OnOpenserial() 
{
    if(m_SerialPort.InitPort(this, 1, 9600,'N',8,1,EV_RXFLAG | EV_RXCHAR,512))
	{
		m_SerialPort.StartMonitoring();
		AfxMessageBox("com1打开，9600波特率，8位，无验证");
	}
	else
	{
		AfxMessageBox("没有发现此串口或被占用");
	}

}

void CSerialDlg::OnCloseserial() 
{
	m_SerialPort.ClosePort();//关闭串口	
}

void CSerialDlg::OnSend() 
{	
	unsigned char buf[2];
	UpdateData(TRUE); //读入编辑框中的数据
	buf[0]=m_send1;
	buf[1]=m_send2;
	m_SerialPort.WriteToPort(buf,2);
}

LONG CSerialDlg::OnComm(WPARAM ch, LPARAM port)//此函数接收到一个字符执行一次
{
	static int count=0;//计数用
	static unsigned char buf[2]; //存储数据用
	if(count==0)
	{	m_rec1=ch;
		count=1;
	}
	if(count==1)
	{	m_rec2=ch;
		count=0;
	}
	UpdateData(FALSE);//写入编辑框
	return 0;
}


void CSerialDlg::OnCancel() 
{
	
	
	CDialog::OnCancel();
}

void CSerialDlg::OnCancel2() 
{
ShellExecute(NULL, NULL, _T("http://xiaohaizhu.taobao.com"), NULL,NULL, SW_SHOWNORMAL);  	
}
