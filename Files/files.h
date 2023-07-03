#pragma once
#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
namespace fs = filesystem;

class Chat 
{
private:
	// start of User
	struct User
	{
		string _name;
		string _login;
		string _pass;

		User() = default;
		User(string name, string login, string pass) : _name(name), _login(login), _pass(pass)
		{

		}
		~User()
		{
			_name.clear();
			_login.clear();
			_pass.clear();
		}

		friend ostream& operator << (ostream& os, const User& obj)
		{
			os << obj._name << '\n' << obj._login << '\n' << obj._pass << endl;

			return os;
		}
	};
	// end of User
	// start of Message
	struct Message
	{
		string _text;
		string _sender;
		string _receiver;

		Message() = default;
		Message(string text, string sender, string receiver) : _text(text), _sender(sender), _receiver(receiver)
		{

		}
		~Message()
		{
			_text.clear();
			_sender.clear();
			_receiver.clear();
		}

		friend ostream& operator << (ostream& os, const Message& obj)
		{
			os << obj._text << '\n' << obj._sender << '\n' << obj._receiver << endl;

			return os;
		}
	};
	// end of Message
	vector<User> users;
	vector<Message> messages;

	void printAllUsersInner(const User& curr);
	void printAllMessagesInner(const Message& msg);

public:
	Chat() = default;
	~Chat();
	void addUser(const string& name, const string& login, const string& pass);
	void addMessage(const string& text, const string& sender, const string& receiver);
	void sendAllUsersToFile();
	void readAllUsersFromFile();
	void printAllUses();
	void sendAllMessagesToFile();
	void readAllMessagesFromFile();
	void printAllMessages();
};
void cinClear();