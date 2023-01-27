#pragma once
#define SAFETY 1024
#define THOUSAND 5000
#define SMALL_X 900
#define STACK_X unsigned long static __stdcall
#define KILL(p)		{ if (p) { delete p; p = NULL; } }
#define KILL_WND(p) { if (p) { if (IsWindow(p->GetSafeHwnd())) p->DestroyWindow(); delete p; p = NULL; } }


//#define COLOR_BACK_GROUND	RGB(37,37,37)
#define COLOR_BACK_GROUND	RGB(100,100,100)
#define	COLOR_LIGHTRED		RGB( 255, 000, 000 )
#define	COLOR_DARKRED		RGB( 064, 000, 000 )
#define	COLOR_BLACK			RGB( 000, 000, 000 )
#define	COLOR_WHITE			RGB( 255, 255, 255 )

#define DEF_JSON_IMAGE_KEY	_T("IMAGE_FILE_NAME")


// Buffer = 2MB
#define DEF_JSON_BUF_SIZ		2097152
#define DEF_JSON_OTHER_BUF_SIZ	2097152
//#define DEF_JSON_OTHER_BUF_SIZ	1048576

// Buffer Size정의
#define BUF_LEN					256
#define LBUF_LEN				512
#define XBUF_LEN				1024
#define XXBUF_LEN				2048


//typedef enum _EN_FILE_Q_TYPE_ {
//	  EN_FILE_Q_TYPE_MAIN = 0
//	, EN_FILE_Q_TYPE_SOLACE
//	, EN_FILE_Q_TYPE_DFS
//	, EN_FILE_Q_TYPE_REST
//	//
//	, EN_FILE_Q_TYPE_MAX
//} _FILE_Q_TYPE_;


typedef enum _EN_DIR_DEPTH_ {
	EN_DIR_DEPTH_ROOT = 0
	// Insp Data
	, EN_DIR_DEPTH_YYYYMM
	, EN_DIR_DEPTH_YYYYMM_DD
	, EN_DIR_DEPTH_YYYYMM_DD_HH
	, EN_DIR_DEPTH_YYYYMM_DD_HH_LOT
	, EN_DIR_DEPTH_YYYYMM_DD_HH_LOT_10M
	//
	// Retry Wait
	, EN_DIR_DEPTH_YYYYMMDDHH
	//
	// Log Data
	, EN_DIR_DEPTH_YYYY
	, EN_DIR_DEPTH_YYYY_MM
	, EN_DIR_DEPTH_YYYY_MM_DD
	//
	, EN_DIR_DEPTH_MAX
} _DIR_DEPTH_;


typedef enum _EN_DATA_TYPE_ {
	EN_DATA_TYPE_INSP = 0
	, EN_DATA_TYPE_PARAM
	, EN_DATA_TYPE_PARAM_HIST
	, EN_DATA_TYPE_ALARM
	, EN_DATA_TYPE_STATUS
	//
	//, EN_DATA_TYPE_SIMULATOR	// Watcher가 아닌 폴더 검색 방식으로 변경
	//
	// 이하 Watcher 실행 X
	, EN_DATA_TYPE_INSP_IMG_OK
	, EN_DATA_TYPE_INSP_IMG_NG
	//
	, EN_DATA_TYPE_MAX
} _DATA_TYPE_;


typedef enum _EN_SIM_DATA_TYPE_ {
	EN_SIM_DATA_TYPE_PARAM = 0
	, EN_SIM_DATA_TYPE_DB
	//
	, EN_SIM_DATA_TYPE_MAX
} _SIM_DATA_TYPE_;





// Agent 상태
typedef enum _EN_AGENT_STATUS_TYPE_
{
	EN_AGENT_STATUS_SPC = 1
	, EN_AGENT_STATUS_DFS = 2
	, EN_AGENT_STATUS_REST = 4
	, EN_AGENT_STATUS_SIMULATOR = 8
} _AGENT_STATUS_TYPE_;

// Agent 상태 : Config
typedef enum _EN_AGENT_STATUS_CONFIG_
{
	EN_AGENT_STATUS_CONFIG_OFF_SPC = (1 << 0)
	, EN_AGENT_STATUS_CONFIG_OFF_DFS = (1 << 1)
	, EN_AGENT_STATUS_CONFIG_OFF_IMS = (1 << 2)
} _AGENT_STATUS_CONFIG_;


// Agent 상태 : Communication
typedef enum _EN_AGENT_STATUS_COMM_
{
	EN_AGENT_STATUS_COMM_ERR_SPC_WAIT_CNT = (1 << 0)
	, EN_AGENT_STATUS_COMM_ERR_DFS_WAIT_CNT = (1 << 1)
	, EN_AGENT_STATUS_COMM_ERR_IMS_WAIT_CNT = (1 << 2)
	, EN_AGENT_STATUS_COMM_ERR_SPC = (1 << 3)
	, EN_AGENT_STATUS_COMM_ERR_DFS = (1 << 4)
	, EN_AGENT_STATUS_COMM_ERR_IMS = (1 << 5)

} _AGENT_STATUS_COMM_;


// Agent 상태 : Inspection file 등
typedef enum _EN_AGENT_STATUS_INSP_
{
	EN_AGENT_STATUS_INSP_ERR_EQPID_INSP = (1 << 0)
	, EN_AGENT_STATUS_INSP_ERR_EQPID_STATUS = (1 << 1)
	, EN_AGENT_STATUS_INSP_ERR_EQPID_PARAM = (1 << 2)
	, EN_AGENT_STATUS_INSP_ERR_EQPID_ALARM = (1 << 3)
	, EN_AGENT_STATUS_INSP_ERR_PARSING_INSP = (1 << 4)
	, EN_AGENT_STATUS_INSP_ERR_PARSING_STATUS = (1 << 5)
	, EN_AGENT_STATUS_INSP_ERR_PARSING_PARAM = (1 << 6)
	, EN_AGENT_STATUS_INSP_ERR_PARSING_ALARM = (1 << 7)
	, EN_AGENT_STATUS_INSP_ERR_NOT_FOUND_STATUS = (1 << 8)
	, EN_AGENT_STATUS_INSP_ERR_NOT_FOUND_IMG = (1 << 9)
	, EN_AGENT_STATUS_INSP_ERR_NOT_FOUND_IMG_RETRY = (1 << 10)
	, EN_AGENT_STATUS_INSP_ERR_EQPID_EMPTY_STATUS = (1 << 11)
	, EN_AGENT_STATUS_INSP_ERR_FAIL_CREATE_STATUS = (1 << 12)
} _AGENT_STATUS_INSP_;




// 변경 될때마다 같이 변경해야 함.
//		- CString GetLogTypeStr(int nType)
typedef enum _EN_LOG_TYPE_
{
	_LOG_MAIN_
	, _LOG_SOLACE_
	, _LOG_DFS_
	, _LOG_REST_
	, _LOG_DB_
	, _LOG_SIMULATOR_
	//
	, _LOG_OTHER_
	, _LOG_OTHER_SOLACE_
	, _LOG_OTHER_REST_
	//
	, _LOG_SOLACE_DEBUG_
	//
	, _LOG_WATCHER_
	//
	, _LOG_DELETE_
	//
	// 20210414 nvMSH : Json File저장수량 log추가
	, _LOG_UPLOAD_CNT
	//, _LOG_UPLOAD_SKIP
	//
	, _LOG_WARNING_
	, _LOG_ERROR_
	, _LOG_ERROR_SOLACE_
	//
	, _LOG_TYPE_MAX_
} _LOG_TYPE_;

