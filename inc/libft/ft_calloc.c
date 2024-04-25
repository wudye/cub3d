/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 16:18:59 by mwu               #+#    #+#             */
/*   Updated: 2023/09/19 14:17:07 by mwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	maxs;

	maxs = -1;
	if (size != 0 && nmemb > (maxs / size))
		return (NULL);
	ptr = (void *)malloc (nmemb * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, nmemb * size);
	return (ptr);
}
/*

int	main()
{
//	void *s1 =ft_calloc(18446744073709551610,1);
//	void *s3 =ft_calloc(9223372036854775807,1);
	void *s5 =ft_calloc(2147483648,1);
//	void *s7 =ft_calloc(4294967296,1);

//	void *s2 =calloc(18446744073709551610,1);
//	void *s4 =calloc(9223372036854775807,1);
	void *s6 =calloc(2147483648,1);
//	void *s8 =calloc(4294967296,1);
//printf("ft_calloc%p\n", s1);
//	printf("calloc%p\n", s2);
	
//	printf("ft_callocft_calloc  %p\n", s3);
	printf("calloc %p\n", s4);
//	printf("%p\n", s5);
//	printf("calloc %p\n", s6);
//	printf("ft_calloc %p\n", s7);
//	printf("calloc %p\n", s8);
	
	
}
*/
