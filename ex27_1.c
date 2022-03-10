#undef NDEBUG
#include "dbg.h"
#include <stdio.h>
#include <assert.h>

/*입력값이 정상이라고 가정하는 순진한 copy이다.*/
void copy(char to[], char from[])
{
	int i = 0;
	while ((to[i] = from[i]) != '\0')
		++i;
}

/*문자열의 길이를 이용하여 루프를제어하고 종료시킴 */
int safecopy(int from_len, char *from, int to_len, char *to_len)
{
	assert(from != NULL && to != NULL && "from and to can't be NULL");
	int i = 0 ;
	int max = from_len > to_len - 1 ?  to_len - 1 : from_len;

	if (from_len < 0 || to_len <= 0)
		return (-1);
	for (i = 0 ; i < max ; i++)
		to[i] = from[i];
	to[to_len - 1] = 0;

	return (i);
}
