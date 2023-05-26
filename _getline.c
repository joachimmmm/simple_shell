#include "files.h"
ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
    static char buffer[BUFFER_SIZE];
    static size_t buffer_poss = 0;
    static size_t buffer_size = 0;
    char current_char;

    ssize_t bytes_read = 0;
    size_t total_bytes_read = 0;
    int line_complete = 0;
    
    if (*lineptr == NULL || *n == 0) {
        *n = BUFFER_SIZE;
        *lineptr = malloc(*n);
        if (*lineptr == NULL) {
            return -1;
        }
    }
    
    while (!line_complete)
    {
        if (buffer_poss >= buffer_size)
       	{
            bytes_read = read(fileno(stream), buffer, BUFFER_SIZE);
            if (bytes_read <= 0) {
                break;
        }
            buffer_poss = 0;
            buffer_size = bytes_read;
        }
        
        if (buffer_poss < buffer_size) {
            if (total_bytes_read >= *n - 1) 
	{
                size_t new_size = *n + BUFFER_SIZE;
                char *new_lineptr = realloc(*lineptr, new_size);
                if (new_lineptr == NULL) {
                    return -1;
                }
                *lineptr = new_lineptr;
                *n = new_size;
        }     
            current_char = buffer[buffer_poss++];
            (*lineptr)[total_bytes_read++] = current_char;
            
            if (current_char == '\n') {
                line_complete = 1;
            }
        }
    }
    
    if (total_bytes_read == 0 && bytes_read <= 0) {
        return -1; 
    }
    
    (*lineptr)[total_bytes_read] = '\0';
    
    return total_bytes_read;
}

