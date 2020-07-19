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


#define MAX_arg_countBER			4
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

#define cmd_CMD_STRING			".cmd"
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

# define PROG_cmd_LENGTH		(128)
# define COMMENT_LENGTH			(2048)
# define COREWAR_EXEC_MAGIC		0xea83f3

// typedef struct		s_header
// {
//   unsigned int		magic;
//   char				prog_cmd[PROG_cmd_LENGTH + 1];
//   unsigned int		prog_size;
//   char				comment[COMMENT_LENGTH + 1];
// }					t_header;

typedef struct		s_op
{
	unsigned char	cmd[6];
	unsigned char	opcode;
	unsigned char	arg_count;
	int				a_typecode;
	unsigned char	arg_type[3];
	int				modify_carry;
	unsigned char	dir_size;
	unsigned int	cycles;
	void			(*function)(t_vm *, t_cursor *);
}					t_op;

//extern t_op				g_op_tab[17];


static t_op		g_op[16] = {
	{
		.cmd = "live",
		.opcode = 0x01,
		.arg_count = 1,
		.a_typecode = 0,
		.arg_type = {T_DIR, 0, 0},
		.modify_carry = 0,
		.dir_size = 4,
		.cycles = 10,
		.function = &op_live
	},
	{
		.cmd = "ld",
		.opcode = 0x02,
		.arg_count = 2,
		.a_typecode = 1,
		.arg_type = {T_DIR | T_IND, T_REG, 0},
		.modify_carry = 1,
		.dir_size = 4,
		.cycles = 5,
		.function = &op_ld
	},
	{
		.cmd = "st",
		.opcode = 0x03,
		.arg_count = 2,
		.a_typecode = 1,
		.arg_type = {T_REG, T_REG | T_IND, 0},
		.modify_carry = 0,
		.dir_size = 4,
		.cycles = 5,
		.function = &op_st
	},
	{
		.cmd = "add",
		.opcode = 0x04,
		.arg_count = 3,
		.a_typecode = 1,
		.arg_type = {T_REG, T_REG, T_REG},
		.modify_carry = 1,
		.dir_size = 4,
		.cycles = 10,
		.function = &op_add
	},
	{
		.cmd = "sub",
		.opcode = 0x05,
		.arg_count = 3,
		.a_typecode = 1,
		.arg_type = {T_REG, T_REG, T_REG},
		.modify_carry = 1,
		.dir_size = 4,
		.cycles = 10,
		.function = &op_sub
	},
	{
		.cmd = "and",
		.opcode = 0x06,
		.arg_count = 3,
		.a_typecode = 1,
		.arg_type = {T_REG | T_DIR | T_IND, T_REG | T_DIR | T_IND, T_REG},
		.modify_carry = 1,
		.dir_size = 4,
		.cycles = 6,
		.function = &op_and
	},
	{
		.cmd = "or",
		.opcode = 0x07,
		.arg_count = 3,
		.a_typecode = 1,
		.arg_type = {T_REG | T_DIR | T_IND, T_REG | T_DIR | T_IND, T_REG},
		.modify_carry = 1,
		.dir_size = 4,
		.cycles = 6,
		.function = &op_or
	},
	{
		.cmd = "xor",
		.opcode = 0x08,
		.arg_count = 3,
		.a_typecode = 1,
		.arg_type = {T_REG | T_DIR | T_IND, T_REG | T_DIR | T_IND, T_REG},
		.modify_carry = 1,
		.dir_size = 4,
		.cycles = 6,
		.function = &op_xor
	},
	{
		.cmd = "zjmp",
		.opcode = 0x09,
		.arg_count = 1,
		.a_typecode = 0,
		.arg_type = {T_DIR, 0, 0},
		.modify_carry = 0,
		.dir_size = 2,
		.cycles = 20,
		.function = &op_zjmp
	},
	{
		.cmd = "ldi",
		.opcode = 0x0A,
		.arg_count = 3,
		.a_typecode = 1,
		.arg_type = {T_REG | T_DIR | T_IND, T_REG | T_DIR, T_REG},
		.modify_carry = 0,
		.dir_size = 2,
		.cycles = 25,
		.function = &op_ldi
	},
	{
		.cmd = "sti",
		.opcode = 0x0B,
		.arg_count = 3,
		.a_typecode = 1,
		.arg_type = {T_REG, T_REG | T_DIR | T_IND, T_REG | T_DIR},
		.modify_carry = 0,
		.dir_size = 2,
		.cycles = 25,
		.function = &op_sti
	},
	{
		.cmd = "fork",
		.opcode = 0x0C,
		.arg_count = 1,
		.a_typecode = 0,
		.arg_type = {T_DIR, 0, 0},
		.modify_carry = 0,
		.dir_size = 2,
		.cycles = 800,
		.function = &op_fork
	},
	{
		.cmd = "lld",
		.opcode = 0x0D,
		.arg_count = 2,
		.a_typecode = 1,
		.arg_type = {T_DIR | T_IND, T_REG, 0},
		.modify_carry = 1,
		.dir_size = 4,
		.cycles = 10,
		.function = &op_lld
	},
	{
		.cmd = "lldi",
		.opcode = 0x0E,
		.arg_count = 3,
		.a_typecode = 1,
		.arg_type = {T_REG | T_DIR | T_IND, T_REG | T_DIR, T_REG},
		.modify_carry = 1,
		.dir_size = 2,
		.cycles = 50,
		.function = &op_lldi
	},
	{
		.cmd = "lfork",
		.opcode = 0x0F,
		.arg_count = 1,
		.a_typecode = 0,
		.arg_type = {T_DIR, 0, 0},
		.modify_carry = 0,
		.dir_size = 2,
		.cycles = 1000,
		.function = &op_lfork
	},
	{
		.cmd = "aff",
		.opcode = 0x10,
		.arg_count = 1,
		.a_typecode = 1,
		.arg_type = {T_REG, 0, 0},
		.modify_carry = 0,
		.dir_size = 4,
		.cycles = 2,
		.function = &op_aff
	}
};


#endif
