#ifndef _CLIENT_SESSION_H
#define _CLIENT_SESSION_H

#include "util/hashtbl.h"

typedef struct http_request_s
{
    char    	method[7];		/* HTTP 方法 */
    char    	url[1024];		/* 所有GET URL */
    char    	version[10];	/* 版本 */
	char		indata[256];
	char		vdir[32];		/* 虚拟目录文件部分 */
	hashtbl_t	*headers;		/* 请求头部 */
	hashtbl_t	*params;		/* 请求数据 */
} HttpRequest;

typedef struct http_response_s
{
	char	respcode[5];	/* 返回码 */
	char	respText[33];
	char	date[50];		/* 日期 */
    char    html[2048];
} HttpResponse;

typedef struct http_session_s
{
	int				fd;
	int				state;
	HttpRequest		*request;
	HttpResponse	*response;
} HttpSession;

HttpSession *HttpSession_New(int fd);

void HttpSession_Destroy(HttpSession **session);

#endif

