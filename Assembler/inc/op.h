/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   op.h											   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: immn <immn@student.42.fr>				  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2013/10/04 11:33:27 by zaz			   #+#	#+#			 */
/*   Updated: 2020/02/04 13:05:17 by immn			 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

/*
** Toutes les tailles sont en octets.
** On part du principe qu'un int fait 32 bits. Est-ce vrai chez vous ?
*/

#ifndef OP_H
# define OP_H

#define IND_SIZE				2
#define REG_SIZE				4
#define DIR_SIZE				REG_SIZE


# define REG_CODE				1
# define DIR_CODE				2
# define IND_CODE				3


#define MAX_ARGS_NUMBER			4
#define MAX_PLAYERS				4
#define MEM_SIZE				(4*1024)
#define IDX_MOD					(MEM_SIZE / 8)
#define CHAMP_MAX_SIZE			(MEM_SIZE / 6)

#define COMMENT_CHAR			'#'
#define LABEL_CHAR				':'
#define DIRECT_CHAR				'%'
#define SEPARATOR_CHAR			','
#define ALT_COMMENT_CHAR		';'

#define LABEL_CHARS				"abcdefghijklmnopqrstuvwxyz_0123456789"

#define NAME_CMD_STRING			".name"
#define COMMENT_CMD_STRING		".comment"

#define REG_NUMBER				16

#define CYCLE_TO_DIE			1536
#define CYCLE_DELTA				50
#define NBR_LIVE				21
#define MAX_CHECKS				10

#define NUMBER_OF_COMMAND		17

/*
**
*/

typedef char	t_arg_type;

#define T_REG					1
#define T_DIR					2
#define T_IND					4
#define T_LAB					8

/*
**
*/

# define PROG_NAME_LENGTH		(128)
# define COMMENT_LENGTH			(2048)
# define COREWAR_EXEC_MAGIC		0xea83f3//from subj
# define IIOOOOOO				192
# define OOIIOOOO				48
# define OOOOIIOO				12

// typedef struct		s_header
// {
//   unsigned int		magic;
//   char				prog_name[PROG_NAME_LENGTH + 1];
//   unsigned int		prog_size;
//   char				comment[COMMENT_LENGTH + 1];
// }					t_header;

typedef struct		s_op
{
	unsigned char	cmd[6];
	unsigned char	arg_q;			  //rename args_quantity
	unsigned char	arg_type[3];
	unsigned char	opcode;
	unsigned int	cycles;
	unsigned char	descrip[37];
	unsigned char	a_typecode;
	unsigned char	dir_size;
}					t_op;

extern t_op				g_op_tab[17];

#endif
