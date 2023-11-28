#ifndef STRSPL_H
#define STRSPL_H

char *split_string(const char *str, const char delim);
int find_next_delim(const char *str, const char delim);
char *get_next_token(const char delim);

#endif 
