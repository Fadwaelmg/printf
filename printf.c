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
va_start(args_list, format);
int format_length = strlen(format);
int char_count = 0;
for (int i = 0; i < format_length; i++)
{
if (format[i] == '%')
{
i++;
if (format[i] == 'c')
{
char c = (char)va_arg(args_list, int);
write(1, &c, 1);
char_count ++;
} 
else if (format[i] == 's')
{
char *str = va_arg(args_list, char *);
write(1, str, strlen(str));
char_count += strlen(str);
}
else if (format[i] == '%') 
{
write(1, "%", 1);
char_count++;
}
else if (format[i] == 'd' || format[i] == 'i')
{
int d = va_arg(args_list, int);
char str[100];
sprintf(str, "%d", d);
write(1, str, strlen(str));
char_count += strlen(str);
}
}
else 
{
write(1, &format[i], 1);
char_count++;
}
}
va_end(args_list);
return char_count;
}
