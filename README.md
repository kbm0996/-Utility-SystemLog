# 시스템 로그 클래스
## 📢 개요
 프로그램은 언제든지 오류가 발생할 가능성이 있다. 따라서, 언제 어느 부분에서 무슨 이유로 오류가 발생했는지 파일로 기록할 필요가 있다.
 
 Debug 모드로 실행한 프로세스라면 이러한 로그가 필요하지 않지만, 이미 Release가 완료된 프로세스의 경우 오류가 났을때 정확한 원인을 찾기 어려우므로 별도의 로그를 남기도록 프로그래밍하는 것이 불가피하다.
   
## 🅿 사용법

### 1. 디렉토리 지정 : LOG_SET(int iWriteFlag, int iLogLevel, WCHAR *szDir_SubName));

* int iWriteFlag : 콘솔 출력, 파일 출력 여부(각각 LOG_CONSOLE, LOG_FILE). 비트 연산자 OR로 중복 선택 가능
* int iLogLevel : 감지할 로그의 최고 수위. 출력 시 로그의 중요도를 표시하기 위한 옵션. 지정한 수위 이하의 모든 로그를 저장한다. (ex. LOG_ERROR로 설정해놓으면 하위 레벨인 LOG_WARNG, LOG_DEBUG의 로그도 기록)
* WCHAR *szDir_SubName : 로그가 저장될 SubDirectory 이름

 기본적으로 로그는 프로그램이 있는 폴더에서 _LOG(기본 설정)\\SubDirectory(LOG_SET 함수로 지정)\\EscortDirectory(LOG 함수로 지정)에 저장되도록 설계했다.

### 2. 로그 출력 : LOG(WCHAR *szType, int iLogLevel, WCHAR *szString, ...)

* WCHAR *szType : 로그가 저장될 EscortDirectory 이름
* int iLogLevel : 해당 로그의 수위(LOG_DEBUG, LOG_WARNG, LOG_ERROR, LOG_SYSTM)
* WCHAR *szString, ... : 로그 문자열(가변 인자 삽입 가능)

### ▶ 예제

    LOG_SET(LOG_CONSOLE | LOG_FILE, LOG_DEBUG, L"MMOSERVER_LOG");
    LOG(L"SYSTEM", LOG_ERROR, L"Error() StringCchVPrintf() Error");
