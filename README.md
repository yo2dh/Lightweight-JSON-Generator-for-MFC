# Lightweight JSON Generator for MFC

Copyright (c) 2014 DaeHun Yoo (yo2dh@naver.com)

## Introduction

This module is an lightweight JSON generator for MFC.

## Compatiability

JsonMfcGenerator have been tested on Visual C++ 2010 

## Usage at a glance

### CJsonObject
~~~~~~~~~~cpp
#include "JsonMfcGenerator.h"

...

void Test()
{
	CString strJson;
	CJsonObject json;
	json.SetValue( _T("Int") , 3 );
	json.SetValue( _T("Float") , 3.5 );
	
    json.ToString( strJson );
	TRACE ( _T("Json : %s\n") , strJson );
}

~~~~~~~~~~

Output
~~~~~~~~~~json
Json : {'Float':3.5,'Int':3}
~~~~~~~~~~

### CJsonArray
~~~~~~~~~~cpp
#include "JsonMfcGenerator.h"

...

void Test()
{
	CString strJson;
	CJsonArray array;
	array.Push( 3.5 );
	array.Push( _T("arraydata") );
	array.Push( 5 );

    array.ToString( strJson );
	TRACE ( _T("Json : %s\n") , strJson );
}

~~~~~~~~~~

Output
~~~~~~~~~~json
Json : [3.5,'arraydata',5]
~~~~~~~~~~

### CJsonObject & CJsonArray

~~~~~~~~~~cpp
#include "JsonMfcGenerator.h"

...

void Test()
{
	CJsonObject json;
	json.SetValue( _T("Int") , 3 );
	json.SetValue( _T("Float") , 3.5 );

	CJsonArray* pArray = new CJsonArray;
	pArray->Push( 3.5 );
	pArray->Push( _T("arraydata") );
	pArray->Push( 5 );

	CJsonObject* pData1 = new CJsonObject;
	pData1->SetValue( _T("Data") , _T("test") );
	pData1->SetValue( _T("Int") , 3 );
	pData1->SetValue( _T("Float") , 3.5 );

	CJsonObject* pData2 = new CJsonObject;
	pData2->SetValue( _T("Int") , 3 );
	pData2->SetValue( _T("Float") , 3.5 );

	json.SetValue( _T("Data1") , pData1 );
	pData1->SetValue( _T("Data2") , pData2 );
	pData1->SetValue( _T("Array") , pArray );

	json.ToString( strJson );

	TRACE ( _T("Json : %s\n") , strJson );
}
~~~~~~~~~~

Output
~~~~~~~~~~json
Json : {'Data1':{'Array':[3.5,'arraydata',5],'Float':3.5,'Data':'test','Int':3,'Data2':{'Float':3.5,'Int':3}},'Float':3.5,'Int':3}
~~~~~~~~~~




