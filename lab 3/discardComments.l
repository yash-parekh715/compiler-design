%optionyywrap
%{
#include <stdio.h>

int char_count = 0, word_count = 0, line_count = 0;
FILE *output_file;
%}

%%
"<!--".*"-->"                  { /* Discard block comments */ }
"//".*                         { /* Discard single-line comments */ }
"<"[a-zA-Z][^>]*">"            { fprintf(output_file, "%s\n", yytext); } // Store HTML tags

[^ \t\n<>]+                    { word_count++; char_count += yyleng; } // Count words and characters
\n                             { line_count++; char_count++; }
.                              { char_count++; } // Count other characters

%%

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <input.txt>\n", argv[0]);
        return 1;
    }

    FILE *input_file = fopen(argv[1], "r");
    if (!input_file) {
        printf("Error: Could not open input file.\n");
        return 1;
    }
    yyin = input_file;  // Set the input file for lex to read from

    output_file = fopen("output.txt", "w");
    if (!output_file) {
        printf("Error: Could not open output file.\n");
        fclose(input_file);
        return 1;
    }

    yylex();  // Start lexical analysis

    fclose(input_file);
    fclose(output_file);

    printf("Characters: %d\n", char_count);
    printf("Words: %d\n", word_count);
    printf("Lines: %d\n", line_count);

    return 0;
}