/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouchra <ybouchra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 07:40:45 by ybouchra          #+#    #+#             */
/*   Updated: 2023/12/21 11:50:14 by ybouchra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void ft_puterr(char *str)
{
    while(*str)
        write(2, str++, 1);
    write(2,"\n",2);
    exit(1);
}

int is_exist(char *str, int c)
{
    int i;
    
    i = 0;
    if(!str || !str[0])
        return(0);
    while(str[i])
    {
        if(str[i] == c)
            return(1);
        i++;
    }
    return(0);
}

void print_map(char **map)
{
    int i = 0;
    if(!map || !map[0])
        ft_puterr("Error: Empty Map !!");
    else
    {
        while(map[i])
        printf("%s\n", map[i++]);
    }
}

int nbr_item(char *s, char c)
{
    int i;
    int cp;
    
    cp = 0;
    i = -1;
    if(!s)
        return 0;
    while(s[++i])
    {
        if(s[i] == c)
            cp++;
    }
    return(cp);
}

void ft_clearr(char **arr)
{
    int i;

    i = -1;
    if(arr || !arr[0])
        return;
    while(arr[++i])
        free(arr[i]);
    free(arr);
    arr = NULL;
}
