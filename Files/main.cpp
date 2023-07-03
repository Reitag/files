#include "files.h"

int main()
{
	Chat chat;
	chat.readAllUsersFromFile();
	chat.readAllMessagesFromFile();

	char choice;
	cout << "Enter your futher step:\n1 - add user\n2 - text a message\n3 - show all users\n4 - show all messages\nq - exit" << endl;
	cin >> choice;

	while (choice != 'q')
	{
		switch (choice)
		{
		case '1':
		{
			cinClear();
			string name, login, pass;

			cout << "Enter name: ";
			getline(cin, name);

			cout << "Enter login: ";
			getline(cin, login);

			cout << "Enter pass: ";
			getline(cin, pass);

			chat.addUser(name, login, pass);

			break;
		}
		case '2':
		{
			cinClear();
			string text, sender, receiver;

			cout << "Enter text: ";
			getline(cin, text);

			cout << "Enter your name: ";
			getline(cin, sender);

			cout << "Enter receiver: ";
			getline(cin, receiver);

			chat.addMessage(text, sender, receiver);

			break;
		}
		case '3':
		{
			cinClear();
			chat.printAllUses();

			break;
		}
		case '4':
		{
			cinClear();
			chat.printAllMessages();

			break;
		}
		}
		cout << "Enter your futher step:\n1 - add user\n2 - text a message\n3 - show all users\n4 - show all messages\nq - exit" << endl;
		cin >> choice;
	}

	chat.sendAllUsersToFile();
	chat.sendAllMessagesToFile();

	return 0;
}