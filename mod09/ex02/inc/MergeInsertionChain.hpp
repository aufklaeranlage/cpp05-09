#ifndef MERGEINSERTIONCHAIN_HPP
# define MERGEINSERTIONCHAIN_HPP

template <typename Value>
class	MergeInsertionChain {
private:
	Value	*_value;
	MergeInsertionChain	*_main;
	MergeInsertionChain	*_pend;

public:
	typedef class	less {
	public:
		bool	operator()(const MergeInsertionChain<Value> &a, const MergeInsertionChain<Value> &b) {
			return (*a.value() < *b.value());
		}
	}	less;

	MergeInsertionChain(void): _value(NULL), _main(NULL), _pend(NULL) {};
	MergeInsertionChain(Value *v): _value(v), _main(NULL), _pend(NULL) {};
	MergeInsertionChain(MergeInsertionChain *main, MergeInsertionChain *pend): _value(main->value()), _main(main), _pend(pend) {};
	MergeInsertionChain(const MergeInsertionChain<Value> &other) { *this = other; };
	~MergeInsertionChain(void) { };

	MergeInsertionChain<Value> &operator=(const MergeInsertionChain<Value> &other) {
		_value = other.value();
		_main = other.main();
		_pend = other.pend();
		return (*this);
	};

	/* ACCESS */
	Value			*value(void) const { return (_value); };
	MergeInsertionChain<Value>	*main(void) const { return (_main); };
	MergeInsertionChain<Value>	*pend(void) const { return (_pend); };

	void			setValue(Value *value) { _value = value; };
	void			setMain(MergeInsertionChain *main) { _main = main; _value = main->value(); };
	void			setPend(MergeInsertionChain *pend) { _pend = pend; };
};

#endif
