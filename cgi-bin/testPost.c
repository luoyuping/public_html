#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#define MAXLINE 8192

int main(void) {
    char *buf,*p;
    int length=0;
    char content[MAXLINE],data[MAXLINE];
    char name[100],passwd[100];

    if ((buf = getenv("CONTENT-LENGTH")) != NULL)
    {
    	length=atoi(buf);
    }
    p=fgets(data,length+1,stdin);
    if(p==NULL) {
        sprintf(content, "Something is wrong\r\n");
    }
    else {
        p = strchr(data, '&');
        *p = '\0';
        strcpy(name, data);
        strcpy(passwd, p+1);
        sprintf(content, "<h1>Test CGI in method Post </h1>\r\n<p>the name:%s</p>\r\n <p>the password:%s\r\n</p>\r\n<p>Thanks for visiting!</p>\r\n",name,passwd);
    }
    printf("HTTP/1.0 200 OK\r\n");
    printf("Server: Linux_C Web Server\r\n");
    printf("Content-length: %d\r\n", strlen(content));
    printf("Content-type: text/html\r\n\r\n");
    printf("%s", content);
    fflush(stdout);
    exit(0);
}
