#ifndef __UIIPADDRESSEX_H__
#define __UIIPADDRESSEX_H__

#pragma once

namespace DuiLib
{


	/// IP����ؼ�
	class DUILIB_API CIPAddressExUI : public CEditUI
	{
	public:
		CIPAddressExUI();
		LPCTSTR GetClass() const;
		LPVOID GetInterface(LPCTSTR pstrName);
		UINT GetControlFlags() const;
		void DoEvent(TEventUI& event);
		void PaintText(HDC hDC);

		void SetIP(LPCSTR lpIP);
		CDuiString GetIP();

	private:
		void CharToInt();
		void GetNumInput(TCHAR chKey);
		void UpdateText();
		void IncNum();
		void DecNum();

	protected:
		int m_nFirst;
		int m_nSecond;
		int m_nThird;
		int m_nFourth;
		int m_nActiveSection;

		TCHAR m_chNum;
		CDuiString m_strNum;
	};

}

#endif // __UIIPADDRESSEX_H__