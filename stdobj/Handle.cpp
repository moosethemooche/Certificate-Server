//--------------------------------------------------------------------------------
//
// Copyright (c) 1999 MarkCare Solutions
//
// Programming by Rich Schonthal
//
//--------------------------------------------------------------------------------

// Handle.cpp: implementation of the CHandle class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Handle.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

//--------------------------------------------------------------------------------
CFindFileHandle::CFindFileHandle(HANDLE hand)
		: CHandle(hand)
	{
	}

//--------------------------------------------------------------------------------
CFindFileHandle::~CFindFileHandle()
	{
	Close();
	}

//--------------------------------------------------------------------------------
void CFindFileHandle::Close()
	{
	TRY
		{
		if(IsValid())
			::FindClose(m_handle);
		m_handle = INVALID_HANDLE_VALUE;
		}
	CATCH_ALL(e)
		{
		}
	END_CATCH_ALL
	}

//--------------------------------------------------------------------------------
CFindFileHandle::operator HANDLE()
	{
	return m_handle;
	}

//--------------------------------------------------------------------------------
CFindFileHandle::operator=(HANDLE hand)
	{
	m_handle = hand;
	}

//--------------------------------------------------------------------------------
//--------------------------------------------------------------------------------
//--------------------------------------------------------------------------------
CHandle::CHandle(HANDLE hand)
		: m_handle(hand)
	{
	}

//--------------------------------------------------------------------------------
CHandle::CHandle(const CHandle& rHand)
	{
	m_handle = rHand.m_handle;
	}

//--------------------------------------------------------------------------------
CHandle::~CHandle()
	{
	Close();
	}

//--------------------------------------------------------------------------------
void CHandle::Close()
	{
	TRY
		{
		if(IsValid())
			::CloseHandle(m_handle);
		m_handle = INVALID_HANDLE_VALUE;
		}
	CATCH_ALL(e)
		{
		}
	END_CATCH_ALL
	}

//--------------------------------------------------------------------------------
CHandle::operator HANDLE()
	{
	return m_handle;
	}

//--------------------------------------------------------------------------------
CHandle::operator=(HANDLE hand)
	{
	m_handle = hand;
	}

//--------------------------------------------------------------------------------
bool CHandle::IsValid()
	{
	return m_handle != NULL && m_handle != INVALID_HANDLE_VALUE;
	}
