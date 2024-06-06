// DcsObject.h: interface for the CDcsObject class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DCSOBJECT_H__5D207903_0D2B_11D5_962A_0050FC0F4715__INCLUDED_)
#define AFX_DCSOBJECT_H__5D207903_0D2B_11D5_962A_0050FC0F4715__INCLUDED_

#ifdef _MSC_VER
	#if _MSC_VER > 1000
		#pragma once
	#endif // _MSC_VER > 1000
#endif // _MSC_VER


#if !defined(BYTE)
typedef unsigned char BYTE;
#endif

#ifndef NULL
  #define NULL	0L
#endif // NULL

#include <time.h>

// X.690 ��׼�� DER ����� (������������� X.690 ��׼)
// Encoding of class of Tag 
enum EAnsiClass			// Class			Bit8  Bit7
{						// ----------------------------
    UNIV = 0,			// Universal		0		0		
    APPL = (1 << 6),	// Application		0		1
    CNTX = (2 << 6),	// Context-specific 1		0
    PRIV = (3 << 6)		// Private			1		1
};

// Encoding of P/C of Tag
enum EAnsiForm			// P/C			Bit6
{						// ------------------
    PRIM = 0,			// Primitive	0
    CONS = (1 << 5)		// Constructed	1
};

// �������͵� Tag (class=Universal) �ĺ�5���� (Bit5 to Bit1) ����ֵ
// ����д����10��ֵ��ʽ��ȡֵ
enum EAnsiCode
{
    NO_TAG_CODE = 0,
    BOOLEAN_TAG_CODE = 1,
    INTEGER_TAG_CODE,
    BITSTRING_TAG_CODE,
    OCTETSTRING_TAG_CODE,
    NULLTYPE_TAG_CODE,
    OID_TAG_CODE,
    OD_TAG_CODE,
    EXTERNAL_TAG_CODE,
    REAL_TAG_CODE,
    ENUM_TAG_CODE,
	UTF8STRING_TAG_CODE = 12,
    SEQUENCE_TAG_CODE =  16,
    SET_TAG_CODE,
    NUMERICSTRING_TAG_CODE,
    PRINTABLESTRING_TAG_CODE,
    TELETEXSTRING_TAG_CODE,
    VIDEOTEXSTRING_TAG_CODE,
    IA5STRING_TAG_CODE,
    UTCTIME_TAG_CODE,
    GENERALIZEDTIME_TAG_CODE,
    GRAPHICSTRING_TAG_CODE,
    VISIBLESTRING_TAG_CODE,
    GENERALSTRING_TAG_CODE,
	UNIVERSALSTRING_TAG_CODE,
	NULLTYPE,
	BMPSTRING_TAG_CODE
};

#define TT61STRING_TAG_CODE TELETEXSTRING_TAG_CODE
#define ISO646STRING_TAG_CODE VISIBLESTRING_TAG_CODE


// �趨���� OID �� DER ����ֵ (T L V ��ʽ)
// ˫�����е�16������ʽ����ֵ��ÿһ���ֽڶ��� \x ��ͷ����
// ���Ǹ���OID��DER����������T L V��ʽ��ʾ��

// ��������㷨�� ID �� OID 
#define DES_ECB								1
#define DES_CBC								2
#define DES_OFB								3
#define DES_CFB								4
#define TRIDES_ECB							5

#define OID_DES_ECB							(BYTE*)"\x06\x05\x2B\x0E\x03\x02\x06"
#define OID_DES_CBC							(BYTE*)"\x06\x05\x2B\x0E\x03\x02\x07"
#define OID_DES_OFB							(BYTE*)"\x06\x05\x2B\x0E\x03\x02\x08"
#define OID_DES_CFB							(BYTE*)"\x06\x05\x2B\x0E\x03\x02\x09"
#define OID_TRIDES_ECB						(BYTE*)"\x06\x08\x2A\x86\x48\x86\xF7\x0D\x03\x07" 


// PKCS #7 �� ID �� OID 
#define PKCS7_DATA							6
#define PKCS7_SIGNEDDATA					7
#define PKCS7_ENVELOPEDDATA					8
#define PKCS7_SIGNEDANDENVELOPEDDATA		9
#define PKCS7_DIGESTEDDATA					10
#define PKCS7_ENCRYPTEDDATA					11

#define OID_PKCS7_DATA						(BYTE*)"\x06\x09\x2A\x86\x48\x86\xF7\x0D\x01\x07\x01"
#define OID_PKCS7_SIGNEDDATA				(BYTE*)"\x06\x09\x2A\x86\x48\x86\xF7\x0D\x01\x07\x02" 
#define OID_PKCS7_ENVELOPEDDATA				(BYTE*)"\x06\x09\x2A\x86\x48\x86\xF7\x0D\x01\x07\x03" 
#define OID_PKCS7_SIGNEDANDENVELOPEDDATA	(BYTE*)"\x06\x09\x2A\x86\x48\x86\xF7\x0D\x01\x07\x04" 
#define OID_PKCS7_DIGESTEDDATA				(BYTE*)"\x06\x09\x2A\x86\x48\x86\xF7\x0D\x01\x07\x05"
#define OID_PKCS7_ENCRYPTEDDATA				(BYTE*)"\x06\x09\x2A\x86\x48\x86\xF7\x0D\x01\x07\x06"


// PKCS #1 �е��㷨 ID ��OID ������(para) 
#define PKCS1_RSAENCRYPTION					12
#define PKCS1_MD2WITHRSAENCRYPTION			13
#define PKCS1_MD4WITHRSAENCRYPTION			14
#define PKCS1_MD5WITHRSAENCRYPTION			15
#define PKCS1_SHA1WITHRSAENCRYPTION			16
#define PKCS1_MD2							17
#define PKCS1_MD4							18
#define PKCS1_MD5							19
#define PKCS1_SHA1							20

#define OID_PKCS1_RSAENCRYPTION				(BYTE*)"\x06\x09\x2A\x86\x48\x86\xF7\x0D\x01\x01\x01"
#define OID_PKCS1_MD2WITHRSAENCRYPTION		(BYTE*)"\x06\x09\x2A\x86\x48\x86\xF7\x0D\x01\x01\x02"
#define OID_PKCS1_MD4WITHRSAENCRYPTION		(BYTE*)"\x06\x09\x2A\x86\x48\x86\xF7\x0D\x01\x01\x03"
#define OID_PKCS1_MD5WITHRSAENCRYPTION		(BYTE*)"\x06\x09\x2A\x86\x48\x86\xF7\x0D\x01\x01\x04"
#define OID_PKCS1_SHA1WITHRSAENCRYPTION		(BYTE*)"\x06\x09\x2A\x86\x48\x86\xF7\x0D\x01\x01\x05"
#define OID_PKCS1_MD2						(BYTE*)"\x06\x08\x2A\x86\x48\x86\xF7\x0D\x02\x02"
#define OID_PKCS1_MD4						(BYTE*)"\x06\x08\x2A\x86\x48\x86\xF7\x0D\x02\x04"
#define OID_PKCS1_MD5						(BYTE*)"\x06\x08\x2A\x86\x48\x86\xF7\x0D\x02\x05"
#define OID_PKCS1_SHA1						(BYTE*)"\x06\x05\x2B\x0E\x03\x02\x1A"

#define PARA_PKCS1_RSAENCRYPTION			512
#define DER_PARA_PKCS1_RSAENCRYPTION		(BYTE*)"\x05\x00"
#define PARA_PKCS1_SHA1WITHRSAENCRYPTION	516
#define DER_PARA_PKCS1_SHA1WITHRSAENCRYPTION	(BYTE*)"\x05\x00"

// ǩ���㷨�� ID �� OID  (������ǩ���㷨�� PKCS #1��)
#define DSA									21
#define DSAWITHSHA1							22

#define OID_DSA								(BYTE*)"\x06\x07\x2A\x86\x48\xCE\x38\x04\x01"
#define OID_DSAWITHSHA1						(BYTE*)"\x06\x07\x2A\x86\x48\xCE\x38\x04\x03"


// ��ԿЭ���㷨�� ID �� OID 
#define DH_PUBLICKEY						23

#define OID_DH_PUBLICKEY					(BYTE*)"\x06\x07\x2A\x86\x48\xCE\x3E\x02\x01"


// ��Ϣ��֤�㷨�� ID �� OID 
#define MD5_HMAC							24
#define SHA1_HMAC							25

#define OID_MD5_HMAC						(BYTE*)"\x06\x08\x2B\x06\x01\x05\x05\x08\x01\x01"
#define OID_SHA1_HMAC						(BYTE*)"\x06\x08\x2B\x06\x01\x05\x05\x08\x01\x02"

//����λ��������ӵĳ���
#define LENGTHOFPRIVATEKEY 1200
#define LENGTHOFSIGNATURE  1024
#define MAX					1
//

class CDcsObject  
{
public:
	CDcsObject();
	virtual ~CDcsObject();

protected:	
	int   m_iMyLevel;			// ��¼�̳������ĳ������Ա��ڶ��ؼ̳���ȷ�������λ��
	int   m_iErrorCode;			// ��¼����Ĵ��룬�Ա������ڳ������ܹ��Զ����д�����
	char  *m_pcErrorMessage;	// ָ�������Ϣ���ַ����ף�һ������Դ�ڶ���
};

#endif // !defined(AFX_DCSOBJECT_H__5D207903_0D2B_11D5_962A_0050FC0F4715__INCLUDED_)
