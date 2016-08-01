/*
** log.c for tools in /home/lecouv_v/rendu/PSU_2015_myirc
** 
** Made by Victorien LE COUVIOUR--TUFFET
** Login   <lecouv_v@epitech.net>
** 
** Started on  Thu May 19 00:36:15 2016 Victorien LE COUVIOUR--TUFFET
** Last update Fri May 20 01:02:09 2016 Victorien LE COUVIOUR--TUFFET
*/

#include <errno.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "tools.h"
#include "tools_disp_fmt.h"

extern FILE	*g_log_fileptr;

static bool		g_is_done = true;
static enum e_logtype	g_last;

void		print_info(char *fmt, ...)
{
  va_list	ap[2];

  va_start(ap[0], fmt);
  va_copy(ap[1], ap[0]);
  if (g_is_done || g_last != INFO)
    {
      printf("%s[INFO]%s: ", DISP_BLUE, DISP_DEFAULT);
      fprintf(g_log_fileptr, "[INFO]: ");
    }
  vprintf(fmt, ap[0]);
  vfprintf(g_log_fileptr, fmt, ap[1]);
  fflush(stdout);
  fflush(g_log_fileptr);
  va_end(ap[0]);
  va_end(ap[1]);
  g_is_done = ((fmt[strlen(fmt) - 1] == '\n') ? (true) : (false));
  g_last = INFO;
}

void		print_warning(char *fmt, ...)
{
  va_list	ap[2];

  if (!g_is_done && g_last == INFO)
    {
      printf("KO\n");
      fprintf(g_log_fileptr, "KO\n");
      g_is_done = true;
    }
  va_start(ap[0], fmt);
  va_copy(ap[1], ap[0]);
  if (g_is_done || g_last != WARNING)
    {
      printf("%s[WARNING]%s: ", DISP_YELLOW, DISP_DEFAULT);
      fprintf(g_log_fileptr, "[WARNING]: ");
    }
  vprintf(fmt, ap[0]);
  vfprintf(g_log_fileptr, fmt, ap[1]);
  fflush(stdout);
  fflush(g_log_fileptr);
  va_end(ap[0]);
  va_end(ap[1]);
  g_is_done = ((fmt[strlen(fmt) - 1] == '\n') ? (true) : (false));
  g_last = WARNING;
}

int		print_error(char *fmt, ...)
{
  va_list	ap[2];

  if (!g_is_done && g_last == INFO)
    {
      printf("KO\n");
      fprintf(g_log_fileptr, "KO\n");
      g_is_done = true;
    }
  va_start(ap[0], fmt);
  va_copy(ap[1], ap[0]);
  if (g_is_done || g_last != ERROR)
    {
      dprintf(STDERR_FILENO, "%s[ERROR]%s: ", DISP_RED, DISP_DEFAULT);
      fprintf(g_log_fileptr, "[ERROR]: ");
    }
  vdprintf(STDERR_FILENO, fmt, ap[0]);
  vfprintf(g_log_fileptr, fmt, ap[1]);
  fflush(stdout);
  fflush(g_log_fileptr);
  va_end(ap[0]);
  va_end(ap[1]);
  g_is_done = ((fmt[strlen(fmt) - 1] == '\n') ? (true) : (false));
  g_last = ERROR;
  return (EXIT_FAILURE);
}

int	print_error_errno(char *fmt, ...)
{
  va_list	ap[2];

  if (!g_is_done && g_last == INFO)
    {
      printf("KO\n");
      fprintf(g_log_fileptr, "KO\n");
      g_is_done = true;
    }
  va_start(ap[0], fmt);
  va_copy(ap[1], ap[0]);
  if (g_is_done || g_last != ERROR)
    {
      dprintf(STDERR_FILENO, "%s[ERROR]%s: ", DISP_RED, DISP_DEFAULT);
      fprintf(g_log_fileptr, "[ERROR]: ");
    }
  g_last = ERROR;
  vdprintf(STDERR_FILENO, fmt, ap[0]);
  vfprintf(g_log_fileptr, fmt, ap[1]);
  g_is_done = false;
  print_error(": ");
  print_error(strerror(errno));
  print_error("\n");
  va_end(ap[0]);
  va_end(ap[1]);
  g_is_done = true;
  return (EXIT_FAILURE);
}
