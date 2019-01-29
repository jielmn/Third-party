#ifndef __UIFILEBROWSE_H__
#define __UIFILEBROWSE_H__

#pragma once

namespace DuiLib
{

	class DUILIB_API CFileBrowseUI : public CContainerUI, INotifyUI
	{
	public:
		CFileBrowseUI();
		~CFileBrowseUI();
		LPCTSTR GetClass() const;
		LPVOID GetInterface(LPCTSTR pstrName);
		CDuiString GetFileName() const;
		void SetFileName(LPCTSTR pstrFileName);

	private:
		void DoInit();
		void Notify(TNotifyUI& msg);
		void SetAttribute(LPCTSTR pstrName, LPCTSTR pstrValue);
		void OnBrowse();

	private:
		CEditUI *               m_edFileName;
		CButtonUI *             m_btnBrowse;

		CDuiString              m_sNormalImage;
		CDuiString              m_sHotImage;
		CDuiString              m_sPushedImage;
		CDuiString              m_sFocusedImage;
		CDuiString              m_sDisabledImage;
		int                     m_nBtnBrowseWidth;
		CDuiString              m_sBtnBrowseText;
		int                     m_nBrowseFont;
		int                     m_nFileNameFont;
		char                    m_sFilter[1024];
	};



}



#endif