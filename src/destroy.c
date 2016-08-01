/*
** destroy.c for tools in /home/lecouv_v/rendu/PSU_2015_myirc
** 
** Made by Victorien LE COUVIOUR--TUFFET
** Login   <lecouv_v@epitech.net>
** 
** Started on  Thu May 19 00:56:57 2016 Victorien LE COUVIOUR--TUFFET
** Last update Thu May 19 22:16:13 2016 Victorien LE COUVIOUR--TUFFET
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "tools.h"

extern FILE	*g_log_fileptr;

int		destroy_tools(void)
{
  time_t const	tm = time(NULL);
  char		*const time_str = ctime(&tm);

  time_str[strlen(time_str) - 1] = 0;
  fprintf(g_log_fileptr, "%s: end of log.\n\n", time_str);
  if (fclose(g_log_fileptr) == SYSERR)
    return (print_errno("cannot close log file"));
  return (EXIT_SUCCESS);
}
