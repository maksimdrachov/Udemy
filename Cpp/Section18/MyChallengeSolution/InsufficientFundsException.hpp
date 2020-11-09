#ifndef INSUFFICIENTFUNDSEXCEPTION_HPP
#define INSUFFICIENTFUNDSEXCEPTION_HPP

class InsufficientFundsException
{
public:
    InsufficientFundsException() noexcept {};
    ~InsufficientFundsException() {};
    virtual const char* what() const noexcept {
		return "Insufficient Funds Exception";
	}
};

#endif // INSUFFICIENTFUNDSEXCEPTION_HPP
