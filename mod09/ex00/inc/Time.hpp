#ifndef TIME_H
# define TIME_H

# include <iostream>
# include <stdint.h>
# include <sstream>

struct Time {
public:
	static const short daysPerMonth[2][12];

	int32_t	year;
	int16_t	month;
	int16_t day;
	enum err {
		NOERR =0,
		EINVAL_Y,
		EINVAL_M,
		EINVAL_D,
		ERANGE_M,
		ERANGE_D,
	} err;

	// Constructors and Destructors
	Time(void);
	Time(const Time &other);
	~Time(void);

	// Operators
	Time &operator=(const Time &other);

	// Methods
	bool 		set(std::stringstream &stream);
	bool		set(int64_t n);
	int64_t		toInt64(void) const;
};

std::ostream &operator<<(std::ostream &out, const Time &t);

#endif
