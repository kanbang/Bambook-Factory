/**************************************************************
** Copyright (C) 2009-2010 ʢ������
** All right reserved
***************************************************************
**
** ��Ŀ���ƣ�Bambook SDK
** ���ܼ�飺Bambook PC �����������ͷ�ļ�
**
** ԭʼ���ߣ����ǵ��� Bambook SDK ��Ŀ��
** ��    ע��
** ����ʱ�䣺2010-10-12
** �����£�2010-11-05
** ��    ����1.1
***************************************************************
** ��Ԫ��ʶ��$Id: $
** �汾��ʷ��
** �� �� �ߣ�
** ����޸ģ�
**************************************************************/

#ifndef __BAMBOOKCORE_H__
#define __BAMBOOKCORE_H__

//==============================================================================
// �������ͼ���������
//==============================================================================

// ���幫������
typedef __int32             int32_t;
typedef unsigned __int32    uint32_t;
typedef __int32             intptr_t2;

// API ����ֵ����
typedef int32_t             BB_RESULT;

// ���Ӿ��
typedef intptr_t2            BB_HANDLE;

// SDK �汾��
#define BAMBOOK_SDK_VERSION 0x00090000

// ʹ�� USB ���� Bambook ���豸 IP
#define DEFAULT_BAMBOOK_IP  "192.168.250.2"

// ��������ֵ����
#define BR_SUCC             0     // �����ɹ�
#define BR_FAIL             1001  // ����ʧ��
#define BR_NOT_IMPL         1002  // �ù��ܻ�δʵ��
#define BR_DISCONNECTED     1003  // ���豸�������ѶϿ�
#define BR_PARAM_ERROR      1004  // ���ú�������Ĳ�������
#define BR_TIMEOUT          1005  // ������ͨѶ��ʱ
#define BR_INVALID_HANDLE   1006  // ����ľ����Ч
#define BR_INVALID_FILE     1007  // ������ļ������ڻ��ʽ��Ч
#define BR_INVALID_DIR      1008  // �����Ŀ¼������
#define BR_BUSY             1010  // �豸æ����һ��������δ���
#define BR_EOF              1011  // �ļ�������ѽ���
#define BR_IO_ERROR         1012  // �ļ���дʧ��
#define BR_FILE_NOT_INSIDE  1013  // ָ�����ļ����ڰ���

// ��ǰ����״̬
#define CONN_CONNECTED      0     // ������
#define CONN_DISCONNECTED   1     // δ���ӻ������ѶϿ�
#define CONN_CONNECTING     2     // ��������
#define CONN_WAIT_FOR_AUTH  3     // �����ӣ����ڵȴ������֤����δʵ�֣�

// ����״̬
#define TRANS_STATUS_TRANS  0     // ���ڴ���
#define TRANS_STATUS_DONE   1     // �������
#define TRANS_STATUS_ERR    2     // �������

// ��������
enum BambookKey
{
    BBKeyNum0 = 0, BBKeyNum1, BBKeyNum2, BBKeyNum3, BBKeyNum4,
    BBKeyNum5, BBKeyNum6, BBKeyNum7, BBKeyNum8, BBKeyNum9,
    BBKeyStar, BBKeyCross, BBKeyUp, BBKeyDown, BBKeyLeft, BBKeyRight, BBKeyPageUp, BBKeyPageDown,
    BBKeyOK, BBKeyESC, BBKeyBookshelf, BBKeyStore, BBKeyTTS, BBKeyMenu, BBKeyInteract
};

// �豸��Ϣ�ṹ
struct DeviceInfo
{
    uint32_t cbSize;              // �ṹ��С
    char sn[20];                  // �豸���к�
    char firmwareVersion[20];     // �豸�̼��汾
    uint32_t deviceVolume;        // �豸�ܴ洢�ռ䣬��λΪKB
    uint32_t spareVolume;         // ʣ��洢�ռ䣬��λΪKB
};

// ��������Ϣ�ṹ
struct PrivBookInfo
{
    uint32_t cbSize;              // �ṹ��С
    char bookGuid[20];            // �鼮id(���豸���snb�ļ���)
    char bookName[80];            // ����
    char bookAuthor[40];          // ����
    char bookAbstract[256];       // ժҪ
};

////////////////////////////////////////////////////////////////////////////////
// ���ܣ�����������ص�����
// ������status: ����״̬
//       progress: ������ȣ�0..100
//       userData: �û�����APIʱ���������
// ע�ͣ��ڵ��������鴫��ʱʹ��
////////////////////////////////////////////////////////////////////////////////
typedef void(* TransCallback)(uint32_t status, uint32_t progress, intptr_t2 userData);

//==============================================================================
// SDK API ��������
//==============================================================================

////////////////////////////////////////////////////////////////////////////////
// ���ܣ�ȡ��SDK DLL�汾��
// ������version: ָ�룬���ذ汾��
// ���أ��ɹ����� BR_SUCC
// ע�ͣ����øú������Է���DLL֧��SDK�汾�ţ������ڼ����Դ���
////////////////////////////////////////////////////////////////////////////////
extern "C" BB_RESULT BambookGetSDKVersion(uint32_t * version);

////////////////////////////////////////////////////////////////////////////////
// ���ܣ�����Bambook�豸
// ������lpszIP: Bambook IP��ַ������ʱʹ��Ĭ��ֵ DEFAULT_BAMBOOK_IP
//       timeOut: ��ʱֵ����λ���룬0ΪĬ��
//       hConn: ���ָ�룬ִ�гɹ��������Ӿ��
// ���أ��ɹ����� BR_SUCC��ʧ�ܷ��� BR_FAIL����ʱ���� BR_TIMEOUT
// ע�ͣ����ú����������ִ�У����ӳɹ��� hConn Ϊ���Ӿ����
//       ���ӱ��жϻ�ͨѶ������Ӧ���� BambookDisconnect �ͷ���Դ
////////////////////////////////////////////////////////////////////////////////
extern "C" BB_RESULT BambookConnect(const char * lpszIP, uint32_t timeOut, BB_HANDLE * hConn);

////////////////////////////////////////////////////////////////////////////////
// ���ܣ��Ͽ�Bambook�豸������
// ������hConn: ���Ӿ��
// ���أ��ɹ����� BR_SUCC��ʧ�ܷ��� BR_FAIL
// ע�ͣ����ú����������ִ�У�ֱ�����ӱ��Ͽ���ʧ�ܣ��ɹ��� hConn �����������
////////////////////////////////////////////////////////////////////////////////
extern "C" BB_RESULT BambookDisconnect(BB_HANDLE hConn);

////////////////////////////////////////////////////////////////////////////////
// ���ܣ���ѯ��ǰBambook�豸������״̬
// ������hConn: ���Ӿ��
//       status: ָ�룬��������״̬
// ���أ��ɹ����� BR_SUCC��ʧ�ܷ��� BR_FAIL
// ע�ͣ�Ӧ���ڵ�������APIǰ�ɵ��øú����Բ�ѯ����״̬
////////////////////////////////////////////////////////////////////////////////
extern "C" BB_RESULT BambookGetConnectStatus(BB_HANDLE hConn, uint32_t * status);

////////////////////////////////////////////////////////////////////////////////
// ���ܣ���ȡBambook������Ϣ
// ������hConn: ���Ӿ��
//       pInfo: ��Ϣָ�룬���ڷ��ػ�����Ϣ������ǰӦ���� pInfo->cbSize = SizeOf(DeviceInfo)
// ���أ��ɹ����� BR_SUCC��ʧ�ܷ��� BR_FAIL �����ԭ�����
//       ��� pInfo->cbSize ����ȷ������ BR_PARAM_ERROR
// ע�ͣ����ú����������ִ�У�ֱ�������ɹ���ʧ��
////////////////////////////////////////////////////////////////////////////////
extern "C" BB_RESULT BambookGetDeviceInfo(BB_HANDLE hConn, DeviceInfo * pInfo);

////////////////////////////////////////////////////////////////////////////////
// ���ܣ���ȡBambook��һ����������Ϣ
// ������hConn: ���Ӿ��
//       pInfo: ��Ϣָ�룬���ڷ�����������Ϣ������ǰӦ���� pInfo->cbSize = SizeOf(PrivBookInfo)
// ���أ��ɹ����� BR_SUCC������Ҳ��������鷵�� BR_EOF���������󷵻ش������
// ע�ͣ����øú����󽫴�ͷ��ʼ���豸������������Ϣ���ɹ�������ٴε��� BambookGetNextPrivBookInfo
//       ����ʣ�µ���������Ϣ���ú���������ִ�У�ֱ�������ɹ���ʧ��
////////////////////////////////////////////////////////////////////////////////
extern "C" BB_RESULT BambookGetFirstPrivBookInfo(BB_HANDLE hConn, PrivBookInfo * pInfo);

////////////////////////////////////////////////////////////////////////////////
// ���ܣ���ȡBambook��һ����������Ϣ
// ������hConn: ���Ӿ��
//       pInfo: ��Ϣָ�룬���ڷ�����������Ϣ������ǰӦ���� pInfo->cbSize = SizeOf(PrivBookInfo)
// ���أ��ɹ����� BR_SUCC������Ҳ��������鷵�� BR_EOF���������󷵻ش������
// ע�ͣ��ڵ��� BambookGetFirstPrivBookInfo �ɹ����ٵ��ñ����������Һ�̵���������Ϣ��
//       �ú���������ִ�У�ֱ�������ɹ���ʧ��
////////////////////////////////////////////////////////////////////////////////
extern "C" BB_RESULT BambookGetNextPrivBookInfo(BB_HANDLE hConn, PrivBookInfo * pInfo);

////////////////////////////////////////////////////////////////////////////////
// ���ܣ���Bambook���������飬����Bambook�Ժ���鼮IDΪ������ɵ��ִ�
// ������hConn: ���Ӿ��
//       pszSnbFile: ������ȫ·���ļ���
//       pCallbackFunc: ��������лص��������ص��������ڵ������߳���ִ��
//       userData: �ڻص��д���
// ���أ��ɹ����� BR_SUCC��ʧ�ܷ��� BR_FAIL �����ԭ�����
// ע�ͣ����øú������������ء�������óɹ���������̻���ûص�����֪ͨ״̬�ͽ���
////////////////////////////////////////////////////////////////////////////////
extern "C" BB_RESULT BambookAddPrivBook(BB_HANDLE hConn, const char * pszSnbFile,
                                        TransCallback pCallbackFunc, intptr_t2 userData);

////////////////////////////////////////////////////////////////////////////////
// ���ܣ���Bambook���������飬��ָ���鼮ID���鼮ID���ȴ���0���ó���char[20]
//       IDΪӢ�ĺ���ĸ�������λΪ".snb"��
//       ���������������滻Bambook���ض��鼮��
// ������hConn: ���Ӿ��
//       pszSnbFile: ������ȫ·���ļ���
//       lpszBookID: �鼮ID
//       pCallbackFunc: ��������лص��������ص��������ڵ������߳���ִ��
//       userData: �ڻص��д���
// ���أ��ɹ����� BR_SUCC��ʧ�ܷ��� BR_FAIL �����ԭ�����
// ע�ͣ����øú������������ء�������óɹ���������̻���ûص�����֪ͨ״̬�ͽ���
////////////////////////////////////////////////////////////////////////////////
extern "C" BB_RESULT BambookReplacePrivBook(BB_HANDLE hConn, const char * pszSnbFile, const char * lpszBookID,
                                            TransCallback pCallbackFunc, intptr_t2 userData);

////////////////////////////////////////////////////////////////////////////////
// ���ܣ�ɾ��Bambook������
// ������hConn: ���Ӿ��
//       lpszBookID: ��Ӧ��������Ϣ�е� bookGuid
// ���أ��ɹ����� BR_SUCC��ʧ�ܷ��� BR_FAIL �����ԭ�����
// ע�ͣ��ú���������ִ�У�ֱ�������ɹ���ʧ��
////////////////////////////////////////////////////////////////////////////////
extern "C" BB_RESULT BambookDeletePrivBook(BB_HANDLE hConn, const char * lpszBookID);

////////////////////////////////////////////////////////////////////////////////
// ���ܣ���Bambook�����������ļ�
// ������hConn: ���Ӿ��
//       lpszBookID: ��Ӧ��������Ϣ�е� bookGuid
//       lpszFilePath: �����������ļ����Ŀ¼
//       pCallbackFunc: ��������лص��������ص��������ڵ������߳���ִ��
//       userData: �ڻص��д���
// ���أ��ɹ����� BR_SUCC��ʧ�ܷ��� BR_FAIL �����ԭ�����
// ע�ͣ����øú������������ء�������óɹ���������̻���ûص�����֪ͨ״̬�ͽ���
////////////////////////////////////////////////////////////////////////////////
extern "C" BB_RESULT BambookFetchPrivBook(BB_HANDLE hConn, const char * lpszBookID, const char * lpszFilePath,
                                          TransCallback pCallbackFunc, intptr_t2 userData);

////////////////////////////////////////////////////////////////////////////////
// ���ܣ���Bambook���Ͱ�������
// ������hConn: ���Ӿ��
//       key: ����ֵ
// ���أ��ɹ����� BR_SUCC��ʧ�ܷ��� BR_FAIL �����ԭ�����
////////////////////////////////////////////////////////////////////////////////
extern "C" BB_RESULT BambookKeyPress(BB_HANDLE hConn, BambookKey key);

////////////////////////////////////////////////////////////////////////////////
// ���ܣ���һ������ SNB Ŀ¼�ṹ��Ŀ¼��� SNB ��
// ������snbName: ���ɵ� snb �ļ���
//       rootDir: Ҫ����ĸ�Ŀ¼
// ���أ��ɹ����� BR_SUCC��ʧ�ܷ��� BR_FAIL��BR_IO_ERROR �����ԭ�����
////////////////////////////////////////////////////////////////////////////////
extern "C" BB_RESULT BambookPackSnbFromDir(const char * snbName, const char * rootDir);

////////////////////////////////////////////////////////////////////////////////
// ���ܣ��������·���ļ����� SNB ���н��һ���ļ�
// ������snbName: Ҫ������ snb �ļ���
//       relativePath: Ҫ��ѹ���ļ��ڰ��е����·�����ļ��������磺"snbf/book.snbf"
//       outputName: ��ѹ�������ļ������ȫ·���ļ���
// ���أ��ɹ����� BR_SUCC��ʧ�ܷ��� BR_FAIL��BR_IO_ERROR��BR_FILE_NOT_INSIDE �����ԭ�����
////////////////////////////////////////////////////////////////////////////////
extern "C" BB_RESULT BambookUnpackFileFromSnb(const char * snbName, const char * relativePath, const char * outputName);

////////////////////////////////////////////////////////////////////////////////
// ���ܣ����һ���ļ��Ƿ�Ϸ��� SNB �ļ�
// ������snbName: Ҫ������ snb �ļ���
// ���أ�����ļ��Ϸ� BR_SUCC�����򷵻� BR_INVALID_FILE �����ԭ�����
////////////////////////////////////////////////////////////////////////////////
extern "C" BB_RESULT BambookVerifySnbFile(const char * snbName);

////////////////////////////////////////////////////////////////////////////////
// ���ܣ����ش������Ӧ�����ĺ���
// ������nCode: �������
// ���أ�������Ϣ�ַ���ָ��
// ע�ͣ��ú�������ȡ�ô����ַ������������δ����Ĵ�����룬������ "δ֪����"
////////////////////////////////////////////////////////////////////////////////
extern "C" const char * BambookGetErrorString(BB_RESULT nCode);

#endif /* __BAMBOOKCORE_H__ */
