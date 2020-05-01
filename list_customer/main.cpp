#include <iostream>
#include <vector>
#include <limits>
#include <string.h>
#include <algorithm>
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
    string mName;
    string mProduct;
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
void sort_list_customer(TY_CustomerList *vList);

//Other supporting funtion
void print_info_customer(TY_CustomerList :: iterator tmp);
double caculator(TY_CustomerList :: iterator tmp);
double get_discount(char *type_customer);
void menu(void);
void delete_cache(){
	cin.clear();
	cin.ignore(numeric_limits<streamsize> :: max(), '\n');
}
// input number of customer and check
int input_number_customer(void){
	cout << "\n\tPlease input number of customer(>1): " ;
	int n;
	cin >> n;
		// check
		while(!cin || n < 0){
			cout << endl << "ERROR. Please input positive numeric data.";
			delete_cache();
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
		cout << "\n\tPlease input info of customer #" << i+1;

		// name of customer
		cout << "\n\t\tInput the name of customer: ";
		delete_cache();
		getline(cin, tmp.mName);
		cout << "\t\tCustomer name = " << tmp.mName << endl;

		// type of customer
		do{
			cout << "\n\t\tInput the type of customer(CN/CT/NN): ";
			//delete_cache();
			cin >> tmp.mCustype;
		}while(strcmp(tmp.mCustype, "CN") != 0 && strcmp(tmp.mCustype, "CT") != 0 && strcmp(tmp.mCustype, "NN") != 0);
		cout << "\t\tCustomer type: " << tmp.mCustype << endl;

		// name of product
		cout << "\n\t\tInput the product name: ";
		delete_cache();
		getline(cin, tmp.mProduct);
		cout << "\t\tProduct name: " << tmp.mProduct << endl;

		// quantity of product
		cout << "\n\t\tInput the quantity of product(numeric): ";
		cin >> tmp.mQuantity;
		while(!cin || tmp.mQuantity < 0){
			cout << "ERROR. Please input number." ;
			delete_cache();
			cin >> tmp.mQuantity;
		}
		cout << "\t\tQuantity of product: " << tmp.mQuantity << endl;

		// price of product
		cout << "\n\t\tInput the price of product(numeric): ";
		cin >> tmp.mPrice;
		while(!cin || tmp.mPrice < 0){
			cout << "ERROR.Please input number.";
			delete_cache();
			cin >> tmp.mPrice;
		}
		cout << "\t\tPrice of product: " << tmp.mPrice << endl;

		vList -> push_back(tmp);
	}
}
//output the list of customer in monitor
void display_list_customer(TY_CustomerList vList){
	if(vList.empty()){
		cout << "NO RECORD\n";
		return ;
	}
	cout << "NAME\t\t" << "TYPE\t" << "PRODUCT\t" << "QUANTITY\t" << "PRICE\t" << "MONEY\n";
	cout <<"--------------------------------------------------------------------------";
	FOR(tmp, vList.begin(), vList.end())
		print_info_customer(tmp);
}
void print_info_customer(TY_CustomerList :: iterator tmp){
	cout << endl << tmp -> mName << "\t" << tmp -> mCustype << "\t" << tmp -> mProduct << "\t" << tmp -> mQuantity << "\t" << tmp -> mPrice << "\t" << caculator(tmp) << endl;
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
bool compare(TY_Customer tmp1, TY_Customer tmp2){
	return tmp1.mPrice > tmp2.mPrice;
}
void sort_list_customer(TY_CustomerList *vList){
	sort(vList -> begin(), vList -> end(), compare);
}

void menu(void){
	cout << "\n\tCUSTOMER MANAGEMENT\n";
	cout << "\t-----------------------\n";
	cout << "\t1. Input number of customer.\n";
	cout << "\t2. Input infomation of customer.\n";
	cout << "\t3. Sort the customer(due to Price).\n";
	cout << "\t4. Print the list of customer.\n";
	cout << "\t5. Exit.\n";
	cout << "\n\t\tYour select: ";
}
int main(){
	TY_CustomerList vList;
	static __int16 numberCustomer, select;
	while(1){
		menu();
		cin >> select;
		if(!cin || select < 0){
			delete_cache();
			cin >> select;
		}

		switch(select){

			case 1:
				numberCustomer = input_number_customer();
				break;
			case 2:
				input_info_customer(&vList, numberCustomer);
				break;
			case 3:
				sort_list_customer(&vList);
				break;
			case 4:
				display_list_customer(vList);
				break;
			case 5:
				vList.clear();
				exit(1);
				break;

			default:
				break;
		}
	}
	return 0;
}
