/*
** init.c for tools in /home/lecouv_v/rendu/PSU_2015_myirc
**
** Made by Victorien LE COUVIOUR--TUFFET
** Login   <lecouv_v@epitech.net>
**
** Started on  Thu May 19 00:38:05 2016 Victorien LE COUVIOUR--TUFFET
** Last update Sat Jul  9 14:50:52 2016 Victorien LE COUVIOUR--TUFFET
*/

#include <errno.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "tools.h"

char	*g_bin_name;
FILE	*g_log_fileptr;

int		init_tools(char *bin_name)
{
  char		log_file[PATH_MAX];
  time_t const	tm = time(NULL);
  char		*const time_str = ctime(&tm);
  char		*tmp;

  errno = 0;
  if ((tmp = strrchr(bin_name, '/')))
    g_bin_name = tmp + 1;
  else
    g_bin_name = bin_name;
  strcpy(log_file, "/tmp/");
  strcat(log_file, g_bin_name);
  strcat(log_file, ".log");
  if (!(g_log_fileptr = fopen(log_file, "a")))
    return (print_errno("cannot open log file"));
  time_str[strlen(time_str) - 1] = 0;
  fprintf(g_log_fileptr, "%s: starting new log.\n", time_str);
  return (EXIT_SUCCESS);
}
