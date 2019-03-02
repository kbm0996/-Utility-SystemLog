#include "CSystemLog.h"

void main()
{
	// testcase 1
	// 콘솔 출력 | 파일 쓰기, 인자 전달 
	LOG_SET(LOG_CONSOLE | LOG_FILE, LOG_DEBUG, L"SECOND DIR");
	LOG(L"THIRD DIR", LOG_ERROR, L"Error() testr %s", L"parameter");

	// testcase 2
	// 파일 쓰기
	LOG_SET(LOG_FILE, LOG_DEBUG, L"2SECOND DIR");
	LOG(L"THIRD DIR", LOG_ERROR, L"Error() testr2");

	// testcase 3
	// 콘솔 출력
	LOG_SET(LOG_CONSOLE, LOG_DEBUG, L"3SECOND DIR");
	LOG(L"THIRD DIR", LOG_ERROR, L"Error() testr3");
}