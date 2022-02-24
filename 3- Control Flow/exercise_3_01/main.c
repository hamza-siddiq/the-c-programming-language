#include <stdio.h>
int string_length(char s[]);
int visible_escape_sequence(char s[], char t[]);
int main() {
    char s [] = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Nunc id purus diam."
               " Nunc hendrerit massa \"consequat pellentesque mattis. Proin pretium pellentesque"
               " dui, ac dapibus massa ullamcorper id. Phasellus dictum dui \\et laoreet fringilla."
               " Aliquam tincidunt tristique mollis. \t Vivamus mollis, odio nec sollicitudin efficitur,"
               " lorem nibh laoreet nibh,\' ac volutpat urna ipsum vel ipsum.\n  Sed egestas molestie lectus,"
               " quis mattis orci lobortis ac. Fusce eleifend imperdiet ante,\\ id tincidunt sem dictum eget."
               " Ut laoreet erat ac lacinia bibendum. Vestibulum lacinia velit sem, id vehicula leo varius at."
               "Vestibulum leo sem, ornare sit amet convallis at, fermentum molestie eros.";
    int length = string_length(s);

    char t[length*2];
    visible_escape_sequence(s, t);
    printf("%s", t);
}

int string_length(s)    /* Calculates the length of a string */
char s[];
{
    int i = 0;
    while(s[i++]!='\0');
    return i;
}

int visible_escape_sequence(s, t) /* Adds modified version, with a visible escape sequence, to a new string */
char s[];
char t[];
{
    int c;
    int i = 0;
    int j =0;
    while ((s[j] != EOF )) {
        switch (s[j]) {
            case '\n':
                t[i++] = '\\';
                t[i++] = 'n';
                break;
            case '\t':
                t[i++] = '\\';
                t[i++] = 't';
                break;
            case '\"':
                t[i++] = '\\';
                t[i++] = '\"';
                break;
            case '\'':
                t[i++] = '\\';
                t[i++] = '\'';
                break;
            case '\\':
                t[i++] = '\\';
                t[i++] = '\\';
                break;
            default:
                t[i++] = s[j];
        }
        j++;
    }
    t[i] ='\0';
    return 0;
}