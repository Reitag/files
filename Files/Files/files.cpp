#include "files.h"

using namespace std;

void Chat::printAllUsersInner(const User& curr)
{
	cout << "Name: " << curr._name << '\n' << "Login: " << curr._login << '\n' << "Pass: " << curr._pass << '\n' << endl;
}

void Chat::printAllMessagesInner(const Message& msg)
{
	cout << "Message: " << msg._text << '\n' << "From: " << msg._sender << '\n' << "To: " << msg._receiver << '\n' << endl;
}

Chat::~Chat()
{
	users.clear();
	users.shrink_to_fit();
	messages.clear();
	messages.shrink_to_fit();
}

void Chat::addUser(const string& name, const string& login, const string& pass)
{
	User newUser;
	newUser._name = name; newUser._login = login; newUser._pass = pass;
	users.push_back(newUser);
}

void Chat::addMessage(const string& text, const string& sender, const string& receiver)
{
	Message newMessage;
	newMessage._text = text; newMessage._sender = sender; newMessage._receiver = receiver;
	messages.push_back(newMessage);
}

void Chat::sendAllUsersToFile()
{
	ofstream user_file("users.txt", ios::out | ios::binary);

	fs::permissions("users.txt", fs::perms::all, fs::perm_options::remove);
	fs::permissions("users.txt", fs::perms::owner_read | fs::perms::owner_write, fs::perm_options::add);

	if (user_file.is_open())
	{
		for (vector<User>::iterator it = users.begin(); it != users.end(); ++it)
		{
			user_file << *it;
		}
	}
	else
	{
		//cout << "File could not open!" << endl;
	}
	user_file.close();
}

void Chat::readAllUsersFromFile()
{
	ifstream user_file("users.txt", ios::in | ios::binary);

	if (user_file.is_open())
	{
		int count = 1;
		string name, login, pass;
		while (!user_file.eof())
		{
			if (count == 1)
			{
				getline(user_file, name);
				++count;
			}
			else if (count == 2)
			{
				getline(user_file, login);
				++count;
			}
			else
			{
				getline(user_file, pass);
				this->addUser(name, login, pass);
				name.clear();
				login.clear();
				pass.clear();
				count = 1;
			}
		}
	}
	else
	{
		//cout << "File could not open!" << endl;
	}
	user_file.close();
}

void Chat::printAllUses()
{
	for (vector<User>::iterator it = users.begin(); it != users.end(); ++it)
	{
		printAllUsersInner(*it);
	}
}

void Chat::sendAllMessagesToFile()
{
	ofstream message_file("messages.txt", ios::out | ios::binary);

	fs::permissions("messages.txt", fs::perms::all, fs::perm_options::remove);
	fs::permissions("messages.txt", fs::perms::owner_read | fs::perms::owner_write, fs::perm_options::add);

	if (message_file.is_open())
	{
		for (vector<Message>::iterator it = messages.begin(); it != messages.end(); ++it)
		{
			message_file << *it;
		}
	}
	message_file.close();
}

void Chat::readAllMessagesFromFile()
{
	ifstream message_file("messages.txt", ios::in | ios::binary);

	if (message_file.is_open())
	{
		int count = 1;
		string text, sender, receiver;
		while (!message_file.eof())
		{
			if (count == 1)
			{
				getline(message_file, text);
				++count;
			}
			else if (count == 2)
			{
				getline(message_file, sender);
				++count;
			}
			else
			{
				getline(message_file, receiver);
				this->addMessage(text, sender, receiver);
				text.clear();
				sender.clear();
				receiver.clear();
				count = 1;
			}
		}
	}
	message_file.close();
}

void Chat::printAllMessages()
{
	for (vector<Message>::iterator it = messages.begin(); it != messages.end(); ++it)
	{
		printAllMessagesInner(*it);
	}
}

void cinClear()
{
	cin.clear();
	cin.ignore(1, '\n');
}