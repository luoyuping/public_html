#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAXLINE 8192
int main(void) {
    char *buf, *p;
    char name[MAXLINE], passwd[MAXLINE],content[MAXLINE];

    /* Extract the two arguments */
    if ((buf = getenv("QUERY_STRING")) != NULL) {
        p = strchr(buf, '&');
        *p = '\0';
        strcpy(name, buf);
        strcpy(passwd, p+1);
    }


    /* Make the response body */
    sprintf(content, "<h1>Test CGI in method get </h1>\r\n<p>the name:%s</p>\r\n 
            <p>the password:%s\r\n</p>\r\n<p>Thanks for visiting!</p>\r\n",name,passwd);

    /* Generate the HTTP response */

	printf("HTTP/1.0 200 OK\r\n");
	printf("Server: Linux_C Web Server\r\n");
    printf("Content-length: %d\r\n", strlen(content));
    printf("Content-type: text/html\r\n\r\n");
    printf("%s", content);
    fflush(stdout);
    exit(0);
}
