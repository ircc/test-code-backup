// ReceiverDlg.h : header file
//

#if !defined(AFX_RECEIVERDLG_H__5AA98424_35AD_4D6B_A28F_64DD0F8CE0DD__INCLUDED_)
#define AFX_RECEIVERDLG_H__5AA98424_35AD_4D6B_A28F_64DD0F8CE0DD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CReceiverDlg dialog
#include "Protocol.h"

#define MAX_SEQ 15
#define NR_BUFS ((MAX_SEQ+1)/2)
//Timer ID
#define ID_RECV_TIMER 1
#define ID_ACK_TIMER  2
//Event Type. ʹ��Windows��Ϣģ��
typedef enum
{
	FRAME_ARRIVAL = (WM_USER+1),
	CKSUM_ERROR,
	TIMEOUT,
	NETWORK_LAYTER_READY,
	ACK_TIMEOUT,
} eventType;

class CReceiverDlg : public CDialog
{
// Construction
public:
	CReceiverDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CReceiverDlg)
	enum { IDD = IDD_RECEIVER_DIALOG };
	CListBox	m_ListOutput;
	int		m_RecvWndSize;
	int		m_RecvInterval;
	int		m_ErrSetting;
	CString	m_strAckLost;
	CString	m_strAckChkErr;
	int		m_AuxiliaryTime;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CReceiverDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CReceiverDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnStartRecv();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnStopRecv();
	virtual void OnCancel();
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	afx_msg void OnMenuCleanup();
	//}}AFX_MSG
	afx_msg LRESULT OnFrameArrival(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnCksumErr(WPARAM wParam, LPARAM lParam);
	DECLARE_MESSAGE_MAP()

private:
	static DWORD WINAPI UdpReceiveThread(LPVOID lpParam);	//UDP�����߳�
	void UdpReceive();
	void SendFrame(frameKind fk, seqNum ack);
	void ToNetworkLayer(packet* p) {}
	void ToNetworkLayer(int iSeqNo); //��Ϊ�����ģ�������־��Ϣ
	void FromPhysicalLayer(char* p, char* pFromPhysical);
	void ToPhysicalLayer(char* pBuf, int iSize);
	void Inc(seqNum& seq) { (seq < MAX_SEQ) ? seq++ : seq=0; }
	BOOL Between(seqNum a, seqNum b, seqNum c)
	{
		//return true if a<=b<c, false otherwise
		return ((a<=b && b<c) || (c<a && a<=b) || (b<c && c<a));
	}

private:
	SOCKET m_UDPRcvrSocket;
	SOCKADDR_IN m_UDPSndrAddr;
	frame* m_pInBuf;		//���ݽ��ջ����� = �������ڴ�С�����֡��
	BOOL* m_pArrived;		//���ܴ��������ݰ��Ƿ񵽴��λͼ
	seqNum m_frameExpected;	//���մ������
	seqNum m_tooFar;		//���մ����Ҳ�+1
	errMode m_errArray[MAX_SEQ+1]; //Ӧ��֡�Ĵ���ģʽ
	int m_iTokenCount;		//���Ƽ����������Ϊ���մ��ڴ�С
	BOOL m_bNoNak;			//��־��δ���͹�nak
	BOOL m_bRecving;		//��־�Ƿ�ʼ�������ݰ�
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RECEIVERDLG_H__5AA98424_35AD_4D6B_A28F_64DD0F8CE0DD__INCLUDED_)
