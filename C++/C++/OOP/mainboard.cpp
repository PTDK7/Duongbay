#ifndef COMPONENT_H
#define COMPONENT_H
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
using namespace std;
struct Date {
    int day, month, year;
    void input();
    void display() const;
    void fromString(const string& str);
};

class Component {
protected:
    string id;
    string name;
    Date manufacturingDate;
    int quantity;
    double price;
    string manufacturer;

public:
    Component() = default;
    virtual ~Component() = default;

    virtual void input();
    virtual void display() const;
    virtual string toFileString() const;
    virtual void fromFileString(const string* tokens, int tokenCount);

    virtual string getType() const = 0;
    virtual string getSocket() const { return ""; }

    string getId() const { return id; }
    string getName() const { return name; }
    double getPrice() const { return price; }
    void setId(const std::string& newId) { id = newId; }
};
void Date::input() {
    cout << "Ngay: "; cin >> day;
    cout << "Thang: "; cin >> month;
    cout << "Nam: "; cin >> year;
}

void Date::display() const {
    cout << setw(2) << setfill('0') << day << "/"
              << setw(2) << setfill('0') << month << "/"
              << year;
}

void Date::fromString(const string& str) {
    char slash;
    istringstream iss(str);
    iss >> day >> slash >> month >> slash >> year;
}

void Component::input() {
    cin.ignore();
    cout << "Nhap ten linh kien: ";
    getline(cin, name);
    cout << "Nhap ngay san xuat (dd/mm/yyyy): ";
    string dateStr;
    getline(cin, dateStr);
    manufacturingDate.fromString(dateStr);
    cout << "Nhap so luong: ";
    cin >> quantity;
    cout << "Nhap gia: ";
    cin >> price;
    cin.ignore();
    cout << "Nhap nha san xuat: ";
    getline(cin, manufacturer);
}

void Component::display() const {
    cout << left << setw(10) << id
         << setw(25) << name
              << setw(12);
    manufacturingDate.display();
    cout << setw(10) << quantity
         << setw(15) << fixed << setprecision(2) << price
              << setw(20) << manufacturer;
}

string Component::toFileString() const {
    ostringstream oss;
    oss << "COMPONENT;" << id << ";" << name << ";"
        << setw(2) << setfill('0') << manufacturingDate.day << "/"
        << setw(2) << setfill('0') << manufacturingDate.month << "/"
        << manufacturingDate.year << ";"
        << quantity << ";" << price << ";" << manufacturer;
    return oss.str();
}

void Component::fromFileString(const string* tokens, int tokenCount) {
    if (tokenCount >= 8) {
        id = tokens[1];
        name = tokens[2];
        manufacturingDate.fromString(tokens[3]);
        quantity = stoi(tokens[4]);
        price = stod(tokens[5]);
        manufacturer = tokens[6];
    }
}
#endif

//#include "Component.h"

class CPU : public Component {
private:
    string socket;
    int cores;
    double baseClock;
    double boostClock;
    int threads;
    int cache;

public:
    CPU() = default;

    void input() override;
    void display() const override;
    string toFileString() const override;
    void fromFileString(const string* tokens, int tokenCount) override;

    string getType() const override { return "CPU"; }
    string getSocket() const override { return socket; }

    int getCores() const { return cores; }
    double getBaseClock() const { return baseClock; }
};

void CPU::input() {
    Component::input();
    cout << "Nhap socket: ";
    getline(cin, socket);
    cout << "Nhap so nhan: ";
    cin >> cores;
    cout << "Nhap xung nhan co ban (GHz): ";
    cin >> baseClock;
    cout << "Nhap xung nhan cao nhat (GHz): ";
    cin >> boostClock;
    cout << "Nhap so luong thread: ";
    cin >> threads;
    cout << "Nhap dung luong cache (MB): ";
    cin >> cache;
}

void CPU::display() const {
    Component::display();
    cout << setw(10) << socket
        << setw(8) << cores
        << setw(8) << fixed << setprecision(1) << baseClock << "GHz"
        << setw(8) << fixed << setprecision(1) << boostClock << "GHz"
        << setw(10) << threads
        << setw(8) << cache << "MB" << endl;
}

string CPU::toFileString() const {
    ostringstream oss;
    oss << "CPU;" << id << ";" << name << ";"
        << setw(2) << setfill('0') << manufacturingDate.day << "/"
        << setw(2) << setfill('0') << manufacturingDate.month << "/"
        << manufacturingDate.year << ";"
        << quantity << ";" << price << ";" << manufacturer << ";"
        << socket << ";" << cores << ";" << baseClock << ";"
        << boostClock << ";" << threads << ";" << cache;
    return oss.str();
}

void CPU::fromFileString(const string* tokens, int tokenCount) {
    if (tokenCount >= 13) {
        Component::fromFileString(tokens, tokenCount);
        socket = tokens[7];
        cores = stoi(tokens[8]);
        baseClock = stod(tokens[9]);
        boostClock = stod(tokens[10]);
        threads = stoi(tokens[11]);
        cache = stoi(tokens[12]);
    }
}

#ifndef MAINBOARD_H
#define MAINBOARD_H

//#include "Component.h"
using namespace std;

class Mainboard : public Component {
private:
    string socket;
    string chipset;
    string formFactor;
    int ramSlots;
    int maxRAM;
    string memoryType;

public:
    Mainboard() = default;

    void input() override;
    void display() const override;
    string toFileString() const override;
    void fromFileString(const std::string* tokens, int tokenCount) override;

    string getType() const override { return "Mainboard"; }
    string getSocket() const override { return socket; }

    string getChipset() const { return chipset; }
    int getRamSlots() const { return ramSlots; }
};

#endif

//#include "Mainboard.h"

void Mainboard::input() {
    Component::input();
    cout << "Nhap socket ho tro: ";
    getline(cin, socket);
    cout << "Nhap chipset: ";
    getline(cin, chipset);
    cout << "Nhap kich thuoc (ATX/mATX/ITX): ";
    getline(cin, formFactor);
    cout << "Nhap so khe RAM: ";
    cin >> ramSlots;
    cout << "Nhap RAM toi da (GB): ";
    cin >> maxRAM;
    cin.ignore();
    cout << "Nhap loai RAM (DDR4/DDR5): ";
    getline(cin, memoryType);
}

void Mainboard::display() const {
    Component::display();
    cout << setw(10) << socket
              << setw(15) << chipset
              << setw(12) << formFactor
              << setw(12) << ramSlots
              << setw(10) << maxRAM << "GB"
              << setw(10) << memoryType << endl;
}

string Mainboard::toFileString() const {
    ostringstream oss;
    oss << "MAINBOARD;" << id << ";" << name << ";"
        << setw(2) << setfill('0') << manufacturingDate.day << "/"
        << setw(2) << setfill('0') << manufacturingDate.month << "/"
        << manufacturingDate.year << ";"
        << quantity << ";" << price << ";" << manufacturer << ";"
        << socket << ";" << chipset << ";" << formFactor << ";"
        << ramSlots << ";" << maxRAM << ";" << memoryType;
    return oss.str();
}

void Mainboard::fromFileString(const string* tokens, int tokenCount) {
    if (tokenCount >= 13) {
        Component::fromFileString(tokens, tokenCount);
        socket = tokens[7];
        chipset = tokens[8];
        formFactor = tokens[9];
        ramSlots = stoi(tokens[10]);
        maxRAM = stoi(tokens[11]);
        memoryType = tokens[12];
    }
}

//#include "ComputerStore.h"
#include <fstream>

int main() {
    ComputerStore store;
    store.loadFromFile("linhkien.txt");
    store.showMenu();
    return 0;
}