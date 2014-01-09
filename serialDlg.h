// serialDlg.h : header file
//
#include "SerialPort.h"
#if !defined(AFX_SERIALDLG_H__52D2D6BD_56C4_4D56_9A5F_E005760AA71C__INCLUDED_)
#define AFX_SERIALDLG_H__52D2D6BD_56C4_4D56_9A5F_E005760AA71C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CSerialDlg dialog

class CSerialDlg : public CDialog
{
// Construction
public:
	CSerialDlg(CWnd* pParent = NULL);	// standard constructor
	CSerialPort m_SerialPort; //CSerailPort¿‡∂‘œÛ
// Dialog Data
	//{{AFX_DATA(CSerialDlg)
	enum { IDD = IDD_SERIAL_DIALOG };
	UINT	m_rec1;
	UINT	m_rec2;
	UINT	m_send1;
	UINT	m_send2;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSerialDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;
	
	// Generated message map functions
	//{{AFX_MSG(CSerialDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnOpenserial();
	afx_msg void OnCloseserial();
	afx_msg void OnSend();
	afx_msg LONG OnComm(WPARAM ch, LPARAM port);
	virtual void OnCancel();
	afx_msg void OnCancel2();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SERIALDLG_H__52D2D6BD_56C4_4D56_9A5F_E005760AA71C__INCLUDED_)
