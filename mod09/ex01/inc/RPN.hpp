#ifndef RPN_H
# define RPN_H

# include <iostream>
# include <stack>
# include <list>

class RPN {
private:
	std::stack<int, std::list<int> >	st;
	int									err;
	static const char					calcFuncSymbols[5];

	int 	add(void);
	int 	sub(void);
	int 	mul(void);
	int 	div(void);
	int		calc(char c);
	bool	isOp(char c);
	int		numOp(char c);
public:
	// Constructors and Destructors
	RPN(void);
	RPN(const RPN &other);
	~RPN(void);

	// Operators
	RPN &operator=(const RPN &other);

	// Methods
	int	calculate(const char *);
	bool fail() const;
};

#endif
