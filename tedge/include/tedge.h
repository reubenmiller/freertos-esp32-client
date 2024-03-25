#ifndef TEDGE_HDR_H
#define TEDGE_HDR_H

void tedge_banner(void);

char * replace_prefix(char *input, char *prefix, char *new_prefix);
char * tedge_get_url_path(char *url);
char * tedge_get_c8y_proxy_url(char *mqtt_host, char *url);

#endif
