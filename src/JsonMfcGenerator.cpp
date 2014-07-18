#include "StdAfx.h"
#include "JsonMfcGenerator.h"

void CJsonStringBuffer::Append( CString& str )
{
	Append( str , str.GetLength() );
}

void CJsonStringBuffer::Append( LPCTSTR lpsz )
{
	m_list.AddTail( lpsz );
	m_nLength += _tcslen( lpsz );
}

void CJsonStringBuffer::Append( LPCTSTR lpsz , int nLength )
{
	m_list.AddTail( lpsz );
	m_nLength += nLength;
}


void CJsonStringBuffer::Clear()
{
	m_list.RemoveAll();
}

void CJsonStringBuffer::ToString( CString& strOutput )
{
	int nOffset = 0;
	int nSize = m_nLength + 1;
	LPTSTR pBuffer = strOutput.GetBuffer ( nSize );
	for( POSITION pos = m_list.GetHeadPosition() ; pos != NULL ; )
	{
		CString& str = m_list.GetNext( pos );
		_tcscpy_s( pBuffer + nOffset , nSize - nOffset , str );
		nOffset += str.GetLength();
	}
	strOutput.ReleaseBuffer( m_nLength );
}


CJsonObject::~CJsonObject()
{
	CString strKey;
	CJsonItem* pItem;
	POSITION pos = m_map.GetStartPosition();
	while( pos != NULL )
	{
		m_map.GetNextAssoc ( pos , strKey , pItem );
		if( pItem ) delete pItem;
	}
	m_map.RemoveAll();
}

void CJsonObject::AppendStringBuffer( CJsonStringBuffer& sb )
{
	CString strKey;
	CString strTemp;
	CJsonItem* pItem;
	sb.Append( _T("{") );
	POSITION pos = m_map.GetStartPosition();
	BOOL bFirst = TRUE;
	while( pos != NULL )
	{
		if( bFirst ) bFirst = FALSE;
		else
		{
			sb.Append( _T(",") );
		}
		m_map.GetNextAssoc ( pos , strKey , pItem );
		strTemp.Format ( _T("'%s':") , strKey );
		sb.Append( strTemp );
		pItem->AppendStringBuffer( sb );
	}
	sb.Append( _T("}") );
}

void CJsonObject::ToString( CString& strOutput )
{
	CJsonStringBuffer sb;
	AppendStringBuffer( sb );
	sb.ToString( strOutput );
}

void CJsonObject::SetValue( LPCTSTR lpszKey , int nValue )
{
	m_map.SetAt( lpszKey , new CJsonValue( nValue ) );
}

void CJsonObject::SetValue( LPCTSTR lpszKey , double fValue )
{
	m_map.SetAt( lpszKey , new CJsonValue( fValue ) );
}

void CJsonObject::SetValue( LPCTSTR lpszKey , LPCTSTR strValue )
{
	m_map.SetAt( lpszKey , new CJsonValue( strValue ) );
}

void CJsonObject::SetValue( LPCTSTR lpszKey , CJsonItem* pValue )
{
	m_map.SetAt( lpszKey , pValue );
}

CJsonArray::~CJsonArray()
{
	while( m_list.IsEmpty() == FALSE )
	{
		delete m_list.RemoveHead();
	}
}

void CJsonArray::AppendStringBuffer( CJsonStringBuffer& sb )
{
	sb.Append( _T("[") );
	BOOL bFirst = TRUE;
	for( POSITION pos = m_list.GetHeadPosition() ; pos != NULL ; )
	{
		if( bFirst ) bFirst = FALSE;
		else
		{
			sb.Append( _T(",") );
		}
		auto p = m_list.GetNext( pos );
		p->AppendStringBuffer( sb );		
	}
	sb.Append( _T("]") );
}

void CJsonArray::ToString( CString& strOutput )
{
	CJsonStringBuffer sb;
	AppendStringBuffer( sb );

	sb.ToString( strOutput );
}

void CJsonArray::Push( int nValue )
{
	m_list.AddTail( new CJsonValue( nValue ) );
}

void CJsonArray::Push( double fValue )
{
	m_list.AddTail( new CJsonValue( fValue ) );
}

void CJsonArray::Push( LPCTSTR strValue )
{
	m_list.AddTail( new CJsonValue( strValue ) );
}

void CJsonArray::Push( CJsonItem* pValue )
{
	m_list.AddTail( pValue );
}

void CJsonValue::ToString( CString& strOutput )
{
	strOutput += m_strValue;
}

void CJsonValue::AppendStringBuffer( CJsonStringBuffer& sb )
{
	sb.Append( m_strValue );
}
