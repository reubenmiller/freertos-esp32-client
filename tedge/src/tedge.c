#include <stdio.h>
#include <string.h>
#include "tedge.h"

void tedge_banner(void)
{
    printf("\n----------------------------\ntedge app\n----------------------------\n\n");
}

char * replace_prefix(char *input, char *prefix, char *new_prefix)
{
    char *schema_token = strstr(input, prefix);
    int len = (int) strlen(input);
    int substr_len = (int) strlen(prefix);

    char *value = calloc(len + 1, sizeof(char));

    if (schema_token != NULL && len > substr_len)
    {
        int i_start = (int) (schema_token - input);
        strcpy(value, new_prefix);
        strcat(value, input + i_start + substr_len);
    }
    else
    {
        strcpy(value, new_prefix);
        strcat(value, input);
    }
    return value;
}

char *tedge_get_url_path(char *url)
{
    // Remove schema prefix
    char *schema_tok = strstr(url, "://");
    if (schema_tok != NULL)
    {
        url = schema_tok + 3;
    }

    // Find first slash and return rest or the path (including first slash)
    int end = (int)strlen(url);
    int x = 0;
    char sep = '/';
    for (x = 0; x < end; x++)
    {
        if (url[x] == sep)
        {
            char *value = calloc(256, sizeof(char));
            strcpy(value, url + x);
            return value;
        }
    }
    return NULL;
}

/*
    Get tedge c8y proxy
*/
char * tedge_get_c8y_proxy_url(char *mqtt_host, char *url)
{
    char *path = tedge_get_url_path(url);
    char *output = replace_prefix(mqtt_host, "://", "http://");
    strcat(output, ":8001/c8y");

    if (path != NULL)
    {
        strcat(output, path);
    }
    return output;
}
