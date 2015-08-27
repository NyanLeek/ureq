#ifndef UREQ_H
#define UREQ_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define GET 0
#define POST 1

struct HttpRequest {
    char *type;
    char *url;
    char *version;
};

struct Page {
    char *url;
    char *(*func)();
    // TODO: method
};

struct Page *pages = NULL;
int pageCount = 0;


int ureq_parse_header(char *r, struct HttpRequest *req);

char *ureq_get_header(char *r);

void ureq_init();
void ureq_send(char *r);
void ureq_run(struct HttpRequest *req);
void ureq_serve(char *url, char *(func)(), int method );


#endif