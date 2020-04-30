#include <iostream>
#include <vector>
#include <limits>
#include <string.h>
//define for
#define For(i, a, b) for(int i = a; i < b; i++)
#define FOR(tmp, a, b) for(TY_CustomerList :: iterator tmp = a; tmp != b; tmp++)
//define type of customer
#define PERSIONAL_CUSTOMER	"CN"
#define COMPANY_CUSTOMER	"CT"
#define FOREIGNER_CUSTOMER	"NN"

using namespace std;
//declare structure infomation
typedef struct customer{
    char mName[100];
    char mProduct[100];
    char mCustype[3];
    __int16 mQuantity;
    double mPrice;
}TY_Customer;
typedef vector<TY_Customer> TY_CustomerList;
TY_CustomerList vList;

//Main funtion
int input_number_customer(void);
void input_info_customer(TY_CustomerList *vList, int n);
void display_list_customer(TY_CustomerList vList);
void sort_list_customer(TY_CustomerList *vList, int n);

//Other supporting funtion
void print_info_customer(TY_CustomerList :: iterator tmp);
double caculator(TY_CustomerList :: iterator tmp);
double get_discount(char *type_customer);

// input number of customer and check
int input_number_customer(void){
	cout << "Please input number of customer(>1): " ;
	int n;
	cin >> n;
		// check
		while(!cin || n < 0){
			cout << endl << "ERROR. Please input positive numeric data.";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cin >> n;
		}
	return n;
}
//input info of customer
void input_info_customer(TY_CustomerList *vList, int n){
	char select;
	if(!vList -> empty()){
		cout << "The list is not empty. Do you want to add more data ? (Y/N)";
		cin >> select;
		if(select == 'N' || select == 'n')
			return ;
	}

	TY_Customer tmp;
	For(i, 0, n){
		cout << "Please input info of customer #" << i+1;

		// name of customer
		cout << "\nInput the name of customer: ";
		cin >> tmp.mName;
		cout << "Customer name = " << tmp.mName << endl;

		// type of customer
		do{
			cout << "\nInput the type of customer(CN/CT/NN): ";
			cin >> tmp.mCustype;
		}while(strcmp(tmp.mCustype, "CN") != 0 && strcmp(tmp.mCustype, "CT") != 0 && strcmp(tmp.mCustype, "NN") != 0);
		cout << "Customer type: " << tmp.mCustype << endl;

		// name of product
		cout << "\nInput the product name: ";
		cin >> tmp.mProduct;
		cout << "Product name: " << tmp.mProduct << endl;

		// quantity of product
		cout << "\nInput the quantity of product(numeric): ";
		cin >> tmp.mQuantity;
		while(!cin || tmp.mQuantity < 0){
			cout << "ERROR. Please input number." ;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cin >> tmp.mQuantity;
		}
		cout << "Quantity of product: " << tmp.mQuantity << endl;

		// price of product
		cout << "\nInput the price of product(numeric): ";
		cin >> tmp.mPrice;
		while(!cin || tmp.mPrice < 0){
			cout << "ERROR.Please input number.";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cin >> tmp.mPrice;
		}
		cout << "Price of product: " << tmp.mPrice << endl;

		vList -> push_back(tmp);
	}
}
//output the list of customer in monitor
void display_list_customer(TY_CustomerList *vList){
	if(vList->empty()){
		cout << "NO RECORD\n";
		return ;
	}
	cout << "NAME\t" << "TYPE\t" << "PRODUCT\t" << "QUANTITY\t" << "PRICE\t" << "MONEY\n";
	cout <<"--------------------------------------------------------------------------";
	FOR(tmp, vList->begin(), vList->end())
		print_info_customer(tmp);
}
void print_info_customer(TY_CustomerList :: iterator tmp){
	cout << tmp -> mName << "\t" << tmp -> mCustype << "\t" << tmp -> mProduct << "\t" << tmp -> mQuantity << "\t" << tmp -> mPrice << "\t" << caculator(tmp);
}
double get_discount(char *type_customer){
	double discount;
	if(strcmp(type_customer, (const char*)PERSIONAL_CUSTOMER) == 0)
		return discount = 0.8;
	else if(strcmp(type_customer, (const char*)COMPANY_CUSTOMER) == 0)
		return discount = 0.9;
	else return discount = 1;
}
double caculator(TY_CustomerList :: iterator tmp){
	return tmp -> mQuantity * tmp -> mPrice * get_discount(tmp -> mCustype);
}
int main(){

}
