/*
** tools_dico.h for tools in /home/lecouv_v/rendu/PSU_2015_myirc
**
** Made by Victorien LE COUVIOUR--TUFFET
** Login   <lecouv_v@epitech.eu>
**
** Started on  Tue May 31 14:45:29 2016 Victorien LE COUVIOUR--TUFFET
** Last update Tue May 31 17:09:36 2016 Victorien LE COUVIOUR--TUFFET
*/

#ifndef TOOLS_DICO_H_
# define TOOLS_DICO_H_

typedef struct	s_fdico
{
  char		*key;
  void		(*value)();
}		t_fdico;

#endif /* !TOOLS_DICO_H_ */
