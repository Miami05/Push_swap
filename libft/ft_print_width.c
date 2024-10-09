/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_width.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ledio <ledio@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 17:29:38 by ldurmish          #+#    #+#             */
/*   Updated: 2024/10/07 23:09:36 by ledio            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_get_width(t_print *print, const char *str, int pos)
{
	int	res;

	res = 0;
	while (ft_isdigit(str[pos]) && !ft_strchr(".cspdiuoxX%", str[pos]))
	{
		res = res * 10 + str[pos] - '0';
		pos++;
	}
	print->width = res;
	return (--pos);
}

int	ft_get_precision(t_print *print, const char *str, int pos)
{
	int	res;

	res = 0;
	while (ft_isdigit(str[pos]) && !ft_strchr("cspdiuoxX%", str[pos]))
	{
		res = res * 10 + str[pos] - '0';
		pos++;
	}
	print->precision = res;
	return (--pos);
}
