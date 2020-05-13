//
//  is_valid.c
//  NewCoreWar
//
//  Created by  Alex on 22/04/2020.
//  Copyright © 2020  Alex. All rights reserved.
//

#include "corewar.h"

int	is_filename(char *filemane, char *ext)
{
	if (ft_strstr(filemane, ext) != NULL) {
		return (1);
	}
	put_error(7);
	return (0);
}

void read_champs(t_champion *champ, char *filename)
{
	int fd;
//	t_header header;
	char *buff;
	char *str;
	char *comment;
	char *code;
	


	if (!(fd = open(filename, O_RDONLY)))				//open player file
		put_error(9);
	
	if (!(buff = malloc(4)))							//check magic header
		put_error(3);
	read(fd, buff, 4);
	champ->magic = ft_strisnumeric(buff);
	
	if (!(str = malloc(PROG_NAME_LENGTH)))				//check name
		put_error(3);
	read(fd, str, PROG_NAME_LENGTH);
	champ->name = str;
	
	read(fd, buff, 4);									//check NULL
	if (buff != NULL)
		put_error(10);
	
	read(fd, buff, 4);									//check code_size
	champ->code_range = ft_strisnumeric(buff);			//это не точно!!
	
	if (!(comment = malloc(COMMENT_LENGTH)))			//check comment
		put_error(3);
	read(fd, comment, COMMENT_LENGTH);
	champ->comment = comment;
	
	read(fd, buff, 4);									//check NULL
	if (buff != NULL)
		put_error(10);
	
	if (!(code = malloc(CHAMP_MAX_SIZE)))				//check code
		put_error(3);
	read(fd, code, CHAMP_MAX_SIZE);
	champ->code = code;
}
