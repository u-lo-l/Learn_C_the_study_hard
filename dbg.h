#ifndef __DBG_H__
# define __DBG_H__

#include <stdio.h>
#include <errno.h>
#include <string.h>
// 프로그램을 재컴파일하도록 만들어 디버그 로그 메세지가 모두 출력되도록 한다.
// NDEBUG가 정의된 상태에서 컴파일을 하면 아무런 디버그 마시지도 남지 않는다.
// 디버그 메세지를 표시하고 싶지 않을 때, NDBUG를 define하면 된다.
# ifdef NDBUG
#  define debug(M,...)
// debug("format", arg1, arg2)를 stderr에 출력시키는 fprintf로 바꾼다.
// 아래는 C의 전처리기에서 지정해주는 매크로이다.
// __FILE__      : 현재 파일의 이름(전체 경로)를 의미하는 매크로
// __LINE__      : 줄 번호
// ##__VA_ARGS__ : 가변 인자
// 추가적으로 __FUNCTION__ : 현재 함수 명 등이 있다.
# else
#  define debug(M,...) fprintf(stderr, "DEBUG, %s:%d:" M "\n", \
		__FILE__, __LINE__, ##__VA_ARGS__)
# endif
// errno를 안전하게 읽을 수 있도록 해준다.
# define clean_errno() (errno == 0 ? "None" : strerror(errno))
// error 출력 매크로이다. 
# define log_err(M,...) fprintf(stderr, \
		"[ERROR] (%s:%d: errno:%s) " M "\n", __FILE__, __LINE__, \
		clean_errno(), ##__VA_ARGS__)
# define log_warn(M,...) fprintf(stderr,\
		"[WARN] (%s:%d: errno:%s)" M "\n",\
		__FILE__, __LINE__, clean_errno(), ##__VA_ARGS__)
# define log_info(M,...) fprintf(stderr, "[INFO] (%s:%d)" M "\n",\
		__FILE__, __LINE__, ##__VA_ARGS__)
// A가 참인 경우 에러메세지를 로그로 남긴 후 함수 내 error:로 이동한다.
# define check(A, M, ...) if(!A) {log_err(M, ##__VA_ARGS__);\
		errno = 0; goto error;}
// 함수 내 어디에나 놓을 수 있지만 실행되면 안되는 매크로이다.
// 실행하는 일이 발생하면 오류 메세지를 출력한 다음 error로 점프한다.
// if 나 switch문에 넣어 일어나면 안 될 만한 곳에 놓는다.
# define sentinel(M,...) {log_err(M,##__VA_ARGS__);\
		errno = 0; goto error;}
//포인터를 점검하여 유효하지 않은 경우 out of memory를 출력한다.
# define check_mem(A) check((A), "Out of memory.")
// 오류가 이쓰면 처리하지만 오류가 흔한 경우에는 보고하지 않는다.
# define check_debug(A,M,...) if(!(A)) {debug(M, ##__VA_ARGS__);\
		errno=0; goto error; }

#endif
