#ifndef SKYSCRAPERS_H
# define SKYSCRAPERS_H


/*Struct for the initial border values*/
typedef struct	s_initsquare{
	int	*b_border;
	int	*t_border;
	int *r_border;
	int *l_border;
}				t_initsquare;

/*Struct for the empty field to be filled with values*/
typedef struct	s_field{
	int *field;
}				t_field;

/*Struct for cells : coordinates for cell address and value that was put in*/
typedef struct	s_cell{
	int row;
	int col;
	int value;
}				t_cell;

/*Pseudo - stack for guesser (all guesses are stacked	*/
/*to be reverted in case of result being invalid)		*/
typedef struct	s_callstack{
	t_cell *stack;
	int error;
}				t_callstack;



/*generates initsquare from argv string*/
t_initsquare	*generate_initsquare(const char *st, int *size);

/*generates initial empty field*/
t_field			*generate_field(const int size);

#endif