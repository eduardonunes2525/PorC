#ifndef C_TEMPLATES
#define C_TEMPLATES

void write_to_file_or_die(FILE* file, char* content);

void write_declares_variable(FILE* file, char* content, char* content01);


void write_declares_variable_with_comma(FILE* file, char* content);

void write_end_line(FILE* file);

void write_default_header(FILE* file);

void write_body_begin(FILE* file);

void write_body_end(FILE* file);

#endif