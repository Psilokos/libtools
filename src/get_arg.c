/*
** get_arg.c for tools in /home/lecouv/rendu/philosophe
** 
** Made by Victorien LE COUVIOUR--TUFFET
** Login   <lecouv@epitech.eu>
** 
** Started on  Sat Mar  5 17:16:38 2016 Victorien LE COUVIOUR--TUFFET
** Last update Wed Apr  6 05:06:33 2016 Victorien LE COUVIOUR--TUFFET
*/

#include <string.h>
#include "tools.h"

char	*get_arg(char *argv[], char *arg)
{
  int	pos;

  return (((pos = get_arg_pos(argv, arg)) ^ -0x1) ? (argv[pos]) : (0x0));
}

int	get_arg_pos(char *argv[], char *arg)
{
  int	i;

  i = 0;
  while (argv[i] && strcmp(argv[i], arg))
    ++i;
  return ((argv[i]) ? (i) : (-1));
}

char	**get_arg_addr(char *argv[], char *arg)
{
  int	pos;

  return (((pos = get_arg_pos(argv, arg)) ^ -0x1) ? (argv + pos) : (0x0));
}
