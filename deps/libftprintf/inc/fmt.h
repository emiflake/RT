/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fmt.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/22 16:33:57 by nmartins       #+#    #+#                */
/*   Updated: 2019/07/05 16:16:00 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FMT_H
# define FMT_H

# include "writer.h"
# include "token.h"
# include "color.h"
# include "number.h"

typedef void		(*t_formatter)(
						t_writer *writer,
						t_token *token,
						va_list vlist);

void				fmt_putstr(t_writer *writer, t_token *token, va_list vlist);
void				fmt_putstrlit(
						t_writer *writer,
						t_token *token,
						va_list vlist);
void				fmt_putpercent(
						t_writer *writer,
						t_token *token,
						va_list vlist);
void				fmt_putnbr(t_writer *writer, t_token *token, va_list vlist);
void				fmt_putuns(t_writer *writer, t_token *token, va_list vlist);
void				fmt_putcolor(
						t_writer *writer,
						t_token *token,
						va_list vlist);
void				fmt_putptr(t_writer *writer, t_token *token, va_list vlist);
void				fmt_puthex(t_writer *writer, t_token *token, va_list vlist);
void				fmt_putoct(t_writer *writer, t_token *token, va_list vlist);
void				fmt_putchr(t_writer *writer, t_token *token, va_list vlist);
void				fmt_putflt(t_writer *writer, t_token *token, va_list vlist);
void				fmt_printmemory(
						t_writer *writer,
						t_token *token,
						va_list vlist);

void				intern_fmt_puthex(
						t_writer *writer,
						unsigned long long value,
						int caps);
void				intern_fmt_pad(t_writer *writer, char c, int amt);
char				intern_to_hex(char num, int caps);
void				intern_pop_wildcards(t_token *token, va_list vlist);
void				intern_fmt_pad_auto(
						t_writer *writer,
						char c,
						int pad_amount,
						int length);
void				intern_fmt_pad_left(
						t_writer *writer,
						t_token *token,
						char c,
						int length);
void				intern_fmt_pad_right(
						t_writer *writer,
						t_token *token,
						char c,
						int length);
int					intern_hex_size(long long n);
void				intern_fmt_color(t_writer *writer, t_color color);
size_t				intern_ntoa(char *buf_out, t_number number, int caps);
char				intern_pad_char(t_flags flags);
unsigned long long	intern_abs(long long source);

unsigned long long	intern_read_unsigned_int(t_size size, va_list vlist);
long long			intern_read_signed_int(t_size size, va_list vlist);
long double			intern_read_float(t_size size, va_list vlist);

char				*intern_sign_for(t_number *number);
void				intern_number_prefix(
						t_writer *writer,
						t_token *token,
						t_number n,
						size_t size);

#endif
