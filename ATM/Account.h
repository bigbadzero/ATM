

class Account
{
	
public:
	Account(int accountNumber)
	{
		this->AccoutNumber = accountNumber;
		Balance = 1000;
		LowBalance = false;
	}
	void DisplayBalance();
	void Withdraw(double withdrawelAmount);
	void Deposit(double depositAmount);
	double GetBalance();

private:
	int AccoutNumber;
	double Balance;
	bool LowBalance;
};

