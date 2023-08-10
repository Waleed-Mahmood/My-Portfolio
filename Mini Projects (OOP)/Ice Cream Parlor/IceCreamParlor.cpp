//#include<iostream>
//using namespace std;
//
//class DessertItem {
//	char* name;
//	int _cost;
//	double dessertCost;
//	double dessertTax;
//	int taxRate;
//public:
//	DessertItem() {
//		name = 0;
//		dessertCost = 0;
//		dessertTax = 0;
//		taxRate = 0;
//	}
//	DessertItem(const char n[], double cost, double taxRt) {
//		name = new char[strlen(n) + 1];
//		strcpy_s(name, strlen(n) + 1, n);
//		taxRate = taxRt * 10;
//		_cost = (int)cost;	//round off to nearest rupee
//		dessertTax = _cost * (taxRate / 100);
//	}
//	 
//	int getCostWithoutTax() {
//		return _cost;
//	}
//	virtual double getCost() {
//		dessertCost = _cost - dessertTax;
//		return dessertCost;
//	}
//
//	
//	virtual double getTax() {
//		dessertTax = _cost * (taxRate / 100);
//		return _cost * (taxRate / 100);
//
//	}
//
//	void printDessertItem() {
//		cout << "Name: " << name << endl;
//		cout << "Tax Deducted: " << this->getTax() << endl;
//		cout << "Dessert Cost: " << this->getCost() << endl;
//
//	}
//
//	char* getDessertName() {
//		return name;
//	}
//
//	~DessertItem() {
//		delete[]name;
//	}
//
//
//};
//
//class Cookie :public DessertItem {
//	int no;
//	double ppDoz;
//	int cost;
//
//
//public:
//	Cookie(const char desName[], int n, double ppDz, double tax) :DessertItem(desName, ppDz, tax) {
//		no = n;
//		ppDoz = ppDz;
//		cost = (int)(ppDoz / (12 / no)) + (int)((tax * 10) / 100);
//
//	}
//
//	void printCookie() {
//		cout << "Dessert Name: " << DessertItem::getDessertName() << endl;
//		cout << "Total Coookies: " << no << "\t Cost After Tax Deduction: " << cost << endl;
//	}
//
//	~Cookie() {
//
//	}
//
//};
//
//class IceCream :virtual public DessertItem {
//	int cost;
//	char* flvName;
//public:
//	IceCream(const char dessName[], const char flvr[], double c, double tax) :DessertItem(dessName, c, tax) {
//		flvName = new char[strlen(dessName) + 1];
//		strcpy_s(flvName, strlen(dessName) + 1, dessName);
//		cost = c;
//	}
//
//	char* getFlavour() {
//		return flvName;
//	}
//	void printIceCream() {
//		cout << "FLavour: " << flvName << endl;
//		DessertItem::printDessertItem();
//	}
//
//
//	~IceCream() {
//		delete[] flvName;
//	}
//};
//
//class Sundae : public IceCream {
//	double topCost;
//	double cost;
//public:
//	Sundae(const char dessName[], const char flvr[], double c, double tCost, double tax) :IceCream(dessName, flvr, c + tCost, tax) {
//		topCost = tCost;
//	}
//	void printSundae() {
//		cout << "Dessert: Sundae" << "\tFlavour: " << IceCream::getFlavour() << "\t Cost With Topping + Tax Deduction: " << IceCream::getCost() << endl;
//	}
//};
//
//class Order {
//	int noOfItems;
//	DessertItem** itemList;
//	int currenNoOfItems;
//
//public:
//	Order() {
//		noOfItems = 0;
//		itemList = 0;
//		currenNoOfItems = 0;
//
//	}
//
//	Order(int cnt) {
//		noOfItems = cnt;
//		itemList = new DessertItem * [cnt];
//		currenNoOfItems = 0;
//	}
//
//	void OrderPrint() {
//		for (int i = 0; i < currenNoOfItems; i++) {
//			itemList[i]->printDessertItem();
//		}
//	}
//
//	double addTax() {
//		double t = 0;
//		for (int i = 0; i < currenNoOfItems; i++) {
//			t+=itemList[i]->getTax();
//		}
//		return t;
//	}
//
//	double addCOst() {
//		double t = 0;
//		for (int i = 0; i < currenNoOfItems; i++) {
//			t += itemList[i]->getCostWithoutTax();
//		}
//		return t;
//	}
//
//	void placeOrder() {
//		int userChoice;
//		int i = 0, itemCount = 0;
//		while (i < this->noOfItems)
//		{
//			cout << "1-Cookies\n2-IceCream\n3-Sundae\n";
//			cout << "Choose Item you want to add\n";
//			cin >> userChoice;
//			if (userChoice == 1)
//			{
//				int n = 0;
//				double p = 0, t = 0;
//				//take parameters from user needed for a Cookie
//				cout << "Enter No Of Cookies: ";
//				cin >> n;
//				cout << "Enter prize/dozen: ";
//				cin >> p;
//				cout << "Enter Tax Rate: ";
//				cin >> t;
//				itemList[itemCount++] = new Cookie("Cookies", n, p, t);
//				currenNoOfItems++;
//				//making base class pointer //point cookie object
//			}
//			else if (userChoice == 2)
//			{
//				char n[60];
//				double p = 0, t = 0;
//				//take parameters from user needed for an IceCream
//
//				cout << "Enter Flavour: ";
//				cin >> n;
//				cout << "Enter Prize: ";
//				cin >> p;
//				cout << "Enter Tax Rate: ";
//				cin >> t;
//				itemList[itemCount++] = new IceCream("IceCream", n, p, t);
//				currenNoOfItems++;
//				//making base class pointer //point IceCream object
//			}
//			else if (userChoice == 3)
//			{
//				//take parameters from user needed for a Sundae
//				char n[60];
//				double p = 0, t = 0, tc = 0;
//
//				cout << "Enter Flavour: ";
//				cin >> n;
//				cout << "Enter Prize: ";
//				cin >> p;
//				cout << "Enter Topping Prize: ";
//				cin >> tc;
//				cout << "Enter Tax Rate: ";
//				cin >> t;
//
//				itemList[itemCount++] = new Sundae("Sundae", n, p, tc, t);
//				currenNoOfItems++;
//				//making base class pointer //point Sundae object
//			}
//			i++;
//		}
//	}
//};
//
//void main() {
//	Cookie c1("cookie", 4, 399, 2.0);
//	c1.printCookie();
//	IceCream i1("IceCream", "Vanilla", 399, 2.0);
//	i1.printIceCream();
//
//	int totalOrders;
//	cout << "How many orders you want to place: ?";
//	cin >> totalOrders;
//	Order** ordersList = new Order * [totalOrders];
//	for (int i = 0; i < totalOrders; i++)
//	{
//		int itemsCount;
//		cout << "How many items you want: ?";
//		cin >> itemsCount;
//		ordersList[i] = new Order(itemsCount);
//		ordersList[i]->placeOrder();
//	}
//	//diplay all the orders here
//	for (int i = 0; i < totalOrders; i++) {
//		ordersList[i]->OrderPrint();
//	}
//	int TotalCost;
//	//Find totalCost (sum of costs of all items in list without tax) and print it.
//	for (int i = 0; i < totalOrders; i++) {
//		cout<< "Total Cost: "<<ordersList[i]->addCOst()<<endl;
//	}
//	int TotalTax;
//	//Find totalCost (sum of taxes of all items in list) and print it.
//	for (int i = 0; i < totalOrders; i++) {
//		cout << "Total Tax: "<<ordersList[i]->addTax() << endl;
//	}
//	//delete the dynamially allocated memory.
//	for (int i = 0; i < totalOrders; i++) {
//		delete ordersList[i];
//	}
//}