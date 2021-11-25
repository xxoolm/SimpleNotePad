﻿// DonateDlg.cpp: 实现文件
//

#include "stdafx.h"
#include "SimpleNotePad.h"
#include "DonateDlg.h"
#include "afxdialogex.h"
#include "DrawCommon.h"


// CDonateDlg 对话框

IMPLEMENT_DYNAMIC(CDonateDlg, CDialog)

CDonateDlg::CDonateDlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DONATE_DIALOG, pParent)
{

}

CDonateDlg::~CDonateDlg()
{
}

void CDonateDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDonateDlg, CDialog)
    ON_WM_PAINT()
END_MESSAGE_MAP()


// CDonateDlg 消息处理程序
BOOL CDonateDlg::OnInitDialog()
{
    CDialog::OnInitDialog();

    // TODO:  在此添加额外的初始化
    //载入图片
    m_pic1.LoadBitmap(IDB_DONATE);
    m_pic2.LoadBitmap(IDB_DONATE_WECHAT);

    //计算两个二维码图片的位置
    CRect rect{};
    CWnd* pWnd = nullptr;
    pWnd = GetDlgItem(IDC_DONATE_STATIC);
    if (pWnd != nullptr)
    {
        pWnd->GetWindowRect(rect);
        ScreenToClient(rect);
    }

    CRect rc_pic_area;
    GetClientRect(rc_pic_area);
    rc_pic_area.top = rect.bottom + theApp.DPI(8);
    rc_pic_area.left += theApp.DPI(10);
    rc_pic_area.right -= theApp.DPI(10);
    pWnd = GetDlgItem(IDCANCEL);
    if (pWnd != nullptr)
    {
        pWnd->GetWindowRect(rect);
        ScreenToClient(rect);
    }
    rc_pic_area.bottom = rect.top - theApp.DPI(8);
    m_pic1_rect = rc_pic_area;
    m_pic1_rect.right = m_pic1_rect.left + (rc_pic_area.Width() / 2) - theApp.DPI(4);

    m_pic2_rect = rc_pic_area;
    m_pic2_rect.left = m_pic2_rect.right - (rc_pic_area.Width() / 2) + theApp.DPI(4);

    return TRUE;  // return TRUE unless you set the focus to a control
                  // 异常: OCX 属性页应返回 FALSE
}


void CDonateDlg::OnPaint()
{
    CPaintDC dc(this); // device context for painting
                       // TODO: 在此处添加消息处理程序代码
                       // 不为绘图消息调用 CDialogEx::OnPaint()

    CDrawCommon draw;
    draw.Create(&dc, this);
    draw.DrawBitmap(m_pic1, m_pic1_rect.TopLeft(), m_pic1_rect.Size(), CDrawCommon::StretchMode::FIT);
    draw.DrawBitmap(m_pic2, m_pic2_rect.TopLeft(), m_pic2_rect.Size(), CDrawCommon::StretchMode::FIT);
}
