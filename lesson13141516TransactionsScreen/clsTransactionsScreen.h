#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsDepositScreen.h"
#include "clsWithdrawScreen.h"
#include "clsTotalBalancesScreen.h"

class clsTransactionsScreen : protected clsScreen
{
private:
	enum enTransactionsMenueOption{eDeposite = 1, eWithdraw = 2, eShowTotalBalance = 3, eShowMainMenue = 4};

	static short ReadTransactionsOption()
	{
		cout << setw(37) << left << "\n\t\t\t\t\tChoose what do you want to do ? 1 to 4?";
		short choice = clsInputValidate::ReadDblNumberBetween(1, 4, "Enter Number bewteen 1 to 4");
		return choice;
	}
	static void _ShowDepositeScreen()
	{
		clsDepositScreen::ShowDepositScreen();
	}
	static void _ShowWithDrawScreen()
	{
		clsWithdrawScreen::ShowWithDrawScreen();
	}
	static void _ShowTotalBalanceScreen()
	{
		clsTotalBalancesScreen::ShowTotalBalances();
	}
	static void _GoBackTransctionMenue()
	{
		cout << "\nPress any key to go back to transaction Meune ...",
			system("pause>0");
		ShowTransactionsMenue();
	}
	static void _PerformTransacionsMenue(enTransactionsMenueOption TransactionsMenueOption)
	{
		switch (TransactionsMenueOption)
		{
		case enTransactionsMenueOption::eDeposite:
		{
			system("cls");
			_ShowDepositeScreen();
			_GoBackTransctionMenue();
			break;
		}
		case enTransactionsMenueOption::eWithdraw:
		{
			system("cls");
			_ShowWithDrawScreen();
			_GoBackTransctionMenue();
			break;
		}
		case enTransactionsMenueOption::eShowTotalBalance:
		{
			system("cls");
			_ShowTotalBalanceScreen();
			_GoBackTransctionMenue();
			break;
		}
		case enTransactionsMenueOption::eShowMainMenue:
		{
			// do nothing here the main screen will handle it :-)
			//_GoBackTransctionMenue();
			
		}
		}

}










public:
	static void ShowTransactionsMenue()
	{
		system("cls");
		_DrawScreenHeader("\tTransaction Screen ");

		cout << setw(37) << left << "" << "\t=============================================\n";
		cout << setw(37) << left << "" << "\tTransaction Menue\n ";
		cout << setw(37) << left << "" << "\t=============================================\n";
		cout << setw(37) << left << "" << "\tDeposite Screen.\n";
		cout << setw(37) << left << "" << "\tWithDraw Screen.\n";
		cout << setw(37) << left << "" << "\tTotal Balance.\n";
		cout << setw(37) << left << "" << "\tMain Menue.\n";
		cout << setw(37) << left << "" << "\t==============================================";

		_PerformTransacionsMenue((enTransactionsMenueOption)ReadTransactionsOption());


	}

};

