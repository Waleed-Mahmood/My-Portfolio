#include <iostream>
#include <fstream>
using namespace std;

//------------------------------------Global Template Function----------------------------------------
//Add here
 template<class Type>
 void growList2D(Type**& List, int& cap) {
	Type** temp = new Type * [cap + 1];
	for (int i = 0; i < cap; i++) {
		temp[i] = List[i];
	}
	delete[]List;
	List = temp;
	temp = NULL;
}



//-----------------------------------------Name----------------------------------------------------------
class Name {
	char* fname;
	char* lname;
public:
	Name() {
		fname = 0; lname = 0;
	}
	Name(char* fname, char* lname) {
		this->fname = new char[strlen(fname) + 1];
		this->lname = new char[strlen(lname) + 1];
		strcpy_s(this->fname, strlen(fname) + 1, fname);
		strcpy_s(this->lname, strlen(lname) + 1, lname);
	}
	~Name() {
		if (fname != nullptr)
			delete[] fname;
		if (lname != nullptr)
			delete[] lname;
	}

	Name(const Name& n) {
		this->fname = new char[strlen(n.fname) + 1];
		this->lname = new char[strlen(n.lname) + 1];
		strcpy_s(this->fname, strlen(n.fname) + 1, n.fname);
		strcpy_s(this->lname, strlen(n.lname) + 1, n.lname);


		
	}
	void printInfo() {
		cout << fname << "\t" << lname;
	}

	friend ostream& operator<<(ostream& out, const Name& n);
};

ostream& operator<<(ostream& out, const Name& n) {
	out << n.fname << " " << n.lname;
	return out;
}

//-----------------------------------------Player----------------------------------------------------------

class Player :public Name{
	int id;
	Name  pname;
	char* contact;
	int balance;
	static int count;
public:
	Player() {
		id = 0;
		contact = 0;
		balance = 0;
		count++;
	}

	Player(char* fn,char* ln,char* cont,int bal):Name(fn,ln) {
		contact = new char[strlen(cont) + 1];
		strcpy_s(contact, strlen(cont) + 1, cont);
		balance = bal;
		count++;
		id = count;
	}

	void printPlayerInfo() {
		cout << "Your Details are: " << endl << "Player ID: " << id;
		cout << "Player Name: ";
		Name::printInfo();
		cout << endl << "Player Balance: " << balance << endl << "Player Number: " << contact << endl;
	}

	int getPlayerBalance() {
		return balance;
	}
	int getPlayerID() {
		return id;
	}
	~Player() {
		if (contact != nullptr)
			delete[]contact;
	}

	

	//Add all required functions.
	friend ostream& operator<<(ostream& out, const Player& p);
};
int Player::count = 0;
//ostream& operator<<(ostream& out, const Player& p) {
//}

//--------------------------
	//---------------------------------------------------------------------------------//

//Add all required classes with complete Implementaion here.

class PS {
private:
	int psID;
	int maxcontrollers;
	int* listOfCnt;
	bool vacancy;
public:
	PS() {
		psID = 0; maxcontrollers = 0; listOfCnt = 0; 
	}
	PS(int id, int cn) {
		psID = id;
		maxcontrollers = cn;
		listOfCnt = new int[maxcontrollers];
		for (int i = 0; i < maxcontrollers; i++) {
			listOfCnt[i] = 0;
		}
		vacancy = true;
	}
	void assign(int plyId) {
		for (int i = 0; i < maxcontrollers; i++) {
			if (listOfCnt[i] != 0) {
				listOfCnt[i] = plyId;
				cout << "Controller Number Assigned: " << i << endl;
			}
		}
	}
	bool getVac() {
		return vacancy;
	}
	int getPsID() {
		return psID;
	}
	


};

class PC {
	int pcID;
public:
	PC() {
		pcID = 0;
	}

	PC(int id) {
		pcID = id;
	}



};



//-----------------------------------------GamingZone----------------------------------------------------------

class GamingZone {
	//Add all required functions and data members.
	PC** listOfPC; //association
	int currentNoOfPC;
	int maxPC;
	PS** listOfPS; //association
	int currentNoOfPS;
	int maxPS;
	Player** listOfPlayers;	//association
	int currentNoOfPlayers;
	int maxPlayers;

public:
	GamingZone() {
		listOfPC=0; //association
		currentNoOfPC=0;
		maxPC = 0;
		listOfPS = 0;//association
		currentNoOfPS=0;
		maxPS = 0;
		listOfPlayers=0;	//association
		currentNoOfPlayers=0;
		maxPlayers=0;
	}

	GamingZone(int mP, int mPC, int mPS) {
		maxPlayers = mP;
		currentNoOfPlayers = 0;
		maxPC = mPC;
		currentNoOfPC = 0;
		maxPS = mPS;
		currentNoOfPS = 0;

		listOfPlayers = new Player * [mP];
		listOfPC = new PC * [maxPC];
		listOfPS = new PS * [maxPS];

	}

	void signUp(char* fn, char*ln,char*cont,int bal) {
		
		if (currentNoOfPlayers == maxPlayers) {
			cout<<"Max PLayer Limit Reached! :(	Incresing Limit by 1" << endl;
			growList2D(listOfPlayers, maxPlayers);
		}
		listOfPlayers[currentNoOfPlayers++] = new Player(fn, ln,cont, bal);
			cout << "PLayer Successfully Registered :)" << endl;
	}

	int getPlayerWithId(int id) {
		for (int i = 0; i < currentNoOfPlayers; i++) {
			if (id == listOfPlayers[i]->getPlayerID()) {
				return i;
			}
		}
	}

	void playOnPS(int id) {
		for (int i = 0; i < currentNoOfPS; i++) {
			if (listOfPS[i]->getVac() == true) {
				cout << "PS Number: " << listOfPS[i]->getPsID() << endl;
				listOfPS[i]->assign(id);
			}
		}
	
	}
	void addPS(int id, int c) {
		if (currentNoOfPS == maxPS) {
			cout << "Max Limit Reached :( Increasing Limit By 1 " << endl;
			growList2D(listOfPS, maxPS);
		}
		listOfPS[currentNoOfPS++] = new PS(id, c);
		cout << "PS Successfully Added :)" << endl;
	}

	void addPC(int id) {
		if (currentNoOfPC == maxPC) {
			cout << "Max Limit Reached :( Increasing Limit By 1 " << endl;
			growList2D(listOfPC, maxPC);
		}
		listOfPC[currentNoOfPC++] = new PC(id);
		cout << "PC Successfully Added :)" << endl;
	}
	void loadPlayers() {
		ifstream PlyFile("Player.txt");
		int count=0, id=0,  bal=0,i=0;
		char fn[50], ln[50],cont[50];

		PlyFile >> count;
		while (PlyFile>>id>>fn>>ln>>cont>>bal) {
			if (i == count) {
				break;
			}
			signUp(fn,ln,cont,bal);
				i++;
		}
		PlyFile.close();
	}

	void loadPlatforms() {

		ifstream PltForm("Platforms.txt");
		int c1 = 0, c2 = 0, i = 1;
		int id1, id2, cnt;
		id1 = id2 = cnt = 0;
		PltForm >> c1;
		cout << c1 << endl;
		while (PltForm >> id1) {
						
		}

		PltForm >> c2;
		cout << c2 << endl;
		i = 1;
		
		while (PltForm >> id2 >> cnt) {
			addPS(id2, cnt);
		}
		
		PltForm.close();
	}
	void run() {
		while (true) {
			system("cls");
			int option;
			cout << "What do you want to do?\n\t1. Register new player\n\t2. Login\n\t3. Press Any key to Exit \n\nEnter your choice: ";
			cin >> option;
			if (option == 1) // 1. Register new player
			{  
				char fn[50], ln[50], cn[50];
				int bal = 0;
				cin >> fn >> ln >> cn >> bal;
				signUp(fn,ln,cn,bal);
				system("PAUSE");
			}
			else if (option == 2)	// 2. Login
			{
				int id;
				cout << "Enter Your User Id:";
				cin >> id;
				if (getPlayerWithId(id) != 0) { //Search player in list and return its address if exist.
					cout << "What do you want to do?\n\t1. Play a PS game\n\t2. Play a PC game\n\t3. Press Any key to Exit\n\nEnter your choice: ";
					cin >> option;
					if (option == 1) // 1. Play a PS game
						playOnPS(id);
					//else if (option == 2)	// 2. Play a PC game
					//	/*playonPC(id);*/
					else  //3. Exit
						return;
				}
			}
			else //3. Exit
				return;
		}
	}

};

//-----------------------------------------Driver----------------------------------------------------------
int main() {
	GamingZone zone(100,50, 20);//max player, maxPS,maxPC
	zone.loadPlayers();
	zone.loadPlatforms();
	zone.run();
	return 0;
}