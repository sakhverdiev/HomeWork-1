#include <iostream>
#include <string>
#include <list>
#include <algorithm>
using namespace std;

class Debtor {
	string _fullName;
	string _birthDay;
	string _phone;
	string _email;
	string _address;
	int _debt;

public:
	Debtor();
	Debtor(string fullName, string birthDay, string phone, string email, string address, int debt) :
		_fullName(fullName), _birthDay(birthDay), _phone(phone), _email(email), _address(address), _debt(debt) { }

	// Set
	void setName(string fullName) { _fullName = fullName; }
	void setBirthDay(string birthDay) { _birthDay = birthDay; }
	void setPhone(string phone) { _phone = phone; }
	void setEmail(string email) { _email = email; }
	void setAddress(string address) { _address = address; }
	void setDebt(int debt) { _debt = debt; }

	// Get
	string& getName() { return _fullName; }
	string& getBirthDay() { return _birthDay; }
	string& getPhone() { return _phone; }
	string& getEmail() { return _email; }
	string& getAddress() { return _address; }
	int getDebt() { return _debt; }


	void show() {
		string year;
		int age;
		year.resize(4);
		int index = 0;
		for (int i = _birthDay.size() - 4; i < _birthDay.size(); i++) year[index++] = _birthDay[i];
		age = 2023 - typecast_str(year);
		cout << "Surname : " << _fullName[_fullName.find(' ') + 1] << endl;
		cout << "Age : " << age << endl;
		cout << "Debt : " << _debt << endl;
	}

	friend ostream& operator<<(ostream& print, const Debtor& other) {
		cout << "Full Name : " << other._fullName << endl
			 << "Birth Day : " << other._birthDay << endl
			 << "Phone : " << other._phone << endl
			 << "Email : " << other._email << endl
			 << "Address : " << other._address << endl
			 << "Debt : " << other._debt << endl;

		return print;
	}

};

list<Debtor*> debtors = {
           new Debtor("Shirley T. Qualls", "March 30, 1932", "530-662-7732", "ShirleyTQualls@teleworm.us", "3565 Eagles Nest Drive Woodland, CA 95695", 2414),
           new Debtor("Danielle W. Grier", "October 18, 1953", "321-473-4178", "DanielleWGrier@rhyta.com", "1973 Stoneybrook Road Maitland, FL 32751", 3599),
           new Debtor("Connie W. Lemire", "June 18, 1963", "828-321-3751", "ConnieWLemire@rhyta.com", "2432 Hannah Street Andrews, NC 28901", 1219),
           new Debtor("Coy K. Adams", "March 1, 1976", "410-347-1307", "CoyKAdams@dayrep.com", "2411 Blue Spruce Lane Baltimore, MD 21202", 3784),
           new Debtor("Bernice J. Miles", "June 1, 1988", "912-307-6797", "BerniceJMiles@armyspy.com", "4971 Austin Avenue Savannah, GA 31401", 4060),
           new Debtor("Bob L. Zambrano", "February 28, 1990", "706-446-1649", "BobLZambrano@armyspy.com", "2031 Limer Street Augusta, GA 30901", 6628),
           new Debtor("Adam D. Bartlett", "May 6, 1950", "650-693-1758", "AdamDBartlett@rhyta.com", "2737 Rardin Drive San Jose, CA 95110", 5412),
           new Debtor("Pablo M. Skinner", "August 26, 1936", "630-391-2034", "PabloMSkinner@armyspy.com", "16 Fraggle Drive Hickory Hills, IL 60457", 11097),
           new Debtor("Dorothy J. Brown", "July 9, 1971", "270-456-3288", "DorothyJBrown@rhyta.com", "699 Harper Street Louisville, KY 40202", 7956),
           new Debtor("Larry A. Miracle", "May 22, 1998", "301-621-3318", "LarryAMiracle@jourrapide.com", "2940 Adams Avenue Columbia, MD 21044", 7150),
           new Debtor("Donna B. Maynard", "January 26, 1944", "520-297-0575", "DonnaBMaynard@teleworm.us", "4821 Elk Rd Little Tucson, AZ 85704", 2910),
           new Debtor("Jessica J. Stoops", "April 22, 1989", "360-366-8101", "JessicaJStoops@dayrep.com", "2527 Terra Street Custer, WA 98240", 11805),
           new Debtor("Audry M. Styles", "February 7, 1937", "978-773-4802", "AudryMStyles@jourrapide.com", "151 Christie Way Marlboro, MA 01752", 1001),
           new Debtor("Violet R. Anguiano", "November 4, 1958", "585-340-7888", "VioletRAnguiano@dayrep.com", "1460 Walt Nuzum Farm Road Rochester, NY 14620", 9128),
           new Debtor("Charles P. Segundo","October 21, 1970", "415-367-3341", "CharlesPSegundo@dayrep.com", "1824 Roosevelt Street Fremont, CA 94539", 5648),
           new Debtor("Paul H. Sturtz", "September 15, 1944", "336-376-1732", "PaulHSturtz@dayrep.com", "759 Havanna Street Saxapahaw, NC 27340", 10437),
           new Debtor("Doris B. King", "October 10, 1978", "205-231-8973", "DorisBKing@rhyta.com", "3172 Bedford Street Birmingham, AL 35203", 7230),
           new Debtor("Deanna J. Donofrio", "April 16, 1983", "952-842-7576", "DeannaJDonofrio@rhyta.com", "1972 Orchard Street Bloomington, MN 55437", 515),
           new Debtor("Martin S. Malinowski", "January 17, 1992", "765-599-3523", "MartinSMalinowski@dayrep.com", "3749 Capitol Avenue New Castle, IN 47362", 1816),
           new Debtor("Melissa R. Arner", "May 24, 1974", "530-508-7328", "MelissaRArner@armyspy.com", "922 Hill Croft Farm Road Sacramento, CA 95814", 5037),
           new Debtor("Kelly G. Hoffman", "September 22, 1969", "505-876-8935", "KellyGHoffman@armyspy.com", "4738 Chapmans Lane Grants, NM 87020", 7755),
           new Debtor("Doyle B. Short", "June 15, 1986", "989-221-4363", "DoyleBShort@teleworm.us", "124 Wood Street Saginaw, MI 48607", 11657),
           new Debtor("Lorrie R. Gilmore", "December 23, 1960", "724-306-7138", "LorrieRGilmore@teleworm.us", "74 Pine Street Pittsburgh, PA 15222", 9693),
           new Debtor("Lionel A. Cook", "April 16, 1972", "201-627-5962", "LionelACook@jourrapide.com", "29 Goldleaf Lane Red Bank, NJ 07701", 2712),
           new Debtor("Charlene C. Burke","January 18, 1990", "484-334-9729", "CharleneCBurke@armyspy.com", "4686 Renwick Drive Philadelphia, PA 19108", 4016),
           new Debtor("Tommy M. Patton", "June 30, 1981", "774-571-6481", "TommyMPatton@rhyta.com", "748 Rockford Road Westborough, MA 01581", 349),
           new Debtor("Kristin S. Bloomer", "June 16, 1944", "443-652-0734", "KristinSBloomer@dayrep.com", "15 Hewes Avenue Towson, MD 21204", 9824),
           new Debtor("Daniel K. James", "November 10, 1997", "801-407-4693", "DanielKJames@rhyta.com", "3052 Walton Street Salt Lake City, UT 84104", 8215),
           new Debtor("Paula D. Henry", "September 6, 1976", "618-378-5307", "PaulaDHenry@rhyta.com", "3575 Eagle Street Norris City, IL 62869", 5766),
           new Debtor("Donna C. Sandoval", "December 13, 1947", "540-186-792", "DonnaCSandoval@rhyta.com", "675 Jehovah Drive Martinsville, VA 24112", 8363),
           new Debtor("Robert T. Taylor", "August 17, 1932", "270-596-6442", "RobertTTaylor@armyspy.com", "2812 Rowes Lane Paducah, KY 42001", 7785),
           new Debtor("Donna W. Alamo", "December 9, 1948", "978-778-2533", "DonnaWAlamo@teleworm.us", "4367 Christie Way Marlboro, MA 01752", 10030),
           new Debtor("Amy R. Parmer", "May 19, 1995", "480-883-4934", "AmyRParmer@armyspy.com", "85 Elmwood Avenue Chandler, AZ 85249", 5347),
           new Debtor("Newton K. Evans", "October 8, 1986", "303-207-9084", "NewtonKEvans@rhyta.com", "3552 Columbia Road Greenwood Village, CO 80111", 9838),
           new Debtor("Kathleen C. Chaney", "January 5, 1949", "605-245-3513", "KathleenCChaney@rhyta.com", "316 Elsie Drive Fort Thompson, SD 57339", 1672),
           new Debtor("Manuel C. Johnson", "February 23, 1957", "606-247-2659", "ManuelCJohnson@jourrapide.com", "4146 May Street Sharpsburg, KY 40374", 9195),
           new Debtor("Carla A. Creagh", "November 21, 1988", "614-307-8974", "CarlaACreagh@dayrep.com", "3106 Bates Brothers Road Columbus, OH 43215", 11271),
           new Debtor("Norma M. New", "May 18, 1988", "857-492-8703", "NormaMNew@jourrapide.com", "965 Metz Lane Woburn, MA 01801", 9761),
           new Debtor("Roy D. Green", "January 27, 1983", "308-340-5981", "RoyDGreen@jourrapide.com", "401 Romrog Way Grand Island, NE 68801", 10771),
           new Debtor("Cristy J. Jensen", "November 2, 1935", "440-626-9550", "CristyJJensen@jourrapide.com", "2177 Harley Vincent Drive Cleveland, OH 44113", 5205),
           new Debtor("Nancy J. Fergerson", "June 10, 1993", "219-987-8498", "NancyJFergerson@dayrep.com", "3584 Jadewood Drive Demotte, IN 46310", 1276),
           new Debtor("Dave N. Rodriguez", "January 21, 1938", "214-540-2499", "DaveNRodriguez@rhyta.com", "1890 Poco Mas Drive Dallas, TX 75247", 9132),
           new Debtor("James E. Denning", "May 4, 1988", "504-289-8640", "JamesEDenning@jourrapide.com", "1444 Rose Avenue Metairie, LA 70001", 8176),
           new Debtor("Richard M. Thomas", "February 13, 1972", "510-735-3359", "RichardMThomas@jourrapide.com", "4454 Green Avenue Oakland, CA 94609", 7875),
           new Debtor("Lakisha R. Forrest", "December 1, 1973", "334-830-1181", "LakishaRForrest@armyspy.com", "3121 Quarry Drive Montgomery, AL 36117", 3088),
           new Debtor("Pamela H. Beauchamp", "November 20, 1959", "801-559-6347", "PamelaHBeauchamp@jourrapide.com", "3239 Tori Lane Salt Lake City, UT 84104", 6588)
};

int typecast_str(string data) {
	int str_int = 0;
	for (int i = 0; i < data.size(); i++) str_int = str_int * 10 + data[i] - 48;
	return str_int;
}

int main() {
	cout << "rhyta.com ve ya dayrep.com domenlerinde emaili olan borclulari cixartmag\n\n";
	for_each(begin(debtors), end(debtors), 
    [](Debtor*& deb)->void {
		string rhyta = "rhyta.com";
		string dayrep = "dayrep.com";
		for (int i = 1; i < deb->getEmail().size(); i++) {
			if (deb->getEmail()[i - 1] == '@') {
				int index = 0;
				for (int j = i; deb->getEmail()[j] == rhyta[index++] && j < deb->getEmail().size() - 1; j++) {}
				if (index == rhyta.size()) 
                cout << *deb << endl;
				else {
					index = 0;
					for (int j = i; deb->getEmail()[j] == dayrep[index++] && j < deb->getEmail().size() - 1; j++) {}
					if (index == dayrep.size()) 
                    cout << *deb << endl;
				}
			}
		}
	});

	cout << "Yashi 26-dan 36-ya qeder olan borclulari cixartmag\n\n";
	for_each(begin(debtors), end(debtors), 
    [](Debtor*& deb)->void {
		string year;
		year.resize(4);
		int index = 0;
		for (int i = deb->getBirthDay().size() - 4; i < deb->getBirthDay().size(); i++) year[index++] = deb->getBirthDay()[i];
		if (2023 - typecast_str(year) >= 26 && 2023 - typecast_str(year) <= 36) 
        cout << *deb << endl;
	});


	cout << "Borcu 5000-den cox olmayan borclularic cixartmag\n\n";
	for_each(begin(debtors), end(debtors), 
    [](Debtor*& deb)->void {
		if (deb->getDebt() <= 5000) 
        cout << *deb << endl;
	});

	cout << "Butov adi 18 simvoldan cox olan ve telefon nomresinde 2 ve ya 2-den cox 7 reqemi olan borclulari cixartmaq\n\n";
	for_each(begin(debtors), end(debtors), 
    [](Debtor*& deb)->void {
		if (deb->getName().size() > 18) {
			bool have2 = false;
			bool have27 = false;
			if (deb->getPhone().find("2") != string::npos) have2 = true;
			if (deb->getPhone().find("7") != string::npos && deb->getPhone().rfind("7") != string::npos) {
				if (deb->getPhone().find("7") != deb->getPhone().rfind("7")) have27 = true;
			} if (have2 || have27) 
            cout << *deb << endl;
		}
	});

	cout << "Qishda anadan olan borclulari cixardmaq\n\n";
	for_each(begin(debtors), end(debtors), 
    [](Debtor*& deb)->void {
		int len = 0;
		for (int i = 0; deb->getBirthDay()[i] != ' '; i++) len++;
		if (!deb->getBirthDay().compare(0, len, "January") ||
			!deb->getBirthDay().compare(0, len, "February") ||
			!deb->getBirthDay().compare(0, len, "December")) 
        cout << *deb << endl;
	});

	cout << "Borcu, umumi borclarin orta borcunnan cox olan borclulari cixarmaq ve evvel familyaya gore sonra ise meblegin azalmagina gore sortirovka etmek.\n\n\n";
	int sum = 0;
	int avg;
	for (auto& i : debtors) {
		sum += i->getDebt();
	}
	avg = sum / debtors.size();

	debtors.sort([](Debtor* d1, Debtor* d2)->auto {
		int surname = d1->getName().find(' ') + 1;
		int surname2 = d2->getName().find(' ') + 1;
		if (d1->getName()[surname] == d2->getName()[surname2]) {
			if (d2->getDebt() < d1->getDebt()) return true;
		}return d1->getName()[surname] < d2->getName()[surname2];
	});

	for_each(begin(debtors), end(debtors), 
    [&avg](Debtor*& deb)->void {
		if (deb->getDebt() > avg) 
        cout << *deb << endl;
	});

	cout << "Telefon nomresinde 8 olmayan borclularin yalniz familyasin,yashin ve umumi borcun meblegin cixarmaq\n\n";
	for_each(begin(debtors), end(debtors), 
    [&avg](Debtor*& deb)->void {
		if (deb->getPhone().find("8") == string::npos) deb->show();
		else 
        cout << *deb << endl;
	});

	cout << "Adinda ve familyasinda hec olmasa 3 eyni herf olan borclularin siyahisin cixarmaq ve onlari elifba sirasina gore sortirovka elemek\n\n";
	debtors.sort([](Debtor* d1, Debtor* d2)->auto {
		return d2->getDebt() < d1->getDebt();
	});

	for_each(begin(debtors), end(debtors), 
    [](Debtor*& deb)->void {
		int surname = deb->getName().find('.') + 2, count = 0;
		string surnames;
		surnames.resize(deb->getName().size() - (surname + 1));
		for (int i = surname; i < deb->getName().size(); i++) surnames[i - surname] = deb->getName()[i];
		for (int i = 0; deb->getName()[i] != ' '; i++) {
			if (surnames.find(deb->getName()[i]) != string::npos) count++;
		}if (count >= 3) 
        cout << *deb << endl;
	});

	cout << "Butun borcu olanlarin borcunu cemleyib umumi borcu cixartmaq\n\n";
	int sums = 0;
	for (auto& i : debtors) {
		sums += i->getDebt();
	}
    cout << sums << endl;

	cout << "2ci dunya muharibesin gormush borclularin siyahisi cixartmaq\n\n";
	for_each(begin(debtors), end(debtors), 
    [](Debtor*& deb)->void {
		string year;
		year.resize(4);
		int index = 0;
		for (int i = deb->getBirthDay().size() - 4; i < deb->getBirthDay().size(); i++) year[index++] = deb->getBirthDay()[i];
		if (typecast_str(year) >= 1939 && 1945 >= typecast_str(year)) 
        cout << *deb << endl;
	});

	cout << "Nomresinde tekrar reqemler olmayan borclularin ve onlarin borcunun meblegin cixartmaq\n\n";
	for_each(begin(debtors), end(debtors), 
    [](Debtor*& deb)->void {
		bool issame = false;
		for (int i = 0; i < deb->getPhone().size(); i++) {
			if (count(deb->getPhone().begin(), deb->getPhone().end(), deb->getPhone()[i]) != 1 && deb->getPhone()[i] != '-') issame = true;
		} if (!issame) 
        cout << *deb << endl;
	});
}