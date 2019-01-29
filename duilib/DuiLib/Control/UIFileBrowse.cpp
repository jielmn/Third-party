#include "StdAfx.h"

#define DO_ONCE( statement )     do{ statement }while(0)
#define SNPRINTF(s,n, f,...)      _snprintf(s, n, f, __VA_ARGS__)
#define STRNCPY(d, s, n)          DO_ONCE( strncpy( d, s, (n)-1 ); d[(n)-1] = '\0'; )

#define  BROWSE_XML              \
"<?xml version=\"1.0\" encoding=\"utf-8\"?>" \
"<Window>"  \
"<HorizontalLayout>"  \
"<Edit name=\"edFileName\" readonly=\"true\" bkcolor=\"0xFFCCCCCC\" nativebkcolor=\"0xFFCCCCCC\" />"  \
"<Button name=\"btnBrowse\" padding=\"1,0,0,0\" />"  \
"</HorizontalLayout>"  \
"</Window>"

namespace DuiLib
{

	CFileBrowseUI::CFileBrowseUI() {
		m_edFileName = 0;
		m_btnBrowse = 0;

		m_nBtnBrowseWidth = 30;
		m_sBtnBrowseText = "...";

		m_nBrowseFont = -1;
		m_nFileNameFont = -1;

		// "�����ļ�\0*.*\0\0";
		const char * p = "�����ļ�";
		DWORD dwLen = strlen(p);

		memcpy(m_sFilter, p, dwLen);
		memcpy(m_sFilter + dwLen, "\0*.*\0\0", 6);
	}

	CFileBrowseUI::~CFileBrowseUI() {

	}

	LPCTSTR CFileBrowseUI::GetClass() const {
		return _T("FileBrowseUI");
	}

	LPVOID CFileBrowseUI::GetInterface(LPCTSTR pstrName) {
		if (_tcscmp(pstrName, DUI_CTR_FILEBROWSE) == 0) {
			return static_cast<CFileBrowseUI*>(this);
		}
		return CContainerUI::GetInterface(pstrName);
	}

	void CFileBrowseUI::DoInit() {
		CDialogBuilder builder;
		CContainerUI* pChildWindow =
			static_cast<CHorizontalLayoutUI*>(
				builder.Create(_T(BROWSE_XML), (UINT)0, NULL, m_pManager));
		if (pChildWindow) {
			this->Add(pChildWindow);
			m_pManager->AddNotifier(this);

			m_edFileName = static_cast<CEditUI*>(m_pManager->FindControl(_T("edFileName")));
			m_btnBrowse = static_cast<CButtonUI*>(m_pManager->FindControl(_T("btnBrowse")));

			m_btnBrowse->SetNormalImage(m_sNormalImage);
			m_btnBrowse->SetHotImage(m_sHotImage);
			m_btnBrowse->SetPushedImage(m_sPushedImage);
			m_btnBrowse->SetFocusedImage(m_sFocusedImage);
			m_btnBrowse->SetDisabledImage(m_sDisabledImage);
			m_btnBrowse->SetFixedWidth(m_nBtnBrowseWidth);
			m_btnBrowse->SetText(m_sBtnBrowseText);
			if (m_nBrowseFont >= 0) {
				m_btnBrowse->SetFont(m_nBrowseFont);
			}
			if (m_nFileNameFont >= 0) {
				m_edFileName->SetFont(m_nFileNameFont);
			}
		}
		else {
			this->RemoveAll();
		}
	}

	void CFileBrowseUI::Notify(TNotifyUI& msg) {
		if (msg.sType == "click") {
			if (msg.pSender->GetName() == "btnBrowse") {
				OnBrowse();
			}
		}
	}

	void CFileBrowseUI::OnBrowse() {
		OPENFILENAME ofn = { 0 };
		TCHAR strFilename[MAX_PATH] = { 0 };//���ڽ����ļ���  
		ofn.lStructSize = sizeof(OPENFILENAME);//�ṹ���С  
		ofn.hwndOwner = NULL;//ӵ���Ŵ��ھ����ΪNULL��ʾ�Ի����Ƿ�ģ̬�ģ�ʵ��Ӧ����һ�㶼Ҫ��������  
		ofn.lpstrFilter = m_sFilter; //TEXT("Excel Flie(*.xls)\0*.xls\0�����ļ�\0*.*\0\0");//���ù���  
		ofn.nFilterIndex = 1;//����������  
		ofn.lpstrFile = strFilename;//���շ��ص��ļ�����ע���һ���ַ���ҪΪNULL  
		ofn.nMaxFile = sizeof(strFilename);//����������  
										   //ofn.lpstrInitialDir = NULL;//��ʼĿ¼ΪĬ��  
		ofn.lpstrInitialDir = CPaintManagerUI::GetInstancePath();
		ofn.lpstrTitle = TEXT("��ѡ��һ���ļ�");//ʹ��ϵͳĬ�ϱ������ռ���  
		ofn.Flags = OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST | OFN_HIDEREADONLY;//�ļ���Ŀ¼������ڣ�����ֻ��ѡ��  
		if (GetOpenFileName(&ofn))
		{
			m_edFileName->SetText(strFilename);
		}
	}

	void CFileBrowseUI::SetAttribute(LPCTSTR pstrName, LPCTSTR pstrValue) {
		char buf[1024];

		if (_tcscmp(pstrName, _T("normalimage")) == 0) {
			m_sNormalImage = pstrValue;
		}
		else if (_tcscmp(pstrName, _T("hotimage")) == 0) {
			m_sHotImage = pstrValue;
		}
		else if (_tcscmp(pstrName, _T("pushedimage")) == 0) {
			m_sPushedImage = pstrValue;
		}
		else if (_tcscmp(pstrName, _T("focusedimage")) == 0) {
			m_sFocusedImage = pstrValue;
		}
		else if (_tcscmp(pstrName, _T("disabledimage")) == 0) {
			m_sDisabledImage = pstrValue;
		}
		else if (_tcscmp(pstrName, _T("browsewidth")) == 0) {
			sscanf(pstrValue, "%d", &m_nBtnBrowseWidth);
		}
		else if (_tcscmp(pstrName, _T("text")) == 0) {
			m_sBtnBrowseText = pstrValue;
		}
		else if (_tcscmp(pstrName, _T("browsefont")) == 0) {
			sscanf(pstrValue, "%d", &m_nBrowseFont);
		}
		else if (_tcscmp(pstrName, _T("font")) == 0) {
			sscanf(pstrValue, "%d", &m_nFileNameFont);
		}
		else if (_tcscmp(pstrName, _T("filter")) == 0) {
			STRNCPY(buf, pstrValue, sizeof(buf));
			memset(m_sFilter, 0, sizeof(m_sFilter));

			char * pDest  = m_sFilter;
			char * pStart = buf;
			char * pFind  = strstr(pStart, "\\0");
			while (pFind) {
				DWORD  dwLen = pFind - pStart;
				memcpy( pDest, pStart, dwLen );
				pDest[dwLen] = '\0';
				pDest += dwLen + 1;

				pStart = pFind + 2;
				pFind = strstr(pStart, "\\0");
			}
		}
		else {
			CContainerUI::SetAttribute(pstrName, pstrValue);
		}
	}

	CDuiString CFileBrowseUI::GetFileName() const {
		if (m_edFileName) {
			return m_edFileName->GetText();
		}
		else {
			return "";
		}
	}

	void CFileBrowseUI::SetFileName(LPCTSTR pstrFileName) {
		if ( m_edFileName ) {
			m_edFileName->SetText(pstrFileName);
		}
	}


}
