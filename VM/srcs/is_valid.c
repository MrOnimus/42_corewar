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

void convert_field(char *field)
{
    size_t  len;
    size_t  i;
    char    *buff;
    char    *c;

    len = ft_strlen(field);
    i = 0;
    if (!(buff = ft_memalloc(len / 2)))
        return ;
    while (i < len) {
        c = ft_strsub(field, i, 2);
        buff[i/2] = (char)ft_atoi_base(c, 16);
        ft_strdel(c);
        i += 2;
    }
    return(buff);
}

void read_strfield(int fd, char *strfield, size_t size)
{
	char *buff;

	if (!(buff = malloc(size)))
		put_error(3);
	read(fd, buff, size);
	strfield = buff;
    printf("%s\n", strfield);
    ft_strdel(buff);
    printf("%s\n", strfield);
}

void read_null(int fd)
{
	char *buff;

	if (!(buff = malloc(4)))
		put_error(3);
	read(fd, buff, 4);
	if (!(ft_strempty(buff)))
		put_error(10);
}

void read_intfield(inf fd, int *intfield, size_t size)
{
	char *buff;

	if (!(buff = malloc(size)))
		put_error(3);
	read(fd, buff, size);
    if (ft_strisnumeric(buff))
	    *intfield = ft_atoi(convert_field(buff));
    ft_strdel(buff);
}

void read_champs(t_champion *champ, char *filename)
{
	int fd;
//	t_header header;


	if (!(fd = open(filename, O_RDONLY)))				//open player file
		put_error(9);

    read_intfield(fd, &(unsigned int)champ->magic, 4);
	/*if (!(buff = malloc(4)))							//check magic header
		put_error(3);
	read(fd, buff, 4);
    if (ft_strisnumeric(buff))
	    champ->magic = ft_atoi(convert_field(buff));
    ft_strdel(buff);*/

    read_strfield(fd, champ->name, PROG_NAME_LENGTH);
	/*if (!(buff = malloc(PROG_NAME_LENGTH)))			//check name
		put_error(3);
	read(fd, buff, PROG_NAME_LENGTH);
	champ->name = buff;*/

    read_null(fd);
	/*read(fd, buff, 4);								//check NULL
	if (!(ft_strempty(buff)))
		put_error(10);*/

    read_intfield(fd, &(champ->code_range), 4)
	/*read(fd, buff, 4);								//check code_range
	champ->code_range = ft_strisnumeric(buff);			//это не точно!!*/

    read_strfield(fd, champ->comment, COMMENT_LENGTH)
	/*if (!(comment = malloc(COMMENT_LENGTH)))			//check comment
		put_error(3);
	read(fd, comment, COMMENT_LENGTH);
	champ->comment = comment;*/

    read_null(fd);
	/*read(fd, buff, 4);								//check NULL
	if (buff != NULL)
		put_error(10);*/

    read_strfield(fd, champ->code, CHAMP_MAX_SIZE)      // TODO: Maybe we should read not the MAX_SIZE, but the champ->code_range
	/*if (!(code = malloc(CHAMP_MAX_SIZE)))				//check code
		put_error(3);
	read(fd, code, CHAMP_MAX_SIZE);
	champ->code = code;*/
}
