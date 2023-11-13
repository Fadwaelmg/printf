#include "main.h"

/**
 * _printf - Custom implementation of a simplified printf function.
 * @format: Format string specifying the output format.
 * Supported format specifiers: %c(character), %s (string) and %
* @...: Variable number of argument corresponding to the format specifiers.
* Return: Number of characters written to the standard output.
*/
int _printf(const char *format, ...)
{
va_list args_list;
int format_length;
int char_count;
int i;
va_start(args_list, format);
format_length = strlen(format);
char_count = format_length;
for (i = 0; i < format_length; i++)
{
if (format[i] == '%')
{
i++;
if (format[i] == 'c')
{
char c = (char)va_arg(args_list, int);
write(1, &c, 1);
char_count--;
}
else if (format[i] == 's')
{
char *str = va_arg(args_list, char*);
write(1, str, strlen(str));
char_count -= strlen(str);
}
else if (format[i] == '%')
{
char percent='%';
write(1,&percent, 1);
char_count--;
}
else
{
write(1, &format[i], 1);
}
}
}
va_end(args_list);
return (char_count);
}

