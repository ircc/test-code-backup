//file IniUtil.h
/*************************************************************************************************** 
* 1�� Class      �� CIniUtil
* 2�� Version    �� 1.1
* 3�� Description�� INI�ļ�����������
* 4�� Author     �� QNA (http://www.9cpp.com/)
* 5�� Created    �� 2012-7-18 10:30:07
* 6�� History    �� 
* 7�� Remark     �� ֧�ֿ��ֽںͶ��ֽ�
****************************************************************************************************/  
#ifndef __INI_UNTIL_H__
#define __INI_UNTIL_H__

#include <iostream>
#include <windows.h>
#include <assert.h>

namespace COMMON
{
#ifdef _UNICODE
#define tstring wstring
#else
#define tstring string
#endif
//��ֹBOOLǿ��ת����ʾ
#pragma warning(disable: 4800)

	class CIniUtil
	{
	public:
		CIniUtil()
		{
			m_IniFilename.clear();
		}

		CIniUtil(LPCTSTR IniFilename)
		{
			SetIniFilename(IniFilename);
		}

		virtual ~CIniUtil()
		{
			::WritePrivateProfileString(NULL, NULL, NULL, m_IniFilename.c_str());
		}

		//����
	public:
		//���õ�ǰ��ini�ļ�ʹ��
		bool SetIniFilename(LPCTSTR IniFilename)
		{
			assert(IniFilename);
			m_IniFilename = IniFilename;
			if(m_IniFilename.empty()) 
				return false;

			return true;
		}

		// ��INI�ļ���ȡ����
		UINT GetInt(LPCTSTR lpszSection, LPCTSTR lpszEntry, int nDefault=0)
		{
			TCHAR tszDefault[MAX_PATH/2] = {0};
			if(m_IniFilename.empty()) 
				return 0; 

            //���vs2005��vs2003 vc6.0��
#if _MSC_VER <= 1400 // for vc8, or vc7.1 vc6.0
            _stprintf(tszDefault, _T("%d"), nDefault);
#else	
            _stprintf_s(tszDefault, MAX_PATH/2, _T("%d"), nDefault);
#endif

			std::tstring s = GetString(lpszSection, lpszEntry, tszDefault);
			return _ttol(s.c_str());
		}

		//��ȡboolֵ 
		bool GetBoolean(LPCTSTR lpszSection, LPCTSTR lpszEntry, bool bDefault=false)
		{
			TCHAR tszDefault[MAX_PATH/2] = {0};
			assert(lpszSection);
			assert(lpszEntry);
			if(m_IniFilename.empty()) 
				return 0; // error
		
            //���vs2005��vs2003 vc6.0��
#if _MSC_VER <= 1400 // for vc8, or vc7.1 vc6.0
            _stprintf(tszDefault, _T("%d"), bDefault);
#else	
            _stprintf_s(tszDefault, MAX_PATH/2, _T("%d"), bDefault);
#endif

			return !GetString(lpszSection, lpszEntry, tszDefault).compare(_T("Y"));
		}

		//��INI�ļ���ȡһ���ַ���
		std::tstring GetString(LPCTSTR lpszSection, LPCTSTR lpszEntry, LPCTSTR lpszDefault=NULL)
		{
			long ret = 0;
			TCHAR tszTem[MAX_PATH*2] = {0};

			assert(lpszSection);
			assert(lpszEntry);

			if(m_IniFilename.empty())
				return std::tstring();		
			ret = ::GetPrivateProfileString(lpszSection, lpszEntry, lpszDefault, tszTem, MAX_PATH*2, m_IniFilename.c_str());

			if(0 == ret) 
			{
				return std::tstring(lpszDefault);
			}
			return std::tstring(tszTem);
		}

		//��ָ���ֶ�ָ����д������ֵ
		bool WriteInt(LPCTSTR lpszSection, LPCTSTR lpszEntry, int nValue)
		{
			TCHAR tszValue[MAX_PATH/2] = {0};
			assert(lpszSection);
			assert(lpszEntry);
			
            //���vs2005��vs2003 vc6.0��
#if _MSC_VER <= 1400 // for vc8, or vc7.1 vc6.0
            _stprintf(tszValue, _T("%d"), nValue);
#else	
            _stprintf_s(tszValue, MAX_PATH/2, _T("%d"), nValue);
#endif
			return WriteString(lpszSection, lpszEntry, tszValue);
		}

		//��ָ���ֶ�ָ����д��boolֵ
		bool WriteBoolean(LPCTSTR lpszSection, LPCTSTR lpszEntry, bool bValue)
		{
			std::tstring strTem;
			bValue ? strTem = _T("Y") : strTem = _T("N");
			return WriteString(lpszSection, lpszEntry, strTem.c_str());
		}

		//��ָ���ֶ�ָ����д���ַ���
		bool WriteString(LPCTSTR lpszSection, LPCTSTR lpszEntry, LPCTSTR lpszValue)
		{
			assert(lpszSection);
			assert(lpszEntry);
			if(m_IniFilename.empty())
				return false;
			return ::WritePrivateProfileString(lpszSection, lpszEntry, lpszValue, m_IniFilename.c_str());
		}

		//ɾ����
		bool DeleteKey(LPCTSTR lpszSection, LPCTSTR lpszEntry)
		{
			assert(lpszSection);
			assert(lpszEntry);
			if(m_IniFilename.empty())
				return false;
			return ::WritePrivateProfileString(lpszSection, lpszEntry, NULL, m_IniFilename.c_str());
		}

		//�ֶ�
		bool DeleteSection(LPCTSTR lpszSection)
		{
			assert(lpszSection);
			if(m_IniFilename.empty())
				return false;
			return ::WritePrivateProfileString(lpszSection, NULL, NULL, m_IniFilename.c_str());
		}

		//��ȡ��ǰ��������Ŀ¼
		bool GetExePath(LPTSTR pstrPath)
		{
			LPTSTR ptTem = NULL;
			TCHAR tszTemp[MAX_PATH] = {0};
			//��ȡ��ǰĿ¼  //�����ǻ�ȡ��ǰ�����ļ�������·�� 
			if (!GetModuleFileName(NULL, tszTemp, MAX_PATH) && pstrPath)
				return false; 

			ptTem = _tcsrchr(tszTemp, '\\');
			memcpy(pstrPath, tszTemp, (_tcslen(tszTemp)-_tcslen(ptTem))*sizeof(TCHAR));
			return true;
		}

		//����
	protected:
		std::tstring m_IniFilename;  //INI�ļ���
	};
}
#endif