/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piotrwojnarowski <piotrwojnarowski@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 16:11:41 by piotrwojnar       #+#    #+#             */
/*   Updated: 2024/04/11 19:11:28 by piotrwojnar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int main() 
{
    int i = 0;
    int file = open("s.txt", 'r');
    if (file < 0) {
        printf("Failed to open the file.\n");
        return 1;
    }
    char* line;
    
    line = get_next_line(file);
    if (line) {
        printf("first line: %s\n", line);
    }
    while (line)
	{
		line = get_next_line(file);
		if (line[i++])
		{
			printf("next line: %c\n", line[i]);
		}
	}
    close(file);
    return 0;
}
