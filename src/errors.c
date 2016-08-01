/*
** errors.c for tools in /home/lecouv/rendu/PSU_2015_nmobjdump/src/nm
** 
** Made by Victorien LE COUVIOUR--TUFFET
** Login   <lecouv@epitech.eu>
** 
** Started on  Thu Feb 25 12:10:37 2016 Victorien LE COUVIOUR--TUFFET
** Last update Thu May 19 00:39:10 2016 Victorien LE COUVIOUR--TUFFET
*/

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

extern char	*g_bin_name;

int	print_err(char *context, char *msg)
{
  if (context)
    dprintf(STDERR_FILENO, "%s: %s: %s\n", g_bin_name, context, msg);
  else
    dprintf(STDERR_FILENO, "%s: %s\n", g_bin_name, msg);
  return (EXIT_FAILURE);
}

int	print_errno(char *msg)
{
  dprintf(STDERR_FILENO, "%s: ", g_bin_name);
  fflush(stderr);
  perror(msg);
  return (EXIT_FAILURE);
}
