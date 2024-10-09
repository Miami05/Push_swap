/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ledio <ledio@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 20:48:20 by ldurmish          #+#    #+#             */
/*   Updated: 2024/10/07 23:09:04 by ledio            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_init_print(t_print *print)
{
	print->dash = 0;
	print->zero = 0;
	print->point = 0;
	print->plus = 0;
	print->space = 0;
	print->hash = 0;
	print->width = 0;
	print->precision = 0;
	print->baselen = 0;
	print->specifier = 0;
	print->base = NULL;
	print->base_n = 0;
}
