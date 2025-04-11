/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboufqir <iboufqir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 12:09:08 by iboufqir          #+#    #+#             */
/*   Updated: 2024/04/26 10:02:08 by iboufqir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *format, ...);
void	ft_putchr(const char c, int *count);
void	ft_putstr(const char *str, int *count);
void	ft_put_adr(void *p, int *count);
void	ft_putnbr(long nbr, int *count);
void	ft_hexanbr(unsigned int nbr, const char format, int *count);

#endif