; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CSerialDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "serial.h"

ClassCount=3
Class1=CSerialApp
Class2=CSerialDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_SERIAL_DIALOG

[CLS:CSerialApp]
Type=0
HeaderFile=serial.h
ImplementationFile=serial.cpp
Filter=N

[CLS:CSerialDlg]
Type=0
HeaderFile=serialDlg.h
ImplementationFile=serialDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=CSerialDlg

[CLS:CAboutDlg]
Type=0
HeaderFile=serialDlg.h
ImplementationFile=serialDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_SERIAL_DIALOG]
Type=1
Class=CSerialDlg
ControlCount=15
Control1=IDCANCEL,button,1342242816
Control2=IDC_OPENSERIAL,button,1342242816
Control3=IDC_CLOSESERIAL,button,1342242816
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC,static,1342308352
Control6=IDC_SEND1,edit,1350631552
Control7=IDC_SEND2,edit,1350631552
Control8=IDC_SEND,button,1342242816
Control9=IDC_STATIC,static,1342308352
Control10=IDC_STATIC,static,1342308352
Control11=IDC_REC1,edit,1350631552
Control12=IDC_REC2,edit,1350631552
Control13=IDC_STATIC,button,1342177287
Control14=IDC_STATIC,button,1342177287
Control15=IDCANCEL2,button,1342242816

